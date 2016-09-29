// PSUltimateBetLogSmallBlind.cpp: implementation of the CPSUltimateBetLogSmallBlind class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "HistoryParser_DLL.h"
#include "PSUltimateBetLogSmallBlind.h"
#include "PSUltimateBetLogBigBlind.h"
#include "PSUltimateBetLogBigBlind.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPSUltimateBetLogSmallBlind::CPSUltimateBetLogSmallBlind(CParseFile* pPF)
: CPSUltimateBetLog(pPF)
{

}

CPSUltimateBetLogSmallBlind::~CPSUltimateBetLogSmallBlind()
{

}

CParseState* CPSUltimateBetLogSmallBlind::ParseI(const CString &strInLine, const CString &strFullLine)
{
	CString strUnreadLine = strInLine;

	if (IsLastWord("has posted the big blind.", strInLine))
	{
		return ChangeState(new  CPSUltimateBetLogBigBlind(m_cParseFile),  strFullLine);
	}

	sm_cInputHand.SetGame(GAME_TEXUS_HOLDEM); 
	sm_cInputHand.SetTableName(m_cParseFile->GetTableName());
	ReverseReadText("has posted the small blind.", strUnreadLine);

	strUnreadLine.TrimLeft(' ');
	strUnreadLine.TrimRight(' ');

	sm_cInputHand.SetSmallBlind(strUnreadLine, 0);
	sm_listNicks.push_back(strUnreadLine);
	
	return new CPSUltimateBetLogBigBlind(m_cParseFile);
}
