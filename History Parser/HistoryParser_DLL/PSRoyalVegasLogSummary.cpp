// PSRoyalVegasLogSummary.cpp: implementation of the CPSRoyalVegasLogSummary class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PSRoyalVegasLogSummary.h"
#include "RoyalVegasLogNone.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPSRoyalVegasLogSummary::CPSRoyalVegasLogSummary(CParseFile* cPF)
: CPSRoyalVegasLog(cPF)
{

}

CPSRoyalVegasLogSummary::CPSRoyalVegasLogSummary(CParseFile* cPF, const CString& strNick, const CString& strAction, CString& strUnreadLine)
: CPSRoyalVegasLog(cPF),
 m_strNick(strNick),
 m_strAction(strAction),
 m_strUnreadLine(strUnreadLine),
 m_bFirst(true)
{

}


CPSRoyalVegasLogSummary::~CPSRoyalVegasLogSummary()
{

}

CParseState* CPSRoyalVegasLogSummary::ParseI(const CString &strInLine, const CString &strFullLine)
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
		if (-1 != strInLine.Find("posted small blind"))
		{
			sm_cInputHand.WriteToDataBase();
			m_cParseFile->RefreshPlayers();
			m_cParseFile->NewHand();
			return ChangeState(new CRoyalVegasLogNone(m_cParseFile), strFullLine);

		}

		CString strNick = ReadNick(strUnreadLine);
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
