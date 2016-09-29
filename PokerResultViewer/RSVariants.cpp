// RSVariants.cpp : implementation file
//

#include "stdafx.h"
#include "PokerResultViewer.h"
#include "RSVariants.h"
#include "PPokerObject.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// RSVariants

IMPLEMENT_DYNAMIC(RSVariants, CRecordset)

RSVariants::RSVariants(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(RSVariants)
	m_Varients_Id = 0;
	m_Name = _T("");
	m_Description = _T("");
	m_nFields = 3;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString RSVariants::GetDefaultConnect()
{
	return _T(POKER_RESULTS_CONNECT_STRING);
}

CString RSVariants::GetDefaultSQL()
{
	return _T("[dbo].[Varients]");
}

void RSVariants::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(RSVariants)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[Varients Id]"), m_Varients_Id);
	RFX_Text(pFX, _T("[Name]"), m_Name);
	RFX_Text(pFX, _T("[Description]"), m_Description);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// RSVariants diagnostics

#ifdef _DEBUG
void RSVariants::AssertValid() const
{
	CRecordset::AssertValid();
}

void RSVariants::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
