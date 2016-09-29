// PSParadiseLogPlayerAction.cpp: implementation of the CPSParadiseLogPlayerAction class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "HistoryParser_DLL.h"
#include "PSParadiseLogPlayerAction.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPSParadiseLogPlayerAction::CPSParadiseLogPlayerAction(CParseFile* cPF)
: CPSParadiseLog(cPF)
{

}

CPSParadiseLogPlayerAction::~CPSParadiseLogPlayerAction()
{

}

CParseState* CPSParadiseLogPlayerAction::ParseI(const CString &strInLine, const CString &strFullLine)
{
	CString strUnreadLine = strInLine;

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
	}
	
	CString strNick = ReadLongNick(strUnreadLine);
	if (strNick.IsEmpty())
		throw(new CParsingException(IDS_PARADISE_HAND_JUMBLED));;

	PPlayerAction cAction;
	CString strAction = GetNextWord(strUnreadLine);
	
	cAction =  PPlayerAction(strAction);
	if (cAction == PPlayerAction(PPlayerAction::ACTION_NONE))
	{
		return this;
	}
	sm_cInputHand.AddPlayerAction(strNick, cAction, 0);

	return this;
}




