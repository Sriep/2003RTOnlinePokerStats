// PSPokerRoomLogSmallBlind.cpp: implementation of the CPSPokerRoomLogSmallBlind class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "HistoryParser_DLL.h"
#include "PSPokerRoomLogSmallBlind.h"
#include "PSPokerRoomLogPlayerFirxtAction.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPSPokerRoomLogSmallBlind::CPSPokerRoomLogSmallBlind(CParseFile* pPF)
: CPSPokerRoomLog(pPF)
{

}

CPSPokerRoomLogSmallBlind::~CPSPokerRoomLogSmallBlind()
{

}

CParseState* CPSPokerRoomLogSmallBlind::ParseI(const CString &strInLine, const CString &strFullLine)
{
	CString strUnreadLine = strInLine;
	if(ReverseReadIfNextWord("blind.", strUnreadLine))
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
		CParseState* pNewState = new  CPSPokerRoomLogPlayerFirstAction(m_cParseFile);
		return ChangeState(pNewState,  strInLine);
	}
	return this;
}
