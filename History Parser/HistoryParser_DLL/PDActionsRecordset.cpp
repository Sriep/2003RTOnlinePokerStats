// PDActionsRecordset.cpp : implementation file
//

#include "stdafx.h"
#include "PDActionsRecordset.h"
#include "PPokerSite.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPDActionsRecordset

IMPLEMENT_DYNAMIC(CPDActionsRecordset, CRecordset)

CPDActionsRecordset::CPDActionsRecordset(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CPDActionsRecordset)
	m_Action_Id = 0;
	m_Results_Id = 0;
	m_Action = 0;
	m_Amount = 0;
	m_Round = 0;
	m_nFields = 5;
	//}}AFX_FIELD_INIT
	m_nDefaultType = dynaset;

	m_iSiteId = PPokerSite::POKER_SITE_NONE;
}

CPDActionsRecordset::CPDActionsRecordset(int iSiteId, CDatabase* pdb )
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CPDActionsRecordset)
	m_Action_Id = 0;
	m_Results_Id = 0;
	m_Action = 0;
	m_Amount = 0;
	m_Round = 0;
	m_nFields = 5;
	//}}AFX_FIELD_INIT
	m_nDefaultType = dynaset;

	m_iSiteId = iSiteId;
}

void CPDActionsRecordset::SetSite(int iSiteId)
{
	m_iSiteId = iSiteId;
}


CString CPDActionsRecordset::GetDefaultConnect()
{
	if (m_pDatabase)
	{
		return m_pDatabase->GetConnect();
	}
	else
	{
		ASSERT(FALSE);
		return CString(_T(""));
	}
}

CString CPDActionsRecordset::GetDefaultSQL()
{
	return _T("[dbo].[Actions]");
}

void CPDActionsRecordset::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CPDActionsRecordset)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[Action Id]"), m_Action_Id);
	RFX_Long(pFX, _T("[FK_Results Id]"), m_Results_Id);
	RFX_Int(pFX, _T("[Action]"), m_Action);
	RFX_Long(pFX, _T("[Amount]"), m_Amount);
	RFX_Int(pFX, _T("[Round]"), m_Round);
	//}}AFX_FIELD_MAP
}

void CPDActionsRecordset::AddAction(long lResults, int iAction, long iAmount, int iRound)
{
	if (!IsOpen())
	{
		Open(CRecordset::snapshot);
	}

	AddNew();
	m_Results_Id = lResults;
	m_Action = iAction;
	m_Amount = iAmount;
	m_Round = iRound;
	Update();
}

/////////////////////////////////////////////////////////////////////////////
// CPDActionsRecordset diagnostics

#ifdef _DEBUG
void CPDActionsRecordset::AssertValid() const
{
	CRecordset::AssertValid();
}

void CPDActionsRecordset::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
