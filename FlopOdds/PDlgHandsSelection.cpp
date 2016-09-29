// PDlgHandsSelection.cpp : implementation file
//

#include "stdafx.h"
#include "FlopOdds.h"
#include "PDlgHandsSelection.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// PDlgHandsSelection dialog

/*
PDlgHandsSelection::PDlgHandsSelection(CWnd* pParent =NULL)
	: CDialog(PDlgHandsSelection::IDD, pParent)
{
	//{{AFX_DATA_INIT(PDlgHandsSelection)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
} */


PDlgHandsSelection::PDlgHandsSelection(PHandsList& cHandsList, CWnd *pParent)
	: CDialog(PDlgHandsSelection::IDD, pParent)	,
	m_cHandsList(cHandsList)
{
}

void PDlgHandsSelection::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(PDlgHandsSelection)
	DDX_Control(pDX, IDC_HS_PERCENTAGE, m_ctlPercentage);
	DDX_Control(pDX, IDC_HS_NAME, m_ctlName);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(PDlgHandsSelection, CDialog)
	//{{AFX_MSG_MAP(PDlgHandsSelection)
	ON_BN_CLICKED(IDC_HS_SAVE, OnHsSave)
	ON_BN_CLICKED(IDC_DS_READ, OnDsRead)
	ON_CONTROL_RANGE(BN_CLICKED, IDC_HS_CB_AA, IDC_HS_CB_32, OnCheckBoxHit)	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// PDlgHandsSelection message handlers

void PDlgHandsSelection::OnOK() 
{
	// TODO: Add extra validation here
	try
	{
		populateHandsMap(m_cHandsList);
	}
	catch (CString strExcption)
	{
		return;
	}
	CDialog::OnOK();
}

void  PDlgHandsSelection::populateHandsMap(PHandsList& cHandsMap)
{
	cHandsMap.clear();
	for ( int iControlId = IDC_HS_CB_AA ; iControlId <= IDC_HS_CB_32 ; iControlId++ ) 
	{
		CString strHand;
		GetDlgItem(iControlId)->GetWindowText(strHand);
		if (IsDlgButtonChecked(iControlId))
		{
			cHandsMap.pushBackHands(strHand);
		}
	}
}


PHandsList& PDlgHandsSelection::getHandsList()
{
	return m_cHandsList;
}

void PDlgHandsSelection::OnHsSave() 
{
	// TODO: Add your control notification handler code here
	CString strName;
	m_ctlName.GetWindowText(strName);
	m_cHandsList.setTtitle(strName);
	populateHandsMap(m_cHandsList);
	m_cHandsList.DBWrite();
}

void PDlgHandsSelection::OnDsRead() 
{
	// TODO: Add your control notification handler code here
	populateDialog();
}

void PDlgHandsSelection::populateDialog()
{
	uncheckAll();
	m_cHandsList.DBRead();
	for ( HoldemHandIterator iIter = m_cHandsList.begin() ; iIter != m_cHandsList.end() ; ++iIter )
	{
		CString strHand = (*iIter).asString();
		setControlMatching(strHand);
	}
	UpdatePercentage();
	m_ctlName.SetWindowText(m_cHandsList.getTitle());
}

void PDlgHandsSelection::setControlMatching(CString strHand)
{
	for ( int iControlId = IDC_HS_CB_AA ; iControlId <= IDC_HS_CB_32 ; iControlId++ ) 
	{
		CString strWindowText;
		GetDlgItem(iControlId)->GetWindowText(strWindowText);
		if (strWindowText == strHand)
		{
			SendDlgItemMessage(iControlId, BM_SETCHECK,BST_CHECKED);
			return;
		}
	}
}

void PDlgHandsSelection::uncheckAll()
{
	for ( int iControlId = IDC_HS_CB_AA ; iControlId <= IDC_HS_CB_32 ; iControlId++ ) 
	{
		SendDlgItemMessage(iControlId, BM_SETCHECK, BST_UNCHECKED);
	}
	m_cHandsList.clear();
}

void PDlgHandsSelection::OnCheckBoxHit() 
{
	// TODO: Add your control notification handler code here
	CString strName;
	m_ctlName.GetWindowText(strName);
	m_cHandsList.setTtitle(strName);
	populateHandsMap(m_cHandsList);

	UpdatePercentage();

}

void PDlgHandsSelection::UpdatePercentage()
{
	CString strPercentage;
	strPercentage.Format("%i", m_cHandsList.getPercentage());
	strPercentage += "%";
	m_ctlPercentage.SetWindowText(strPercentage);
}

BOOL PDlgHandsSelection::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	populateDialog();

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
