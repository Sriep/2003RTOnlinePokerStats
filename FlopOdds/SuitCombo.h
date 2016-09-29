#if !defined(AFX_SUITCOMBO_H__648D0988_3D6D_46DE_BD0D_CD7927134CA9__INCLUDED_)
#define AFX_SUITCOMBO_H__648D0988_3D6D_46DE_BD0D_CD7927134CA9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SuitCombo.h : header file
//
#include "PPokerObject.h"
/////////////////////////////////////////////////////////////////////////////
// CSuitCombo window

class CSuitCombo : public CComboBox,	public PPokerObject
{
// Construction
public:
	CSuitCombo();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSuitCombo)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual PSuit getSelectedSuit();
	virtual void populate();
	virtual ~CSuitCombo();

	// Generated message map functions
protected:
	//{{AFX_MSG(CSuitCombo)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SUITCOMBO_H__648D0988_3D6D_46DE_BD0D_CD7927134CA9__INCLUDED_)
