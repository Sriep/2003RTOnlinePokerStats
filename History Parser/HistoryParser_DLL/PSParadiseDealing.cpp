// PSParadiseDealing.cpp: implementation of the CPSParadiseDealing class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PSParadiseDealing.h"

#include "ParsingException.h"
#include "PSNone.h"
#include "PSParadisePlayerAction.h"
#include "PSParadiseSumary1.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPSParadiseDealing::CPSParadiseDealing(CParseFile* pPF)
: CParseState(pPF)
{

}

CPSParadiseDealing::~CPSParadiseDealing()
{

}

CParseState* CPSParadiseDealing::Parse(const CString& strInLine)
{
	CString strUnreadLine = strInLine;

	ReadText(CHAR_ASTERIX, strUnreadLine);
	ReadText(CHAR_ASTERIX, strUnreadLine);
	ReadText(CHAR_ASTERIX, strUnreadLine);
	CString strRound = GetNextWord(strUnreadLine);

	if (strRound == "FLOP")
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
	CParseState* pNewState = new CPSParadisePlayerAction(m_cParseFile);
	delete this;
	return pNewState;
}


void CPSParadiseDealing::ParseFlopDeal(CString& strUnreadLine)
{
	ReadText(CHAR_ASTERIX, strUnreadLine);
	ReadText(CHAR_ASTERIX, strUnreadLine);
	ReadText(CHAR_ASTERIX, strUnreadLine);
	ReadText(CHAR_COLON, strUnreadLine);
	ReadText(CHAR_OPEN_SQ_BRACKET, strUnreadLine);
	PCard cFlopCard1 = ReadCard(strUnreadLine);
	PCard cFlopCard2 = ReadCard(strUnreadLine);
	PCard cFlopCard3 = ReadCard(strUnreadLine);

	sm_cInputHand.SetFlop(cFlopCard1, cFlopCard2, cFlopCard3);
}

void CPSParadiseDealing::ParseTurnDeal(CString& strUnreadLine)
{
	ReverseReadText(CHAR_CLOSE_SQ_BRACKET, strUnreadLine);
	PCard cTurnCard = ReverseReadCard(strUnreadLine);

	sm_cInputHand.SetTurn(cTurnCard);
}

void CPSParadiseDealing::ParseRiverDeal(CString& strUnreadLine)
{
	ReverseReadText(CHAR_CLOSE_SQ_BRACKET, strUnreadLine);
	PCard cRiverCard = ReverseReadCard(strUnreadLine);

	sm_cInputHand.SetRiver(cRiverCard);
}

