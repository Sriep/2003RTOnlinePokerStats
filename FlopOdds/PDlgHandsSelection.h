#if !defined(AFX_PDLGHANDSSELECTION_H__E7DC5F4A_2E2A_4573_9499_43298658B8E6__INCLUDED_)
#define AFX_PDLGHANDSSELECTION_H__E7DC5F4A_2E2A_4573_9499_43298658B8E6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PDlgHandsSelection.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// PDlgHandsSelection dialog
#include "HandsMap.h"

class PDlgHandsSelection : public CDialog
{
// Construction
public:
	virtual void UpdatePercentage();
	void uncheckAll();
	void setControlMatching(CString strHand);
	virtual PHandsList& getHandsList();
	PDlgHandsSelection(PHandsList& cHandsMap, CWnd* pParent = NULL);
	//PDlgHandsSelection(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(PDlgHandsSelection)
	enum { IDD = IDD_HAND_SELECTION };
	CStatic	m_ctlPercentage;
	CEdit	m_ctlName;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(PDlgHandsSelection)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(PDlgHandsSelection)
	virtual void OnOK();
	afx_msg void OnHsSave();
	afx_msg void OnDsRead();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG

	afx_msg void OnCheckBoxHit();
	DECLARE_MESSAGE_MAP()

private:
	virtual void populateDialog();
	PHandsList& m_cHandsList;
	void  populateHandsMap(PHandsList& cHandsList);

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PDLGHANDSSELECTION_H__E7DC5F4A_2E2A_4573_9499_43298658B8E6__INCLUDED_)
