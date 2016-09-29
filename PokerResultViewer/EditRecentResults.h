#if !defined(AFX_EDITRECENTRESULTS_H__F8CCB904_166B_46C7_B415_3252B636EFCC__INCLUDED_)
#define AFX_EDITRECENTRESULTS_H__F8CCB904_166B_46C7_B415_3252B636EFCC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// EditRecentResults.h : header file
//
#include "GridCtrl.h"
/////////////////////////////////////////////////////////////////////////////
// CEditRecentResults dialog

class CEditRecentResults : public CDialog
{
// Construction
public:
	CEditRecentResults(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CEditRecentResults)
	enum { IDD = IDD_EDIT_RESULTS };
	CGridCtrl 	m_gridEditResults;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEditRecentResults)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CEditRecentResults)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EDITRECENTRESULTS_H__F8CCB904_166B_46C7_B415_3252B636EFCC__INCLUDED_)
