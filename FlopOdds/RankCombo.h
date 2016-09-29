#if !defined(AFX_RANKCOMBO_H__8917E85B_6B3C_40F1_AC88_3B0B5E279442__INCLUDED_)
#define AFX_RANKCOMBO_H__8917E85B_6B3C_40F1_AC88_3B0B5E279442__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RankCombo.h : header file
//
#include "PPokerObject.h"

/////////////////////////////////////////////////////////////////////////////
// CRankCombo window

class CRankCombo : public CComboBox,	 public PPokerObject

{
// Construction
public:
	CRankCombo();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRankCombo)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual PRank getSelectedRank();
	virtual void populate();
	virtual ~CRankCombo();

	// Generated message map functions
protected:
	//{{AFX_MSG(CRankCombo)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RANKCOMBO_H__8917E85B_6B3C_40F1_AC88_3B0B5E279442__INCLUDED_)
