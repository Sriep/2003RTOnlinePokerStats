// SPDeleteHand.cpp : implementation file
//

#include "stdafx.h"
#include "HistoryParser_DLL.h"
#include "SPDeleteHand.h"
#include "PPokerSite.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// SPDeleteHand

IMPLEMENT_DYNAMIC(SPDeleteHand, CRecordset)

SPDeleteHand::SPDeleteHand(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(SPDeleteHand)
	m_nFields = 0;
	//}}AFX_FIELD_INIT
	m_nParams = 1;
	m_strHandReferenceParm = _T("");
	m_nDefaultType = snapshot;
}


CString SPDeleteHand::GetDefaultConnect()
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

CString SPDeleteHand::GetDefaultSQL()
{
	return _T("{Call sp_delete_hand (?)}");
}

void SPDeleteHand::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(SPDeleteHand)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	//}}AFX_FIELD_MAP
   	pFX->SetFieldType(CFieldExchange::param);
	RFX_Text(pFX, _T("[HandReference]"), m_strHandReferenceParm);
}

/////////////////////////////////////////////////////////////////////////////
// SPDeleteHand diagnostics

#ifdef _DEBUG
void SPDeleteHand::AssertValid() const
{
	CRecordset::AssertValid();
}

void SPDeleteHand::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
