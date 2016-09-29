// NickGridCell.h: interface for the CNickGridCell class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_NICKGRIDCOMBOCELL_H___)
#define AFX_NICKGRIDCOMBOCELL_H___

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "GridCellCombo.h"
#include "RSPlayers.h"	 
#include "StatsGrid1.h"
#include "PPokerSite.h"

#define PLAYER_ARRAY_GROW_BY 500

class CNickGridComboCell : public CGridCellCombo  
{
public:
	DECLARE_DYNCREATE(CNickGridComboCell)
	CNickGridComboCell();
	virtual ~CNickGridComboCell();
    virtual void EndEdit();
	void SetSite(int iSite);
	virtual BOOL Edit(int nRow, int nCol, CRect rect, CPoint /* point */, UINT nID, UINT nChar);
	CString GetOldText() const;
	void SetOldText(const CString& strOldText);
	
	static void RefrestPlayerList(int iSite);
	static void GetPlayerListUpdates();
private:
	static void ResetStringArrays(int iSite);

	static RSPlayers sm_rsPlayers [PPokerSite::NUM_OF_POKER_SITES + 1];
	static CStringArray sm_aPlayers[PPokerSite::NUM_OF_POKER_SITES + 1];
	int iCurrentSite;
	CString m_strOldText;
};

#endif // !defined(AFX_NICKGRIDCOMBOCELL_H___)
