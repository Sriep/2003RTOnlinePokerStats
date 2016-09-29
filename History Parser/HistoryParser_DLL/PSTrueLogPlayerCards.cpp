// PSTrueLogBigBlind.cpp: implementation of the CPSTrueLogBigBlind class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "HistoryParser_DLL.h"
#include "PSTrueLogPlayerCards.h"
#include "PSTrueLogDealing.h"
#include "PSTrueLogPlayerFirxtAction.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPSTrueLogPlayerCards::CPSTrueLogPlayerCards(CParseFile* pPF)
: CPSTrueLog(pPF)
{


}

CPSTrueLogPlayerCards::~CPSTrueLogPlayerCards()
{

}

CParseState* CPSTrueLogPlayerCards::ParseI(const CString &strInLine, const CString &strFullLine)
{
	CString strUnreadLine = strInLine;

	if (ReadIfNextWord("Dealer deals you", strUnreadLine))
	{
		ReadText("[", strUnreadLine);
		PCard cFirstCard = ReadCard(strUnreadLine);
		ReadText(",", strUnreadLine);
		PCard cSecondCard = ReadCard(strUnreadLine);
		sm_cInputHand.SetPlayersCards(TRUE_POKER_NICK, cFirstCard, cSecondCard);
		return new CPSTrueLogPlayerFirstAction(m_cParseFile);
	}
	else
	{
		if (IsNumber(strUnreadLine[strUnreadLine.GetLength() - 1]))
		{
			int iAmount = ReverseGetNextNumber(strUnreadLine);
			CString strAction = ReverseGetNextWord(strUnreadLine);
			if (strAction == "posts")
			{
				sm_cInputHand.AddPlayerAction(strUnreadLine, PPlayerAction(PPlayerAction::ACTION_POST), iAmount);
				return this;
			}
		}
	}
	return ChangeState(new CPSTrueLogPlayerFirstAction(m_cParseFile), strInLine);
}

