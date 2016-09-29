// CryptologicLogNone.cpp: implementation of the CCryptologicLogNone class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "HistoryParser_DLL.h"
#include "CryptologicLogNone.h"
#include "PPokerSite.h"
#include "PSCryptologicLogBlind.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CCryptologicLogNone::CCryptologicLogNone(CParseFile* pPF)
: CParseState(pPF)
{
}

CCryptologicLogNone::~CCryptologicLogNone()
{

}

CParseState* CCryptologicLogNone::Parse(const CString &strInLine)
{
	CString strUnreadLine = strInLine;
	TRACE("Looking for start of Cryptologic Hand\n");
	if (IsCryptologicPokerNewHamd(strInLine))
	{
		sm_cInputHand.NewHand();
		((CParserCryptologicLogFile*) m_cParseFile)->NewRound();
		sm_cInputHand.SetPokerSite(PPokerSite::POKER_SITE_CRYPTOLOGIC);
		sm_cInputHand.SetIncomplete();
		sm_cInputHand.SetGameNumber(GetCryptologicLogGameNumber(strInLine));
		sm_cInputHand.SetGame(GAME_TEXUS_HOLDEM);
		sm_listNicks.clear();
		return new CPSCryptologicLogBlind(m_cParseFile);
	}
	else
	{
		return this;
	}		
}





