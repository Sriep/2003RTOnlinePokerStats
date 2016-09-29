// BettingFormatsCombo.cpp : implementation file
//

#include "stdafx.h"
#include "BettingFormatsCombo.h"
#include "RSBettingFormats.h"
#include "GameSizeCombo.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBettingFormatsCombo

CBettingFormatsCombo::CBettingFormatsCombo()
{
}

CBettingFormatsCombo::~CBettingFormatsCombo()
{
}


BEGIN_MESSAGE_MAP(CBettingFormatsCombo, CComboBox)
	//{{AFX_MSG_MAP(CBettingFormatsCombo)
	ON_CONTROL_REFLECT(CBN_DROPDOWN, OnDropdown)
	ON_CONTROL_REFLECT(CBN_SELCHANGE, OnSelchange)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBettingFormatsCombo message handlers

void CBettingFormatsCombo::OnDropdown() 
{
	// TODO: Add your control notification handler code here
	if (GetCount() == 0)
	{
		Populate();
	}
}

void CBettingFormatsCombo::SetDependantCombo(CGameSizeCombo* pctlGameSize)
{
   m_pctlGameSizeCombo =  pctlGameSize;
}

void CBettingFormatsCombo::OnSelchange() 
{
	// TODO: Add your control notification handler code here  
}

long CBettingFormatsCombo::GetBettingFormatId()
{
	return lBettingFormatId[GetCurSel()];
}

void CBettingFormatsCombo::Populate()
{
	int iIndex = 0;
	ResetContent();
	RSBettingFormats rs;
	if (!rs.Open(CRecordset::snapshot, NULL, CRecordset::readOnly))
	{
		return;
	}
	try
	{
		while (!rs.IsEOF())
		{
			InsertString(iIndex, rs.m_BettingFormat);
			lBettingFormatId[iIndex] = rs.m_BettingFormatID;
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

CString CBettingFormatsCombo::GetText()
{
	CString strText;
	GetWindowText(strText);
	return strText;
}
