#if !defined(AFX_BETTINGFORMATSCOMBO_H__7CEB2106_8884_4D8C_8C90_3AB54EEEBB98__INCLUDED_)
#define AFX_BETTINGFORMATSCOMBO_H__7CEB2106_8884_4D8C_8C90_3AB54EEEBB98__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// BettingFormatsCombo.h : header file
//
class CGameSizeCombo;
/////////////////////////////////////////////////////////////////////////////
// CBettingFormatsCombo window
#include "ComboCompletion.h"
#define MAX_NUMBER_OF_BETTING_FORMATS  20

class CBettingFormatsCombo : public CComboCompletion
{
// Construction
public:
	CBettingFormatsCombo();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBettingFormatsCombo)
	//}}AFX_VIRTUAL

// Implementation
public:
	CString GetText();
	void Populate();
	long GetBettingFormatId();
	void SetDependantCombo(CGameSizeCombo* pctlGameSize);
	virtual ~CBettingFormatsCombo();

	// Generated message map functions
protected:
	//{{AFX_MSG(CBettingFormatsCombo)
	afx_msg void OnDropdown();
	afx_msg void OnSelchange();
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
private:
	long lBettingFormatId [MAX_NUMBER_OF_BETTING_FORMATS];
	CGameSizeCombo* m_pctlGameSizeCombo;
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BETTINGFORMATSCOMBO_H__7CEB2106_8884_4D8C_8C90_3AB54EEEBB98__INCLUDED_)
