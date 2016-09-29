// PPokerSite.cpp: implementation of the PPokerSite class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PPokerSite.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

PPokerSite::PPokerSite()
: m_eSite(POKER_SITE_NONE)
{

}

PPokerSite::~PPokerSite()
{

}

  
void PPokerSite::DUMP() const
{
	TRACE(GetName(m_eSite));
}

CString PPokerSite::GetDealerTextName(HWND hwnd, int iSiteId)
{
	CString strSiteName = GetName(iSiteId);
	CString strFileName;
	strFileName.Format("%s_%X", strSiteName, (long) hwnd);
	return strFileName;
};

CString PPokerSite::GetPlayerListName(HWND hwnd, int iSiteId)
{
	CString strSiteName = GetName(iSiteId);
	CString strFileName;
	strFileName.Format("Players_At_%s_%X", strSiteName, (long) hwnd);
	return strFileName;
}

