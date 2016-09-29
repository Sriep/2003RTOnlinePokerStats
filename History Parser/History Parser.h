// History Parser.h : main header file for the HISTORY PARSER application
//

#if !defined(AFX_HISTORYPARSER_H__01BA627C_300F_43F7_8F53_16F2E83F2722__INCLUDED_)
#define AFX_HISTORYPARSER_H__01BA627C_300F_43F7_8F53_16F2E83F2722__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CHistoryParserApp:
// See History Parser.cpp for the implementation of this class
//

class CHistoryParserApp : public CWinApp
{
public:
	CHistoryParserApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHistoryParserApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CHistoryParserApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HISTORYPARSER_H__01BA627C_300F_43F7_8F53_16F2E83F2722__INCLUDED_)
