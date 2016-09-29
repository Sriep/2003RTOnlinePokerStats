// PSPartySumaryGereral.cpp: implementation of the CPSPartySumaryGereral class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PSPartySumaryGereral.h"

#include "ParsingException.h"
#include "PSNone.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPSPartySumaryGereral::CPSPartySumaryGereral(CParseFile* pPF)
: CParseState(pPF)
{

}

CPSPartySumaryGereral::~CPSPartySumaryGereral()
{

}

CParseState* CPSPartySumaryGereral::Parse(const CString &strInLine)
{
	CString strUnreadLine = strInLine;
	strUnreadLine.TrimLeft(' ');
	strUnreadLine.TrimRight(' ');

	if (strInLine.IsEmpty())
	{
		sm_cInputHand.WriteToDataBase();
		m_cParseFile->RefreshPlayers();
		CParseState* pNewState = new CPSNone(m_cParseFile);
		delete this;
		return pNewState;
	}

	CString strNick = ReadNick(strUnreadLine);
	if (strNick == "")
		return this;
	if (IsNextWord("balance", strUnreadLine))
	{
		ReadText("balance", strUnreadLine);
		ReadText(CHAR_DOLLAR, strUnreadLine);
		int iBalance = GetNextNumber(strUnreadLine);
		if (IsNextWord(CHAR_COMMA, strUnreadLine))
		{
			ReadText(CHAR_COMMA, strUnreadLine);
		}
	}
	
	int iProfitLoss = 0;
	CString strStatus = GetNextWord(strUnreadLine);
	if (strStatus != "sits")
	{
		if (strStatus== "didn't")
		{
			iProfitLoss = 0;
		}
		else if  (strStatus == "lost")
		{
			iProfitLoss = GetLoss(strUnreadLine, strNick);
		}
		else if (strStatus == "bet")
		{
			iProfitLoss = GetProfit(strUnreadLine, strNick);
		}
		sm_cInputHand.SetPlayerProfitLoss(strNick, iProfitLoss);
	}
	else
	{
		sm_cInputHand.SetPlayerSatOut(strNick);
	}

	return this;
}

int CPSPartySumaryGereral::GetProfit(CString &strUnreadLine, const CString& strNick)
{
	int iWin = 0;
	int iIndexNet = strUnreadLine.Find("net");
	if (iIndexNet > 0)
	{
		const int LENGTH_NET = 3;
		strUnreadLine = strUnreadLine.Right(strUnreadLine.GetLength() - iIndexNet - LENGTH_NET);

		
		ReadText("+", strUnreadLine);
		ReadText(CHAR_DOLLAR, strUnreadLine);
		iWin = GetNextNumber(strUnreadLine);
	}
	else
	{
		int iIndexNet = strUnreadLine.Find("lost");
		const int LENGTH_LOST = 4;
		strUnreadLine = strUnreadLine.Right(strUnreadLine.GetLength() - iIndexNet - LENGTH_LOST);

		ReadText("-", strUnreadLine);
		ReadText(CHAR_DOLLAR, strUnreadLine);
		iWin = GetNextNumber(strUnreadLine) * -1;
	}
	
	strUnreadLine.TrimLeft(' ');
	if (!strUnreadLine.IsEmpty())
	{
		CString strGotHand = GetNextWord(strUnreadLine);
		if (strGotHand == "[")
		{
			try
			{
				PCard cCard1 = ReadCard(strUnreadLine);
				if (IsNextWord(CHAR_COMMA, strUnreadLine))
				{
					ReadText(CHAR_COMMA, strUnreadLine);
				}
				PCard cCard2 = ReadCard(strUnreadLine);
				ReadText(CHAR_CLOSE_SQ_BRACKET, strUnreadLine);
				sm_cInputHand.SetPlayersCards(strNick, cCard1, cCard2);
			}
			catch (...)
			{
				throw(new CParsingException("Party Error reading players cards"));
			}
		}
		else
		{
			ASSERT(strGotHand == "(folded)");
		}
	}

	return iWin;
}

int CPSPartySumaryGereral::GetLoss(CString &strUnreadLine, const CString& strNick)
{
	ReadText(CHAR_DOLLAR, strUnreadLine);
	int iLoss = GetNextNumber(strUnreadLine);
	
	strUnreadLine.TrimLeft(' ');
	if (!strUnreadLine.IsEmpty())
	{
		CString strGotHand = GetNextWord(strUnreadLine);
		if (strGotHand == "[")
		{
			try
			{
				PCard cCard1 = ReadCard(strUnreadLine);
				if (IsNextWord(CHAR_COMMA, strUnreadLine))
				{
					ReadText(CHAR_COMMA, strUnreadLine);
				}
				PCard cCard2 = ReadCard(strUnreadLine);
				ReadText(CHAR_CLOSE_SQ_BRACKET, strUnreadLine);
				sm_cInputHand.SetPlayersCards(strNick, cCard1, cCard2);
			}
			catch (...)
			{
				throw(new CParsingException("Party Error reading players cards"));
			}
		}
		else
		{
			ASSERT(strGotHand == "(folded)");
		}
	}

	return iLoss*-1;
}
