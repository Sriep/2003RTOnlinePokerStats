// PSPokerRoomLogSmallBlind.cpp: implementation of the CPSPokerRoomLogSmallBlind class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "HistoryParser_DLL.h"
#include "PSCryptologicLogBlind.h"
#include "PSCryptologicLogPlayerFirxtAction.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPSCryptologicLogBlind::CPSCryptologicLogBlind(CParseFile* pPF)
: CPSCryptologicLog(pPF)
{

}

CPSCryptologicLogBlind::~CPSCryptologicLogBlind()
{

}

CParseState* CPSCryptologicLogBlind::ParseI(const CString &strInLine, const CString &strFullLine)
{
	CString strUnreadLine = strInLine;
	
	int iAmount = 0;
	if (IsNumber(strUnreadLine[strUnreadLine.GetLength() - 1]))
	{
		iAmount = ReverseGetNextNumber(strUnreadLine);
		strUnreadLine = strUnreadLine.Left(strUnreadLine.GetLength() - 1);
	}
	
	if(ReverseReadIfNextWord("blind", strUnreadLine))
	{
		PPlayerAction cAction("Post");
		if (ReverseReadIfNextWord("big", strUnreadLine))
		{
			ReverseReadText(WORD_posts, strUnreadLine);
			strUnreadLine.TrimLeft(' ');
			strUnreadLine.TrimRight(' ');
			sm_cInputHand.SetBigBlind(strUnreadLine, 0);
			if (sm_listNicks.size() <= 1)
			{
				sm_listNicks.push_back(strUnreadLine);
			}
			GetCryptologicLogFile()->ProcessAction(cAction,  strUnreadLine);

			CParseState* pNewState = new  CPSCryptologicLogPlayerFirstAction(m_cParseFile);
			return pNewState;

		}
		else if (ReverseReadIfNextWord("small", strUnreadLine))
		{
			sm_cInputHand.SetGame(GAME_TEXUS_HOLDEM); 
			sm_cInputHand.SetTableName(m_cParseFile->GetTableName());
			ReverseReadText(WORD_posts, strUnreadLine);
			strUnreadLine.TrimLeft(' ');
			strUnreadLine.TrimRight(' ');
			GetCryptologicLogFile()->ProcessAction(cAction,  strUnreadLine);

			sm_cInputHand.SetSmallBlind(strUnreadLine, 0);
			if (sm_listNicks.size() <= 1)
			{
				sm_listNicks.push_back(strUnreadLine);
			}
		}
	}
	return this;
}
