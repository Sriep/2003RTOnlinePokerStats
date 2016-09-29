// PSRoyalVegasLogPlayerFirxtAction.cpp: implementation of the CPSRoyalVegasLogPlayerFirxtAction class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "HistoryParser_DLL.h"
#include "PSRoyalVegasLogPlayerFirxtAction.h"
#include "PSRoyalVegasLogPlayerAction.h"
#include "PSRoyalVegasLogDealing.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPSRoyalVegasLogPlayerFirstAction::CPSRoyalVegasLogPlayerFirstAction(CParseFile* cPF)
: CPSRoyalVegasLog(cPF)
{

}

CPSRoyalVegasLogPlayerFirstAction::~CPSRoyalVegasLogPlayerFirstAction()
{

}

CParseState* CPSRoyalVegasLogPlayerFirstAction::ParseI(const CString &strInLine, const CString &strFullLine)
{
	CString strUnreadLine = strInLine;

	int iAmount = 0;
	if (-1 != strUnreadLine.Find(" for $"))
	{
		iAmount = ReverseGetNextNumber(strUnreadLine);
		ReverseReadText("for $", strUnreadLine);
	}

	PPlayerAction cAction;
	CString strAction = ReverseGetNextWord(strUnreadLine);
	cAction =  PPlayerAction(strAction);
	if (cAction == PPlayerAction(PPlayerAction::ACTION_NONE))
	{
		if (strAction == "all-in")
		{
			ReverseReadText("went", strUnreadLine);
			cAction = PPlayerAction(PPlayerAction::ACTION_CALL);
		}
		else
		{
			return this;
		}
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
		return  new CPSRoyalVegasLogPlayerAction(m_cParseFile);
	}
	else
	{
		sm_cInputHand.AddPlayer(0, strUnreadLine, 0);
		sm_listNicks.push_back(strUnreadLine);
		sm_cInputHand.AddPlayerAction(strUnreadLine, cAction, iAmount);
		return this;
	}
}

