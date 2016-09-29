#include "stdafx.h"
#include "HookProcedure.h"

#define MSG_LABROKE_UD52 0x434
#define MSG_LABROKE_UD55 0x437
#define MSG_LABROKE_UD68 0x444
#define MSG_LABROKE_UD73 0x449
#define MSG_POKER_ROOM 0x0410

LRESULT CALLBACK PokerSpyHook(int nCode, WPARAM wParam, LPARAM lParam) 
{ 
	CWPSTRUCT*  pmsg = (CWPSTRUCT*) lParam;

	switch (pmsg->message)
	{
	case EM_REPLACESEL:
		if (CFishingApp::GetApp().IsWindowInSpyedOnWindowsList((pmsg->hwnd), PPokerSite::POKER_SITE_PARTY) )
		{
			HandlePartyPokerMessage(pmsg);			
		}
		else  if (CFishingApp::GetApp().IsWindowInSpyedOnWindowsList((pmsg->hwnd), PPokerSite::POKER_SITE_HIGH_STAKES) )
		{
			HandleHighStakesPokerMessage(pmsg);			
		}
		else  if (CFishingApp::GetApp().IsWindowInSpyedOnWindowsList((pmsg->hwnd), PPokerSite::POKER_SITE_WSEX) )
		{
			HandleWSEXPokerMessage(pmsg);			
		} 
		else  if (CFishingApp::GetApp().IsWindowInSpyedOnWindowsList((pmsg->hwnd), PPokerSite::POKER_SITE_POKER_CLUB) )
		{
			HandlePokerClubPokerMessage(pmsg);			
		}
		else  if (CFishingApp::GetApp().IsWindowInSpyedOnWindowsList((pmsg->hwnd), PPokerSite::POKER_SITE_CRYPTOLOGIC) )
		{
			HandleCryptologicMessage(pmsg);			
		}
		break;
	case LB_ADDSTRING:
		if (CFishingApp::GetApp().IsWindowInSpyedOnWindowsList((pmsg->hwnd), PPokerSite::POKER_SITE_PARADISE))
		{
			HandleParadisePokerMessage(pmsg);			
		}
		else if (CFishingApp::GetApp().IsWindowInSpyedOnWindowsList((pmsg->hwnd), PPokerSite::POKER_SITE_ULTIMATE_BET))
		{
			HandleUltimateBetrMessage(pmsg);			
		}
		break;
	case LB_GETCOUNT:
		if (CFishingApp::GetApp().IsWindowInSpyedOnWindowsList((pmsg->hwnd), PPokerSite::POKER_SITE_PARADISE))
		{
			HandleParadisePokerMessage(pmsg);			
		}
		break;
	case MSG_LABROKE_UD73:
		if (CFishingApp::GetApp().IsWindowInSpyedOnWindowsList((pmsg->hwnd), PPokerSite::POKER_SITE_LABROKES))
		{
			HandleLabrokePokerMessage(pmsg);			
		}
		else if (CFishingApp::GetApp().IsWindowInSpyedOnWindowsList((pmsg->hwnd), PPokerSite::POKER_SITE_ROYAL_VEGAS))
		{
			HandleRoyalVegasPokerMessage(pmsg);			
		}
		break;
	case MSG_POKER_ROOM:  
		if (CFishingApp::GetApp().IsWindowInSpyedOnWindowsList((pmsg->hwnd), PPokerSite::POKER_SITE_POKER_ROOM))
		{
			HandlePokerRoomPokerMessage(pmsg);			
		}
		break;
	default:
		;
	}
    return CallNextHookEx(NULL, nCode, wParam, lParam); 
} 





