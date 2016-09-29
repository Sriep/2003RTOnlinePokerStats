// PSStarsPlayerAction.cpp: implementation of the CPSStarsPlayerAction class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PSStarsPlayerAction.h"

#include "PPlayerAction.h"
#include "PSStarsSumary1.h"
#include "PSStarsDealing.h"
#include "ParsingException.h"
#include "PSStarsShowDown.h"
#include "ParseState.inl"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPSStarsPlayerAction::CPSStarsPlayerAction(CParseFile* pPF)
: CParseState(pPF)
{

}

CPSStarsPlayerAction::~CPSStarsPlayerAction()
{

}

CParseState* CPSStarsPlayerAction::Parse(const CString &strInLine)
{
	if (IsSummary(strInLine))
	{
		CParseState* pNewState = new CPSStarsShowDown(m_cParseFile);
		delete this;
		return pNewState;
	}

	if (IsDealingNewCards(strInLine))
	{
		return ChangeState(new CPSStarsDealing(m_cParseFile), strInLine);
	}

	if (StarsIgnoreLine(strInLine))
	{
		return this;
	}

	CString strUnreadLine = strInLine;
	PPlayerAction cAction;

	CString strNick = ReadLongNick(strUnreadLine);

	if (IsNextWord("said,", strUnreadLine))
	{
		return this;
	}

	ReadText(":", strUnreadLine);
	CString strAction = GetNextWord(strUnreadLine);
	cAction =  PPlayerAction(strAction);

	if (!strNick.IsEmpty())
	{
		int iAmount = 0;
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
		sm_cInputHand.AddPlayerAction(strNick, cAction, iAmount);
	}

	return this;
}

bool CPSStarsPlayerAction::IsSummary(const CString &strInLine)
{
	return strInLine == "*** SHOW DOWN ***" || IsLastWord("from  pot", strInLine);
}

bool CPSStarsPlayerAction::IsDealingNewCards(const CString &strInLine)
{
  	const CString strFlop = "*** FLOP *** [";
	const int FLOP_LEN = 14;
  	const CString strTurn = "*** TURN *** [";
	const int TURN_LEN = 14;
  	const CString strRiver ="*** RIVER *** [";
	const int RIVER_LEN = 15;
	return strInLine.Left(FLOP_LEN) == strFlop
		|| strInLine.Left(TURN_LEN) == strTurn
		|| strInLine.Left(RIVER_LEN) == strRiver;
}

int CPSStarsPlayerAction::ReadAmount(CString& strUnreadLine)
{
	ReadText("$", strUnreadLine);
	return GetNextNumber(strUnreadLine);
}







