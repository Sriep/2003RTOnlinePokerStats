// PSUltimateBetLogPlayerFirxtAction.cpp: implementation of the CPSUltimateBetLogPlayerFirxtAction class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "HistoryParser_DLL.h"
#include "PSUltimateBetLogPlayerFirxtAction.h"
#include "PSUltimateBetLogPlayerAction.h"
#include "PSUltimateBetLogDealing.h"
#include "PSUltimateBetLogShowdown.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPSUltimateBetLogPlayerFirstAction::CPSUltimateBetLogPlayerFirstAction(CParseFile* cPF)
: CPSUltimateBetLog(cPF)
{

}

CPSUltimateBetLogPlayerFirstAction::~CPSUltimateBetLogPlayerFirstAction()
{

}

CParseState* CPSUltimateBetLogPlayerFirstAction::ParseI(const CString &strInLine, const CString &strFullLine)
{
	CString strUnreadLine = strInLine;

	if (strInLine.Left(strlen("Dealing")) == "Dealing")
	{
		return ChangeState(new CPSUltimateBetLogDealing(m_cParseFile), strFullLine);
	}

	if (strInLine == "It's time to show cards.")
	{
		return new CPSUltimateBetLogShowdown(m_cParseFile);
	}

	int iAmount = 0;
	ReverseReadIfNextWord(".", strUnreadLine);
	CString strNextNumber = ReverseSpanIncluding(strUnreadLine, "0123456789");
	if (!strNextNumber.IsEmpty())
	{
		iAmount = ReverseGetNextNumber(strUnreadLine);
		ReverseReadText(CHAR_DOLLAR, strUnreadLine);
		ReverseReadIfNextWord("to", strUnreadLine);
	}

	ReverseReadIfNextWord("a dead blind of", strUnreadLine);
	
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
		return  new CPSUltimateBetLogPlayerAction(m_cParseFile);
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

