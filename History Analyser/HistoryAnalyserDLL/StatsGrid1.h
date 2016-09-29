// StatsGrid1.h: interface for the CStatsGrid1 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_STATSGRID1_H__83138FC8_A28C_42BC_AF4B_55891DAAF281__INCLUDED_)
#define AFX_STATSGRID1_H__83138FC8_A28C_42BC_AF4B_55891DAAF281__INCLUDED_

#include "GridCtrl.h"
#if !defined(LIST_DEFS)
#define	 LIST_DEFS
#include <list>
using std::list;
typedef std::list <CString>::iterator StringListIterator;
typedef std::list <CString>::const_iterator ConstStringListIterator;
typedef std::list <CString> StringList; 
typedef std::list <CString*> CNickPtrList;
typedef std::list <CString*>::iterator CNickPtrListIter;
#endif

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CHistoryAnalyserDlg;

class CStatsGrid : public CGridCtrl  
{
public:
	void UpdatePlayers(const StringList& listPlayers);
	DECLARE_DYNCREATE(CStatsGrid)
	virtual void SetUp(int iGridNumber, CHistoryAnalyserDlg* pdlgParent);
	CStatsGrid();
	virtual ~CStatsGrid();

    virtual void  OnEndEditCell(int nRow, int nCol, CString str);
	void RefreshRow(int row);
	int GetPokerSite();
	void ReplaceRow(const CString& strOld, const CString& strNew);
	void RefreshGrid();
	void ClearGrid();
	void RefreshPlayerCombos(int iSite);

	static int CALLBACK pfnCellStatsGridCompare(LPARAM lParam1, LPARAM lParam2, LPARAM lParamSort);
	static const int NUM_ROWS_IN_GRID;
private:
	void PlaceInFirstEmptyRow(const CString& strPlayer);
	bool ExistingPlayer(const CString& strPlayer);
	void RemovePlayersNotInList(const StringList& listPlayers);
	int m_iPokerSite;
	int m_iGridNumber;
	CHistoryAnalyserDlg* m_pdlgParent;
};

#endif // !defined(AFX_STATSGRID1_H__83138FC8_A28C_42BC_AF4B_55891DAAF281__INCLUDED_)
