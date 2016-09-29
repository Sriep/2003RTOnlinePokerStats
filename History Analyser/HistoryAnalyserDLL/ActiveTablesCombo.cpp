// ActiveTablesCombo.cpp : implementation file
//

#include "stdafx.h"
#include "historyanalyserdll.h"
#include "ActiveTablesCombo.h"
#include "RSCurrentTables.h"
#include "RSSelectAllCurrentTables.h"
#include "RSCurrentPlayers.h"
#include "PPokerSite.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CActiveTablesCombo

CActiveTablesCombo::CActiveTablesCombo()
{
}

CActiveTablesCombo::~CActiveTablesCombo()
{
}


BEGIN_MESSAGE_MAP(CActiveTablesCombo, CComboBox)
	//{{AFX_MSG_MAP(CActiveTablesCombo)
	ON_CONTROL_REFLECT(CBN_DROPDOWN, OnDropdown)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CActiveTablesCombo message handlers




void CActiveTablesCombo::OnDropdown() 
{
	// TODO: Add your control notification handler code here
	ResetContent();
	int iIndex = 0;

	RSSelectAllCurrentTables rsActiveTables;
	if (!rsActiveTables.Open(CRecordset::snapshot, NULL, CRecordset::readOnly))
	{
		return;
	}
	while (!rsActiveTables.IsEOF())
	{
		InsertString(iIndex, rsActiveTables.m_TableName);
		m_lDealerWindow[iIndex] = (HWND) rsActiveTables.m_DealerWindow;
		m_iSiteId[iIndex] = rsActiveTables.m_Site;
		m_strTableName[iIndex] = rsActiveTables.m_TableName;
		iIndex++;
		rsActiveTables.MoveNext();
	}
	rsActiveTables.Close();
} 

StringList CActiveTablesCombo::GetListOfPlayers() 
{	 
	if (GetCurSel()  >= 0)
	{
		RSCurrentPlayers rsActivePlayers;
		return rsActivePlayers.GetPlayerList(GetDealerTextWindow(), GetSite(), GetTableName());
	}
	else
	{
		StringList listEmpty;
		return listEmpty;
	}
}

int CActiveTablesCombo::GetSite() const
{
	if (GetCurSel()  >= 0)
	{
		return m_iSiteId[GetCurSel()];
	}
	else
	{
		return PPokerSite::POKER_SITE_NONE;
	}
}

HWND CActiveTablesCombo::GetDealerTextWindow() const
{
	if (GetCurSel()  >= 0)
	{
		return m_lDealerWindow[GetCurSel()];
	}
	else
	{
		return NULL;
	}
}						  

CString CActiveTablesCombo::GetTableName()
{
	if (GetCurSel()  >= 0)
	{
		return m_strTableName[GetCurSel()];
	}
	else
	{
		return CString("");
	}
}
