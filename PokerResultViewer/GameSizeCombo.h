#if !defined(AFX_GAMESIZECOMBO_H__BB54103F_3F8D_4625_86CD_4984EF50022D__INCLUDED_)
#define AFX_GAMESIZECOMBO_H__BB54103F_3F8D_4625_86CD_4984EF50022D__INCLUDED_
#include "ComboCompletion.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// GameSizeCombo.h : header file
//
#define MAX_NUMBER_GAME_SIZES 100
/////////////////////////////////////////////////////////////////////////////
// CGameSizeCombo window

class CGameSizeCombo : public CComboCompletion
{
// Construction
public:
	CGameSizeCombo();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGameSizeCombo)
	//}}AFX_VIRTUAL

// Implementation
public:
	CString GetText();
	void Populate();
	long GetGameSizeId();
	bool SetSelToGameSizeId(long lGameSizeId);
	long GetSmallBlind() const;
	long GetMiddleBlind() const;
	long GetBigBlind() const;
	long GetAnte() const;
	long GetSmallBet() const;
	long GetBigBet() const;
	CString	GetName() const;
	long GetFKCurrency() const;
	virtual ~CGameSizeCombo();

	// Generated message map functions
protected:
	//{{AFX_MSG(CGameSizeCombo)
	afx_msg void OnDropdown();
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()

private:
	long m_lGameSizeID[MAX_NUMBER_GAME_SIZES];
	long m_Small_Blind[MAX_NUMBER_GAME_SIZES];
	long m_Middle_Blind[MAX_NUMBER_GAME_SIZES];
	long m_Big_Blind[MAX_NUMBER_GAME_SIZES];
	long m_Ante[MAX_NUMBER_GAME_SIZES];
	long m_Small_Bet[MAX_NUMBER_GAME_SIZES];
	long m_Big_Bet[MAX_NUMBER_GAME_SIZES];
	CString	m_Name[MAX_NUMBER_GAME_SIZES];
	long m_FK_Currency[MAX_NUMBER_GAME_SIZES];
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GAMESIZECOMBO_H__BB54103F_3F8D_4625_86CD_4984EF50022D__INCLUDED_)
