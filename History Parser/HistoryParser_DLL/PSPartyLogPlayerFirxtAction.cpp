// PSPartyLogPlayerFirxtAction.cpp: implementation of the CPSPartyLogPlayerFirxtAction class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "HistoryParser_DLL.h"
#include "PSPartyLogPlayerFirxtAction.h"
#include "PSPartyLogPlayerAction.h"
#include "PSPartyLogDealing.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPSPartyLogPlayerFirstAction::CPSPartyLogPlayerFirstAction(CParseFile* cPF)
: CPSPartyLog(cPF)
{

}

CPSPartyLogPlayerFirstAction::~CPSPartyLogPlayerFirstAction()
{

}

CParseState* CPSPartyLogPlayerFirstAction::ParseI(const CString &strInLine, const CString &strFullLine)
{
	CString strUnreadLine = strInLine;

	if (strInLine.Left(strlen("** Dealing")) == "** Dealing")
	{
		return ChangeState(new CPSPartyLogDealing(m_cParseFile), strFullLine);
	}

	int iAmount = 0;
	ReverseReadIfNextWord('.', strUnreadLine);
	if (ReverseReadIfNextWord(']', strUnreadLine))
	{
		iAmount = ReverseGetNextNumber(strUnreadLine);
		ReverseReadText(CHAR_DOLLAR, strUnreadLine);
		ReverseReadText('[', strUnreadLine);
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
		return  new CPSPartyLogPlayerAction(m_cParseFile);
	}
	else
	{
		if (cAction != PPlayerAction(PPlayerAction::ACTION_POST))
		{
			sm_listNicks.push_back(strUnreadLine);
			sm_cInputHand.AddPlayer(0, strUnreadLine, 0);
		}
		sm_cInputHand.AddPlayerAction(strUnreadLine, cAction, iAmount);
		return this;
	}
}

