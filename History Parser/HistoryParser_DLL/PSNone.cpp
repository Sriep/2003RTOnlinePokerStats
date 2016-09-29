// PSNone.cpp: implementation of the CPSNone class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PSNone.h"

#include "PSPartyHeader1.h"
#include "PSStarsHeader1.h"
#include "PSParadiseHeader1.h"
#include "PPokerSite.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

const CString CPSNone::POKERSTARS_START = "*********** # ";
const CString CPSNone::PARTYPOKER_START = "***** Hand History for Game ";
const CString CPSNone::PARADISEPOKER_START = "-----------------------------------------------------";
const CString CPSNone::TRUEPOKER_START = "******************************************************";


//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPSNone::CPSNone(CParseFile* pPF)
: CParseState(pPF)
{

}

CPSNone::~CPSNone()
{

}

CParseState* CPSNone::Parse(const CString& strInLine)
{
	CParseState* pNextParseState = NULL;
	
	if (strInLine.Left(POKERSTARS_START.GetLength()) == POKERSTARS_START)
	{
		sm_cInputHand.NewHand();
		sm_cInputHand.SetPokerSite(PPokerSite::POKER_SITE_STARS);
		pNextParseState = new CPSStarsHeader1(m_cParseFile);
	}
	else if (IsPartyPokerStart(strInLine))
	{
		sm_cInputHand.NewHand();
		sm_cInputHand.SetPokerSite(PPokerSite::POKER_SITE_PARTY);
		sm_cInputHand.SetGameNumber(GetGameNumber(strInLine));
		pNextParseState = new CPSPartyHeader1(m_cParseFile);
	}
	else if (IsParadisePokerStart(strInLine))
	{
		sm_cInputHand.NewHand();
		pNextParseState = new class CPSParadiseHeader1(m_cParseFile);
	}
	else if (strInLine.Left(TRUEPOKER_START.GetLength()) == TRUEPOKER_START)
	{
	   pNextParseState = new CPSNone(m_cParseFile);
	}
	

	if (pNextParseState)
	{
		delete this;
		return pNextParseState;
	}
	else
	{
		return this;
	}
}

