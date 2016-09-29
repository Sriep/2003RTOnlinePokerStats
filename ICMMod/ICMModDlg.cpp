// ICMModDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ICMMod.h"
#include "ICMModDlg.h"
#include "TournamentEquity.h"
#include "StealRaises.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CICMModDlg dialog

CICMModDlg::CICMModDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CICMModDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CICMModDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CICMModDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CICMModDlg)
	DDX_Control(pDX, IDC_EQUITY9, m_Equity9);
	DDX_Control(pDX, IDC_EQUITY8, m_Equity8);
	DDX_Control(pDX, IDC_EQUITY7, m_Equity7);
	DDX_Control(pDX, IDC_EQUITY6, m_Equity6);
	DDX_Control(pDX, IDC_EQUITY5, m_Equity5);
	DDX_Control(pDX, IDC_EQUITY4, m_Equity4);
	DDX_Control(pDX, IDC_EQUITY3, m_Equity3);
	DDX_Control(pDX, IDC_EQUITY2, m_Equity2);
	DDX_Control(pDX, IDC_EQUITY1, m_Equity1);
	DDX_Control(pDX, IDC_PROGRESS1, m_ctrlProgressBar);
	DDX_Control(pDX, IDC_STACK1_STEP, m_ctrlStack1Step);
	DDX_Control(pDX, IDC_STACK1_MAX, m_ctrlStack1Max);
	DDX_Control(pDX, IDC_BLINDS_ANTES, m_ctrlBlindsAntes);
	DDX_Control(pDX, IDC_STACK9, m_stack9);
	DDX_Control(pDX, IDC_STACK8, m_stack8);
	DDX_Control(pDX, IDC_STACK7, m_stack7);
	DDX_Control(pDX, IDC_STACK6, m_stack6);
	DDX_Control(pDX, IDC_STACK5, m_stack5);
	DDX_Control(pDX, IDC_STACK4, m_stack4);
	DDX_Control(pDX, IDC_STACK3, m_stack3);
	DDX_Control(pDX, IDC_STACK2, m_stack2);
	DDX_Control(pDX, IDC_STACK1, m_stack1);
	DDX_Control(pDX, IDC_PRIZE9, m_prize9);
	DDX_Control(pDX, IDC_PRIZE8, m_prize8);
	DDX_Control(pDX, IDC_PRIZE7, m_prize7);
	DDX_Control(pDX, IDC_PRIZE6, m_prize6);
	DDX_Control(pDX, IDC_PRIZE5, m_prize5);
	DDX_Control(pDX, IDC_PRIZE4, m_prize4);
	DDX_Control(pDX, IDC_PRIZE3, m_prize3);
	DDX_Control(pDX, IDC_PRIZE2, m_prize2);
	DDX_Control(pDX, IDC_PRIZE1, m_prize1);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CICMModDlg, CDialog)
	//{{AFX_MSG_MAP(CICMModDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CALCULATE, OnCalculate)
	ON_BN_CLICKED(IDC_SRV_LARGEST, OnStealRaises)
	ON_BN_CLICKED(IDC_BIND_DEFENSE, OnBindDefense)
	ON_BN_CLICKED(IDC_SRV_LARGEST, OnSrvLargest)
	ON_BN_CLICKED(IDC_SRV_SMALLIST, OnSrvSmallist)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CICMModDlg message handlers

BOOL CICMModDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CICMModDlg::OnPaint() 
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
HCURSOR CICMModDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CICMModDlg::OnCalculate() 
{
	// TODO: Add your control notification handler code here
	GetControlData();
	
	int iStack1Min = *(m_stackSizes.begin());

	CStackSizes stackSizes =  m_stackSizes;
 	CTournamentEquity caclulator;
	CStackSizeEVTAble stackSizeEVTable;
	
	*(stackSizes.begin())  = iStack1Min;
	stackSizes.DUMP();

	caclulator.CalculateEquity(m_stackSizes, m_prizes);
	stackSizeEVTable.AddStackEVPair(iStack1Min, *(caclulator.begin()));
	stackSizeEVTable.DUMP();
	populateEquityStatics(caclulator);

}

void CICMModDlg::populateEquityStatics(CTournamentEquity& results)
{
	CString strText;
	strText.Format("%f", results[0]);
	m_Equity1.SetWindowText(strText);
	strText.Format("%f", results[1]);
	m_Equity2.SetWindowText(strText);
	strText.Format("%f", results[2]);
	m_Equity3.SetWindowText(strText);
	strText.Format("%f", results[3]);
	m_Equity4.SetWindowText(strText);
	strText.Format("%f", results[4]);
	m_Equity5.SetWindowText(strText);
	strText.Format("%f", results[5]);
	m_Equity6.SetWindowText(strText);
	strText.Format("%f", results[6]);
	m_Equity7.SetWindowText(strText);
	strText.Format("%f", results[7]);
	m_Equity8.SetWindowText(strText);
	strText.Format("%f", results[8]);
	m_Equity9.SetWindowText(strText);
	OnPaint();
}



void CICMModDlg::OnStealRaises() 
{
	// TODO: Add your control notification handler code here
	GetControlData();
	
	CStealRaises stealRaises;
	stealRaises.SetBlindsAntes(m_iBlindsAntes);
	stealRaises.SetPrizes(m_prizes);
	int iStack1Min = *(m_stackSizes.begin());
	stealRaises.SetStack1Min(iStack1Min);	
	stealRaises.SetStack1Max(m_iStack1Max);
	stealRaises.SetStack1Step(m_iStack1Step);
	stealRaises.SetStackSizes(m_stackSizes);
	//stealRaises.GenerateVrsNoOne();
	stealRaises.GenerateVrsLargest(*this);
}

void CICMModDlg::OnBindDefense() 
{
	// TODO: Add your control notification handler code here
	
}


void CICMModDlg::GetPrizes()
{
	CString strTempPrize;
	m_prizes.clear();
	m_prize1.GetWindowText(strTempPrize);
	m_prizes.push_back(atoi(strTempPrize));
	m_prize2.GetWindowText(strTempPrize);
	m_prizes.push_back(atoi(strTempPrize));
	m_prize3.GetWindowText(strTempPrize);
	m_prizes.push_back(atoi(strTempPrize));
	m_prize4.GetWindowText(strTempPrize);
	m_prizes.push_back(atoi(strTempPrize));
	m_prize5.GetWindowText(strTempPrize);
	m_prizes.push_back(atoi(strTempPrize));
	m_prize6.GetWindowText(strTempPrize);
	m_prizes.push_back(atoi(strTempPrize));
	m_prize7.GetWindowText(strTempPrize);
	m_prizes.push_back(atoi(strTempPrize));
	m_prize8.GetWindowText(strTempPrize);
	m_prizes.push_back(atoi(strTempPrize));
	m_prize9.GetWindowText(strTempPrize);
	m_prizes.push_back(atoi(strTempPrize));
	m_prizes.DUMP();
}

void CICMModDlg::GetStackSizes()
{
	m_stackSizes.clear();
	CString strTempStacks;
	int iTempStack;
	m_stackSizes.clear();

	m_stack1.GetWindowText(strTempStacks);
	iTempStack = atoi(strTempStacks);
	if (0 == iTempStack) return;
	m_stackSizes.push_back(iTempStack);

	m_stack2.GetWindowText(strTempStacks);
	iTempStack = atoi(strTempStacks);
	if (0 == iTempStack) return;
	m_stackSizes.push_back(iTempStack);

	m_stack3.GetWindowText(strTempStacks);
	iTempStack = atoi(strTempStacks);
	if (0 == iTempStack) return;
	m_stackSizes.push_back(iTempStack);

	m_stack4.GetWindowText(strTempStacks);
	iTempStack = atoi(strTempStacks);
	if (0 == iTempStack) return;
	m_stackSizes.push_back(iTempStack);


	m_stack5.GetWindowText(strTempStacks);
	iTempStack = atoi(strTempStacks);
	if (0 == iTempStack) return;
	m_stackSizes.push_back(iTempStack);


	m_stack6.GetWindowText(strTempStacks);
	iTempStack = atoi(strTempStacks);
	if (0 == iTempStack) return;
	m_stackSizes.push_back(iTempStack);


	m_stack7.GetWindowText(strTempStacks);
	iTempStack = atoi(strTempStacks);
	if (0 == iTempStack) return;
	m_stackSizes.push_back(iTempStack);


	m_stack8.GetWindowText(strTempStacks);
	iTempStack = atoi(strTempStacks);
	if (0 == iTempStack) return;
	m_stackSizes.push_back(iTempStack);


	m_stack9.GetWindowText(strTempStacks);
	iTempStack = atoi(strTempStacks);
	if (0 == iTempStack) return;
	m_stackSizes.push_back(iTempStack);
}


void CICMModDlg::GetControlData()
{
	GetStackSizes();
	m_stackSizes.DUMP();
	GetPrizes();

	CString strTemp;
	m_ctrlStack1Step.GetWindowText(strTemp);
	m_iStack1Step = atoi(strTemp);

	m_ctrlStack1Max.GetWindowText(strTemp);
	m_iStack1Max = atoi(strTemp);

	m_ctrlBlindsAntes.GetWindowText(strTemp);
	m_iBlindsAntes = atoi(strTemp);
}





void CICMModDlg::OnSrvLargest() 
{
	// TODO: Add your control notification handler code here
	GetControlData();
	CStealRaises stealRaises;
	stealRaises.SetBlindsAntes(m_iBlindsAntes);
	stealRaises.SetPrizes(m_prizes);
	int iStack1Min = *(m_stackSizes.begin());
	stealRaises.SetStack1Min(iStack1Min);	
	stealRaises.SetStack1Max(m_iStack1Max);
	stealRaises.SetStack1Step(m_iStack1Step);
	stealRaises.SetStackSizes(m_stackSizes);
	stealRaises.GenerateVrsLargest(*this);
}

void CICMModDlg::OnSrvSmallist() 
{
	// TODO: Add your control notification handler code here
	GetControlData();
	CStealRaises stealRaises;
	stealRaises.SetBlindsAntes(m_iBlindsAntes);
	stealRaises.SetPrizes(m_prizes);
	int iStack1Min = *(m_stackSizes.begin());
	stealRaises.SetStack1Min(iStack1Min);	
	stealRaises.SetStack1Max(m_iStack1Max);
	stealRaises.SetStack1Step(m_iStack1Step);
	stealRaises.SetStackSizes(m_stackSizes);
	stealRaises.GenerateVrsSmallist();
}
