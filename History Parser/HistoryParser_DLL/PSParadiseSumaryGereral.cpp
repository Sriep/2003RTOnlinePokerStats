// PSParadiseSumaryGereral.cpp: implementation of the CPSParadiseSumaryGereral class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PSParadiseSumaryGereral.h"

#include "PSNone.h"
#include "PSParadiseHeader1.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPSParadiseSumaryGereral::CPSParadiseSumaryGereral(CParseFile* pPF)
: CParseState(pPF)
{

}

CPSParadiseSumaryGereral::~CPSParadiseSumaryGereral()
{

}

CParseState* CPSParadiseSumaryGereral::Parse(const CString &strInLine)
{
	CString strUnreadLine = strInLine;
	strUnreadLine.TrimLeft(' ');
	strUnreadLine.TrimRight(' ');

	if (strInLine == "-----------------------------------------------------" 
		|| strInLine.IsEmpty())
	{
		sm_cInputHand.WriteToDataBase();
		m_cParseFile->RefreshPlayers();
		m_cParseFile->NewHand();
		return ChangeState(new CPSNone(m_cParseFile), strInLine);	
	}

	CString strNick = ReadLongNick(strUnreadLine);
	if (strNick == "")
		return this;

	if (FindText("lost", strUnreadLine))
	{
		ReadText(CHAR_DOLLAR, strUnreadLine);
		int iLoss = -1 * GetNextNumber(strUnreadLine);
		sm_cInputHand.SetPlayerProfitLoss(strNick, iLoss);
	}
	else if (FindText(" net ", strUnreadLine))
	{
		strUnreadLine.TrimLeft(' ');
		int iMultiple = 1;
		switch (strUnreadLine[0])
		case '-':
		{
			iMultiple = -1;
			ReadText("-", strUnreadLine);
			break;
		case '+':
			ReadText("+", strUnreadLine);
			break;
		}
		ReadText(CHAR_DOLLAR, strUnreadLine);
		int iProfitLoss = iMultiple * GetNextNumber(strUnreadLine);
		sm_cInputHand.SetPlayerProfitLoss(strNick, iProfitLoss);
	}

	if (FindText(" [ ", strUnreadLine))
	{
		PCard cCard1 = ReadCard(strUnreadLine);

		PCard cCard2 = ReadCard(strUnreadLine);

		sm_cInputHand.SetPlayersCards(strNick, cCard1, cCard2);
	}		

	return this;
}



