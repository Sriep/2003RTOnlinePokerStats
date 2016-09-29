// VariantsCombo.cpp : implementation file
//

#include "stdafx.h"
#include "VariantsCombo.h"
#include "RSVariants.h"
#include "GameSizeCombo.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CVariantsCombo

CVariantsCombo::CVariantsCombo()
{
}

CVariantsCombo::~CVariantsCombo()
{
}


BEGIN_MESSAGE_MAP(CVariantsCombo, CComboBox)
	//{{AFX_MSG_MAP(CVariantsCombo)
	ON_CONTROL_REFLECT(CBN_DROPDOWN, OnDropdown)
	ON_CONTROL_REFLECT(CBN_SELCHANGE, OnSelchange)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CVariantsCombo message handlers

void CVariantsCombo::OnDropdown() 
{
	// TODO: Add your control notification handler code here
	if (GetCount() == 0)
	{
		Populate();
	}
}

void CVariantsCombo::SetDependantCombo(CGameSizeCombo* pctlGameSize)
{
   m_pctlGameSizeCombo =  pctlGameSize;
}

void CVariantsCombo::OnSelchange() 
{
	// TODO: Add your control notification handler code here
}

long CVariantsCombo::GetVairiantId()
{
	return lVariatId[GetCurSel()];
}

void CVariantsCombo::Populate()
{
	int iIndex = 0;
	ResetContent();
	RSVariants rs;
	if (!rs.Open(CRecordset::snapshot, NULL, CRecordset::readOnly))
	{
		return;
	}
	while (!rs.IsEOF())
	{
		InsertString(iIndex, rs.m_Name);
		lVariatId[iIndex] = rs.m_Varients_Id;
		iIndex++;
		rs.MoveNext();
	}
	rs.Close();
}

CString CVariantsCombo::GetText()
{
	CString strText;
	GetWindowText(strText);
	return strText;
}
