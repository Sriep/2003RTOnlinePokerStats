// PSUltimateBetLogSmallBlind.cpp: implementation of the CPSUltimateBetLogSmallBlind class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "HistoryParser_DLL.h"
#include "PSUltimateBetLogShowdown.h"
#include "UltimateBetLogNone.h"	  

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPSUltimateBetLogShowdown::CPSUltimateBetLogShowdown(CParseFile* pPF)
: CPSUltimateBetLog(pPF)
{

}

CPSUltimateBetLogShowdown::~CPSUltimateBetLogShowdown()
{

}

CParseState* CPSUltimateBetLogShowdown::ParseI(const CString &strInLine, const CString &strFullLine)
{
	CString strUnreadLine = strInLine;
	CParseState* pNextState = NULL;
	if (IsNextWord("Starting hand", strUnreadLine))
	{
		sm_cInputHand.WriteToDataBase();
		m_cParseFile->RefreshPlayers();
		m_cParseFile->NewHand();
		CParseState* pNewState = new  CUltimateBetLogNone(m_cParseFile);
		return ChangeState(pNewState,  strInLine);
	}

	if (IsNextWord("#", strUnreadLine))
	{
		try
		{
			CString strUnreadLine = strInLine;
			GetNextWord(strUnreadLine);
			CString strNick = ReadLongNick(strUnreadLine);
			ReadText("wins", strUnreadLine);
			if (ReadIfNextWord("$", strUnreadLine))
			{
				int iWin = GetNextNumber(strUnreadLine);
				sm_cInputHand.SetPlayerProfitLoss(strNick, iWin);
			}
		}
		catch (...)
		{
			ASSERT(FALSE);
		}
	}
	
	return this;
}
