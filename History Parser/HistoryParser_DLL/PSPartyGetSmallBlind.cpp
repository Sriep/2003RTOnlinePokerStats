// PSPartyGetSmallBlind.cpp: implementation of the CPSPartyGetSmallBlind class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PSPartyGetSmallBlind.h"

#include "PSPartyGetBigBlind.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPSPartyGetSmallBlind::CPSPartyGetSmallBlind(CParseFile* pPF)
: CParseState(pPF)
{

}

CPSPartyGetSmallBlind::~CPSPartyGetSmallBlind()
{

}

CParseState* CPSPartyGetSmallBlind::Parse(const CString &strInLine)
{
	if (PartyIgnoreLine(strInLine))
	{
		return this;
	}
	
	CString strUnreadLine = strInLine;

	ReverseReadText(CHAR_CLOSE_BRACKET, strUnreadLine);
	int iSmallBlind = ReverseGetNextNumber(strUnreadLine);
	ReverseReadText(CHAR_OPEN_BRACKET, strUnreadLine);
	ReverseReadText(WORD_blind, strUnreadLine);
	ReverseReadText(WORD_small, strUnreadLine);
	ReverseReadText(WORD_posts, strUnreadLine);

	strUnreadLine.TrimLeft(' ');
	strUnreadLine.TrimRight(' ');

	sm_cInputHand.SetSmallBlind(strUnreadLine, iSmallBlind);
	sm_itterLastNicks = Find(strUnreadLine);
	CParseState* pNewState = new CPSPartyGetBigBlind(m_cParseFile);
	delete this;
	return pNewState;
}
