// FishingControl.cpp: implementation of the CFishingControl class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Fishing.h"
#include "FishingControl.h"
#include "FishingAPI.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

#define PARTY_POSITION_OF_DEALER_TEXT_WINDOW	49
#define PARADISE_POSITION_OF_DEALER_TEXT_WINDOW	103
#define HIGH_STAKES_POSITION_OF_DEALER_WINDOW 11
#define POKER_CLUB_POSITION_OF_DEALER_WINDOW 42
#define WSEX_POSITION_OF_DEALER_WINDOW 54

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
HHOOK CFishingControl::sm_hHook = 0;
HOOK_HANDLE CFishingControl::sm_iNextHookHandle = 1;
HookWindowPairList CFishingControl::sm_listSubscibers;

CFishingControl::CFishingControl()
{
		FILE* ofFileStrem = fopen(SHARED_DATA_FILE, "a");
		fclose(ofFileStrem);
}

CFishingControl::~CFishingControl()
{

}


HHOOK CFishingControl::GetHookHandle()
{
	return sm_hHook;
}

void CFishingControl::SetHook()
{
	HOOKPROC hkprcPokerSpyHook; 

	static HINSTANCE hinstDLL; 							   
 
	hinstDLL = AfxLoadLibrary((LPCTSTR) FISHING_DLL); 
	hkprcPokerSpyHook = (HOOKPROC)GetProcAddress(hinstDLL, "PokerSpyHook"); 
	sm_hHook = SetWindowsHookEx(WH_CALLWNDPROC ,hkprcPokerSpyHook,hinstDLL,0);

	if (NULL == sm_hHook)
	{
		throw(PHOOKERR_CAN_NOT_CREATE_HOOK);
	}
}

HWND CFishingControl::CastHook(HWND hwndSourceWindow, int iSite)
{

	if (iSite != PPokerSite::POKER_SITE_PARTY 
		&& iSite != PPokerSite::POKER_SITE_PARADISE 
		&& iSite != PPokerSite::POKER_SITE_LABROKES
		&& iSite != PPokerSite::POKER_SITE_POKER_ROOM
		&& iSite != PPokerSite::POKER_SITE_ULTIMATE_BET
		&& iSite != PPokerSite::POKER_SITE_ROYAL_VEGAS
		&& iSite != PPokerSite::POKER_SITE_HIGH_STAKES
		&& iSite != PPokerSite::POKER_SITE_WSEX
		&& iSite != PPokerSite::POKER_SITE_POKER_CLUB
		&& iSite != PPokerSite::POKER_SITE_CRYPTOLOGIC
		)
	{
		throw(PHOOKERR_CAN_NOT_RECOGNISE_SITE);
	}

	HWND hwndDealerText = GetDealerTextWindow(hwndSourceWindow, iSite);
	if (!hwndDealerText)
		throw(PHOOKERR_CAN_NOT_FIND_SOURCE_WINDOW);

	if (!sm_hHook)
	{
		CFishingApp::GetApp().ClearWindowList();
		CFishingApp::GetApp().AddToSpyedOnWindowsList(hwndDealerText, iSite);
		SetHook();
	}
	else
	{
		CFishingApp::GetApp().AddToSpyedOnWindowsList(hwndDealerText, iSite);
	}

	return hwndDealerText;
}


HWND CFishingControl::GetDealerTextWindow(const CString& strSourceWindow, int iSite)
{
	HWND hwndTable = FindWindow(NULL, strSourceWindow);
	if (NULL == hwndTable)
	{
		throw(PHOOKERR_CAN_NOT_FIND_SOURCE_WINDOW);
	}
	return GetDealerTextWindow(hwndTable, iSite);
}

HWND CFishingControl::GetDealerTextWindow(HWND hwndSourceWindow, int iSite)
{
	switch (iSite)
	{
	case  PPokerSite::POKER_SITE_PARTY:
	   return GetPartyDealerTextWindow(hwndSourceWindow);
	case  PPokerSite::POKER_SITE_PARADISE:
	   return GetParadiseDealerTextWindow(hwndSourceWindow);
	case  PPokerSite::POKER_SITE_LABROKES:
	   return GetLabrokesDealerTextWindow(hwndSourceWindow);
	case  PPokerSite::POKER_SITE_ULTIMATE_BET:
	   return GetUltimateBetDealerTextWindow(hwndSourceWindow);
	case  PPokerSite::POKER_SITE_POKER_ROOM:
	   return GetPokerRoomDealerTextWindow(hwndSourceWindow);
	case  PPokerSite::POKER_SITE_ROYAL_VEGAS:
	   return GetRoyalVegasDealerTextWindow(hwndSourceWindow);
	case  PPokerSite::POKER_SITE_HIGH_STAKES:
	   return GetHighStakesDealerTextWindow(hwndSourceWindow);
	case  PPokerSite::POKER_SITE_WSEX:			   
	   return GetWSEXDealerTextWindow(hwndSourceWindow);
	case  PPokerSite::POKER_SITE_POKER_CLUB:
	   return GetPokerClubDealerTextWindow(hwndSourceWindow);
	case  PPokerSite::POKER_SITE_CRYPTOLOGIC:
	   return GetCryptologicDealerTextWindow(hwndSourceWindow);
	default:
		throw(PHOOKERR_CAN_NOT_RECOGNISE_SITE);
	}
}

HWND  CFishingControl::GetPartyDealerTextWindow(HWND hwndSourceWindow)
{
	HWND hwndNextWindow = ::GetWindow(hwndSourceWindow, GW_CHILD); 
	HWND hwndPreviousWindow;
	while (hwndNextWindow != NULL)						 
	{
		hwndPreviousWindow =  hwndNextWindow;
		hwndNextWindow = GetNextWindow(hwndNextWindow, GW_HWNDNEXT);
	}
	//Party update Friday 20 Febuary 2004
	hwndPreviousWindow = GetNextWindow(hwndPreviousWindow, GW_HWNDPREV);
	hwndPreviousWindow = GetNextWindow(hwndPreviousWindow, GW_HWNDPREV);
	return hwndPreviousWindow;
}

HWND  CFishingControl::GetCryptologicDealerTextWindow(HWND hwndSourceWindow)
{
	HWND hwndNextWindow = ::GetWindow(hwndSourceWindow, GW_CHILD); 
	hwndNextWindow = GetNextWindow(hwndNextWindow, GW_HWNDNEXT);
	hwndNextWindow = GetNextWindow(hwndNextWindow, GW_HWNDNEXT);
	return hwndNextWindow;
}


HWND  CFishingControl::GetParadiseDealerTextWindow(HWND hwndSourceWindow)
{
	HWND hwndNextWindow = ::GetWindow(hwndSourceWindow, GW_CHILD); 
	HWND hwndPreviousWindow;
	while (hwndNextWindow != NULL)
	{
		hwndPreviousWindow =  hwndNextWindow;
		hwndNextWindow = GetNextWindow(hwndNextWindow, GW_HWNDNEXT);
	}
	return hwndPreviousWindow;
}

HWND CFishingControl::GetLabrokesDealerTextWindow(HWND hwndSourceWindow)
{
	HWND hwndNextWindow = ::GetWindow(hwndSourceWindow, GW_CHILD); 
	hwndNextWindow = ::GetWindow(hwndNextWindow, GW_HWNDNEXT);
	return hwndNextWindow;
}

HWND CFishingControl::GetRoyalVegasDealerTextWindow(HWND hwndSourceWindow)
{
	HWND hwndNextWindow = ::GetWindow(hwndSourceWindow, GW_CHILD); 
	hwndNextWindow = ::GetWindow(hwndNextWindow, GW_HWNDNEXT);
	return hwndNextWindow;	   
}

HWND CFishingControl::GetWSEXDealerTextWindow(HWND hwndSourceWindow)
{
	HWND hwndNextWindow = ::GetWindow(hwndSourceWindow, GW_CHILD); 
	//for (int iWinNum = 1 ; iWinNum < WSEX_POSITION_OF_DEALER_WINDOW ; iWinNum++ )
	for (int iWinNum = 1 ; iWinNum < 101 ; iWinNum++ )
	{
		hwndNextWindow = ::GetWindow(hwndNextWindow, GW_HWNDNEXT);
		ASSERT(NULL != hwndNextWindow);
	}
	return hwndNextWindow;
}
			 
HWND CFishingControl::GetPokerClubDealerTextWindow(HWND hwndSourceWindow)
{
	HWND hwndNextWindow = ::GetWindow(hwndSourceWindow, GW_CHILD); 
	for (int iWinNum = 1 ; iWinNum < POKER_CLUB_POSITION_OF_DEALER_WINDOW ; iWinNum++ )
	{
		hwndNextWindow = ::GetWindow(hwndNextWindow, GW_HWNDNEXT);
		ASSERT(NULL != hwndNextWindow);
	}
	return hwndNextWindow;
}

HWND CFishingControl::GetHighStakesDealerTextWindow(HWND hwndSourceWindow)
{
	char pchWindowNameBuffer[MAX_WINDOW_CAPTION_SIZE];
	::GetWindowText(hwndSourceWindow, pchWindowNameBuffer, MAX_WINDOW_CAPTION_SIZE);
	CString strHighStakesOptionsWnd(pchWindowNameBuffer);
	strHighStakesOptionsWnd = strHighStakesOptionsWnd.Left(strHighStakesOptionsWnd.Find('$'));
	strHighStakesOptionsWnd += "Options";

	HWND hwndHighStakesOptions = FindWindow(NULL, strHighStakesOptionsWnd.GetBuffer(1));

	HWND hwndDesktop = ::GetDesktopWindow();
	HWND hwndCurrent = ::GetTopWindow(hwndDesktop);
	bool bFound = false;
	while (NULL != hwndCurrent && !bFound)
	{
		
		::GetWindowText(hwndCurrent, pchWindowNameBuffer,	MAX_WINDOW_CAPTION_SIZE);
		if (strHighStakesOptionsWnd == pchWindowNameBuffer)
		{
			char pchFirstChild[MAX_WINDOW_CAPTION_SIZE];
			HWND hwndChild = ::GetWindow(hwndCurrent, GW_CHILD);
			::GetWindowText(hwndChild, pchFirstChild, MAX_WINDOW_CAPTION_SIZE);
			if (0 != strncmp(pchFirstChild, "Send", 6)) 
			{
				bFound = true;
			}
			else
			{
				hwndCurrent = ::GetNextWindow(hwndCurrent, GW_HWNDNEXT) ;
			}
		}
		else
		{
			hwndCurrent = ::GetNextWindow(hwndCurrent, GW_HWNDNEXT);
		}
	} 

	ASSERT(NULL != hwndCurrent);
	if (NULL != hwndCurrent)
	{
		HWND hwndNextWindow = ::GetWindow(hwndCurrent, GW_CHILD); 
		for (int iWinNum = 1 ; iWinNum < HIGH_STAKES_POSITION_OF_DEALER_WINDOW ; iWinNum++ )
		{
			hwndNextWindow = ::GetWindow(hwndNextWindow, GW_HWNDNEXT);
		}
		return hwndNextWindow;
	}
	else
	{
		return NULL;
	}
}

HWND  CFishingControl::GetPokerRoomDealerTextWindow(HWND hwndSourceWindow)
{
	HWND hwndNextWindow = ::GetWindow(hwndSourceWindow, GW_CHILD);
	hwndNextWindow = ::GetWindow(hwndNextWindow, GW_HWNDNEXT);
	hwndNextWindow = ::GetWindow(hwndNextWindow, GW_HWNDNEXT);
	hwndNextWindow = ::GetWindow(hwndNextWindow, GW_HWNDNEXT);

	hwndNextWindow = ::GetWindow(hwndNextWindow, GW_CHILD);
	hwndNextWindow = ::GetWindow(hwndNextWindow, GW_HWNDNEXT);
	hwndNextWindow = ::GetWindow(hwndNextWindow, GW_HWNDNEXT);
	hwndNextWindow = ::GetWindow(hwndNextWindow, GW_HWNDNEXT);
	hwndNextWindow = ::GetWindow(hwndNextWindow, GW_HWNDNEXT);
	hwndNextWindow = ::GetWindow(hwndNextWindow, GW_HWNDNEXT);
	return GetNextWindow(hwndNextWindow, GW_HWNDNEXT);
}

HWND  CFishingControl::GetUltimateBetDealerTextWindow(HWND hwndSourceWindow)
{
	HWND hwndNextWindow = ::GetWindow(hwndSourceWindow, GW_CHILD);
	if (::GetWindow(hwndNextWindow, GW_CHILD))
	{
		hwndNextWindow = ::GetWindow(hwndNextWindow, GW_CHILD);
		return ::GetWindow(hwndNextWindow, GW_HWNDNEXT);
	}
	else
	{
		hwndNextWindow = ::GetWindow(hwndNextWindow, GW_HWNDNEXT);
		hwndNextWindow = ::GetWindow(hwndNextWindow, GW_HWNDNEXT);
		hwndNextWindow = ::GetWindow(hwndNextWindow, GW_HWNDNEXT);
		hwndNextWindow = ::GetWindow(hwndNextWindow, GW_HWNDNEXT);
		hwndNextWindow = ::GetWindow(hwndNextWindow, GW_HWNDNEXT);
		hwndNextWindow = ::GetWindow(hwndNextWindow, GW_CHILD);
		return GetNextWindow(hwndNextWindow, GW_HWNDNEXT);
	}
}

void CFishingControl::AddNewSubsciber(HWND hwndSource, HWND hwndDestination, int iSite)
{
	
	HookWindowPair cNewSubsciber = {sm_iNextHookHandle, hwndSource, hwndDestination, 0};
	sm_listSubscibers.push_front(cNewSubsciber);
}																   

HookWindowPairList CFishingControl::GetSubscribers()
{
	return sm_listSubscibers;
}

void CFishingControl::RemoveSpiedOnWindow(HWND hwnd)
{
	CFishingApp::GetApp().RemoveFromSpyedOnWindowsList(hwnd);
}

