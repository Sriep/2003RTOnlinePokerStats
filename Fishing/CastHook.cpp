#include "stdafx.h"
#include "FishingAPI.h"
#include "FishingControl.h"


STDAPI CastPokerSpyHook(HWND hwndSourceWindow, int iSite, HWND& hwndHandle)
{
	try
	{
		hwndHandle = CFishingControl::CastHook(hwndSourceWindow, iSite);
	}
	catch (int iExp)
	{
		return iExp;
	}

	return PHOOKERR_NO_ERROR;
}
