// WSEXLogNone.cpp: implementation of the CWSEXLogNone class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "HistoryParser_DLL.h"
#include "WSEXLogNone.h"
#include "PSWSEXLogSmallBlind.h"
#include "PPokerSite.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CWSEXLogNone::CWSEXLogNone(CParseFile* pPF)
: CParseState(pPF)
{
}

CWSEXLogNone::~CWSEXLogNone()
{

}

CParseState* CWSEXLogNone::Parse(const CString &strInLine)
{
	CString strUnreadLine = strInLine;
	TRACE("Looking for start of WSEX hand\n");
	if (ReadIfNextWord("Dealer: ** New hand[", strUnreadLine))
	{
		sm_cInputHand.SetPokerSite(m_cParseFile->GetSite());
		//sm_cInputHand.SetPokerSite(PPokerSite::POKER_SITE_WSEX);
		sm_cInputHand.SetIncomplete();
		sm_cInputHand.SetGameNumber(GetNextNumber(strUnreadLine));
		sm_listNicks.clear();
		return new CPSWSEXLogSmallBlind(m_cParseFile);
	}
	else
	{
		return this;
	}		
}





