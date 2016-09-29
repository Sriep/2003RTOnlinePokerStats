// ICMMod.h : main header file for the ICMMOD application
//

#if !defined(AFX_ICMMOD_H__F74702E5_1BB2_4B41_92C1_ECEF855FA759__INCLUDED_)
#define AFX_ICMMOD_H__F74702E5_1BB2_4B41_92C1_ECEF855FA759__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CICMModApp:
// See ICMMod.cpp for the implementation of this class
//

class CICMModApp : public CWinApp
{
public:
	CICMModApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CICMModApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CICMModApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ICMMOD_H__F74702E5_1BB2_4B41_92C1_ECEF855FA759__INCLUDED_)
