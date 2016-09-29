// ICMModDlg.h : header file
//

#if !defined(AFX_ICMMODDLG_H__9A9FA73A_58B7_4870_ADE2_02379FBA5F48__INCLUDED_)
#define AFX_ICMMODDLG_H__9A9FA73A_58B7_4870_ADE2_02379FBA5F48__INCLUDED_

#include "StackSizes.h"	// Added by ClassView
#include "Prizes.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CICMModDlg dialog

#define PAS_FLOAT double

class CTournamentEquity;

class CICMModDlg : public CDialog
{
// Construction
public:
	void GetStackSizes();
	void GetPrizes();
	CICMModDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CICMModDlg)
	enum { IDD = IDD_ICMMOD_DIALOG };
	CStatic	m_Equity9;
	CStatic	m_Equity8;
	CStatic	m_Equity7;
	CStatic	m_Equity6;
	CStatic	m_Equity5;
	CStatic	m_Equity4;
	CStatic	m_Equity3;
	CStatic	m_Equity2;
	CStatic	m_Equity1;
	CProgressCtrl	m_ctrlProgressBar;
	CEdit	m_ctrlStack1Step;
	CEdit	m_ctrlStack1Max;
	CEdit	m_ctrlBlindsAntes;
	CEdit	m_stack9;
	CEdit	m_stack8;
	CEdit	m_stack7;
	CEdit	m_stack6;
	CEdit	m_stack5;
	CEdit	m_stack4;
	CEdit	m_stack3;
	CEdit	m_stack2;
	CEdit	m_stack1;
	CEdit	m_prize9;
	CEdit	m_prize8;
	CEdit	m_prize7;
	CEdit	m_prize6;
	CEdit	m_prize5;
	CEdit	m_prize4;
	CEdit	m_prize3;
	CEdit	m_prize2;
	CEdit	m_prize1;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CICMModDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CICMModDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnCalculate();
	afx_msg void OnStealRaises();
	afx_msg void OnBindDefense();
	afx_msg void OnSrvLargest();
	afx_msg void OnSrvSmallist();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	void populateEquityStatics(CTournamentEquity& results);

	int m_iStack1Max;
	int m_iBlindsAntes;
	int m_iStack1Step;
	void GetControlData();
	CPrizes m_prizes;
	CStackSizes m_stackSizes;

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ICMMODDLG_H__9A9FA73A_58B7_4870_ADE2_02379FBA5F48__INCLUDED_)
