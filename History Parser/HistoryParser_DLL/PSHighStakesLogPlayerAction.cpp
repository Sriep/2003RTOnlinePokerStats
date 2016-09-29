// PSHighStakesLogPlayerAction.cpp: implementation of the CPSHighStakesLogPlayerAction class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "HistoryParser_DLL.h"
#include "PSHighStakesLogPlayerAction.h"
#include "PSHighStakesLogDealing.h"
#include "HighStakesLogNone.h"
#include "PSHighStakesLogSummary.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPSHighStakesLogPlayerAction::CPSHighStakesLogPlayerAction(CParseFile* cPF)
: CPSHighStakesLog(cPF)
{

}

CPSHighStakesLogPlayerAction::~CPSHighStakesLogPlayerAction()
{

}

CParseState* CPSHighStakesLogPlayerAction::ParseI(const CString &strInLine, const CString &strFullLine)
{
	if (strInLine == "Showdown!")
	{
		return new CPSHighStakesLogSummary(m_cParseFile);
	}
	
	CString strUnreadLine = strInLine;
	if (strInLine.Left(strlen("Dealing ")) == "Dealing ")
	{
		return ChangeState(new CPSHighStakesLogDealing(m_cParseFile), strFullLine);
	}

	CString strNick = ReadLongNick(strUnreadLine);
	PPlayerAction cAction;
	CString strAction = GetNextWord(strUnreadLine);
	if (!strNick.IsEmpty())
	{

		cAction =  PPlayerAction(strAction);
		if (cAction == PPlayerAction(PPlayerAction::ACTION_NONE))
		{
			if (IsSummaryLine(strAction))
			{
				return ChangeState(new CPSHighStakesLogSummary(m_cParseFile, strNick, strAction, strUnreadLine), strFullLine);
			}
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

		int iAmount = 0;
		strUnreadLine.TrimLeft(' ');
		if (!strUnreadLine.IsEmpty())
		{
			ReadText('$', strUnreadLine);
			iAmount = GetNextNumber(strUnreadLine);
			if (ReadIfNextWord("and raised $", strUnreadLine))
			{
				iAmount = GetNextNumber(strUnreadLine);
				cAction = PPlayerAction(PPlayerAction::ACTION_RAISE);
			}
		}
		sm_cInputHand.AddPlayerAction(strNick, cAction, iAmount);
	}

	return this;
}




