// RSBettingFormats.cpp : implementation file
//

#include "stdafx.h"
#include "PokerResultViewer.h"
#include "RSBettingFormats.h"
#include "PPokerObject.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// RSBettingFormats

IMPLEMENT_DYNAMIC(RSBettingFormats, CRecordset)

RSBettingFormats::RSBettingFormats(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(RSBettingFormats)
	m_BettingFormatID = 0;
	m_BettingFormat = _T("");
	m_nFields = 2;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString RSBettingFormats::GetDefaultConnect()
{
	return _T(POKER_RESULTS_CONNECT_STRING);
}

CString RSBettingFormats::GetDefaultSQL()
{
	return _T("[dbo].[BettingFormats]");
}

void RSBettingFormats::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(RSBettingFormats)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[BettingFormatID]"), m_BettingFormatID);
	RFX_Text(pFX, _T("[BettingFormat]"), m_BettingFormat);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// RSBettingFormats diagnostics

#ifdef _DEBUG
void RSBettingFormats::AssertValid() const
{
	CRecordset::AssertValid();
}

void RSBettingFormats::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
