// PSPartyLog.cpp: implementation of the CPSPartyLog class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "HistoryParser_DLL.h"
#include "PSPartyLog.h"
#include "PartyLogNone.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPSPartyLog::CPSPartyLog(CParseFile* pPF)
: CParseState(pPF)
{

}

CPSPartyLog::~CPSPartyLog()
{

}

CParseState* CPSPartyLog::Parse(const CString &strInLine)
{
	CString strUnreadLine = strInLine;
	strUnreadLine.TrimRight('\x0D');

	if (!ReadIfNextWord("Dealer: ", strUnreadLine))
	{
		CString strGameNumber;
		strGameNumber.Format("#%s:", sm_cInputHand.GetGameNumber());
		if (IsNextWord(strGameNumber, strUnreadLine))
		{
			ReadText(strGameNumber, strUnreadLine);
			CString strNick = ReadNick(strUnreadLine);
			if (ReadIfNextWord("wins $", strUnreadLine))
			{
				int iProfitLoss = GetNextNumber(strUnreadLine);
				sm_cInputHand.SetPlayerProfitLoss(strNick, iProfitLoss);
			}
			
			sm_cInputHand.WriteToDataBase();
			m_cParseFile->RefreshPlayers();
			m_cParseFile->NewHand();
			CParseState* pNextState = new CPartyLogNone(m_cParseFile);
			delete this;
			return pNextState;
		}
		else
		{
			return this;
		}
	}

	if (strUnreadLine.IsEmpty())
		return this;

	CParseState* pNextState = NULL;
	if (IsNextWord("Game #", strUnreadLine))
	{
		if (IsLastWord("starts.",strUnreadLine)	)
		{
			CParseState* pNewState = new  CPartyLogNone(m_cParseFile);
			pNextState = ChangeState(pNewState,  strInLine);
		}
	}
	else
	{
		if (PartyLogIgnoreLine(strUnreadLine))
		{
			return this;
		}
		strUnreadLine.TrimLeft(' ');
		strUnreadLine.TrimRight('\x0D');

		pNextState = ParseI(strUnreadLine, strInLine);
	}

	if (this != (CPSPartyLog*) pNextState)
	{
		delete this;
	}
	return pNextState;
}



