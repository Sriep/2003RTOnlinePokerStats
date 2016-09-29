// PSStarsDealToPlayer.cpp: implementation of the CPSStarsDealToPlayer class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PSStarsDealToPlayer.h"

#include "PSStarsPlayerAction.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPSStarsDealToPlayer::CPSStarsDealToPlayer(CParseFile* pPF)
: CParseState(pPF)
{

}

CPSStarsDealToPlayer::~CPSStarsDealToPlayer()
{

}

CParseState* CPSStarsDealToPlayer::Parse(const CString &strInLine)
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
	CParseState* pNewState = new CPSStarsPlayerAction(m_cParseFile);
	delete this;
	return pNewState;
}
