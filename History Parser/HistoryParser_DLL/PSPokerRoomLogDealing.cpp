// PSPokerRoomLogDealing.cpp: implementation of the CPSPokerRoomLogDealing class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "HistoryParser_DLL.h"
#include "PSPokerRoomLogDealing.h"
#include "PSNone.h"
#include "PSPokerRoomLogPlayerFirxtAction.h"
#include "PSPokerRoomLogPlayerAction.h"
#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPSPokerRoomLogDealing::CPSPokerRoomLogDealing(CParseFile* pPF)
: CPSPokerRoomLog(pPF)
{

}

CPSPokerRoomLogDealing::~CPSPokerRoomLogDealing()
{

}

CParseState* CPSPokerRoomLogDealing::ParseI(const CString& strInLine, const CString &strFullLine)
{

	CString strUnreadLine = strInLine;

	ReadText("Dealing", strUnreadLine);
	CString strRound = GetNextWord(strUnreadLine);

	if (strRound == "Flop:")
	{
		ParseFlopDeal(strUnreadLine);
	}
	else if (strRound == "Turn:")
	{
		ParseTurnDeal(strUnreadLine);
	}
	else if (strRound == "River:")
	{
		ParseRiverDeal(strUnreadLine);
	}
	else
	{
		throw(new CParsingException(IDS_UNEXPECTED_TEXT, this, new CPSNone(m_cParseFile)));
	}
	return  new CPSPokerRoomLogPlayerAction(m_cParseFile);
}


