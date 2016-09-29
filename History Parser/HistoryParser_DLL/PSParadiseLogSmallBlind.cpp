// PSParadiseLogSmallBlind.cpp: implementation of the CPSParadiseLogSmallBlind class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "HistoryParser_DLL.h"
#include "PSParadiseLogSmallBlind.h"
#include "PSParadiseLogBigBlind.h"
#include "PSParadiseLogPlayerFirxtAction.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPSParadiseLogSmallBlind::CPSParadiseLogSmallBlind(CParseFile* pPF)
: CPSParadiseLog(pPF)
{

}

CPSParadiseLogSmallBlind::~CPSParadiseLogSmallBlind()
{

}

CParseState* CPSParadiseLogSmallBlind::ParseI(const CString &strInLine, const CString &strFullLine)
{
	CString strUnreadLine = strInLine;
	if(ReverseReadIfNextWord("blind", strUnreadLine))
	{
		if (ReverseReadIfNextWord("big", strUnreadLine))
		{
			ReverseReadText("the", strUnreadLine);
			ReverseReadText(WORD_posts, strUnreadLine);
			strUnreadLine.TrimLeft(' ');
			strUnreadLine.TrimRight(' ');
			sm_cInputHand.SetBigBlind(strUnreadLine, 0);
			if (sm_listNicks.size() <= 1)
			{
				sm_listNicks.push_back(strUnreadLine);
			}
		}
		else if (ReverseReadIfNextWord("small", strUnreadLine))
		{
			sm_cInputHand.SetGame(GAME_TEXUS_HOLDEM); 
			sm_cInputHand.SetTableName(m_cParseFile->GetTableName());
			ReverseReadText("the", strUnreadLine);
			ReverseReadText(WORD_posts, strUnreadLine);
			strUnreadLine.TrimLeft(' ');
			strUnreadLine.TrimRight(' ');
			sm_cInputHand.SetSmallBlind(strUnreadLine, 0);
			if (sm_listNicks.size() <= 1)
			{
				sm_listNicks.push_back(strUnreadLine);
			}
		}
	}
	else
	{

		PPlayerAction cAction;
		CString strAction = ReverseGetNextWord(strUnreadLine);
		cAction =  PPlayerAction(strAction);
		if (cAction != PPlayerAction(PPlayerAction::ACTION_NONE))
		{
			CParseState* pNewState = new  CPSParadiseLogPlayerFirstAction(m_cParseFile);
			return ChangeState(pNewState,  "»Dealer:" + strInLine);
		}
		return new  CPSParadiseLogPlayerFirstAction(m_cParseFile);
	}
	return this;
}
