#if !defined(AFX_HANDEVDIALOG_H__827BBBE5_77BC_430A_9528_BB39AE46F9AF__INCLUDED_)
#define AFX_HANDEVDIALOG_H__827BBBE5_77BC_430A_9528_BB39AE46F9AF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// HandEVDialog.h : header file
//
#include "resource.h"
#include "PDBSpradList.h"
#include "PHandsListArray.h"

/////////////////////////////////////////////////////////////////////////////
// CHandEVDialog dialog

class CHandEVDialog : public CDialog
{
// Construction
public:
	long GetNumberOfTests();
	CHandEVDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CHandEVDialog)
	enum { IDD = IDD_HAND_EVS };
	CEdit	m_numberTests;
	CProgressCtrl	m_ProgressCtrl;
	//}}AFX_DATA



// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHandEVDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CHandEVDialog)
	virtual BOOL OnInitDialog();
	afx_msg void OnEvaluate();
	//}}AFX_MSG
	PHandsList  m_cHandsList[9];
	PDBSpradListGrid  m_ctlSpradListsGrid[9];
	PHandsListArray m_handsListArray;

	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HANDEVDIALOG_H__827BBBE5_77BC_430A_9528_BB39AE46F9AF__INCLUDED_)
