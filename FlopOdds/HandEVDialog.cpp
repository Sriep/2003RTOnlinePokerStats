// HandEVDialog.cpp : implementation file
//

#include "stdafx.h"
#include "HandEVDialog.h"
#include "PCalculateStartEVs.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHandEVDialog dialog


CHandEVDialog::CHandEVDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CHandEVDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CHandEVDialog)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CHandEVDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CHandEVDialog)
	DDX_Control(pDX, IDC_NUM_TESTS, m_numberTests);
	DDX_Control(pDX, IDC_EVALC_PROGRESS, m_ProgressCtrl);
	//}}AFX_DATA_MAP
	DDX_GridControl(pDX, IDC_HANDSEL_0, m_ctlSpradListsGrid[0]);
	DDX_GridControl(pDX, IDC_HANDSEL_1, m_ctlSpradListsGrid[1]);
	DDX_GridControl(pDX, IDC_HANDSEL_2, m_ctlSpradListsGrid[2]);
	DDX_GridControl(pDX, IDC_HANDSEL_3, m_ctlSpradListsGrid[3]);
	DDX_GridControl(pDX, IDC_HANDSEL_4, m_ctlSpradListsGrid[4]);
	DDX_GridControl(pDX, IDC_HANDSEL_5, m_ctlSpradListsGrid[5]);
	DDX_GridControl(pDX, IDC_HANDSEL_6, m_ctlSpradListsGrid[6]);
	DDX_GridControl(pDX, IDC_HANDSEL_7, m_ctlSpradListsGrid[7]);
	DDX_GridControl(pDX, IDC_HANDSEL_8, m_ctlSpradListsGrid[8]);
}


BEGIN_MESSAGE_MAP(CHandEVDialog, CDialog)
	//{{AFX_MSG_MAP(CHandEVDialog)
	ON_BN_CLICKED(ID_EVALUATE, OnEvaluate)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHandEVDialog message handlers

BOOL CHandEVDialog::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here

   for ( int iGrid = 0 ; iGrid < 9 ; iGrid++ )
   //for ( int iGrid = 0 ; iGrid < 1 ; iGrid++ )
   {							   
		m_ctlSpradListsGrid[iGrid].setup(&m_cHandsList[iGrid]);
		//m_ctlSpradListsGrid[iGrid].setup(m_handsListArray(iGrid));
   }
   m_numberTests.SetWindowText("10000");
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CHandEVDialog::OnEvaluate() 
{																														   
	// TODO: Add your control notification handler code here
    m_handsListArray.Set(m_cHandsList);

	UpdateWindow();
	PCalculateStartEVs cModel;
	cModel.calculateEVs(m_handsListArray, *this, GetNumberOfTests());

}


long CHandEVDialog::GetNumberOfTests()
{
	CString strNumberTests;
	m_numberTests.GetWindowText(strNumberTests);
	return atoi(strNumberTests);
}
