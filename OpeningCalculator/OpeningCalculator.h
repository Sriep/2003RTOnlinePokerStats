// OpeningCalculator.h : main header file for the OPENINGCALCULATOR application
//

#if !defined(AFX_OPENINGCALCULATOR_H__68C6161D_770C_4088_A055_BEB4D36DBEAD__INCLUDED_)
#define AFX_OPENINGCALCULATOR_H__68C6161D_770C_4088_A055_BEB4D36DBEAD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// COpeningCalculatorApp:
// See OpeningCalculator.cpp for the implementation of this class
//

class COpeningCalculatorApp : public CWinApp
{
public:
	COpeningCalculatorApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COpeningCalculatorApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(COpeningCalculatorApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OPENINGCALCULATOR_H__68C6161D_770C_4088_A055_BEB4D36DBEAD__INCLUDED_)
