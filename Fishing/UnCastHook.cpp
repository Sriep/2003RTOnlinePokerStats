#include "stdafx.h"
#include "FishingAPI.h"
#include "FishingControl.h"

STDAPI UnCastPokerSpyHook(HWND hwnd)
{
	CFishingControl::RemoveSpiedOnWindow(hwnd);
	return 0;
}
