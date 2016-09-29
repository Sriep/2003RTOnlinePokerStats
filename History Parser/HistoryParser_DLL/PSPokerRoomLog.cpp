// PSPokerRoomLog.cpp: implementation of the CPSPokerRoomLog class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "HistoryParser_DLL.h"
#include "PSPokerRoomLog.h"
#include "PSPokerRoomLogResult.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPSPokerRoomLog::CPSPokerRoomLog(CParseFile* pPF)
: CParseState(pPF)
{

}

CPSPokerRoomLog::~CPSPokerRoomLog()
{

}

CParseState* CPSPokerRoomLog::Parse(const CString &strInLine)
{
	CParseState* pNextState = NULL;
	CString strUnreadLine = strInLine;
	//strUnreadLine.TrimRight('\x0D');

	strUnreadLine.TrimRight(' ');

	if (PokerRoomLogIgnoreLine(strUnreadLine))
	{
		TRACE("Ignoring line %s\n", strInLine);
		return this;
	}

	if (IsNextWord("Hand #", strUnreadLine))
	{
		return this;
	}
	/*
	if (strUnreadLine.Left(strlen("** DEALING")) == "** DEALING")
	{
		if(strUnreadLine.Left(strlen("** DEALING FLOP **")) == "** DEALING FLOP **")
		{
			sm_cInputHand.SetFlop();
		}
		else  if(strUnreadLine.Left(strlen("** DEALING TURN **")) == "** DEALING TURN **")
		{
			sm_cInputHand.SetTurn();
		}
		else  if(strUnreadLine.Left(strlen("** DEALING RIVER **")) == "** DEALING RIVER **")
		{
			sm_cInputHand.SetRiver();
		}
		return this;
	} */

	//strUnreadLine.TrimLeft(' ');
	//strUnreadLine.TrimRight('\x0D');
	
	pNextState = ParseI(strUnreadLine, strInLine);
	if (this != (CPSPokerRoomLog*) pNextState)
	{
		delete this;
	}
	return pNextState;
}



