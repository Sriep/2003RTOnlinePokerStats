// PDHandRecordset.cpp : implementation file
//

#include "stdafx.h"
#include "PDHandRecordset.h"
#include "ParsingException.h"
#include "InputHand.h"
#include "SPDeleteHand.h"
#include "PPokerSite.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPDHandRecordset

IMPLEMENT_DYNAMIC(CPDHandRecordset, CRecordset)

CPDHandRecordset::CPDHandRecordset(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CPDHandRecordset)
	m_Hand_Id = 0;
	m_Small_bet = 0;
	m_Big_bet = 0;
	m_Ante = 0;
	m_Hand_reference = _T("");
	m_Date = CTime::GetCurrentTime();
	m_Variant = 0;
	m_Pot = 0;
	m_Rake = 0;
	m_Flop_card_1_rank = 0;
	m_Flop_card_1_suit = 0;
	m_Flop_card_2_rank = 0;
	m_Flop_card_2_suit = 0;
	m_Flop_card_3_rank = 0;
	m_Flop_card_3_suit = 0;
	m_Turn_rank = 0;
	m_Turn_suit = 0;
	m_River_rank = 0;
	m_River_suit = 0;
	m_Active_Players = 0;
	m_Table_name = _T("");
	m_Incomplete = 0;
	m_nFields = 22;

	m_Jumbled = 0;
	//}}AFX_FIELD_INIT
	m_strHandReferenceParam = _T("");
	m_nDefaultType = snapshot;
	m_nParams = 1;
	m_strFilter = "[Hand reference] = ?";
	m_bParadiseHand = false;
}


CString CPDHandRecordset::GetDefaultConnect()
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

CString CPDHandRecordset::GetDefaultSQL()
{
	return _T("[dbo].[Hands]");
}

void CPDHandRecordset::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CPDHandRecordset)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[Hand Id]"), m_Hand_Id);
	RFX_Long(pFX, _T("[Small bet]"), m_Small_bet);
	RFX_Long(pFX, _T("[Big bet]"), m_Big_bet);
	RFX_Long(pFX, _T("[Ante]"), m_Ante);
	RFX_Text(pFX, _T("[Hand reference]"), m_Hand_reference);
	RFX_Date(pFX, _T("[Date]"), m_Date);   
	RFX_Int(pFX, _T("[Variant]"), m_Variant);
	RFX_Int(pFX, _T("[Pot]"), m_Pot);			   
	RFX_Byte(pFX, _T("[Rake]"), m_Rake);
	RFX_Byte(pFX, _T("[Flop card 1 rank]"), m_Flop_card_1_rank);
	RFX_Byte(pFX, _T("[Flop card 1 suit]"), m_Flop_card_1_suit);
	RFX_Byte(pFX, _T("[Flop card 2 rank]"), m_Flop_card_2_rank);
	RFX_Byte(pFX, _T("[Flop card 2 suit]"), m_Flop_card_2_suit);
	RFX_Byte(pFX, _T("[Flop card 3 rank]"), m_Flop_card_3_rank);
	RFX_Byte(pFX, _T("[Flop card 3 suit]"), m_Flop_card_3_suit);
	RFX_Byte(pFX, _T("[Turn rank]"), m_Turn_rank);
	RFX_Byte(pFX, _T("[Turn suit]"), m_Turn_suit);
	RFX_Byte(pFX, _T("[River rank]"), m_River_rank);	 
	RFX_Byte(pFX, _T("[River suit]"), m_River_suit);
	RFX_Byte(pFX, _T("[Active Players]"), m_Active_Players);
	RFX_Text(pFX, _T("[Table name]"), m_Table_name);
	RFX_Byte(pFX, _T("[Incomplete]"), m_Incomplete);

	if (m_bParadiseHand)
	{
		RFX_Byte(pFX, _T("[Jumbled]"), m_Jumbled);
	}

   	pFX->SetFieldType(CFieldExchange::param); 
	RFX_Text(pFX, _T("[Hand reference]"), m_strHandReferenceParam);

	//}}AFX_FIELD_MAP
}
		   
/////////////////////////////////////////////////////////////////////////////
// CPDHandRecordset diagnostics

#ifdef _DEBUG
void CPDHandRecordset::AssertValid() const
{
	CRecordset::AssertValid();
}

void CPDHandRecordset::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

void CPDHandRecordset::PrepareForEdit(bool bFromLogFile)
{
	CString strHandRef = m_strHandReferenceParam;
	CTime tDate = m_Date;

	if (HandHistoryAlreadyInDatabase(bFromLogFile))
	{
		if (m_Incomplete != 1 || bFromLogFile)
		{
			throw(new CParsingException(IDS_HAND_ALREADY_IN_DB));
		}
		else
		{
			DeleteHandFromdatabase();		
		}
	}
	AddNew();
	m_Hand_reference = strHandRef;
	m_Date = tDate;
	m_Active_Players = 0;
	Update();
	m_strHandReferenceParam = strHandRef;
	Requery();
	ASSERT(GetRecordCount() == 1);
	Edit();
}

bool CPDHandRecordset::HandHistoryAlreadyInDatabase(bool bFromLogFile)
{
	ASSERT(m_strHandReferenceParam != "");
	if (!Open(CRecordset::snapshot))
	{
		ASSERT(FALSE);
		if (m_Incomplete != 1 || bFromLogFile)
		{
			throw(new CParsingException(IDS_HAND_ALREADY_IN_DB));
		}
		else
		{
			DeleteHandFromdatabase();		
		}
	}
	return GetRecordCount() != 0;
}

void CPDHandRecordset::DeleteHandFromdatabase()
{
	Close();
	SPDeleteHand spDeleteHand;
	spDeleteHand.m_strHandReferenceParm = m_Hand_reference;
	spDeleteHand.Open();
	spDeleteHand.Close();
	Open();
}
			  

bool CPDHandRecordset::HasHandBeenRead(const CString& strHandReference, int iSite)
{
	m_strHandReferenceParam = strHandReference;
	ASSERT(m_strHandReferenceParam != "");
	//CString strSQL;
	//strSQL.Format("select [Hand id] from Hands where [Hand reference] = %s", strHandReference);
	//if (!Open(CRecordset::snapshot, strSQL))
	if (!Open(CRecordset::snapshot))
	{
		ASSERT(FALSE);
	}
	bool bRT = GetRecordCount() != 0;
	Close();
	return bRT;
}	

void CPDHandRecordset::AddJumbledGame(const CString &strGameNumber, int iSiteId)
{

	SetParadiseOn();
	if (!Open(CRecordset::snapshot))
	{
		ASSERT(FALSE);
	}
	AddNew();
	m_Hand_reference = strGameNumber;
	m_Jumbled = 1;
	Update();
	Close();
}
