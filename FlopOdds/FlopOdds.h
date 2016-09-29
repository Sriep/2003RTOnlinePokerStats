// FlopOdds.h : main header file for the FLOPODDS application
//

#if !defined(AFX_FLOPODDS_H__5F2BE1EE_CEC9_4BF0_A0BB_BEC404851D3F__INCLUDED_)
#define AFX_FLOPODDS_H__5F2BE1EE_CEC9_4BF0_A0BB_BEC404851D3F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CFlopOddsApp:
// See FlopOdds.cpp for the implementation of this class
//

class CFlopOddsApp : public CWinApp
{
public:
	CFlopOddsApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFlopOddsApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CFlopOddsApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FLOPODDS_H__5F2BE1EE_CEC9_4BF0_A0BB_BEC404851D3F__INCLUDED_)
