// PSHighStakesLogDealing.cpp: implementation of the CPSHighStakesLogDealing class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "HistoryParser_DLL.h"
#include "PSHighStakesLogDealing.h"
#include "PSNone.h"
#include "HighStakesLogNone.h"
#include "PSHighStakesLogPlayerAction.h"
#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPSHighStakesLogDealing::CPSHighStakesLogDealing(CParseFile* pPF)
: CPSHighStakesLog(pPF),
	m_eRound(ROUND_PRE_FLOP)
{

}

CPSHighStakesLogDealing::~CPSHighStakesLogDealing()
{

}

CParseState* CPSHighStakesLogDealing::ParseI(const CString& strInLine, const CString &strFullLine)
{

	CString strUnreadLine = strInLine;

	if (ReadIfNextWord("Dealing " , strUnreadLine))
	{
		if (ReadIfNextWord("flop.", strUnreadLine))
		{
			m_eRound = ROUND_FLOP;
		}
		else if (ReadIfNextWord("turn.", strUnreadLine))
		{
			m_eRound = ROUND_TURN;
		}
		else if (ReadIfNextWord("river.", strUnreadLine))
		{
			m_eRound = ROUND_RIVER;
		}
		else
		{
			ASSERT(FALSE);
		}
		return this;
	}
	else  
	{
		switch (m_eRound)
		{
		case ROUND_FLOP:
			ParseFlopDeal(strUnreadLine);
			break;
		case ROUND_TURN:
			ParseTurnDeal(strUnreadLine); 
			break;
		case ROUND_RIVER:
			ParseRiverDeal(strUnreadLine);	 
			break;
		default:
			ASSERT(FALSE);
			return new CHighStakesLogNone(m_cParseFile);
		}
		return new CPSHighStakesLogPlayerAction(m_cParseFile);
	}
}


