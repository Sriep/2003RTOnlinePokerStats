// PSRoyalVegasLogPlayerAction.cpp: implementation of the CPSRoyalVegasLogPlayerAction class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "HistoryParser_DLL.h"
#include "PSRoyalVegasLogPlayerAction.h"
#include "PSRoyalVegasLogDealing.h"
#include "RoyalVegasLogNone.h"
#include "PSRoyalVegasLogSummary.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPSRoyalVegasLogPlayerAction::CPSRoyalVegasLogPlayerAction(CParseFile* cPF)
: CPSRoyalVegasLog(cPF)
{

}

CPSRoyalVegasLogPlayerAction::~CPSRoyalVegasLogPlayerAction()
{

}

CParseState* CPSRoyalVegasLogPlayerAction::ParseI(const CString &strInLine, const CString &strFullLine)
{
	CString strUnreadLine = strInLine;

	if (strInLine.Left(strlen("Dealing the")) == "Dealing the")
	{
		return ChangeState(new CPSRoyalVegasLogDealing(m_cParseFile), strFullLine);
	}

	CString strNick = ReadNick(strUnreadLine);
	PPlayerAction cAction;
	CString strAction = GetNextWord(strUnreadLine);
	if (!strNick.IsEmpty())
	{

		cAction =  PPlayerAction(strAction);
		if (cAction == PPlayerAction(PPlayerAction::ACTION_NONE))
		{
			if (IsSummaryLine(strAction))
			{
				return ChangeState(new CPSRoyalVegasLogSummary(m_cParseFile, strNick, strAction, strUnreadLine), strFullLine);
			}
			return this;
		}

		int iAmount = 0;
		strUnreadLine.TrimLeft(' ');
		if (!strUnreadLine.IsEmpty())
		{
			ReadText("for", strUnreadLine);
			ReadText('$', strUnreadLine);
			iAmount = GetNextNumber(strUnreadLine);
		}
		sm_cInputHand.AddPlayerAction(strNick, cAction, iAmount);
	}

	return this;
}




