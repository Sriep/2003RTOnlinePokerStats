// PSCryptologicLogDealing.cpp: implementation of the CPSCryptologicLogDealing class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PSCryptologicLogAllFold.h"
#include "CryptologicLogNone.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPSCryptologicLogAllFold::CPSCryptologicLogAllFold(CParseFile* pPF)
: CPSCryptologicLog(pPF)
{

}

CPSCryptologicLogAllFold::~CPSCryptologicLogAllFold()
{

}

CParseState* CPSCryptologicLogAllFold::ParseI(const CString& strInLine, const CString &strFullLine)
{

	CString strUnreadLine = strInLine;

	ReadText("Game #", strUnreadLine);
	GetNextWord(strUnreadLine);

	CString strNick = GetNextWord(strUnreadLine);

	sm_cInputHand.SetBigBlind(strNick, 0);
	sm_cInputHand.SetSmallBlind(GetCryptologicLogFile()->GetLastPlayer(),0);
	if (ReadIfNextWord("wins (", strUnreadLine))
	{
		strUnreadLine = strUnreadLine.Right(strUnreadLine.GetLength() - 1);
		int iWin = GetNextNumber(strUnreadLine);
		sm_cInputHand.SetPlayerProfitLoss(strNick, iWin);
	}

	sm_cInputHand.WriteToDataBase();
	sm_cInputHand.NewHand();
	m_cParseFile->NewHand();
	m_cParseFile->RefreshPlayers();
	return  new CCryptologicLogNone(m_cParseFile);
}


