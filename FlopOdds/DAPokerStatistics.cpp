// DAPokerStatistics.cpp : implementation file
//

#include "stdafx.h"
#include "flopodds.h"
#include "DAPokerStatistics.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DAPokerStatistics

IMPLEMENT_DYNAMIC(DAPokerStatistics, CRecordset)

DAPokerStatistics::DAPokerStatistics(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(DAPokerStatistics)
	m_ListId = 0;
	m_Name = _T("");
	m_Card1 = 0;
	m_Card2 = 0;
	m_nFields = 4;
	//}}AFX_FIELD_INIT
	m_nDefaultType = dynaset;
}


CString DAPokerStatistics::GetDefaultConnect()
{
	return _T("ODBC;DSN=PokerStatistics");
}

CString DAPokerStatistics::GetDefaultSQL()
{
	return _T("[HandList]");
}

void DAPokerStatistics::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(DAPokerStatistics)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[ListId]"), m_ListId);
	RFX_Text(pFX, _T("[Name]"), m_Name);
	RFX_Long(pFX, _T("[Card1]"), m_Card1);
	RFX_Long(pFX, _T("[Card2]"), m_Card2);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// DAPokerStatistics diagnostics

#ifdef _DEBUG
void DAPokerStatistics::AssertValid() const
{
	CRecordset::AssertValid();
}

void DAPokerStatistics::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
