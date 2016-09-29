// PSTrueLogBigBlind.cpp: implementation of the CPSTrueLogBigBlind class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "HistoryParser_DLL.h"
#include "PSTrueLogSummary.h"
#include "PSTrueLogPlayerCards.h"
#include "TrueLogNone.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPSTrueLogSummary::CPSTrueLogSummary(CParseFile* pPF)
: CPSTrueLog(pPF)
{


}

CPSTrueLogSummary::~CPSTrueLogSummary()
{

}

CParseState* CPSTrueLogSummary::ParseI(const CString &strInLine, const CString &strFullLine)
{
	CString strUnreadLine = strInLine;
	if (IsNextWord("Community Cards:", strUnreadLine))
	{
		sm_cInputHand.WriteToDataBase();
		m_cParseFile->RefreshPlayers();
		m_cParseFile->NewHand();
		return new CTrueLogNone(m_cParseFile);
	}

	CString strNick = ReadLongNick(strUnreadLine);
	ASSERT(!strNick.IsEmpty());

	if (ReadIfNextWord("'s pocket cards were [", strUnreadLine))
	{
		PCard cFirstCard = ReadCard(strUnreadLine);
		ReadText(",", strUnreadLine);
		PCard cSecondCard = ReadCard(strUnreadLine);
		sm_cInputHand.SetPlayersCards(strNick, cFirstCard, cSecondCard);
	}
	else if (ReadIfNextWord("wins ", strUnreadLine))
	{
		ReadText("$", strUnreadLine);
		int iProfitLoss = GetNextNumber(strUnreadLine);
		sm_cInputHand.SetPlayerProfitLoss(strNick, iProfitLoss);
	}
	return this;
}

