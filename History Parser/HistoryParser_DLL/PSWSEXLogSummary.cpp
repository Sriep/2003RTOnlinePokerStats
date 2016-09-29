// PSWSEXLogDealing.cpp: implementation of the CPSWSEXLogDealing class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PSWSEXLogSummary.h"
#include "WSEXLogNone.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPWSEXLogSummary::CPWSEXLogSummary(CParseFile* pPF)
: CPSWSEXLog(pPF)
{

}

CPWSEXLogSummary::~CPWSEXLogSummary()
{

}

CParseState* CPWSEXLogSummary::ParseI(const CString& strInLine, const CString &strFullLine)
{

	CString strUnreadLine = strInLine;

	GetNextWord(strUnreadLine);
	GetNextWord(strUnreadLine);	
	CString strNick = GetNextWord(strUnreadLine);
	if (ReadIfNextWord("wins ($", strUnreadLine))
	{
		int iWin = GetNextNumber(strUnreadLine);
		sm_cInputHand.SetPlayerProfitLoss(strNick, iWin);
	}
	sm_cInputHand.WriteToDataBase();
	sm_cInputHand.NewHand();
	m_cParseFile->NewHand();
	m_cParseFile->RefreshPlayers();
	return  new CWSEXLogNone(m_cParseFile);
}


