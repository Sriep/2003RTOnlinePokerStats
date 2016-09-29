// RSRingGameResults.cpp : implementation file
//

#include "stdafx.h"
#include "PokerResultViewer.h"
#include "RSRingGameResults.h"
#include "PPokerObject.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// RSRingGameResults

IMPLEMENT_DYNAMIC(RSRingGameResults, CRecordset)

RSRingGameResults::RSRingGameResults(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(RSRingGameResults)
	m_ResultID = 0;
	m_FK_RingGames = 0;
	m_Duration = 0;
	m_Date =  GetCurrentTime();
	m_WinLoss = 0;
	m_nFields = 5;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString RSRingGameResults::GetDefaultConnect()
{
	return _T(POKER_RESULTS_CONNECT_STRING);
}

CString RSRingGameResults::GetDefaultSQL()
{
	return _T("[dbo].[RingGameResults]");
}

void RSRingGameResults::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(RSRingGameResults)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[ResultID]"), m_ResultID);
	RFX_Long(pFX, _T("[FK_RingGames]"), m_FK_RingGames);
	RFX_Date(pFX, _T("[Date]"), m_Date);
	RFX_Long(pFX, _T("[Duration]"), m_Duration);
	RFX_Long(pFX, _T("[WinLoss]"), m_WinLoss);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// RSRingGameResults diagnostics

#ifdef _DEBUG
void RSRingGameResults::AssertValid() const
{
	CRecordset::AssertValid();
}

void RSRingGameResults::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
