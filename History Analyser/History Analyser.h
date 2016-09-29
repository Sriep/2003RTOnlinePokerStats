// History Analyser.h : main header file for the HISTORY ANALYSER application
//

#if !defined(AFX_HISTORYANALYSER_H__1483FB17_56A6_4004_9E4F_6362ECB63630__INCLUDED_)
#define AFX_HISTORYANALYSER_H__1483FB17_56A6_4004_9E4F_6362ECB63630__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CHistoryAnalyserApp:
// See History Analyser.cpp for the implementation of this class
//

class CHistoryAnalyserApp : public CWinApp
{
public:
	CHistoryAnalyserApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHistoryAnalyserApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CHistoryAnalyserApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HISTORYANALYSER_H__1483FB17_56A6_4004_9E4F_6362ECB63630__INCLUDED_)
