// HighStakesLogNone.cpp: implementation of the CHighStakesLogNone class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "HistoryParser_DLL.h"
#include "HighStakesLogNone.h"
#include "PPokerSite.h"
#include "PSHighStakesLogPlayerFirxtAction.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CHighStakesLogNone::CHighStakesLogNone(CParseFile* pPF)
: CParseState(pPF),
	m_iNumberOfPosters(0)
{		
}

CHighStakesLogNone::~CHighStakesLogNone()
{

}

CParseState* CHighStakesLogNone::Parse(const CString &strInLine)
{
	CString strUnreadLine = strInLine;
	if (!ReadIfNextWord("D: ", strUnreadLine))
	{
		return this;
	}
	if (-1 != strUnreadLine.Find("posted small blind"))
	{
		ReadSmallBlind(strUnreadLine);
		return this;
	}
	if (-1 != strUnreadLine.Find("posted big blind"))
	{
		ReadPost(strUnreadLine);
		return this;
	}
	else if (ReadIfNextWord("Game [", strUnreadLine))
	{
		SetUpForNewHand(strUnreadLine);
		SetBlinds();
		return new CPSHighStakesLogPlayerFirstAction(m_cParseFile);
	}
	else
	{
		TRACE("Looking for start of High Stakes hand\n");
		return this;
	}
}





