// PSTrueLogSmallBlind.cpp: implementation of the CPSTrueLogSmallBlind class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "HistoryParser_DLL.h"
#include "PSTrueLogHeader.h"
#include "PSTrueLogSmallBlind.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPSTrueLogHeader::CPSTrueLogHeader(CParseFile* pPF)
: CPSTrueLog(pPF)
{

}

CPSTrueLogHeader::~CPSTrueLogHeader()
{

}

CParseState* CPSTrueLogHeader::ParseI(const CString &strInLine, const CString &strFullLine)
{
	CString strUnreadLine = strInLine;
	sm_cInputHand.SetTableName(GetTableName(strUnreadLine));
	ReadText("- Holdem -", strUnreadLine);

	sm_cInputHand.SetSmallBet(GetNextNumber(strUnreadLine));
	ReadText('/', strUnreadLine);
	sm_cInputHand.SetBigBet(GetNextNumber(strUnreadLine));

	ReadText("- Real Money - Hand #", strUnreadLine);
	sm_cInputHand.SetGameNumber(GetNextNumber(strUnreadLine));
	sm_cInputHand.SetGame(GAME_TEXUS_HOLDEM);

	return new CPSTrueLogSmallBlind(m_cParseFile);
}
