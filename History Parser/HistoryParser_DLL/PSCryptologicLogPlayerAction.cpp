// PSCryptologicLogPlayerAction.cpp: implementation of the CPSCryptologicLogPlayerAction class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PSCryptologicLogPlayerAction.h"
#include "CryptologicLogNone.h"
#include "PSCryptologicLogSummary.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPSCryptologicLogPlayerAction::CPSCryptologicLogPlayerAction(CParseFile* cPF)
: CPSCryptologicLog(cPF)
{

}

CPSCryptologicLogPlayerAction::~CPSCryptologicLogPlayerAction()
{

}

CParseState* CPSCryptologicLogPlayerAction::ParseI(const CString &strInLine, const CString &strFullLine)
{
	CString strUnreadLine = strInLine;

	if (IsNextWord("Game #", strUnreadLine))
	{
		CParseState* pNextState = new  CPSCryptologicLogSummary(m_cParseFile);
		return ChangeState(pNextState,  strFullLine);
	} 

	/*if (IsNextWord("Dealing Flop:", strUnreadLine))
	{
		ParseFlopDeal(strUnreadLine);;
		return this;	
	} 
	else if (IsNextWord("Dealing Turn:", strUnreadLine))
	{
		ParseFlopDeal(strUnreadLine);;
		return this;	
	}
	else if (IsNextWord("Dealing River:", strUnreadLine))
	{
		ParseFlopDeal(strUnreadLine);;
		return this;	
	}
	else if (IsNextWord("Game ", strUnreadLine))
	{
		CString strGameNumber;
		strGameNumber.Format("Hand %s", sm_cInputHand.GetGameNumber());
		if (IsNextWord(strGameNumber, strUnreadLine))
		{
			CParseState* pNextState = new  CPSCryptologicLogSummary(m_cParseFile);
			return ChangeState(pNextState,  strFullLine);
		}
	} */


	CString strNick = ReadNick(strUnreadLine);
	PPlayerAction cAction;
	CString strAction = GetNextWord(strUnreadLine);
	
	cAction =  PPlayerAction(strAction);
	if (cAction == PPlayerAction(PPlayerAction::ACTION_NONE))
	{
		return new CPSCryptologicLogSummary(m_cParseFile);
		//return this;
	}

	if (!strNick.IsEmpty())
	{
		int iAmount = 0;
		strUnreadLine.TrimLeft(' ');
		if (!strUnreadLine.IsEmpty())
		{
			try
			{
				strUnreadLine = strUnreadLine.Right(strUnreadLine.GetLength() - 1);
				iAmount = GetNextNumber(strUnreadLine);
			}
			catch(CParsingException* pExc)
			{
				delete pExc;
			}
		}				 
		if (GetCryptologicLogFile()->IsNextRound(strNick))
		{
			SetToNextRound();
		}
		GetCryptologicLogFile()->ProcessAction(cAction,  strNick);
		sm_cInputHand.AddPlayerAction(strNick, cAction, iAmount);
	}

	return this;
}




