#if !defined(AFX_VARIANTSCOMBO_H__E4616CD5_73A1_46FD_AA29_74BB16955633__INCLUDED_)
#define AFX_VARIANTSCOMBO_H__E4616CD5_73A1_46FD_AA29_74BB16955633__INCLUDED_
#include "ComboCompletion.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// VariantsCombo.h : header file
//
class CGameSizeCombo;
#define MAX_NUMBER_VARIANTS 100

/////////////////////////////////////////////////////////////////////////////
// CVariantsCombo window

class CVariantsCombo : public CComboCompletion
{
// Construction
public:
	CVariantsCombo();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CVariantsCombo)
	//}}AFX_VIRTUAL

// Implementation
public:
	CString GetText();
	void Populate();
	long GetVairiantId();
	void SetDependantCombo(CGameSizeCombo* pctlGameSize);
	virtual ~CVariantsCombo();

	// Generated message map functions
protected:
	//{{AFX_MSG(CVariantsCombo)
	afx_msg void OnDropdown();
	afx_msg void OnSelchange();
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
private:
	long lVariatId[MAX_NUMBER_VARIANTS];
	CGameSizeCombo* m_pctlGameSizeCombo;
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VARIANTSCOMBO_H__E4616CD5_73A1_46FD_AA29_74BB16955633__INCLUDED_)
