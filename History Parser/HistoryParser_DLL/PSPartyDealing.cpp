// PSPartyDealing.cpp: implementation of the CPSPartyDealing class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PSPartyDealing.h"

#include "PSPartyDealToPlayer.h"
#include "ParsingException.h"
#include "PSNone.h"
#include "PSPartyPlayerAction.h"
#include "PSPartySumary1.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPSPartyDealing::CPSPartyDealing(CParseFile* pPF)
: CParseState(pPF)
{

}

CPSPartyDealing::~CPSPartyDealing()
{

}

CParseState* CPSPartyDealing::Parse(const CString& strInLine)
{
	CString strUnreadLine = strInLine;

	ReadText("** Dealing", strUnreadLine);
	CString strRound = GetNextWord(strUnreadLine);

	if (strRound == WORD_down)
	{
		ParseInitalDeal(strUnreadLine);
		CParseState* pNewState = new CPSPartyDealToPlayer(m_cParseFile);
		delete this;
		return pNewState;
	}
	else if (strRound == WORD_Flop)
	{
		ParseFlopDeal(strUnreadLine);
	}
	else if (strRound == WORD_Turn)
	{
		ParseTurnDeal(strUnreadLine);
	}
	else if (strRound == WORD_River)
	{
		ParseRiverDeal(strUnreadLine);
	}
	else
	{
		throw(new CParsingException(IDS_UNEXPECTED_TEXT, this, new CPSNone(m_cParseFile)));
	}
	CParseState* pNewState = new CPSPartyPlayerAction(m_cParseFile);
	delete this;
	return pNewState;
}


void CPSPartyDealing::ParseInitalDeal(CString& strUnreadLine)
{
	ReadText(WORD_cards, strUnreadLine);
	ReadText(CHAR_ASTERIX, strUnreadLine);
	ReadText(CHAR_ASTERIX, strUnreadLine);
}

void CPSPartyDealing::ParseFlopDeal(CString& strUnreadLine)
{
	ReadText(CHAR_ASTERIX, strUnreadLine);
	ReadText(CHAR_ASTERIX, strUnreadLine);
	ReadText(CHAR_COLON, strUnreadLine);
	ReadText(CHAR_OPEN_SQ_BRACKET, strUnreadLine);
	PCard cFlopCard1 = ReadCard(strUnreadLine);
	ReadText(CHAR_COMMA, strUnreadLine);
	PCard cFlopCard2 = ReadCard(strUnreadLine);
	ReadText(CHAR_COMMA, strUnreadLine);
	PCard cFlopCard3 = ReadCard(strUnreadLine);
	ReadText(CHAR_CLOSE_SQ_BRACKET, strUnreadLine);

	sm_cInputHand.SetFlop(cFlopCard1, cFlopCard2, cFlopCard3);
}

void CPSPartyDealing::ParseTurnDeal(CString& strUnreadLine)
{
	ReadText(CHAR_ASTERIX, strUnreadLine);
	ReadText(CHAR_ASTERIX, strUnreadLine);
	ReadText(CHAR_COLON, strUnreadLine);
	ReadText(CHAR_OPEN_SQ_BRACKET, strUnreadLine);
	PCard cTurnCard = ReadCard(strUnreadLine);
	ReadText(CHAR_CLOSE_SQ_BRACKET, strUnreadLine);

	sm_cInputHand.SetTurn(cTurnCard);
}

void CPSPartyDealing::ParseRiverDeal(CString& strUnreadLine)
{
	ReadText(CHAR_ASTERIX, strUnreadLine);
	ReadText(CHAR_ASTERIX, strUnreadLine);
	ReadText(CHAR_COLON, strUnreadLine);
	ReadText(CHAR_OPEN_SQ_BRACKET, strUnreadLine);
	PCard cRiverCard = ReadCard(strUnreadLine);
	ReadText(CHAR_CLOSE_SQ_BRACKET, strUnreadLine);

	sm_cInputHand.SetRiver(cRiverCard);
}

