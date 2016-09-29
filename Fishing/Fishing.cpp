// Fishing.cpp : Defines the initialization routines for the DLL.
//

#include "stdafx.h"
#include "Fishing.h"
#include "FishingControl.h"
#include "FishingAPI.h"
#include <fstream.h>
#include "PPokerSite.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//
//	Note!
//
//		If this DLL is dynamically linked against the MFC
//		DLLs, any functions exported from this DLL which
//		call into MFC must have the AFX_MANAGE_STATE macro
//		added at the very beginning of the function.
//
//		For example:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// normal function body here
//		}
//
//		It is very important that this macro appear in each
//		function, prior to any calls into MFC.  This means that
//		it must appear as the first statement within the 
//		function, even before any object variable declarations
//		as their constructors may generate calls into the MFC
//		DLL.
//
//		Please see MFC Technical Notes 33 and 58 for additional
//		details.
//

/////////////////////////////////////////////////////////////////////////////
	
BEGIN_MESSAGE_MAP(CFishingApp, CWinApp)
	//{{AFX_MSG_MAP(CFishingApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFishingApp construction

CFishingApp::CFishingApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

CFishingApp::~CFishingApp()
{
	for ( int iSite = 0 ; iSite < PPokerSite::NUM_OF_POKER_SITES ; iSite++ )
	{
		sm_smSpyedOnWindowsList[iSite].CloseSharedMemory();
	}

	for ( SharedMemoryListIterator iter = sm_asmDealerText.begin() ; iter != sm_asmDealerText.end() ; iter++ )
	{
		(*iter).CloseSharedMemory();
	}

	for ( SharedMemoryListIterator iterPL = sm_asmPlayersList.begin() ; iterPL != sm_asmPlayersList.end() ; iterPL++ )
	{
		(*iterPL).CloseSharedMemory();
	}
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CFishingApp object

CFishingApp theApp;

CFishingApp& CFishingApp::GetApp()	
{
	return theApp;
}

/////////////////////////////////////////////////////////////////////////////
// CFishingApp initialization

BOOL CFishingApp::InitInstance()
{
	// Register all OLE server (factories) as running.  This enables the
	//  OLE libraries to create objects from other applications.
	COleObjectFactory::RegisterAll();
	for ( int iSite = 0 ; iSite < PPokerSite::NUM_OF_POKER_SITES ; iSite++ )
	{
		PPokerSite pokerSite(iSite);
		sm_smSpyedOnWindowsList[iSite].OpenSharedMemory(pokerSite.Name(), FILE_MAP_ALL_ACCESS, 16*16*16);
	}
	return TRUE;
}

void CFishingApp::AddToSpyedOnWindowsList(HWND hwnd, int iSite)
{	
	if (!IsWindowInSpyedOnWindowsList(hwnd, iSite))
	{
		CString strSpiedOnWindows;
		strSpiedOnWindows.Format(" %X ", (long)hwnd);
		sm_smSpyedOnWindowsList[iSite].Append(strSpiedOnWindows);

		CSharedMemory cSharedMemoryDealerText;
		CString strDealerWindowName = PPokerSite::GetDealerTextName(hwnd, iSite);
		cSharedMemoryDealerText.OpenSharedMemory(strDealerWindowName);
		cSharedMemoryDealerText.Clear();
		sm_asmDealerText.push_back(cSharedMemoryDealerText);

		CSharedMemory cSharedMemoryPlayerList;
		CString strPlayerListName = PPokerSite::GetPlayerListName(hwnd, iSite);
		cSharedMemoryPlayerList.OpenSharedMemory(strPlayerListName, FILE_MAP_ALL_ACCESS, 4096);
		cSharedMemoryPlayerList.Clear();
		sm_asmPlayersList.push_back(cSharedMemoryPlayerList);
	}
	if (IsWindowInSpyedOnWindowsList(hwnd, iSite))
	{
		TRACE2("Added %X to spied upon windows at site %s\n", hwnd, PPokerSite::GetName(iSite));
		sm_smSpyedOnWindowsList[iSite].DUMP();
	}
}

CString CFishingApp::GetSpyedOnWindowsList(int iSite)
{
	return sm_smSpyedOnWindowsList[iSite].Get();
}

bool CFishingApp::IsWindowInSpyedOnWindowsList(HWND hwnd, int iSite) 
{
	CString strHWND;
	strHWND.Format("%X", (long)hwnd);

	return sm_smSpyedOnWindowsList[iSite].CanFind(strHWND);
}

void CFishingApp::RemoveFromSpyedOnWindowsList(HWND hwndDealer)
{

}

void CFishingApp::ClearWindowList()
{
	for ( int iSite = 0 ; iSite < PPokerSite::NUM_OF_POKER_SITES ; iSite++ )
	{
		sm_smSpyedOnWindowsList[iSite].Clear();
	}
}


/////////////////////////////////////////////////////////////////////////////
// Special entry points required for inproc servers

STDAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID* ppv)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	return AfxDllGetClassObject(rclsid, riid, ppv);
}

STDAPI DllCanUnloadNow(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	return AfxDllCanUnloadNow();
}

// by exporting DllRegisterServer, you can use regsvr.exe
STDAPI DllRegisterServer(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	COleObjectFactory::UpdateRegistryAll();
	return S_OK;
}




