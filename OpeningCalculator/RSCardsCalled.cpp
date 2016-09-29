// RSCardsCalled.cpp : implementation file
//

#include "stdafx.h"
#include "OpeningCalculator.h"
#include "RSCardsCalled.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// RSCardsCalled

IMPLEMENT_DYNAMIC(RSCardsCalled, CRecordset)

RSCardsCalled::RSCardsCalled(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(RSCardsCalled)
	m_First_Card_Rank = 0;
	m_First_Card_Suit = 0;
	m_Second_Card_Rank = 0;
	m_Second_Card_Suit = 0;
	m_nFields = 4;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString RSCardsCalled::GetDefaultConnect()
{
	return _T("ODBC;DSN=PokerData");
}

CString RSCardsCalled::GetDefaultSQL()
{
	return _T("[dbo].[Individual Results]");
}

void RSCardsCalled::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(RSCardsCalled)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Byte(pFX, _T("[First Card Rank]"), m_First_Card_Rank);
	RFX_Byte(pFX, _T("[First Card Suit]"), m_First_Card_Suit);
	RFX_Byte(pFX, _T("[Second Card Rank]"), m_Second_Card_Rank);
	RFX_Byte(pFX, _T("[Second Card Suit]"), m_Second_Card_Suit);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// RSCardsCalled diagnostics

#ifdef _DEBUG
void RSCardsCalled::AssertValid() const
{
	CRecordset::AssertValid();
}

void RSCardsCalled::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
