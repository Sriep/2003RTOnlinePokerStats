// PSStarsPlayerList.cpp: implementation of the CPSStarsPlayerList class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PSStarsPlayerList.h"

#include "PSStarsGetSmallBlind.h"
#include "ParsingException.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPSStarsPlayerList::CPSStarsPlayerList(CParseFile* pPF)
: CParseState(pPF)
{

}

CPSStarsPlayerList::~CPSStarsPlayerList()
{

}

CParseState* CPSStarsPlayerList::Parse(const CString &strInLine)
{
	if (!IsNextWord(WORD_Seat, strInLine))
	{
		if (strInLine.Find(": posts small blind $") != -1)
		{
			return ChangeState(new CPSStarsGetSmallBlind(m_cParseFile), strInLine);
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

