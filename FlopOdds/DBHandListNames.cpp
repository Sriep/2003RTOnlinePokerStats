// DBHandListNames.cpp : implementation file
//

#include "stdafx.h"
#include "flopodds.h"
#include "DBHandListNames.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DBHandListNames

IMPLEMENT_DYNAMIC(DBHandListNames, CRecordset)

DBHandListNames::DBHandListNames(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(DBHandListNames)
	m_Name = _T("");
	m_nFields = 1;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString DBHandListNames::GetDefaultConnect()
{
	return _T("ODBC;DSN=PokerStatistics");
}

CString DBHandListNames::GetDefaultSQL()
{
	return _T("[HandList_Names]");
}

void DBHandListNames::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(DBHandListNames)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[Name]"), m_Name);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// DBHandListNames diagnostics

#ifdef _DEBUG
void DBHandListNames::AssertValid() const
{
	CRecordset::AssertValid();
}

void DBHandListNames::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
