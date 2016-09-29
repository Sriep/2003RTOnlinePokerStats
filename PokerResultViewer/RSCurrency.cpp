// RSCurrency.cpp : implementation file
//

#include "stdafx.h"
#include "PokerResultViewer.h"
#include "RSCurrency.h"
#include "PPokerObject.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// RSCurrency

IMPLEMENT_DYNAMIC(RSCurrency, CRecordset)

RSCurrency::RSCurrency(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(RSCurrency)
	m_Currency_Code = 0;
	m_Exchange_Rate = 0.0;
	m_Symbol = _T("");
	m_CurrencyName = _T("");
	m_nFields = 4;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString RSCurrency::GetDefaultConnect()
{
	return _T(POKER_RESULTS_CONNECT_STRING);
}

CString RSCurrency::GetDefaultSQL()
{
	return _T("[dbo].[Currencies]");
}

void RSCurrency::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(RSCurrency)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[Currency Code]"), m_Currency_Code);
	RFX_Text(pFX, _T("[Symbol]"), m_Symbol);
	RFX_Double(pFX, _T("[Exchange Rate]"), m_Exchange_Rate);  
	RFX_Text(pFX, _T("[Currency Name]"), m_CurrencyName);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// RSCurrency diagnostics

#ifdef _DEBUG
void RSCurrency::AssertValid() const
{
	CRecordset::AssertValid();
}

void RSCurrency::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
