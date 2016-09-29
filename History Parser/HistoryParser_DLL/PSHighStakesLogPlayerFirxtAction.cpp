// PSHighStakesLogPlayerFirxtAction.cpp: implementation of the CPSHighStakesLogPlayerFirxtAction class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "HistoryParser_DLL.h"
#include "PSHighStakesLogPlayerFirxtAction.h"
#include "PSHighStakesLogPlayerAction.h"
#include "PSHighStakesLogDealing.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPSHighStakesLogPlayerFirstAction::CPSHighStakesLogPlayerFirstAction(CParseFile* cPF)
: CPSHighStakesLog(cPF)
{

}

CPSHighStakesLogPlayerFirstAction::~CPSHighStakesLogPlayerFirstAction()
{

}

CParseState* CPSHighStakesLogPlayerFirstAction::ParseI(const CString &strInLine, const CString &strFullLine)
{
	CString strUnreadLine = strInLine;

	int iAmount = 0;
	if (IsNumber(strUnreadLine[strUnreadLine.GetLength() - 1]))
	{
		iAmount = ReverseGetNextNumber(strUnreadLine);
		ReverseReadText("$", strUnreadLine);
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

	if (strUnreadLine != "and" && ReverseReadIfNextWord("and", strUnreadLine))
	{
		ReverseGetNextNumber(strUnreadLine);
		ReverseReadText(" called $", strUnreadLine);	 
	}


	if (IsNickInNickList(strUnreadLine))
	{
		if (sm_listNicks.size() < MIN_NUMBER_OF_PLAYERS)
		{
			throw(new CParsingException(IDS_NOT_ENOUGH_PLAYERS));
		}
		sm_cInputHand.AddPlayerAction(strUnreadLine, cAction, iAmount);
		return  new CPSHighStakesLogPlayerAction(m_cParseFile);
	}
	else
	{
		sm_cInputHand.AddPlayer(0, strUnreadLine, 0);
		sm_listNicks.push_back(strUnreadLine);
		sm_cInputHand.AddPlayerAction(strUnreadLine, cAction, iAmount);
		return this;
	}
}

