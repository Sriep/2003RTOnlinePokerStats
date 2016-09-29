#if !defined(AFX_ADDRINGGAMERESULTDLG_H__10131501_8982_48E3_9494_33B3C83C6EED__INCLUDED_)
#define AFX_ADDRINGGAMERESULTDLG_H__10131501_8982_48E3_9494_33B3C83C6EED__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AddRingGameResultDlg.h : header file
//
#include "GameSizeCombo.h"
#include "CardRoomCombo.h"
#include "BettingFormatsCombo.h"
#include "VariantsCombo.h"
#include "NumericEdit.h"
#include "CurencyCombo.h"

/////////////////////////////////////////////////////////////////////////////
// CAddRingGameResultDlg dialog

class CAddRingGameResultDlg : public CDialog
{
// Construction
public:
	long GetOrMakeRingGameId();
	CAddRingGameResultDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CAddRingGameResultDlg)
	enum { IDD = IDD_ADD_RING_GAME_RESULT };
	CEdit	m_ctlGameSizeName;
	CNumericEdit	m_ctlSmallBet;
	CNumericEdit	m_ctlMiddleBlind;
	CNumericEdit	m_ctlBigBlind;
	CNumericEdit	m_ctlBigBet;
	CNumericEdit	m_ctlAnte;
	CNumericEdit	m_ctlSmallBlind;
	CCurencyCombo	m_comboCurrency;
	CCardRoomCombo	m_comboCardRoom;
	CVariantsCombo	m_comboVariant;
	CGameSizeCombo	m_comboGameSize;
	CBettingFormatsCombo	m_comboBettingFormat;
	CStatic	m_ctlCurrencySymbol;
	CNumericEdit	m_ctlWinLoss;
	CNumericEdit	m_ctlDuration;
	CDateTimeCtrl	m_ctlDateTime;
	CMonthCalCtrl	m_calctlDate;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAddRingGameResultDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	afx_msg void OnBAddnewgamesize();
	// Generated message map functions
	//{{AFX_MSG(CAddRingGameResultDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeCurrency();
	afx_msg void OnSelchangeRgresultGameSize();
	afx_msg void OnAddResults();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADDRINGGAMERESULTDLG_H__10131501_8982_48E3_9494_33B3C83C6EED__INCLUDED_)
