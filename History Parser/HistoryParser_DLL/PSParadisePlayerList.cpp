// PSParadisePlayerList.cpp: implementation of the CPSParadisePlayerList class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PSParadisePlayerList.h"

#include "PSParadiseGetSmallBlind.h"
#include "ParsingException.h"
#include "PSNone.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPSParadisePlayerList::CPSParadisePlayerList(CParseFile* pPF)
: CParseState(pPF)
{

}

CPSParadisePlayerList::~CPSParadisePlayerList()
{

}

CParseState* CPSParadisePlayerList::Parse(const CString &strInLine)
{
	if (strInLine == "*** SUMMARY ***")
	{
		throw(new CParsingException(IDS_NOTHING_GAME, this, new CPSNone(m_cParseFile)));
	}
	
	if (!IsNextWord(WORD_Seat, strInLine))
	{
		if (strInLine.Find(": Post Small Blind ($") != -1)
		{
			return ChangeState(new CPSParadiseGetSmallBlind(m_cParseFile), strInLine);
		}
		else
		{
			return this;
		}
	}
	
	CString strUnreadLine = strInLine;

	ReadText(WORD_Seat, strUnreadLine);
	int iSeatPosition = GetNextNumber(strUnreadLine);
	ReadText(CHAR_COLON, strUnreadLine);

	ReverseReadText(CHAR_CLOSE_BRACKET, strUnreadLine);
	ReverseReadText("chips", strUnreadLine);
	ReverseReadText("in", strUnreadLine);
	int iMoney = ReverseGetNextNumber(strUnreadLine);
	ReverseReadText(CHAR_DOLLAR, strUnreadLine);
	ReverseReadText(CHAR_OPEN_BRACKET, strUnreadLine);

	strUnreadLine.TrimLeft(' ');
	strUnreadLine.TrimRight(' ');

	sm_cInputHand.AddPlayer(iSeatPosition, strUnreadLine, iMoney);
	sm_listNicks.push_back(strUnreadLine);

	return this;
}

