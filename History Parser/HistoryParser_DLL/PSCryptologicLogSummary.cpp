// PSCryptologicLogDealing.cpp: implementation of the CPSCryptologicLogDealing class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PSCryptologicLogSummary.h"
#include "CryptologicLogNone.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPSCryptologicLogSummary::CPSCryptologicLogSummary(CParseFile* pPF)
: CPSCryptologicLog(pPF)
{

}

CPSCryptologicLogSummary::~CPSCryptologicLogSummary()
{

}

CParseState* CPSCryptologicLogSummary::ParseI(const CString& strInLine, const CString &strFullLine)
{

	CString strUnreadLine = strInLine;

	CString strFirstWord = GetNextWord(strUnreadLine);
	if (strFirstWord == "starting")
	{
		sm_cInputHand.WriteToDataBase();
		sm_cInputHand.NewHand();
		m_cParseFile->NewHand();
		m_cParseFile->RefreshPlayers();
		CParseState* pNextState = new  CCryptologicLogNone(m_cParseFile);
		return ChangeState(pNextState,  strFullLine);
	}
	if (strFirstWord != "Game")
		return this;

	GetNextWord(strUnreadLine);	
	CString strNick = GetNextWord(strUnreadLine);

	if (ReadIfNextWord("wins pot ($", strUnreadLine))
	{
		int iWin = GetNextNumber(strUnreadLine);
		sm_cInputHand.SetPlayerProfitLoss(strNick, iWin);
	}
	sm_cInputHand.WriteToDataBase();
	sm_cInputHand.NewHand();
	m_cParseFile->NewHand();
	m_cParseFile->RefreshPlayers();
	return  new CCryptologicLogNone(m_cParseFile);
}


