// NickGridCell.cpp: implementation of the CNickGridCell class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include <afxdb.h>
#include "NickGridComboCell.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

IMPLEMENT_DYNCREATE(CNickGridComboCell, CGridCellCombo)
															   
RSPlayers CNickGridComboCell::sm_rsPlayers [PPokerSite::NUM_OF_POKER_SITES + 1];
CStringArray CNickGridComboCell::sm_aPlayers [PPokerSite::NUM_OF_POKER_SITES + 1];

CNickGridComboCell::CNickGridComboCell()
:	iCurrentSite(0),
	m_strOldText("")
{

}

CNickGridComboCell::~CNickGridComboCell()
{

}

void CNickGridComboCell::EndEdit()
{
	 CGridCellCombo::EndEdit();
}

void CNickGridComboCell::RefrestPlayerList(int iSite)
{
	if (!sm_rsPlayers[iSite].IsOpen())
	{
		sm_rsPlayers[iSite].SetSite(iSite);
		sm_rsPlayers[iSite].Open(CRecordset::snapshot, NULL, CRecordset::useMultiRowFetch);
	}
	else
	{
		if (sm_rsPlayers[iSite].CanRestart())
		{
			sm_rsPlayers[iSite].SetSite(iSite);
			sm_rsPlayers[iSite].Requery();
		}
		else
		{
			sm_rsPlayers[iSite].Close();
			sm_rsPlayers[iSite].SetSite(iSite);
			sm_rsPlayers[iSite].Open(CRecordset::snapshot, NULL, CRecordset::useMultiRowFetch);
		}
	}
	ResetStringArrays(iSite);
}

void CNickGridComboCell::GetPlayerListUpdates()
{
	for	(int iSite = 1 ; iSite < PPokerSite::NUM_OF_POKER_SITES ; iSite ++ )
	{
		try
		{
			if (sm_rsPlayers[iSite].IsOpen())
			{
				sm_rsPlayers[iSite].Close();
			}
			RefrestPlayerList(iSite);
		}
		catch (CDBException* pE)
		{
			TRACE(pE->m_strError);
			TRACE("Getting players for site %s.\n", PPokerSite::GetName(iSite));
		}
	}	
}

void CNickGridComboCell::ResetStringArrays(int iSite)
{
	int iSize = sm_aPlayers[iSite].GetSize();
	sm_aPlayers[iSite].RemoveAll();
	while (!sm_rsPlayers[iSite].IsEOF())
	{
		for ( unsigned int iPos = 0 ; iPos < sm_rsPlayers[iSite].GetRowsFetched() ; iPos++ )
		{
			CString strPlayer = (sm_rsPlayers[iSite].m_pPlayer + iPos*PLAYER_NAME_MAX_LENGTH);
			sm_aPlayers[iSite].Add(strPlayer);
		}
		sm_rsPlayers[iSite].MoveNext();
	}
}

void CNickGridComboCell::SetSite(int iSite)
{
	if (iCurrentSite != iSite)
	{
		iCurrentSite = iSite;
	}
}

BOOL CNickGridComboCell::Edit(int nRow, int nCol, CRect rect, CPoint /* point */, UINT nID, UINT nChar)
{
    m_bEditing = TRUE;
    
    // CInPlaceList auto-deletes itself
    m_pEditWnd = new CInPlaceList(GetGrid(), rect, GetStyle(), nID, nRow, nCol, 
                                  GetTextClr(), GetBackClr(), sm_aPlayers[iCurrentSite], GetText(), nChar);

    return TRUE;
}

CString CNickGridComboCell::GetOldText() const
{
	return m_strOldText;
}

void CNickGridComboCell::SetOldText(const CString& strOldText)
{
	m_strOldText = strOldText; 
}	












