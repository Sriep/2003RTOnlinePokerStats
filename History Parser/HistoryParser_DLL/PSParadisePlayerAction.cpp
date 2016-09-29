// PSParadisePlayerAction.cpp: implementation of the CPSParadisePlayerAction class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PSParadisePlayerAction.h"

#include "PPlayerAction.h"
#include "PSParadiseSumary1.h"
#include "PSParadiseDealing.h"
#include "ParsingException.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPSParadisePlayerAction::CPSParadisePlayerAction(CParseFile* pPF)
: CParseState(pPF)
{

}

CPSParadisePlayerAction::~CPSParadisePlayerAction()
{

}

CParseState* CPSParadisePlayerAction::Parse(const CString &strInLine)
{
	if (IsSummary(strInLine))
	{
		CParseState* pNewState = new CPSParadiseSumary1(m_cParseFile);
		delete this;
		return pNewState;
	}

	if (IsDealingNewCards(strInLine))
	{
		return ChangeState(new CPSParadiseDealing(m_cParseFile), strInLine);
	}

	if (ParadiseIgnoreLine(strInLine))
	{
		return this;
	}

	CString strUnreadLine = strInLine;
	PPlayerAction cAction;

	CString strNick = ReadLongNick(strUnreadLine);

	if (!strNick.IsEmpty())
	{
		if (IsNextWord("said", strUnreadLine))
		{
			return this;
		}

		ReadText(":", strUnreadLine);
		CString strAction = GetNextWord(strUnreadLine);
		cAction =  PPlayerAction(strAction);

		int iAmount = 0;
		if (IsNextWord("(", strUnreadLine))
		{
			ReadText("(", strUnreadLine);
			if (IsNextWord("$", strUnreadLine))
			{
				try
				{
					iAmount = ReadAmount(strUnreadLine);
				}
				catch(CParsingException* pExc)
				{
					delete pExc;
				}
			}
		}
		sm_cInputHand.AddPlayerAction(strNick, cAction, iAmount);
	}

	return this;
}

bool CPSParadisePlayerAction::IsSummary(const CString &strInLine)
{
	return strInLine == "*** SUMMARY ***";
}

bool CPSParadisePlayerAction::IsDealingNewCards(const CString &strInLine)
{
  	const CString strFlop = "*** FLOP *** : [";
	const int FLOP_LEN = 16;
  	const CString strTurn = "*** TURN *** : [";
	const int TURN_LEN = 16;
  	const CString strRiver ="*** RIVER *** : [";
	const int RIVER_LEN = 17;
	return strInLine.Left(FLOP_LEN) == strFlop
		|| strInLine.Left(TURN_LEN) == strTurn
		|| strInLine.Left(RIVER_LEN) == strRiver;
}

int CPSParadisePlayerAction::ReadAmount(CString& strUnreadLine)
{
	ReadText("$", strUnreadLine);
	return GetNextNumber(strUnreadLine);
}







