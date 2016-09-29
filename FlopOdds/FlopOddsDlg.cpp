// FlopOddsDlg.cpp : implementation file
//

#include "stdafx.h"
#include "FlopOdds.h"
#include "FlopOddsDlg.h"
#include "PDlgHandsSelection.h"	
#include "PHoldemFlop.h"
#include "HandEVDialog.h"

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
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFlopOddsDlg dialog

CFlopOddsDlg::CFlopOddsDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFlopOddsDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFlopOddsDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFlopOddsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFlopOddsDlg)
	DDX_Control(pDX, IDC_FLOP3_SUIT, m_ctlFlop3Suit);
	DDX_Control(pDX, IDC_FLOP2_SUIT, m_ctlFlop2Suit);
	DDX_Control(pDX, IDC_FLOP1_SUIT, m_ctlFlop1Suit);
	DDX_Control(pDX, IDC_FLOP3_RANK, m_ctlFlop3Rank);
	DDX_Control(pDX, IDC_FLOP2_RANK, m_ctlFlop2Rank);	 
	DDX_Control(pDX, IDC_FLOP1_RANK, m_ctlFlop1Rank);
	DDX_GridControl(pDX, IDC_FO_GRID_FLOPSTATS, m_ctlResultsGrid);
	DDX_GridControl(pDX, IDC_FO_GRID_SPREADLIST, m_ctlSpradListsGrid);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CFlopOddsDlg, CDialog)
	//{{AFX_MSG_MAP(CFlopOddsDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_B_HANDS_SELECTOR, OnBHandsSelector)
	ON_BN_CLICKED(IDC_FO_B_CALCULATE, OnFoBCalculate)
	ON_BN_CLICKED(IDC_TOHANDEV_DLG, OnToHandEVDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFlopOddsDlg message handlers

BOOL CFlopOddsDlg::OnInitDialog()
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
	m_ctlFlop3Suit.populate();
	m_ctlFlop2Suit.populate();
	m_ctlFlop1Suit.populate();
	m_ctlFlop3Rank.populate();
	m_ctlFlop2Rank.populate();
	m_ctlFlop1Rank.populate();
	m_ctlSpradListsGrid.setup(&m_cHandsList);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CFlopOddsDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CFlopOddsDlg::OnPaint() 
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
HCURSOR CFlopOddsDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CFlopOddsDlg::OnBHandsSelector() 
{
	// TODO: Add your control notification handler code here
	PDlgHandsSelection dlgHandSelector(m_cHandsList);
	dlgHandSelector.DoModal();
}

void CFlopOddsDlg::OnOK() 
{
	// TODO: Add extra validation here
	CDialog::OnOK();
}

void CFlopOddsDlg::OnFoBCalculate() 
{
	// TODO: Add your control notification handler code here
	m_ctlResultsGrid.clear();
	PHoldemFlop cFlop
	(
		PCard(m_ctlFlop1Rank.getSelectedRank(),m_ctlFlop1Suit.getSelectedSuit()),	
		PCard(m_ctlFlop2Rank.getSelectedRank(),m_ctlFlop2Suit.getSelectedSuit()),
		PCard(m_ctlFlop3Rank.getSelectedRank(),m_ctlFlop3Suit.getSelectedSuit())
	);
	PFlopPercentages* pFlopPercentages = PFlopPercentages::calculateFlopPercentages(m_cHandsList, cFlop);
	m_ctlResultsGrid.populate(pFlopPercentages);
	delete pFlopPercentages;
}

void CFlopOddsDlg::OnToHandEVDlg() 
{
	// TODO: Add your control notification handler code here
	CHandEVDialog dlgHandEVDialog;
	dlgHandEVDialog.DoModal();
}
