// FishingControl.h: interface for the CFishingControl class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FISHINGCONTROL_H__E9FD885C_E038_4EED_95BA_F0F2A5E85BEE__INCLUDED_)
#define AFX_FISHINGCONTROL_H__E9FD885C_E038_4EED_95BA_F0F2A5E85BEE__INCLUDED_

#include <list>
#include "SortingOffice.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define PHOOKERR_NO_ERROR 0
#define PHOOKERR_CAN_NOT_FIND_SOURCE_WINDOW 1
#define PHOOKERR_CAN_NOT_FIND_GAME_WINDOW 2
#define PHOOKERR_CAN_NOT_FIND_DELEAR_WINDOW 3
#define PHOOKERR_CAN_NOT_CREATE_HOOK 4
#define PHOOKERR_CAN_NOT_RECOGNISE_SITE 5	

#define PARTY_POKER 1
#define PARADISE_POKER 2


typedef LRESULT PHOOKERR;
typedef int HOOK_HANDLE;

struct HookWindowPair
{
	HOOK_HANDLE hHandle;
	HWND hwndSpyedOn;
	HWND hwndDestination;
	UINT messageToLookFor;
};

typedef std::list<HookWindowPair> HookWindowPairList;
typedef HookWindowPairList::iterator HookWindowPairListIterator;
typedef std::list<HookWindowPair> HookWindowPairList;

class CFishingControl 
{
public:
	CFishingControl();
	virtual ~CFishingControl();

	static HWND CastHook(HWND wndSourceWindow,  int iSite);	
	static HookWindowPairList GetSubscribers();
	static void RemoveSpiedOnWindow(HWND hwnd);

private:
	static HWND GetDealerTextWindow(const CString& strSourceWindow, int iSite);
	static HWND GetDealerTextWindow(HWND hwndSourceWindow, int iSite);
	static void SetHook();
	static void AddNewSubsciber(HWND hwndSourceWindow, const HWND hwndpDestinationWindow, int iSite);
	static HHOOK GetHookHandle();

	static HWND GetPartyDealerTextWindow(HWND hwndSourceWindow);   
	static HWND GetParadiseDealerTextWindow(HWND hwndSourceWindow);
	static HWND GetLabrokesDealerTextWindow(HWND hwndSourceWindow);
	static HWND GetRoyalVegasDealerTextWindow(HWND hwndSourceWindow);
	static HWND GetPokerRoomDealerTextWindow(HWND hwndSourceWindow);
	static HWND GetUltimateBetDealerTextWindow(HWND hwndSourceWindow);
	static HWND GetHighStakesDealerTextWindow(HWND hwndSourceWindow);
	static HWND GetWSEXDealerTextWindow(HWND hwndSourceWindow);
	static HWND GetPokerClubDealerTextWindow(HWND hwndSourceWindow);
	static HWND GetCryptologicDealerTextWindow(HWND hwndSourceWindow);

	static HHOOK sm_hHook;
	static HOOK_HANDLE sm_iNextHookHandle;
	static HookWindowPairList sm_listSubscibers;
};

#endif // !defined(AFX_FISHINGCONTROL_H__E9FD885C_E038_4EED_95BA_F0F2A5E85BEE__INCLUDED_)
