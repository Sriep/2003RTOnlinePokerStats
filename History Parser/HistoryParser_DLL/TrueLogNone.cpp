// TrueLogNone.cpp: implementation of the CTrueLogNone class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "HistoryParser_DLL.h"
#include "TrueLogNone.h"
#include "PPokerSite.h"
#include "PSTrueLogHeader.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CTrueLogNone::CTrueLogNone(CParseFile* pPF)
: CParseState(pPF)
{
}

CTrueLogNone::~CTrueLogNone()
{

}

CParseState* CTrueLogNone::Parse(const CString &strInLine)
{
	CString strUnreadLine = strInLine;
	TRACE("Looking for start of True Poker hand\n");
	if (ReadIfNextWord("Game Started on",strUnreadLine))
	{
		sm_cInputHand.NewHand();
		sm_cInputHand.SetPokerSite(PPokerSite::POKER_SITE_TRUE);
		sm_cInputHand.SetDate(GetDate(strUnreadLine));
		if (m_cParseFile->IsLog())
		{
			sm_cInputHand.SetIncomplete();
		}
		sm_listNicks.clear();
		return new CPSTrueLogHeader(m_cParseFile);
	}
	else
	{
		return this;
	}		
}





