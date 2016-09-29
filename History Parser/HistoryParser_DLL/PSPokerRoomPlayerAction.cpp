// PSPokerRoomLogPlayerAction.cpp: implementation of the CPSPokerRoomLogPlayerAction class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "HistoryParser_DLL.h"
#include "PSPokerRoomLogPlayerAction.h"
#include "PSPokerRoomLogDealing.h"
#include "PSPokerRoomLogResult.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPSPokerRoomLogPlayerAction::CPSPokerRoomLogPlayerAction(CParseFile* cPF)
: CPSPokerRoomLog(cPF)
{

}

CPSPokerRoomLogPlayerAction::~CPSPokerRoomLogPlayerAction()
{

}

CParseState* CPSPokerRoomLogPlayerAction::ParseI(const CString &strInLine, const CString &strFullLine)
{
	CString strUnreadLine = strInLine;


	if ((strInLine == "The Flop") || (strInLine == "The Turn") || (strInLine == "The River"))
	{
		return new CPSPokerRoomLogDealing(m_cParseFile);
	}
	
	CString strNick = ReadLongNick(strUnreadLine);
	if (strNick.IsEmpty())
		throw(new CParsingException(IDS_NICK_NOT_FOUND));

	PPlayerAction cAction;
	CString strAction = GetNextWord(strUnreadLine);

	int iAmount = 0;
	if (ReadIfNextWord("$", strUnreadLine) )
	{
		iAmount = GetNextNumber(strUnreadLine);
	}
	
	if (strAction == "wins")
	{
		sm_cInputHand.SetPlayerProfitLoss(strNick, iAmount);
		return  new CPSPokerRoomLogResult(m_cParseFile);
	}
	
	cAction =  PPlayerAction(strAction);
	if (cAction == PPlayerAction(PPlayerAction::ACTION_NONE))
	{
		return this;
	}
	sm_cInputHand.AddPlayerAction(strNick, cAction, iAmount);

	return this;
}




