// PSParadiseLogPlayerFirxtAction.cpp: implementation of the CPSParadiseLogPlayerFirxtAction class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "HistoryParser_DLL.h"
#include "PSParadiseLogPlayerFirxtAction.h"
#include "PSParadiseLogPlayerAction.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPSParadiseLogPlayerFirstAction::CPSParadiseLogPlayerFirstAction(CParseFile* cPF)
: CPSParadiseLog(cPF)
{

}

CPSParadiseLogPlayerFirstAction::~CPSParadiseLogPlayerFirstAction()
{

}

CParseState* CPSParadiseLogPlayerFirstAction::ParseI(const CString &strInLine, const CString &strFullLine)
{
	CString strUnreadLine = strInLine;

	if (strUnreadLine.Left(strlen("** DEALING")) == "** DEALING")
	{
		throw(new CParsingException(IDS_PARADISE_HAND_JUMBLED));;
	}
	
	PPlayerAction cAction;
	CString strAction = ReverseGetNextWord(strUnreadLine);
	cAction =  PPlayerAction(strAction);
	if (cAction == PPlayerAction(PPlayerAction::ACTION_NONE))
	{
		return this;
	}

	strUnreadLine.TrimLeft(' ');
	strUnreadLine.TrimRight(' ');


	if (IsNickInNickList(strUnreadLine))
	{
		if (sm_listNicks.size() < PARADISE_MIN_NUMBER_OF_PLAYERS)
		{
			throw(new CParsingException(IDS_NOT_ENOUGH_PLAYERS));
		}
		sm_cInputHand.AddPlayerAction(strUnreadLine, cAction, 0);
		return  new CPSParadiseLogPlayerAction(m_cParseFile);
	}
	else
	{
		if (cAction != PPlayerAction(PPlayerAction::ACTION_POST))
		{
			sm_listNicks.push_back(strUnreadLine);
		}
		sm_cInputHand.AddPlayer(0, strUnreadLine, 0);
		sm_cInputHand.AddPlayerAction(strUnreadLine, cAction, 0);
		return this;
	}
}

