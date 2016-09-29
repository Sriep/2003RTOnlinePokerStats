// OpeningCalculatorDlg.h : header file
//

#if !defined(AFX_OPENINGCALCULATORDLG_H__9D4759C6_6A88_4F41_83E7_CC2F61839B7D__INCLUDED_)
#define AFX_OPENINGCALCULATORDLG_H__9D4759C6_6A88_4F41_83E7_CC2F61839B7D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class COpeningCalculatorDlgAutoProxy;

/////////////////////////////////////////////////////////////////////////////
// COpeningCalculatorDlg dialog

class COpeningCalculatorDlg : public CDialog
{
	DECLARE_DYNAMIC(COpeningCalculatorDlg);
	friend class COpeningCalculatorDlgAutoProxy;

// Construction
public:
	COpeningCalculatorDlg(CWnd* pParent = NULL);	// standard constructor
	virtual ~COpeningCalculatorDlg();

// Dialog Data
	//{{AFX_DATA(COpeningCalculatorDlg)
	enum { IDD = IDD_OPENINGCALCULATOR_DIALOG };
	CEdit	m_NameToCallculate;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COpeningCalculatorDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	COpeningCalculatorDlgAutoProxy* m_pAutoProxy;
	HICON m_hIcon;

	BOOL CanExit();

	// Generated message map functions
	//{{AFX_MSG(COpeningCalculatorDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnClose();
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnBProcess();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OPENINGCALCULATORDLG_H__9D4759C6_6A88_4F41_83E7_CC2F61839B7D__INCLUDED_)
