// PSPartyPlayerAction.cpp: implementation of the CPSPartyPlayerAction class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PSPartyPlayerAction.h"

#include "PPlayerAction.h"
#include "PSPartySumary1.h"
#include "PSPartyDealing.h"
#include "ParsingException.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPSPartyPlayerAction::CPSPartyPlayerAction(CParseFile* pPF)
: CParseState(pPF)
{

}

CPSPartyPlayerAction::~CPSPartyPlayerAction()
{

}

CParseState* CPSPartyPlayerAction::Parse(const CString &strInLine)
{
	CString strUnreadLine = strInLine;
	strUnreadLine.TrimLeft(' ');
	strUnreadLine.TrimRight(' ');
	if (IsSummary(strUnreadLine))
	{
		CParseState* pNewState = new CPSPartySumary1(m_cParseFile);
		delete this;
		return pNewState;
	}

	if (IsDealingNewCards(strUnreadLine))
	{
		return ChangeState(new CPSPartyDealing(m_cParseFile), strInLine);
	}

	
	CString strNick = ReadNick(strUnreadLine);
	PPlayerAction cAction;
	CString strAction = GetNextWord(strUnreadLine);
	cAction =  PPlayerAction(strAction);

	if (!strNick.IsEmpty())
	{
		int iAmount = 0;
		strUnreadLine.TrimLeft(' ');
		if (!strUnreadLine.IsEmpty())
		{
			if (strUnreadLine.GetAt(0) == '(')
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

bool CPSPartyPlayerAction::IsSummary(const CString &strInLine)
{						 
	return strInLine == "** Summary **";
}

bool CPSPartyPlayerAction::IsDealingNewCards(const CString &strInLine)
{
  	CString strDealing = "** Dealing";
	return strInLine.Left(strDealing.GetLength()) == strDealing;
}

int CPSPartyPlayerAction::ReadAmount(CString& strUnreadLine)
{
	ReadText(CHAR_OPEN_BRACKET, strUnreadLine);
	int iAmount = GetNextNumber(strUnreadLine);
	ReadText(CHAR_CLOSE_BRACKET, strUnreadLine);
	return iAmount;
}



