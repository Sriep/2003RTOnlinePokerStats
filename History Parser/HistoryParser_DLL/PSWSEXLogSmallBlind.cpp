// PSWSEXLogSmallBlind.cpp: implementation of the CPSWSEXLogSmallBlind class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "HistoryParser_DLL.h"
#include "PSWSEXLogSmallBlind.h"
#include "PSWSEXLogBigBlind.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPSWSEXLogSmallBlind::CPSWSEXLogSmallBlind(CParseFile* pPF)
: CPSWSEXLog(pPF)
{

}

CPSWSEXLogSmallBlind::~CPSWSEXLogSmallBlind()
{

}

CParseState* CPSWSEXLogSmallBlind::ParseI(const CString &strInLine, const CString &strFullLine)
{
	CString strUnreadLine = strInLine;
	sm_cInputHand.SetGame(GAME_TEXUS_HOLDEM); 
	sm_cInputHand.SetTableName(m_cParseFile->GetTableName());
	int iSmallBlind = ReverseGetNextNumber(strUnreadLine);
	ReverseReadText("posts the small blind $", strUnreadLine);

	strUnreadLine.TrimLeft(' ');
	strUnreadLine.TrimRight(' ');

	sm_cInputHand.SetSmallBlind(strUnreadLine, iSmallBlind);
	sm_listNicks.push_back(strUnreadLine);
	
	return new CPSWSEXLogBigBlind(m_cParseFile);
}
