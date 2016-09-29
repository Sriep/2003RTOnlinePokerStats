// PSStarsDealing.cpp: implementation of the CPSStarsDealing class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PSStarsDealing.h"

#include "PSStarsDealToPlayer.h"
#include "ParsingException.h"
#include "PSNone.h"
#include "PSStarsPlayerAction.h"
#include "PSStarsSumary1.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPSStarsDealing::CPSStarsDealing(CParseFile* pPF)
: CParseState(pPF)
{

}

CPSStarsDealing::~CPSStarsDealing()
{

}

CParseState* CPSStarsDealing::Parse(const CString& strInLine)
{
	CString strUnreadLine = strInLine;

	ReadText(CHAR_ASTERIX, strUnreadLine);
	ReadText(CHAR_ASTERIX, strUnreadLine);
	ReadText(CHAR_ASTERIX, strUnreadLine);
	CString strRound = GetNextWord(strUnreadLine);

	if (strRound == "HOLE")
	{
		ParseInitalDeal(strUnreadLine);
		CParseState* pNewState = new CPSStarsDealToPlayer(m_cParseFile);
		delete this;
		return pNewState;
	}
	else if (strRound == "FLOP")
	{
		ParseFlopDeal(strUnreadLine);
	}
	else if (strRound == "TURN")
	{
		ParseTurnDeal(strUnreadLine);
	}
	else if (strRound == "RIVER")
	{
		ParseRiverDeal(strUnreadLine);
	}
	else
	{
		throw(new CParsingException(IDS_UNEXPECTED_TEXT, this, new CPSNone(m_cParseFile)));
	}
	CParseState* pNewState = new CPSStarsPlayerAction(m_cParseFile);
	delete this;
	return pNewState;
}


void CPSStarsDealing::ParseInitalDeal(CString& strUnreadLine)
{
	ReadText(WORD_cards, strUnreadLine);
	ReadText(CHAR_ASTERIX, strUnreadLine);
	ReadText(CHAR_ASTERIX, strUnreadLine);
}

void CPSStarsDealing::ParseFlopDeal(CString& strUnreadLine)
{
	ReadText(CHAR_ASTERIX, strUnreadLine);
	ReadText(CHAR_ASTERIX, strUnreadLine);
	ReadText(CHAR_ASTERIX, strUnreadLine);

	ReadText(CHAR_OPEN_SQ_BRACKET, strUnreadLine);
	PCard cFlopCard1 = ReadCard(strUnreadLine);
	//ReadText(CHAR_COMMA, strUnreadLine);
	PCard cFlopCard2 = ReadCard(strUnreadLine);
	//ReadText(CHAR_COMMA, strUnreadLine);
	PCard cFlopCard3 = ReadCard(strUnreadLine);
	ReadText(CHAR_CLOSE_SQ_BRACKET, strUnreadLine);

	sm_cInputHand.SetFlop(cFlopCard1, cFlopCard2, cFlopCard3);
}

void CPSStarsDealing::ParseTurnDeal(CString& strUnreadLine)
{
	ReverseReadText(CHAR_CLOSE_SQ_BRACKET, strUnreadLine);
	PCard cTurnCard = ReverseReadCard(strUnreadLine);

	sm_cInputHand.SetTurn(cTurnCard);
}

void CPSStarsDealing::ParseRiverDeal(CString& strUnreadLine)
{
	ReverseReadText(CHAR_CLOSE_SQ_BRACKET, strUnreadLine);
	PCard cRiverCard = ReverseReadCard(strUnreadLine);

	sm_cInputHand.SetRiver(cRiverCard);
}

