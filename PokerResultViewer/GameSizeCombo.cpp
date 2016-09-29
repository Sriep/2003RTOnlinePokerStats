// GameSizeCombo.cpp : implementation file
//

#include "stdafx.h"
#include "PokerResultViewer.h"
#include "GameSizeCombo.h"
#include "RSGameSize.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGameSizeCombo

CGameSizeCombo::CGameSizeCombo()
{
}

CGameSizeCombo::~CGameSizeCombo()
{
}


BEGIN_MESSAGE_MAP(CGameSizeCombo, CComboBox)
	//{{AFX_MSG_MAP(CGameSizeCombo)
	ON_CONTROL_REFLECT(CBN_DROPDOWN, OnDropdown)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGameSizeCombo message handlers

void CGameSizeCombo::OnDropdown() 
{
	// TODO: Add your control notification handler code here
	if (GetCount() == 0)
	{
		Populate();
	}
}

void CGameSizeCombo::Populate() 
{
	int iIndex = 0;
	ResetContent();
	RSGameSize rs;
	rs.m_strFilter = "";
	if (!rs.Open(CRecordset::snapshot, NULL, CRecordset::readOnly))
	{
		return;
	}
	while (!rs.IsEOF())
	{
		InsertString(iIndex, rs.m_Name);
		m_lGameSizeID[iIndex]  = rs.m_Game_Size_Id;
		m_Small_Blind[iIndex]  = rs.m_Small_Blind;
		m_Middle_Blind[iIndex]  = rs.m_Middle_Blind;
		m_Big_Blind[iIndex]  = rs.m_Big_Blind;
		m_Ante[iIndex]  = rs.m_Ante;
		m_Small_Bet[iIndex]  = rs.m_Small_Bet;
		m_Big_Bet[iIndex]  = rs.m_Big_Bet;
		m_Name[iIndex]  = rs.m_Name;
		m_FK_Currency[iIndex]  = rs.m_FK_Currency;
		iIndex++;
		rs.MoveNext();
	}
	rs.Close();
}

long CGameSizeCombo::GetSmallBlind() const
{
	return m_Small_Blind[GetCurSel()];
}

long CGameSizeCombo::GetMiddleBlind() const	 
{
	return m_Middle_Blind[GetCurSel()];
}


long CGameSizeCombo::GetBigBlind() const  
{
	return m_Big_Blind[GetCurSel()];
}


long CGameSizeCombo::GetAnte() const   
{
	return m_Ante[GetCurSel()];
}


long CGameSizeCombo::GetSmallBet() const  
{
	return m_Small_Bet[GetCurSel()];
}

long CGameSizeCombo::GetBigBet() const 
{
	return m_Big_Bet[GetCurSel()];
}

CString	CGameSizeCombo::GetName() const
{
	return (m_Name[GetCurSel()]);
}

long CGameSizeCombo::GetFKCurrency() const
{
	return m_FK_Currency[GetCurSel()];
}

bool CGameSizeCombo::SetSelToGameSizeId(long lGameSizeId)
{
	OnDropdown();
	for ( int iIndex = 0 ; iIndex < GetCount() ; iIndex++ )
	{
		if (m_lGameSizeID[iIndex] == lGameSizeId)
		{
			return CB_ERR != SetCurSel(iIndex);
		}
	}
	return false;
}

long CGameSizeCombo::GetGameSizeId()
{
	return m_lGameSizeID[GetCurSel()];
}

CString CGameSizeCombo::GetText()
{
	CString strText;
	GetWindowText(strText);
	return strText;
}
