// RSCardsRaised.cpp : implementation file
//

#include "stdafx.h"
#include "OpeningCalculator.h"
#include "RSCardsRaised.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// RSCardsRaised

IMPLEMENT_DYNAMIC(RSCardsRaised, CRecordset)

RSCardsRaised::RSCardsRaised(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(RSCardsRaised)
	m_First_Card_Rank = 0;
	m_First_Card_Suit = 0;
	m_Second_Card_Rank = 0;
	m_Second_Card_Suit = 0;	
	m_Position = 0;
	m_nFields = 5;
	//}}AFX_FIELD_INIT
	m_pFirst_Card_Rank = NULL;
	m_pFirst_Card_Suit = NULL;
	m_pSecond_Card_Rank = NULL;
	m_pSecond_Card_Suit = NULL;
	m_pPosition = NULL;

	//m_nFields = 5;
	m_pFirst_Card_RankLengths = NULL;
	m_pFirst_Card_SuitLengths = NULL;
	m_pSecond_Card_RankLengths = NULL;
	m_pSecond_Card_SuitLengths = NULL;
	m_pPositionLengths = NULL;

	m_nDefaultType = snapshot;
	m_nParams = 4;
	m_strNickParam = _T("");
	m_iHostParam = 0;
	m_iVariant = 0;
	m_tDate = CTime::GetCurrentTime();
}


CString RSCardsRaised::GetDefaultConnect()
{
	return _T("ODBC;DSN=PokerData");
}

CString RSCardsRaised::GetDefaultSQL()
{
	return _T("[dbo].[Individual Results]");
}

void RSCardsRaised::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(RSCardsRaised)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Int(pFX, _T("[First Card Rank]"), m_First_Card_Rank);
	RFX_Int(pFX, _T("[First Card Suit]"), m_First_Card_Suit);
	RFX_Int(pFX, _T("[Second Card Rank]"), m_Second_Card_Rank);
	RFX_Int(pFX, _T("[Second Card Suit]"), m_Second_Card_Suit);
	RFX_Int(pFX, _T("[Position]"), m_Position);
	//}}AFX_FIELD_MAP
   	pFX->SetFieldType(CFieldExchange::param);
	RFX_Text(pFX, _T("[Nick]"), m_strNickParam);
	RFX_Int(pFX, _T("[Host Id]"), m_iHostParam);
	RFX_Int(pFX, _T("[Variant]"), m_iVariant);
	RFX_Date(pFX, _T("[Date]"), m_tDate);   
}

/////////////////////////////////////////////////////////////////////////////
// RSCardsRaised diagnostics

#ifdef _DEBUG
void RSCardsRaised::AssertValid() const
{
	CRecordset::AssertValid();
}

void RSCardsRaised::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

void RSCardsRaised::DoBulkFieldExchange( CFieldExchange* pFX )
{
	// call the Bulk RFX functions
	// for field data members
	pFX->SetFieldType( CFieldExchange::outputColumn );
	RFX_Int_Bulk(pFX, _T("[First Card Rank]"), &m_pFirst_Card_Rank, &m_pFirst_Card_RankLengths);
	RFX_Int_Bulk(pFX, _T("[First Card Suit]"), &m_pFirst_Card_Suit, &m_pFirst_Card_SuitLengths);
	RFX_Int_Bulk(pFX, _T("[Second Card Rank]"), &m_pSecond_Card_Rank, &m_pSecond_Card_RankLengths);
	RFX_Int_Bulk(pFX, _T("[Second Card Suit]"), &m_pSecond_Card_Suit, &m_pSecond_Card_SuitLengths);
	RFX_Int_Bulk(pFX, _T("[Position]"), &m_pPosition, &m_pPositionLengths);

	// call the RFX functions for
	// for parameter data members
	pFX->SetFieldType( CFieldExchange::inputParam );
	RFX_Text(pFX, _T("[Nick]"), m_strNickParam);
	RFX_Int(pFX, _T("[Host Id]"), m_iHostParam);
	RFX_Int(pFX, _T("[Variant]"), m_iVariant);
	RFX_Date(pFX, _T("[Date]"), m_tDate);   
}

