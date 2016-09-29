// PSPokerRoomLogPlayerFirxtAction.cpp: implementation of the CPSPokerRoomLogPlayerFirxtAction class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "HistoryParser_DLL.h"
#include "PSPokerRoomLogPlayerFirxtAction.h"
#include "PSPokerRoomLogPlayerAction.h"
#include "PSPokerRoomLogSmallBlind.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPSPokerRoomLogPlayerFirstAction::CPSPokerRoomLogPlayerFirstAction(CParseFile* cPF)
: CPSPokerRoomLog(cPF)
{

}

CPSPokerRoomLogPlayerFirstAction::~CPSPokerRoomLogPlayerFirstAction()
{

}

CParseState* CPSPokerRoomLogPlayerFirstAction::ParseI(const CString &strInLine, const CString &strFullLine)
{
	CString strUnreadLine = strInLine;	
	
	int iAmount = 0;
	ReverseReadIfNextWord(".", strUnreadLine);
	if (ReverseReadIfNextWord("blind", strUnreadLine))
	{
		CParseState* pNewState = new  CPSPokerRoomLogSmallBlind(m_cParseFile);
		return ChangeState(pNewState,  strInLine);
	}

	if (IsNumber(strUnreadLine.GetAt(strUnreadLine.GetLength()-1)))
	{
		iAmount = ReverseGetNextNumber(strUnreadLine);
		ReverseReadText("$", strUnreadLine);
	}
	
	PPlayerAction cAction;
	CString strAction = ReverseGetNextWord(strUnreadLine);
	cAction =  PPlayerAction(strAction);
	if (cAction == PPlayerAction(PPlayerAction::ACTION_NONE))
	{
		return this;
	}

	strUnreadLine.TrimLeft(' ');
	strUnreadLine.TrimRight(' ');


	if (IsNickInNickList(strUnreadLine))
	{
		if (sm_listNicks.size() < MIN_NUMBER_OF_PLAYERS)
		{
			throw(new CParsingException(IDS_NOT_ENOUGH_PLAYERS));
		}
		sm_cInputHand.AddPlayerAction(strUnreadLine, cAction, iAmount);
		return  new CPSPokerRoomLogPlayerAction(m_cParseFile);
	}
	else
	{
		if (cAction != PPlayerAction(PPlayerAction::ACTION_POST))
		{
			sm_listNicks.push_back(strUnreadLine);
		}
		sm_cInputHand.AddPlayer(0, strUnreadLine, 0);
		sm_cInputHand.AddPlayerAction(strUnreadLine, cAction, iAmount);
		return this;
	}
}

