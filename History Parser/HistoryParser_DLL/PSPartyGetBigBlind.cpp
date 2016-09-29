// PSPartyGetBigBlind.cpp: implementation of the CPSPartyGetBigBlind class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PSPartyGetBigBlind.h"

#include "PSPartyDealing.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPSPartyGetBigBlind::CPSPartyGetBigBlind(CParseFile* pPF)
: CParseState(pPF)
{

}

CPSPartyGetBigBlind::~CPSPartyGetBigBlind()
{

}

CParseState* CPSPartyGetBigBlind::Parse(const CString &strInLine)
{
	CString strUnreadLine = strInLine;

	if (IsNextWord("** Dealing down cards **", strUnreadLine))
	{
		return ChangeState(new CPSPartyDealing(m_cParseFile), strInLine);
	}

	if (PartyIgnoreLine(strInLine))
	{
		return this;
	}

	ReverseReadText(CHAR_CLOSE_BRACKET, strUnreadLine);
	int iBigBlind = ReverseGetNextNumber(strUnreadLine);
	ReverseReadText(CHAR_OPEN_BRACKET, strUnreadLine);
	if (IsLastWord("dead", strUnreadLine))
	{
		ReverseReadText("dead", strUnreadLine);
		ReverseReadText("+", strUnreadLine);
	}
	ReverseReadText(WORD_blind, strUnreadLine);
	ReverseReadText(WORD_big, strUnreadLine);
	ReverseReadText(WORD_posts, strUnreadLine);

	strUnreadLine.TrimLeft(' ');
	strUnreadLine.TrimRight(' ');

	sm_cInputHand.SetBigBlind(strUnreadLine, iBigBlind);
	sm_itterLastNicks = Find(strUnreadLine);
	CParseState* pNewState = new CPSPartyGetBigBlind(m_cParseFile);
	delete this;
	return pNewState;
}
