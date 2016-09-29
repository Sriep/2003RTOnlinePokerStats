// PSTrueLogPlayerFirxtAction.cpp: implementation of the CPSTrueLogPlayerFirxtAction class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "HistoryParser_DLL.h"
#include "PSTrueLogPlayerFirxtAction.h"
#include "PSTrueLogPlayerAction.h"
#include "PSTrueLogDealing.h"
#include "PSTrueLogPlayerCards.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPSTrueLogPlayerFirstAction::CPSTrueLogPlayerFirstAction(CParseFile* cPF)
: CPSTrueLog(cPF)
{

}

CPSTrueLogPlayerFirstAction::~CPSTrueLogPlayerFirstAction()
{

}

CParseState* CPSTrueLogPlayerFirstAction::ParseI(const CString &strInLine, const CString &strFullLine)
{
	CString strUnreadLine = strInLine;

	if (IsNextWord("Dealer deals you", strUnreadLine))
	{
		return ChangeState(new CPSTrueLogPlayerCards(m_cParseFile), strFullLine);
	}

	int iAmount = 0;
	strUnreadLine.TrimRight(' ');
	if (IsNumber(strUnreadLine[strUnreadLine.GetLength() - 1])) 
	{
		iAmount = ReverseGetNextNumber(strUnreadLine);
	}

	PPlayerAction cAction;
	if (ReverseReadIfNextWord("has timed out and will now be folded", strUnreadLine))
	{
		cAction = PPlayerAction(PPlayerAction::ACTION_FOLD);	
	}
	else if (ReverseReadIfNextWord("has timed out and will be treated as all-in", strUnreadLine))
	{												
		cAction = PPlayerAction(PPlayerAction::ACTION_FOLD);	
	}
	else
	{
		CString strAction = ReverseGetNextWord(strUnreadLine);
		cAction =  PPlayerAction(strAction);
		if (cAction == PPlayerAction(PPlayerAction::ACTION_NONE))
		{
			ASSERT(FALSE);
			throw(new CParsingException("Ture poker, player first action not found"));
		}
		ReverseReadIfNextWord("goes all in,", strUnreadLine);
	}


	if (cAction != PPlayerAction(PPlayerAction::ACTION_POST))
	{
		strUnreadLine.TrimLeft(' ');
		strUnreadLine.TrimRight(' ');
		if (IsNickInNickList(strUnreadLine))
		{
			//if (sm_listNicks.size() < MIN_NUMBER_OF_PLAYERS)
			//{
			//	throw(new CParsingException(IDS_NOT_ENOUGH_PLAYERS));
			//}
			sm_cInputHand.AddPlayerAction(strUnreadLine, cAction, iAmount);
			return  new CPSTrueLogPlayerAction(m_cParseFile);
		}
		else
		{
			sm_cInputHand.AddPlayer(0, strUnreadLine, 0);
			sm_listNicks.push_back(strUnreadLine);
			sm_cInputHand.AddPlayerAction(strUnreadLine, cAction, iAmount);
			return this;
		}
	}
	else
	{
		sm_cInputHand.AddPlayerAction(strUnreadLine, cAction, iAmount);
		return this;
	}
}

