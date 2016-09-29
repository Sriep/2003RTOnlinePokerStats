// History AnalyserDlg.h : header file
//

#if !defined(AFX_HISTORYANALYSERDLG_H__FE4AC6DA_BB4C_48D9_A9FC_B8CA735C4C97__INCLUDED_)
#define AFX_HISTORYANALYSERDLG_H__FE4AC6DA_BB4C_48D9_A9FC_B8CA735C4C97__INCLUDED_

#include "StatsGrid1.h"
#include "resource.h"
#include "TableGridRowData.h"
#include "ActiveTablesCombo.h"

typedef std::list<CHistoryAnalyserDlg*> AnalyserList;
//typedef AnalyserList::iterator AnalyserListIter;
//typedef AnalyserList::const_iterator CAnalyserListIter;

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define NUM_OF_GRIDS 5


#if !defined(AFX_INPUTHAND_H_INCLUDED_)
#define AFX_INPUTHAND_H_INCLUDED_

enum PokerGames
{
	GAME_TEXUS_HOLDEM,
	NUM_OF_POKER_GAMES
};

enum PokerRound
{
	ROUND_PRE_FLOP = 1,
	ROUND_FLOP,
	ROUND_TURN,
	ROUND_RIVER
};
#endif

/////////////////////////////////////////////////////////////////////////////
// CHistoryAnalyserDlg dialog

class CHistoryAnalyserDlg : public CDialog
{
// Construction
public:
	CHistoryAnalyserDlg(CWnd* pParent = NULL);	// standard constructor
	~CHistoryAnalyserDlg();
	CStatsGrid& GetGrid(int iGridNumber);
	int GetPokerSite();

// Dialog Data
	//{{AFX_DATA(CHistoryAnalyserDlg)
	enum { IDD = IDD_HISTORYANALYSER_DIALOG };
	CProgressCtrl	m_ctlProgressRefresh;
	CActiveTablesCombo	m_ctlActiveTables;
	CStatic	m_ctlRefreshingStatus;
	CStatic	m_ctlSawRiver;
	CComboBox	m_ctlPokerSite;
	CStatic	m_ctlVariance;
	CStatic	m_ctlVolPutMoneyPot;
	//}}AFX_DATA
	CStatsGrid	 pStatsGrid [NUM_OF_GRIDS];
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHistoryAnalyserDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
public:
	HWND GetDealerTextWindowHandle();
	bool IsFixed() const;
	RefreshTableInfo(const CTableGridRowData& cTableData);
	void FixTable(const CTableGridRowData& cTabledata);
	void UpdateStatusBar();

protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CHistoryAnalyserDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnRefresh();
	afx_msg void OnClear();
	afx_msg void OnSelchangePokerSite();
	afx_msg void OnSelchangeActiveTables();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	//CTableGridRowData m_TableData;
	StringList m_listPlayers;
	int m_iSite;
	HWND m_hwndDealerWindow;

	bool m_bFixed;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HISTORYANALYSERDLG_H__FE4AC6DA_BB4C_48D9_A9FC_B8CA735C4C97__INCLUDED_)
