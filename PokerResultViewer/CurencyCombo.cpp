// CurencyCombo.cpp : implementation file
//

#include "stdafx.h"
#include "CurencyCombo.h"
#include "RSCurrency.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCurencyCombo

CCurencyCombo::CCurencyCombo()
{
}

CCurencyCombo::~CCurencyCombo()
{
}


BEGIN_MESSAGE_MAP(CCurencyCombo, CComboBox)
	//{{AFX_MSG_MAP(CCurencyCombo)
	ON_CONTROL_REFLECT(CBN_DROPDOWN, OnDropdown)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCurencyCombo message handlers

void CCurencyCombo::OnDropdown() 
{
	// TODO: Add your control notification handler code here
	
	if (GetCount() == 0)
	{
		Populate();
	}
}

void CCurencyCombo::Populate()
{
	int iIndex = 0;
	ResetContent();
	RSCurrency rs;
	if (!rs.Open(CRecordset::snapshot, NULL, CRecordset::readOnly))
	{
		return;
	}
	try
	{
		while (!rs.IsEOF())
		{
			InsertString(iIndex, rs.m_CurrencyName);
			m_lCurrencyId [iIndex] = rs.m_Currency_Code;
			m_strSymbol[iIndex] = rs.m_Symbol;
			iIndex++;
			rs.MoveNext();
		}
		rs.Close();
	}
	catch (...)
	{
		rs.Close();
	}
}

CString CCurencyCombo::GetCurrencySymbol() const 
{
	return m_strSymbol[GetCurSel()];
}

CString CCurencyCombo::GetCurrencyChar()
{
	if (m_strSymbol[GetCurSel()] == "USD")
	{
		return CString("$");
	}
	else  if (m_strSymbol[GetCurSel()] == "UKP")
	{
		 return CString("£");
	}
	else  if (m_strSymbol[GetCurSel()] == "EUR")
	{
		 return CString("€");
	}
	else return m_strSymbol[GetCurSel()];

}

long CCurencyCombo::GetCurrencyCode()  const
{
	return m_lCurrencyId[GetCurSel()];
}

bool CCurencyCombo::SetFromCurrencyCode(long lCurrencyCode)
{
	OnDropdown();
	for ( int iIndex = 0 ; iIndex < GetCount() ; iIndex++ )
	{
		if (m_lCurrencyId[iIndex] == lCurrencyCode)
		{
			return CB_ERR != SetCurSel(iIndex);
		}
	}
	return false;
}
