// PSStarsShowDown.cpp: implementation of the CPSStarsShowDown class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PSStarsShowDown.h"
#include "PSStarsSumary1.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPSStarsShowDown::CPSStarsShowDown(CParseFile* pPF)
: CParseState(pPF)
{

}

CPSStarsShowDown::~CPSStarsShowDown()
{

}

CParseState* CPSStarsShowDown::Parse(const CString &strInLine)
{
	if (IsNextWord("*** SUMMARY ***", strInLine))
	{
		CParseState* pNewState = new CPSStarsSumary1(m_cParseFile);
		delete this;
		return pNewState;
	}

	CString strUnreadLine = strInLine;
	//CString strNick = ReadPredfinedNickPlusAction(strUnreadLine);
	CString strNick = ReadLongNick(strUnreadLine);

	if (IsNextWord(":", strUnreadLine))
	{
		ReadText(":",strUnreadLine);
		if (IsNextWord("shows", strUnreadLine))
		{
			ReadText("shows", strUnreadLine);
			ReadText("[", strUnreadLine);
			PCard cCard1 = ReadCard(strUnreadLine);
			PCard cCard2 = ReadCard(strUnreadLine);
			ReadText("]", strUnreadLine);
			sm_cInputHand.SetPlayersCards(strNick, cCard1, cCard2);

		}
	}
	else if (IsNextWord("collected", strUnreadLine))
	{
			ReadText("collected", strUnreadLine);
			ReadText("$", strUnreadLine);
			int iAmount = GetNextNumber(strUnreadLine);
			sm_cInputHand.SetPlayerProfitLoss(strNick, iAmount);
	}
	CParseState* pNewState = new CPSStarsShowDown(m_cParseFile);
	delete this;
	return pNewState;
}

CString CPSStarsShowDown::ReadPredfinedNickPlusAction(CString& strUnreadLine)
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
				strUnreadLine = strUnreadLine.Right(strUnreadLine.GetLength() - strToInspect.GetLength());	
				return strToInspect;
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
				strUnreadLine = strUnreadLine.Right(strUnreadLine.GetLength() - strToInspect.GetLength());	
				return strToInspect;
			}
		}
	}

	return  "";
}

