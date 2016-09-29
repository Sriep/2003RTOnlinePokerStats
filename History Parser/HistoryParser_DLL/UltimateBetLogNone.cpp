// UltimateBetLogNone.cpp: implementation of the CUltimateBetLogNone class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "HistoryParser_DLL.h"
#include "UltimateBetLogNone.h"
#include "PSUltimateBetLogSmallBlind.h"
#include "PPokerSite.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CUltimateBetLogNone::CUltimateBetLogNone(CParseFile* pPF)
: CParseState(pPF)
{
}

CUltimateBetLogNone::~CUltimateBetLogNone()
{

}

CParseState* CUltimateBetLogNone::Parse(const CString &strInLine)
{
	CString strUnreadLine = strInLine;
	TRACE("Looking for start of Ultimate Bet hand\n");
	if (ReadIfNextWord("Dealer: Starting hand #", strUnreadLine))
	{
		sm_cInputHand.NewHand();
		sm_cInputHand.SetPokerSite(PPokerSite::POKER_SITE_ULTIMATE_BET);
		sm_cInputHand.SetIncomplete();
		sm_cInputHand.SetGameNumber(GetUltimateBetLogGameNumber(strUnreadLine));
		ReadText("at", strUnreadLine);
		sm_cInputHand.SetDate(GetDate(strUnreadLine));
		sm_cInputHand.SetGame(GAME_TEXUS_HOLDEM); 
		sm_listNicks.clear();
		return new CPSUltimateBetLogSmallBlind(m_cParseFile);
	}
	else
	{
		return this;
	}		
}







