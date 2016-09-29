// PSWSEXLogPlayerAction.cpp: implementation of the CPSWSEXLogPlayerAction class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PSWSEXLogPlayerAction.h"
#include "PSWSEXLogDealing.h"
#include "WSEXLogNone.h"
#include "PSWSEXLogSummary.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPSWSEXLogPlayerAction::CPSWSEXLogPlayerAction(CParseFile* cPF)
: CPSWSEXLog(cPF)
{

}

CPSWSEXLogPlayerAction::~CPSWSEXLogPlayerAction()
{

}

CParseState* CPSWSEXLogPlayerAction::ParseI(const CString &strInLine, const CString &strFullLine)
{
	CString strUnreadLine = strInLine;

	if (strInLine == "DEALING FLOP")
	{
		sm_cInputHand.SetFlop();
		return this;	
	} 
	else if (strInLine == "DEALING TURN")
	{
		sm_cInputHand.SetTurn();
		return this;	
	}
	else if (strInLine == "DEALING RIVER")
	{
		sm_cInputHand.SetRiver();
		return this;	
	}
	else if (IsNextWord("Hand ", strUnreadLine))
	{
		CString strGameNumber;
		strGameNumber.Format("Hand %s", sm_cInputHand.GetGameNumber());
		if (IsNextWord(strGameNumber, strUnreadLine))
		{
			CParseState* pNextState = new  CPWSEXLogSummary(m_cParseFile);
			return ChangeState(pNextState,  strFullLine);
		}
	} 


	CString strNick = ReadNick(strUnreadLine);
	PPlayerAction cAction;
	CString strAction = GetNextWord(strUnreadLine);
	
	cAction =  PPlayerAction(strAction);
	if (cAction == PPlayerAction(PPlayerAction::ACTION_NONE))
	{
		return this;
	}

	if (!strNick.IsEmpty())
	{
		int iAmount = 0;
		strUnreadLine.TrimLeft(' ');
		if (!strUnreadLine.IsEmpty())
		{
			try
			{
				ReadText('$', strUnreadLine);
				iAmount = GetNextNumber(strUnreadLine);
			}
			catch(CParsingException* pExc)
			{
				delete pExc;
			}
		}
		sm_cInputHand.AddPlayerAction(strNick, cAction, iAmount);
	}

	return this;
}




