// RSPokerBase.cpp : implementation file
//

#include "stdafx.h"
#include "spyconsul.h"
#include "RSPokerBase.h"
#include "PPokerSite.h"
#include "TableGridRowData.h"
#include "RSCurrentPlayers.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// RSPokerBase

IMPLEMENT_DYNAMIC(RSPokerBase, CRecordset)

RSPokerBase::RSPokerBase(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(RSPokerBase)
	//}}AFX_FIELD_INIT
}

/////////////////////////////////////////////////////////////////////////////
// RSPokerBase diagnostics

#ifdef _DEBUG
void RSPokerBase::AssertValid() const
{
	CRecordset::AssertValid();
}

void RSPokerBase::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

