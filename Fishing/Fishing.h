// Fishing.h : main header file for the FISHING DLL
//

#if !defined(AFX_FISHING_H__515A1900_EDB9_4E40_AD45_A9AF975D7775__INCLUDED_)
#define AFX_FISHING_H__515A1900_EDB9_4E40_AD45_A9AF975D7775__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include <list>
#include "resource.h"		// main symbols
#include "SharedMemory.h"
#include "FishingControl.h"
#include "PPokerObject.h"
#include "PPokerSite.h"

/////////////////////////////////////////////////////////////////////////////
// CFishingApp
// See Fishing.cpp for the implementation of this class
//

#define MAX_NUM_WINDOWS_TO_SPY_ON 20

typedef std::list<CSharedMemory> SharedMemoryList;
typedef SharedMemoryList::iterator SharedMemoryListIterator;
//typedef WindowList::const_iterator ConstWindowListIterator;

class CFishingApp : public CWinApp
{
public:
	CFishingApp();
	virtual ~CFishingApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFishingApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

	//{{AFX_MSG(CFishingApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
		
public:		
	void ClearWindowList();
	void AddToSpyedOnWindowsList(HWND hwndDealer, int iSiteId); 
	void RemoveFromSpyedOnWindowsList(HWND hwndDealer);
	CString GetSpyedOnWindowsList(int iSite);
	bool IsWindowInSpyedOnWindowsList(HWND hwnd, int iSite); 

	static CFishingApp& GetApp();
private:		   
	CSharedMemory sm_smSpyedOnWindowsList[PPokerSite::NUM_OF_POKER_SITES];
	SharedMemoryList sm_asmDealerText;
	SharedMemoryList sm_asmPlayersList;
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FISHING_H__515A1900_EDB9_4E40_AD45_A9AF975D7775__INCLUDED_)
