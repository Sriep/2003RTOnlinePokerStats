// DlgProxy.h : header file
//

#if !defined(AFX_DLGPROXY_H__352F08DD_D3FC_4587_B1CB_BD2EECE160D3__INCLUDED_)
#define AFX_DLGPROXY_H__352F08DD_D3FC_4587_B1CB_BD2EECE160D3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class COpeningCalculatorDlg;

/////////////////////////////////////////////////////////////////////////////
// COpeningCalculatorDlgAutoProxy command target

class COpeningCalculatorDlgAutoProxy : public CCmdTarget
{
	DECLARE_DYNCREATE(COpeningCalculatorDlgAutoProxy)

	COpeningCalculatorDlgAutoProxy();           // protected constructor used by dynamic creation

// Attributes
public:
	COpeningCalculatorDlg* m_pDialog;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COpeningCalculatorDlgAutoProxy)
	public:
	virtual void OnFinalRelease();
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~COpeningCalculatorDlgAutoProxy();

	// Generated message map functions
	//{{AFX_MSG(COpeningCalculatorDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
	DECLARE_OLECREATE(COpeningCalculatorDlgAutoProxy)

	// Generated OLE dispatch map functions
	//{{AFX_DISPATCH(COpeningCalculatorDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGPROXY_H__352F08DD_D3FC_4587_B1CB_BD2EECE160D3__INCLUDED_)
