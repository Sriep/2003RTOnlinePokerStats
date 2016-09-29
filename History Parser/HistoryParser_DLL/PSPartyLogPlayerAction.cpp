// PSPartyLogPlayerAction.cpp: implementation of the CPSPartyLogPlayerAction class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "HistoryParser_DLL.h"
#include "PSPartyLogPlayerAction.h"
#include "PSPartyLogDealing.h"
#include "PartyLogNone.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPSPartyLogPlayerAction::CPSPartyLogPlayerAction(CParseFile* cPF)
: CPSPartyLog(cPF)
{

}

CPSPartyLogPlayerAction::~CPSPartyLogPlayerAction()
{

}

CParseState* CPSPartyLogPlayerAction::ParseI(const CString &strInLine, const CString &strFullLine)
{
	CString strUnreadLine = strInLine;

	if (strInLine.Left(strlen("** Dealing")) == "** Dealing")
	{
		return ChangeState(new CPSPartyLogDealing(m_cParseFile), strFullLine);
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
		}
		sm_cInputHand.AddPlayerAction(strNick, cAction, iAmount);
	}

	return this;
}




