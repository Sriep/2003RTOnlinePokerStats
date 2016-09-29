// PSCryptologicLogPlayerFirxtAction.cpp: implementation of the CPSCryptologicLogPlayerFirxtAction class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
//#include "HistoryParser_DLL.h"
#include "PSCryptologicLogPlayerFirxtAction.h"
#include "PSCryptologicLogPlayerAction.h"
#include "PSCryptologicLogAllFold.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPSCryptologicLogPlayerFirstAction::CPSCryptologicLogPlayerFirstAction(CParseFile* cPF)
: CPSCryptologicLog(cPF)
{

}

CPSCryptologicLogPlayerFirstAction::~CPSCryptologicLogPlayerFirstAction()
{

}

CParseState* CPSCryptologicLogPlayerFirstAction::ParseI(const CString &strInLine, const CString &strFullLine)
{
	CString strUnreadLine = strInLine;

	int iAmount = 0;
	if (IsNumber(strUnreadLine[strUnreadLine.GetLength() - 1]))
	{
		iAmount = ReverseGetNextNumber(strUnreadLine);
		strUnreadLine = strUnreadLine.Left(strUnreadLine.GetLength() - 1);
	}

	
	bool bPost = ReverseReadIfNextWord("big blind", strUnreadLine);

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
		if (sm_listNicks.size() < MIN_NUMBER_OF_PLAYERS)
		{
			throw(new CParsingException(IDS_NOT_ENOUGH_PLAYERS));
		}
		if (GetCryptologicLogFile()->IsNextRound(strUnreadLine))
		{
			SetToNextRound();
		}
		GetCryptologicLogFile()->ProcessAction(cAction,  strUnreadLine);
		sm_cInputHand.AddPlayerAction(strUnreadLine, cAction, iAmount);
		return  new CPSCryptologicLogPlayerAction(m_cParseFile);
	}
	else
	{
		sm_cInputHand.AddPlayer(0, strUnreadLine, 0);
		//if (GetCryptologicLogFile()->IsNextRound(strUnreadLine))
		//{
		//	SetToNextRound();
		//}	
		if (!bPost)
		{
			sm_listNicks.push_back(strUnreadLine);
			GetCryptologicLogFile()->ProcessAction(cAction,  strUnreadLine);
		}
		sm_cInputHand.AddPlayerAction(strUnreadLine, cAction, iAmount);
		return this;
	}
}

