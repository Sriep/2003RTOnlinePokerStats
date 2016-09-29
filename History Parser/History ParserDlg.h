// History ParserDlg.h : header file
//

#if !defined(AFX_HISTORYPARSERDLG_H__444A1628_D89E_42D1_93CC_CE2602C344EA__INCLUDED_)
#define AFX_HISTORYPARSERDLG_H__444A1628_D89E_42D1_93CC_CE2602C344EA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CHistoryParserDlg dialog

class CHistoryParserDlg : public CDialog
{
// Construction
public:
	CHistoryParserDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CHistoryParserDlg)
	enum { IDD = IDD_HISTORYPARSER_DIALOG };
	CEdit	m_ctrlLogFile;
	CProgressCtrl	m_cProgressBar;
	CStatic	m_cParsingStatus;
	CEdit	m_cToParseDirectory;
	CEdit	m_cFromParseDirectory;
	CEdit	m_strFileName;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHistoryParserDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CHistoryParserDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnParse();
	afx_msg void OnParseDirectory();
	afx_msg void OnParseLog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HISTORYPARSERDLG_H__444A1628_D89E_42D1_93CC_CE2602C344EA__INCLUDED_)
