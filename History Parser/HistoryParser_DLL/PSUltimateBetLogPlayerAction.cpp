// PSUltimateBetLogPlayerAction.cpp: implementation of the CPSUltimateBetLogPlayerAction class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "HistoryParser_DLL.h"
#include "PSUltimateBetLogPlayerAction.h"
#include "PSUltimateBetLogDealing.h"
#include "UltimateBetLogNone.h"
#include "PSUltimateBetLogShowdown.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPSUltimateBetLogPlayerAction::CPSUltimateBetLogPlayerAction(CParseFile* cPF)
: CPSUltimateBetLog(cPF)
{

}

CPSUltimateBetLogPlayerAction::~CPSUltimateBetLogPlayerAction()
{

}

CParseState* CPSUltimateBetLogPlayerAction::ParseI(const CString &strInLine, const CString &strFullLine)
{
	CString strUnreadLine = strInLine;

	if (strInLine.Left(strlen("Dealing")) == "Dealing")
	{
		return ChangeState(new CPSUltimateBetLogDealing(m_cParseFile), strFullLine);
	}

	if (strUnreadLine == "It's time to show cards.")
	{
		return new CPSUltimateBetLogShowdown(m_cParseFile);
	}
	if (ReadIfNextWord("#", strUnreadLine))
	{
		return ChangeState(new  CPSUltimateBetLogShowdown(m_cParseFile),  strFullLine);
	}

	CString strNick = ReadLongNick(strUnreadLine);
	PPlayerAction cAction;
	CString strAction = GetNextWord(strUnreadLine);
	
	cAction =  PPlayerAction(strAction);
	if (cAction == PPlayerAction(PPlayerAction::ACTION_NONE))
	{
		return this;
	}

	if (!strNick.IsEmpty())
	{	
		int iAmount = 0;  /*
		strUnreadLine.TrimLeft(' ');
		if (!strUnreadLine.IsEmpty())
		{
			if (strUnreadLine.GetAt(0) == '[')
			{
				try
				{
					ReadText('[', strUnreadLine);
					ReadText('$', strUnreadLine);
					iAmount = GetNextNumber(strUnreadLine);
				}
				catch(CParsingException* pExc)
				{
					delete pExc;
				}
			}
		} */
		sm_cInputHand.AddPlayerAction(strNick, cAction, iAmount);
	}

	return this;
}




