// PSPokerRoomLogResult.cpp: implementation of the CPSPokerRoomLogResult class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "HistoryParser_DLL.h"
#include "PSPokerRoomLogResult.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPSPokerRoomLogResult::CPSPokerRoomLogResult(CParseFile* pPF)
: CParseState(pPF)
{

}

CPSPokerRoomLogResult::~CPSPokerRoomLogResult()
{

}

CParseState* CPSPokerRoomLogResult::Parse(const CString &strInLine)
{
	CString strUnreadLine = strInLine;
	strUnreadLine.TrimLeft(" ");
	strUnreadLine.TrimRight(" ");

	if (strUnreadLine.IsEmpty())
		return this;
	
	CString strNick = ReadLongNick(strUnreadLine);
	if (strNick.IsEmpty())
		return this;

	CString strAction = GetNextWord(strUnreadLine);

	if (strAction == "wins")
	{
		int iAmount = 0;
		if (ReadIfNextWord("$", strUnreadLine))
		{
			iAmount = GetNextNumber(strUnreadLine);
		}
		sm_cInputHand.SetPlayerProfitLoss(strNick, iAmount);
	}

	return this;
}

