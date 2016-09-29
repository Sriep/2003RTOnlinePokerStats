// History ParserDlg.cpp : implementation file
//

#include "stdafx.h"
#include "History Parser.h"
#include "History ParserDlg.h"
#include "HistoryParserModel.h"

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
// CHistoryParserDlg dialog

CHistoryParserDlg::CHistoryParserDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CHistoryParserDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CHistoryParserDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CHistoryParserDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CHistoryParserDlg)
	DDX_Control(pDX, IDC_LOG_FILE_NAME, m_ctrlLogFile);
	DDX_Control(pDX, IDC_PARSING_PROGRESS, m_cProgressBar);
	DDX_Control(pDX, IDC_PARSING_STATUS, m_cParsingStatus);
	DDX_Control(pDX, IDC_TO_DIRECTORY, m_cToParseDirectory);
	DDX_Control(pDX, IDC_FROM_DIRECTORY, m_cFromParseDirectory);
	DDX_Control(pDX, IDC_FILE_NAME, m_strFileName);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CHistoryParserDlg, CDialog)
	//{{AFX_MSG_MAP(CHistoryParserDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(ID_PARSE, OnParse)
	ON_BN_CLICKED(IDC_PARSE_DIRECTORY, OnParseDirectory)
	ON_BN_CLICKED(ID_PARSE_LOG, OnParseLog)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHistoryParserDlg message handlers

BOOL CHistoryParserDlg::OnInitDialog()
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
	m_strFileName.SetWindowText("B:\\Test\\TestHandHistoryt.txt");
	m_cToParseDirectory.SetWindowText("C:\\Poker\\HandHistories\\Done");
	m_cFromParseDirectory.SetWindowText("C:\\Poker\\HandHistories\\Todo");
	m_ctrlLogFile.SetWindowText("C:\\Poker\\Live\\Old Logs\\Paradise_306FE.txt");

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CHistoryParserDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CHistoryParserDlg::OnPaint() 
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
HCURSOR CHistoryParserDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CHistoryParserDlg::OnParseDirectory() 
{
	// TODO: Add your control notification handler code here
	CString strToDirectory;
	CString strFromDirectory;
	m_cToParseDirectory.GetWindowText(strToDirectory);
	m_cFromParseDirectory.GetWindowText(strFromDirectory);

	CHistoryParserModel cHistoryModel;
	cHistoryModel.ParseDirectory(strFromDirectory, strToDirectory, *this);

	m_cProgressBar.SetPos(0);
	m_cParsingStatus.SetWindowText("Finished");
	UpdateWindow();
}

void CHistoryParserDlg::OnParse() 
{
	// TODO: Add your control notification handler code here
	CString strFileName;
	m_strFileName.GetWindowText(strFileName);
	CHistoryParserModel cHistoryModel;
	cHistoryModel.ParseFile(strFileName);
}

void CHistoryParserDlg::OnParseLog() 
{
	// TODO: Add your control notification handler code here
	CString strLogFileName;
	m_ctrlLogFile.GetWindowText(strLogFileName);
	CHistoryParserModel cHistoryModel;
	cHistoryModel.ParseLogFile(strLogFileName);
}
