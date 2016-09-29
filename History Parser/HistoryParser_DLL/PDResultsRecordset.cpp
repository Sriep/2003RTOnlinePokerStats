// PDResultsRecordset.cpp : implementation file
//

#include "stdafx.h"
#include "PDResultsRecordset.h"
#include "PPokerSite.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPDResultsRecordset

IMPLEMENT_DYNAMIC(CPDResultsRecordset, CRecordset)

CPDResultsRecordset::CPDResultsRecordset(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CPDResultsRecordset)
	m_Individual_Results_Id = 0;
	m_Hand_Id = 0;
	m_Player_Id = 0;
	m_Position = 0;
	m_Win_loss = 0;
	m_First_Card_Rank = 0;
	m_First_Card_Suit = 0;
	m_Second_Card_Rank = 0;
	m_Second_Card_Suit = 0;
	m_Chips = 0;
	m_nFields = 10;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
	m_iHandIdParam = 0;
	m_iPlayerIdParam = 0;
	m_nParams = 2;
	m_strFilter = "[FK_Hand Id] = ? AND [FK_Player Id] = ?";
}


CString CPDResultsRecordset::GetDefaultConnect()
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

CString CPDResultsRecordset::GetDefaultSQL()
{
	return _T("[dbo].[Individual Results]");
}

void CPDResultsRecordset::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CPDResultsRecordset)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[Individual Results Id]"), m_Individual_Results_Id);
	RFX_Long(pFX, _T("[FK_Hand Id]"), m_Hand_Id);
	RFX_Long(pFX, _T("[FK_Player Id]"), m_Player_Id);
	RFX_Byte(pFX, _T("[Position]"), m_Position);
	RFX_Int(pFX, _T("[Win loss]"), m_Win_loss);
	RFX_Byte(pFX, _T("[First Card Rank]"), m_First_Card_Rank);
	RFX_Byte(pFX, _T("[First Card Suit]"), m_First_Card_Suit);
	RFX_Byte(pFX, _T("[Second Card Rank]"), m_Second_Card_Rank);
	RFX_Byte(pFX, _T("[Second Card Suit]"), m_Second_Card_Suit);
	RFX_Long(pFX, _T("[Chips]"), m_Chips);
	//}}AFX_FIELD_MAP
   	pFX->SetFieldType(CFieldExchange::param); 
	RFX_Long(pFX, _T("[FK_Hand Id]"), m_iHandIdParam);
	RFX_Long(pFX, _T("[FK_Player Id"), m_iPlayerIdParam);
}

/////////////////////////////////////////////////////////////////////////////
// CPDResultsRecordset diagnostics

#ifdef _DEBUG
void CPDResultsRecordset::AssertValid() const
{
	CRecordset::AssertValid();
}

void CPDResultsRecordset::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

long CPDResultsRecordset::GetResultsFor(long lPlayerId, long lHandId)
{
	m_iHandIdParam = lHandId;
	m_iPlayerIdParam = lPlayerId;
	if (IsOpen())
	{
		Requery();
	}
	else
	{
		Open(CRecordset::snapshot);
	}

	if (GetRecordCount() == 1)
	{
		return m_Individual_Results_Id;
	}
	//SetFieldNull(NULL);

	ASSERT(GetRecordCount() == 0);
	AddNew();
	m_Hand_Id = lHandId;
	m_Player_Id = lPlayerId;
	Update();
	Requery();
	ASSERT(GetRecordCount() == 1);
	TRACE2("Created new individual resutls with player id %d and hand id %d\n", lPlayerId, lHandId); 
	return m_Individual_Results_Id;
}
