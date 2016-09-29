// RoyalVegasLogNone.cpp: implementation of the CRoyalVegasLogNone class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "HistoryParser_DLL.h"
#include "RoyalVegasLogNone.h"
#include "PPokerSite.h"
#include "PSRoyalVegasLogPlayerFirxtAction.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CRoyalVegasLogNone::CRoyalVegasLogNone(CParseFile* pPF)
: CParseState(pPF),
	m_iAmountSmallBlind(0),	
	m_iNumberOfPosters(0)
{		
}

CRoyalVegasLogNone::~CRoyalVegasLogNone()
{

}

CParseState* CRoyalVegasLogNone::Parse(const CString &strInLine)
{
	CString strUnreadLine = strInLine;
	if (!ReadIfNextWord(">", strUnreadLine))
	{
		return this;
	}
	strUnreadLine.TrimLeft(' ');
	if (-1 != strUnreadLine.Find("posted small blind"))
	{
		ReadSmallBlind(strUnreadLine);
		return this;
	}
	if (-1 != strUnreadLine.Find("posted big blind"))
	{
		ReadBigBlind(strUnreadLine);
		return this;
	}
	if (-1 != strUnreadLine.Find("posted to play"))
	{
		ReadPost(strUnreadLine);
		return this;
	}
	else if (ReadIfNextWord("Game #", strUnreadLine))
	{
		SetUpForNewHand(strUnreadLine);
		SetBlinds();
		return new CPSRoyalVegasLogPlayerFirstAction(m_cParseFile);
	}
	else
	{
		TRACE("Looking for start of Royal Vegas hand\n");
		return this;
	}
}





