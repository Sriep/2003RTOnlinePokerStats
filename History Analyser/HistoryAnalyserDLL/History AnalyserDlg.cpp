// History AnalyserDlg.cpp : implementation file
//

#include "stdafx.h"
#include "History AnalyserDlg.h"
#include "NickGridComboCell.h" 
#include "SPRSCountHands.h"
#include "PPokerSite.h"
#include <math.h>
#include "RS_DBQueue.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHistoryAnalyserDlg dialog

CHistoryAnalyserDlg::CHistoryAnalyserDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CHistoryAnalyserDlg::IDD, pParent),
	m_bFixed(FALSE),
	m_iSite(0),
	m_hwndDealerWindow(NULL)
{
	//{{AFX_DATA_INIT(CHistoryAnalyserDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

CHistoryAnalyserDlg::~CHistoryAnalyserDlg()
{
}

void CHistoryAnalyserDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CHistoryAnalyserDlg)
	DDX_Control(pDX, IDC_PROGRESS_REFRESH, m_ctlProgressRefresh);
	DDX_Control(pDX, IDC_ACTIVE_TABLES, m_ctlActiveTables);
	DDX_Control(pDX, IDC_REFRESHING_STATUS, m_ctlRefreshingStatus);
	DDX_Control(pDX, IDC_SAW_RIVER, m_ctlSawRiver);
	DDX_Control(pDX, IDC_POKER_SITE, m_ctlPokerSite);
	DDX_Control(pDX, IDC_VARIANCE, m_ctlVariance);
	DDX_Control(pDX, IDC_VOL_PUT_MONEY_IN_POT, m_ctlVolPutMoneyPot);
	//}}AFX_DATA_MAP
	DDX_GridControl(pDX, IDC_GRID_PREFLOP,pStatsGrid[1]);
	DDX_GridControl(pDX, IDC_GRID_FLOP, pStatsGrid[2]);
	DDX_GridControl(pDX, IDC_GRID_TURN,pStatsGrid[3]);
	DDX_GridControl(pDX, IDC_GRID_RIVER, pStatsGrid[4]);
}

BEGIN_MESSAGE_MAP(CHistoryAnalyserDlg, CDialog)
	//{{AFX_MSG_MAP(CHistoryAnalyserDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(ID_REFRESH, OnRefresh)
	ON_BN_CLICKED(IDC_CLEAR, OnClear)
	ON_CBN_SELCHANGE(IDC_POKER_SITE, OnSelchangePokerSite)
	ON_CBN_SELCHANGE(IDC_ACTIVE_TABLES, OnSelchangeActiveTables)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHistoryAnalyserDlg message handlers

BOOL CHistoryAnalyserDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	m_ctlProgressRefresh.SetRange(0, CStatsGrid::NUM_ROWS_IN_GRID * 4);

	pStatsGrid[1].SetUp(1, this);
	pStatsGrid[2].SetUp(2, this);
	pStatsGrid[3].SetUp(3, this);
	pStatsGrid[4].SetUp(4, this);

	if (!IsFixed())
	{
		for ( int iSiteId = 1 ; iSiteId < PPokerSite::NUM_OF_POKER_SITES ; iSiteId++ ) 
		{
			m_ctlPokerSite.InsertString(iSiteId-1,PPokerSite::GetName(iSiteId));
		}
	}
	return TRUE;  // return TRUE  unless you set the focus to a control
}

CStatsGrid& CHistoryAnalyserDlg::GetGrid(int iGridNumber)
{
	return pStatsGrid[iGridNumber];
}

int CHistoryAnalyserDlg::GetPokerSite()
{
	return m_iSite;	
}

void CHistoryAnalyserDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CHistoryAnalyserDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CHistoryAnalyserDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CHistoryAnalyserDlg::OnSelchangePokerSite() 
{
	// TODO: Add your control notification handler code here
	m_iSite = m_ctlPokerSite.GetCurSel() + 1;
	OnClear();
	OnRefresh();
	pStatsGrid[1].RefreshPlayerCombos(m_ctlPokerSite.GetCurSel()+1);
}

void CHistoryAnalyserDlg::OnRefresh() 
{
	// TODO: Add your control notification handler code here
	m_ctlRefreshingStatus.SetWindowText("Updating Players");
	m_ctlProgressRefresh.SetPos(0);		 
	m_ctlProgressRefresh.ShowWindow(SW_SHOW);
	UpdateWindow();

	if (CB_ERR != m_ctlActiveTables.GetCurSel())
	{
		m_listPlayers = m_ctlActiveTables.GetListOfPlayers();
		pStatsGrid[1].UpdatePlayers(m_listPlayers);
		pStatsGrid[2].UpdatePlayers(m_listPlayers);
		pStatsGrid[3].UpdatePlayers(m_listPlayers);
		pStatsGrid[4].UpdatePlayers(m_listPlayers);
	}

	m_ctlRefreshingStatus.SetWindowText("Updating Pre Flop Data");
	m_ctlProgressRefresh.SetPos(1);

	RS_DBQueue dbQueue;
	RS_DBQueue::QueueID qId = dbQueue.WaitToUseDB(RS_DBQueue::DB_QUEUE_HISTORY_ANALYSOR_PRIORITY, "History Analyser");
	try
	{
		UpdateWindow();
		pStatsGrid[1].RefreshGrid();

		m_ctlRefreshingStatus.SetWindowText("Updating Flop Data"); 
		UpdateWindow();
		pStatsGrid[2].RefreshGrid();

		m_ctlRefreshingStatus.SetWindowText("Updating Turn Data");
		UpdateWindow();
		pStatsGrid[3].RefreshGrid();

		m_ctlRefreshingStatus.SetWindowText("Updating River Data");
		UpdateWindow();
		pStatsGrid[4].RefreshGrid();

		m_ctlRefreshingStatus.SetWindowText("Updating Status Bar");
		UpdateWindow();
		UpdateStatusBar();

		m_ctlRefreshingStatus.SetWindowText("");
		m_ctlProgressRefresh.ShowWindow(SW_HIDE);		  

		pStatsGrid[1].AutoSizeColumns();
		pStatsGrid[2].AutoSizeColumns();
		pStatsGrid[3].AutoSizeColumns();
		pStatsGrid[4].AutoSizeColumns();

		UpdateWindow();
	}
	catch (CDBException pe)
	{
		int i = 5;
		dbQueue.FinishedUsingDB(qId);
	}
	dbQueue.FinishedUsingDB(qId);
}

void CHistoryAnalyserDlg::OnClear() 
{
	// TODO: Add your control notification handler code here
	pStatsGrid[1].ClearGrid();
	pStatsGrid[2].ClearGrid();
	pStatsGrid[3].ClearGrid();
	pStatsGrid[4].ClearGrid();
}

void CHistoryAnalyserDlg::UpdateStatusBar()
{
	int ipctSawRiver = 0;
	double fVariance = 0;
	int ipctVolPutMoneyPot = 0;
	int iNumDataEntries = 0;
	int iNumVarianceDataEntries = 0;
	const int NUM_HANDS_NEEDED_TO_INCLUDE_IN_STATS = 2;
	const double VARIANCE_OF_STATS = 0.15; //pq where p = .2 ish

	for (int  iRow = 1; iRow < CStatsGrid::NUM_ROWS_IN_GRID ; iRow++ )
	{
		CNickGridComboCell* pComboCell = (CNickGridComboCell*) pStatsGrid[1].GetCell(iRow, 0);
		ASSERT(pComboCell->IsKindOf(RUNTIME_CLASS(CNickGridComboCell)));
		CString strNick = pComboCell->GetText();
		if (!strNick.IsEmpty())
		{
			int iNumHands = SPRSCountHands::GetValue("sp_num_get_hands", strNick, GetPokerSite());
			if (iNumHands >= NUM_HANDS_NEEDED_TO_INCLUDE_IN_STATS)
			{
				iNumDataEntries++;
				iNumVarianceDataEntries++;
				fVariance += VARIANCE_OF_STATS / (double) iNumHands;
				int iNumVolPutMoneyPot = SPRSCountHands::GetValue("sp_preflop_num_vol_put_money_in_Pot", strNick, GetPokerSite());
				ipctVolPutMoneyPot += iNumVolPutMoneyPot * 100 / iNumHands;
				int iNumSawRiver = SPRSCountHands::GetValue("sp_river_num_seen", strNick, GetPokerSite());
				ipctSawRiver += iNumSawRiver * 100 / iNumHands;
			}
			else
			{
				fVariance += VARIANCE_OF_STATS;
				iNumVarianceDataEntries++;
			}
		}
	}

	CString strVolPutMoneyInPot;
 	CString strSawRiver;
	CString strVariance;
	if (iNumDataEntries > 0)
	{
		ipctVolPutMoneyPot /= iNumDataEntries;
		strVolPutMoneyInPot.Format("%d", ipctVolPutMoneyPot);

		ipctSawRiver /= iNumDataEntries;
		strSawRiver.Format("%d", ipctSawRiver);

		fVariance /= iNumVarianceDataEntries;
		fVariance = sqrt(fVariance) * 100;
		strVariance.Format("%d", (int) fVariance);
	}
	m_ctlVolPutMoneyPot.SetWindowText(strVolPutMoneyInPot);
	m_ctlSawRiver.SetWindowText(strSawRiver);
	m_ctlVariance.SetWindowText(strVariance);

}


void CHistoryAnalyserDlg::FixTable(const CTableGridRowData& cTableData)
{
	//m_TableData = cTableData;

	m_listPlayers = cTableData.GetListOfPlayers();
	m_iSite = cTableData.GetSite();
	m_hwndDealerWindow = cTableData.GetDealerTextWindow();
		;

	CString strWindowCaption;
	strWindowCaption.Format("History Analyser for table %s", cTableData.GetTableName());
	SetWindowText(strWindowCaption);
	m_ctlPokerSite.ShowWindow(SW_HIDE);
	m_ctlActiveTables.ShowWindow(SW_HIDE);
	m_bFixed = true;
	RefreshTableInfo(cTableData);
}



CHistoryAnalyserDlg::RefreshTableInfo(const CTableGridRowData &cTableData)
{
	//m_TableData = cTableData;
	m_listPlayers = cTableData.GetListOfPlayers();
	m_iSite = cTableData.GetSite();
	m_hwndDealerWindow = cTableData.GetDealerTextWindow();

	OnRefresh();
}

bool CHistoryAnalyserDlg::IsFixed()	const
{
	return m_bFixed;
}

void CHistoryAnalyserDlg::OnSelchangeActiveTables() 
{
	// TODO: Add your control notification handler code here
	//m_TableData = cTableData;
	m_listPlayers = m_ctlActiveTables.GetListOfPlayers();
	m_iSite = m_ctlActiveTables.GetSite();
	m_hwndDealerWindow = m_ctlActiveTables.GetDealerTextWindow();

	CString strWindowCaption;
	strWindowCaption.Format("History Analyser for table %s", m_ctlActiveTables.GetTableName());
	SetWindowText(strWindowCaption);

	if (m_iSite > 0)
	{
		OnRefresh();
	}

	pStatsGrid[1].AutoSizeColumns();
	pStatsGrid[2].AutoSizeColumns();
	pStatsGrid[3].AutoSizeColumns();
	pStatsGrid[4].AutoSizeColumns();
	Invalidate();
	UpdateWindow();
}

HWND CHistoryAnalyserDlg::GetDealerTextWindowHandle()
{
	return m_hwndDealerWindow;
}
