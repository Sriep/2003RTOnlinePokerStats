#if !defined(AFX_CURENCYCOMBO_H__986CDE7E_E450_4E18_8AC4_EAC9A4BAC97F__INCLUDED_)
#define AFX_CURENCYCOMBO_H__986CDE7E_E450_4E18_8AC4_EAC9A4BAC97F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CurencyCombo.h : header file
//
#define MAX_NUMBER_OF_CURRENCIES 40
/////////////////////////////////////////////////////////////////////////////
// CCurencyCombo window

class CCurencyCombo : public CComboBox
{
// Construction
public:
	CCurencyCombo();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCurencyCombo)
	//}}AFX_VIRTUAL

// Implementation
public:
	void Populate();
	long GetCurrencyCode() const;
	CString GetCurrencySymbol() const;
	bool SetFromCurrencyCode(long lCurrencyCode);
	virtual ~CCurencyCombo(); 
	CString GetCurrencyChar();

	// Generated message map functions
protected:
	//{{AFX_MSG(CCurencyCombo)
	afx_msg void OnDropdown();
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
private:
	long m_lCurrencyId [MAX_NUMBER_OF_CURRENCIES];
	CString m_strSymbol[MAX_NUMBER_OF_CURRENCIES];
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CURENCYCOMBO_H__986CDE7E_E450_4E18_8AC4_EAC9A4BAC97F__INCLUDED_)
