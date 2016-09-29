// PartyLogNone.cpp: implementation of the CPartyLogNone class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "HistoryParser_DLL.h"
#include "PartyLogNone.h"
#include "PSPartyLogSmallBlind.h"
#include "PPokerSite.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPartyLogNone::CPartyLogNone(CParseFile* pPF)
: CParseState(pPF)
{
}

CPartyLogNone::~CPartyLogNone()
{

}

CParseState* CPartyLogNone::Parse(const CString &strInLine)
{
	CString strUnreadLine = strInLine;
	TRACE("Looking for start of Party Hand\n");
	if (IsPartyPokerNewHamd(strInLine))
	{
		sm_cInputHand.NewHand();
		sm_cInputHand.SetPokerSite(PPokerSite::POKER_SITE_PARTY);
		sm_cInputHand.SetIncomplete();
		sm_cInputHand.SetGameNumber(GetPartyLogGameNumber(strInLine));
		sm_listNicks.clear();
		return new CPSPartyLogSmallBlind(m_cParseFile);
	}
	else
	{
		return this;
	}		
}





