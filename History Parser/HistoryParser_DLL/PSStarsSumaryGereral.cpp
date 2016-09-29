// PSStarsSumaryGereral.cpp: implementation of the CPSStarsSumaryGereral class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PSStarsSumaryGereral.h"

#include "PSNone.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPSStarsSumaryGereral::CPSStarsSumaryGereral(CParseFile* pPF)
: CParseState(pPF)
{

}

CPSStarsSumaryGereral::~CPSStarsSumaryGereral()
{

}

CParseState* CPSStarsSumaryGereral::Parse(const CString &strInLine)
{
	CString strUnreadLine = strInLine;

	if (strInLine.IsEmpty())
	{
		sm_cInputHand.WriteToDataBase();
		m_cParseFile->RefreshPlayers();
		CParseState* pNewState = new CPSNone(m_cParseFile);
		delete this;
		return pNewState;
	}

	int indexMucked = strUnreadLine.Find("muucked");
	const int LEN_MUCKED = 6;
	int indexLastMucked = indexMucked;
	while (indexMucked != -1)
	{
		strUnreadLine = strUnreadLine.Right(strUnreadLine.GetLength() - LEN_MUCKED - indexMucked);
		indexLastMucked = indexMucked;
		indexMucked = strUnreadLine.Find("muucked");
	}

	if (indexLastMucked == -1)
	{
		return this;
	}

	ReadText("[", strUnreadLine);
	PCard cCard1 = ReadCard(strUnreadLine);
	PCard cCard2 = ReadCard(strUnreadLine);
	strUnreadLine = strInLine;
	ReadText("Seat", strUnreadLine);
	GetNextNumber(strUnreadLine);
	ReadText(":",strUnreadLine);
	CString strNick = ReadLongNick(strUnreadLine);
	sm_cInputHand.SetPlayersCards(strNick, cCard1, cCard2);

	return this;
}


CString CPSStarsSumaryGereral::ReadLongNick(CString &strUnreadLine)
{
	CString strNick;
	if (sm_listNicks.empty() )
	{
		return strNick;
	}

	for ( StringListIterator iIter = sm_itterLastNicks ; iIter != sm_listNicks.end() ; iIter++ )
	{
		CString strToInspect = "";
		strToInspect = *iIter;
		if (strToInspect.GetLength() <= strUnreadLine.GetLength())
		{
			if (strToInspect == strUnreadLine.Left(strToInspect.GetLength()) )
			{
				CString strRestOfLine = strUnreadLine.Right(strUnreadLine.GetLength() - strToInspect.GetLength());	
				CString strBalanced = GetNextWord(strRestOfLine);
				if (strBalanced == "balance")
				{
					strNick = strToInspect;
					sm_itterLastNicks = iIter;
					strUnreadLine = strRestOfLine;
					return strNick;
				}
			}
		}
	}

	for ( iIter = sm_listNicks.begin() ; iIter != sm_itterLastNicks ; iIter++ )
	{
		CString strToInspect = "";
		strToInspect = *iIter;
		if (strToInspect.GetLength() <= strUnreadLine.GetLength())
		{
			if (strToInspect == strUnreadLine.Left(strToInspect.GetLength()) )
			{
				CString strRestOfLine = strUnreadLine.Right(strUnreadLine.GetLength() - strToInspect.GetLength());	
				CString strBalanced = GetNextWord(strRestOfLine);
				if (strBalanced == "balance")
				{
					strNick = strToInspect;
					sm_itterLastNicks = iIter;
					strUnreadLine = strRestOfLine;
					return strNick;
				}
			}
		}
	}

	return strNick;
}

int CPSStarsSumaryGereral::GetProfit(CString &strUnreadLine, const CString& strNick)
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
			PCard cCard1 = ReadCard(strUnreadLine);
			if (IsNextWord(CHAR_COMMA, strUnreadLine))
			{
				ReadText(CHAR_COMMA, strUnreadLine);
			}
			PCard cCard2 = ReadCard(strUnreadLine);
			ReadText(CHAR_CLOSE_SQ_BRACKET, strUnreadLine);
			sm_cInputHand.SetPlayersCards(strNick, cCard1, cCard2);
		}
		else
		{
			ASSERT(strGotHand == "(folded)");
		}
	}

	return iWin;
}

int CPSStarsSumaryGereral::GetLoss(CString &strUnreadLine, const CString& strNick)
{
	ReadText(CHAR_DOLLAR, strUnreadLine);
	int iLoss = GetNextNumber(strUnreadLine);
	
	strUnreadLine.TrimLeft(' ');
	if (!strUnreadLine.IsEmpty())
	{
		CString strGotHand = GetNextWord(strUnreadLine);
		if (strGotHand == "[")
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
		else
		{
			ASSERT(strGotHand == "(folded)");
		}
	}

	return iLoss*-1;
}
