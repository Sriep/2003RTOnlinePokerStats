// PSStarsGetBigBlind.cpp: implementation of the CPSStarsGetBigBlind class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PSStarsGetBigBlind.h"
#include "PSStarsDealToPlayer.h"
#include "PSStarsDealing.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPSStarsGetBigBlind::CPSStarsGetBigBlind(CParseFile* pPF)
: CParseState(pPF)
{

}

CPSStarsGetBigBlind::~CPSStarsGetBigBlind()
{

}

CParseState* CPSStarsGetBigBlind::Parse(const CString &strInLine)
{
	CString strUnreadLine = strInLine;

	if (StarsIgnoreLine(strInLine))
	{
		return this;
	}

	if (IsNextWord("*** HOLE CARDS ***", strUnreadLine))
	{
		CParseState* pNewState = new CPSStarsDealToPlayer(m_cParseFile);
		delete this;
		return pNewState;
	}

	int iBigBlind = ReverseGetNextNumber(strUnreadLine);
	ReverseReadText("$", strUnreadLine);
	ReverseReadText(WORD_blind, strUnreadLine);
	ReverseReadText(WORD_big, strUnreadLine);
	ReverseReadText(WORD_posts, strUnreadLine);
	ReverseReadText(":", strUnreadLine);
	strUnreadLine.TrimLeft(' ');
	strUnreadLine.TrimRight(' ');

	sm_cInputHand.SetBigBlind(strUnreadLine, iBigBlind);
	sm_itterLastNicks = Find(strUnreadLine);
	CParseState* pNewState = new CPSStarsGetBigBlind(m_cParseFile);
	delete this;
	return pNewState;
}
