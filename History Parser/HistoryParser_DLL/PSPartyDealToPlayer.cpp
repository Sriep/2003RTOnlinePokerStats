// PSPartyDealToPlayer.cpp: implementation of the CPSPartyDealToPlayer class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PSPartyDealToPlayer.h"

#include "PSPartyPlayerAction.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPSPartyDealToPlayer::CPSPartyDealToPlayer(CParseFile* pPF)
: CParseState(pPF)
{

}

CPSPartyDealToPlayer::~CPSPartyDealToPlayer()
{

}

CParseState* CPSPartyDealToPlayer::Parse(const CString &strInLine)
{
	CString strUnreadLine = strInLine;

	ReadText(WORD_Dealt, strUnreadLine);
	ReadText(WORD_to, strUnreadLine);

	ReverseReadText(CHAR_CLOSE_SQ_BRACKET, strUnreadLine);
	PCard cFisrtCard = ReverseReadCard(strUnreadLine);
	if (IsLastWord(CHAR_COMMA, strUnreadLine))
	{
		ReverseReadText(CHAR_COMMA, strUnreadLine);
	}
	PCard cSecondCard = ReverseReadCard(strUnreadLine);
	ReverseReadText(CHAR_OPEN_SQ_BRACKET, strUnreadLine);

	strUnreadLine.TrimLeft();
	strUnreadLine.TrimRight();

	sm_cInputHand.SetPlayersCards(strUnreadLine, cFisrtCard, cSecondCard);
	CParseState* pNewState = new CPSPartyPlayerAction(m_cParseFile);
	delete this;
	return pNewState;
}
