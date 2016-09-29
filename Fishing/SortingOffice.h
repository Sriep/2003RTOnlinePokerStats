#if !defined(AFX_SORTINGOFFICE_H__BC74D1D2_16A4_4E16_BA47_F2A37665EBF9__INCLUDED_)
#define AFX_SORTINGOFFICE_H__BC74D1D2_16A4_4E16_BA47_F2A37665EBF9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SortingOffice.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSortingOffice window
/*
typedef int HOOK_HANDLE;

struct HookWindowPair
{
	HOOK_HANDLE hHandle;
	HWND hwndSpyedOn;
	HWND hwndDestination;
	int iSite;
};*/

class CSortingOffice : public CWnd
{
// Construction
public:
	CSortingOffice();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSortingOffice)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSortingOffice();
	//void AddNewSubscriber(HookWindowPair sSubscriber);

	// Generated message map functions
protected:
	//{{AFX_MSG(CSortingOffice)
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	void SortMail();

	//int m_nTimer;
	//static HookWindowPairList sm_listSubscibers;
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SORTINGOFFICE_H__BC74D1D2_16A4_4E16_BA47_F2A37665EBF9__INCLUDED_)
