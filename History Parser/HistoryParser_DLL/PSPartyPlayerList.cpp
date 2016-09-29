// PSPartyPlayerList.cpp: implementation of the CPSPartyPlayerList class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PSPartyPlayerList.h"

#include "PSPartyHeader3.h"
#include "PSPartyGetSmallBlind.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPSPartyPlayerList::CPSPartyPlayerList(CParseFile* pPF)
: CParseState(pPF)
{

}

CPSPartyPlayerList::~CPSPartyPlayerList()
{

}

CParseState* CPSPartyPlayerList::Parse(const CString &strInLine)
{
	if (!IsNextWord(WORD_Seat, strInLine))
	{
		return ChangeState(new CPSPartyGetSmallBlind(m_cParseFile), strInLine);
	}
	
	
	CString strUnreadLine = strInLine;

	ReadText(WORD_Seat, strUnreadLine);
	int iSeatPosition = GetNextNumber(strUnreadLine);
	ReadText(CHAR_COLON, strUnreadLine);

	ReverseReadText(CHAR_CLOSE_BRACKET, strUnreadLine);
	int iMoney = ReverseGetNextNumber(strUnreadLine);
	ReverseReadText(CHAR_DOLLAR, strUnreadLine);
	ReverseReadText(CHAR_OPEN_BRACKET, strUnreadLine);

	strUnreadLine.TrimLeft(' ');
	strUnreadLine.TrimRight(' ');

	sm_cInputHand.AddPlayer(iSeatPosition, strUnreadLine, iMoney);
	sm_listNicks.push_back(strUnreadLine);

	return this;
}

