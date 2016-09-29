// PokerResultViewer.h : main header file for the POKERRESULTVIEWER application
//

#if !defined(AFX_POKERRESULTVIEWER_H__E68044CF_C0FE_45F8_BE37_2479715BE363__INCLUDED_)
#define AFX_POKERRESULTVIEWER_H__E68044CF_C0FE_45F8_BE37_2479715BE363__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CPokerResultViewerApp:
// See PokerResultViewer.cpp for the implementation of this class
//

class CPokerResultViewerApp : public CWinApp
{
public:
	CPokerResultViewerApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPokerResultViewerApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CPokerResultViewerApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_POKERRESULTVIEWER_H__E68044CF_C0FE_45F8_BE37_2479715BE363__INCLUDED_)
