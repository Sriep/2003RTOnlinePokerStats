// FlopOddsDlg.h : header file
//
//{{AFX_INCLUDES()
#include "PFlopOddsGrid.h"
//}}AFX_INCLUDES

#if !defined(AFX_FLOPODDSDLG_H__06E28C07_C63F_4492_967D_16DED81BD9B3__INCLUDED_)
#define AFX_FLOPODDSDLG_H__06E28C07_C63F_4492_967D_16DED81BD9B3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CFlopOddsDlg dialog
#include "SuitCombo.h"
#include "RankCombo.h"
#include "HandsMap.h"	// Added by ClassView
#include "PDBSpradList.h"

class CFlopOddsDlg : public CDialog
{
// Construction
public:
	CFlopOddsDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CFlopOddsDlg)
	enum { IDD = IDD_FLOPODDS_DIALOG };
	CSuitCombo	m_ctlFlop3Suit;
	CSuitCombo	m_ctlFlop2Suit;
	CSuitCombo	m_ctlFlop1Suit;
	CRankCombo	m_ctlFlop3Rank;
	CRankCombo	m_ctlFlop2Rank;
	CRankCombo	m_ctlFlop1Rank;
	PFlopOddsGrid m_ctlResultsGrid;
	PDBSpradListGrid m_ctlSpradListsGrid;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFlopOddsDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CFlopOddsDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBHandsSelector();
	virtual void OnOK();
	afx_msg void OnFoBCalculate();
	afx_msg void OnToHandEVDlg();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	PHandsList m_cHandsList;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FLOPODDSDLG_H__06E28C07_C63F_4492_967D_16DED81BD9B3__INCLUDED_)
