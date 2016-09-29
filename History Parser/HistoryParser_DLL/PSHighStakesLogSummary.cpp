// PSHighStakesLogSummary.cpp: implementation of the CPSHighStakesLogSummary class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PSHighStakesLogSummary.h"
#include "HighStakesLogNone.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPSHighStakesLogSummary::CPSHighStakesLogSummary(CParseFile* cPF)
:	CPSHighStakesLog(cPF),
	m_bFirst(false)
{

}

CPSHighStakesLogSummary::CPSHighStakesLogSummary(CParseFile* cPF, const CString& strNick, const CString& strAction, CString& strUnreadLine)
: CPSHighStakesLog(cPF),
 m_strNick(strNick),
 m_strAction(strAction),
 m_strUnreadLine(strUnreadLine),
 m_bFirst(true)
{

}


CPSHighStakesLogSummary::~CPSHighStakesLogSummary()
{

}

CParseState* CPSHighStakesLogSummary::ParseI(const CString &strInLine, const CString &strFullLine)
{
	if (m_bFirst)
	{
		if (m_strAction == "wins")
		{
			ReadText('$', m_strUnreadLine);
			int iAmount = GetNextNumber(m_strUnreadLine);
			sm_cInputHand.SetPlayerProfitLoss(m_strNick, iAmount);
		}
		m_bFirst = false;
	}
	else
	{
		CString strUnreadLine = strInLine;
		if (strInLine == "Hand is over.")
		{
			sm_cInputHand.WriteToDataBase();
			m_cParseFile->RefreshPlayers();
			m_cParseFile->NewHand();
			return ChangeState(new CHighStakesLogNone(m_cParseFile), strFullLine);

		}

		CString strNick = ReadLongNick(strUnreadLine);
		CString strEvent = GetNextWord(strUnreadLine);
		if (!strNick.IsEmpty())
		{
			if (strEvent == "wins")
			{
				ReadText('$', strUnreadLine);
				int iAmount = GetNextNumber(strUnreadLine);
				sm_cInputHand.SetPlayerProfitLoss(strNick, iAmount);
			}
		}
	}


	return this;
}
