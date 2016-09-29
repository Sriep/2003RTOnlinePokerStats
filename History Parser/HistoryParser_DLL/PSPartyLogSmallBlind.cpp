// PSPartyLogSmallBlind.cpp: implementation of the CPSPartyLogSmallBlind class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "HistoryParser_DLL.h"
#include "PSPartyLogSmallBlind.h"
#include "PSPartyLogBigBlind.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPSPartyLogSmallBlind::CPSPartyLogSmallBlind(CParseFile* pPF)
: CPSPartyLog(pPF)
{

}

CPSPartyLogSmallBlind::~CPSPartyLogSmallBlind()
{

}

CParseState* CPSPartyLogSmallBlind::ParseI(const CString &strInLine, const CString &strFullLine)
{
	CString strUnreadLine = strInLine;
	sm_cInputHand.SetGame(GAME_TEXUS_HOLDEM); 
	sm_cInputHand.SetTableName(m_cParseFile->GetTableName());
	ReverseReadText('.', strUnreadLine);
	ReverseReadText(']', strUnreadLine);
	int iSmallBlind = ReverseGetNextNumber(strUnreadLine);
	ReverseReadText('$', strUnreadLine);
	ReverseReadText('[', strUnreadLine);
	ReverseReadText(WORD_blind, strUnreadLine);
	ReverseReadText(WORD_small, strUnreadLine);
	ReverseReadText(WORD_posts, strUnreadLine);

	strUnreadLine.TrimLeft(' ');
	strUnreadLine.TrimRight(' ');

	sm_cInputHand.SetSmallBlind(strUnreadLine, iSmallBlind);
	sm_listNicks.push_back(strUnreadLine);
	
	return new CPSPartyLogBigBlind(m_cParseFile);
}
