// PSStarsGetSmallBlind.cpp: implementation of the CPSStarsGetSmallBlind class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PSStarsGetSmallBlind.h"

#include "PSStarsGetBigBlind.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPSStarsGetSmallBlind::CPSStarsGetSmallBlind(CParseFile* pPF)
: CParseState(pPF)
{

}

CPSStarsGetSmallBlind::~CPSStarsGetSmallBlind()
{

}

CParseState* CPSStarsGetSmallBlind::Parse(const CString &strInLine)
{
	CString strUnreadLine = strInLine;

	if (StarsIgnoreLine(strInLine))
	{
		return this;
	}

	int iSmallBlind = ReverseGetNextNumber(strUnreadLine);
	ReverseReadText("$", strUnreadLine);
	ReverseReadText(WORD_blind, strUnreadLine);
	ReverseReadText(WORD_small, strUnreadLine);
	ReverseReadText(WORD_posts, strUnreadLine);
	ReverseReadText(":", strUnreadLine);
	strUnreadLine.TrimLeft(' ');
	strUnreadLine.TrimRight(' ');

	sm_cInputHand.SetSmallBlind(strUnreadLine, iSmallBlind);
	sm_itterLastNicks = Find(strUnreadLine);
	CParseState* pNewState = new CPSStarsGetBigBlind(m_cParseFile);
	delete this;
	return pNewState;
}
