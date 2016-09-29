// PokerResultViewerDlg.h : header file
//

#if !defined(AFX_POKERRESULTVIEWERDLG_H__20D16B06_3807_44AB_963D_35AF2CB989AE__INCLUDED_)
#define AFX_POKERRESULTVIEWERDLG_H__20D16B06_3807_44AB_963D_35AF2CB989AE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "AddRingGameResultDlg.h"

class CEditRecentResults;

/////////////////////////////////////////////////////////////////////////////
// CPokerResultViewerDlg dialog

class CPokerResultViewerDlg : public CDialog
{
// Construction
public:
	CPokerResultViewerDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CPokerResultViewerDlg)
	enum { IDD = IDD_POKERRESULTVIEWER_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPokerResultViewerDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CPokerResultViewerDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnDestroy();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnView();
	afx_msg void OnResults();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CAddRingGameResultDlg* m_pwndAddRingGameResultDlg;
	CEditRecentResults* m_pwndEditRecentResultsDlg;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_POKERRESULTVIEWERDLG_H__20D16B06_3807_44AB_963D_35AF2CB989AE__INCLUDED_)
