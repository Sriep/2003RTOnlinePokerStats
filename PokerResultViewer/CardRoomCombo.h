#if !defined(AFX_CARDROOMCOMBO_H__2560B7D4_BB04_431F_8C6C_63E89E31E648__INCLUDED_)
#define AFX_CARDROOMCOMBO_H__2560B7D4_BB04_431F_8C6C_63E89E31E648__INCLUDED_
#include "ComboCompletion.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CardRoomCombo.h : header file
//

#define MAX_NUMBER_OF_CARD_ROOMS 100
/////////////////////////////////////////////////////////////////////////////
// CCardRoomCombo window

class CCardRoomCombo : public CComboCompletion
{
// Construction
public:
	CCardRoomCombo();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCardRoomCombo)
	//}}AFX_VIRTUAL

// Implementation
public:
	CString GetText();
	void Populate();
	long GetCardRoomId();
	virtual ~CCardRoomCombo();

	// Generated message map functions
protected:
	//{{AFX_MSG(CCardRoomCombo)
	afx_msg void OnDropdown();
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
private:
	long m_lCardRoomID[MAX_NUMBER_OF_CARD_ROOMS];

};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CARDROOMCOMBO_H__2560B7D4_BB04_431F_8C6C_63E89E31E648__INCLUDED_)
