// PSParadiseHeader1.cpp: implementation of the CPSParadiseHeader1 class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PSParadiseHeader1.h"
#include "PSNone.h"
#include "ParsingException.h"
#include "PSParadiseHeader2.h"
#include "PPokerSite.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

const CString CPSParadiseHeader1::TEXAS_HOLDEM_TABLE = "TexasHTGameTable";

CPSParadiseHeader1::CPSParadiseHeader1(CParseFile* pPF)
: CParseState(pPF)
{

}

CPSParadiseHeader1::~CPSParadiseHeader1()
{

}

CParseState* CPSParadiseHeader1::Parse(const CString &strInLine)
{
	if (strInLine == "If you have any questions regarding this hand history,")
	{
		CParseState* pNewState = new CPSNone(m_cParseFile);
		delete this;
		return pNewState;
	}
	try
	{
		CString strUnreadLine = strInLine;
		sm_listNicks.clear();

		ReadText("Game", strUnreadLine);
		ReadText("#", strUnreadLine);
		sm_cInputHand.SetGameNumber(GetNextNumber(strUnreadLine));
		sm_cInputHand.SetPokerSite(PPokerSite::POKER_SITE_PARADISE);
		ReadText("-", strUnreadLine);

		ReadText("$", strUnreadLine);
		sm_cInputHand.SetSmallBet(GetNextNumber(strUnreadLine));
		ReadText("/", strUnreadLine);
		ReadText("$", strUnreadLine);
		sm_cInputHand.SetBigBet(GetNextNumber(strUnreadLine));

		CString strTexas = GetNextWord(strUnreadLine);
		CString strHoldem = GetNextWord(strUnreadLine);
		if (strTexas != "Texas" || strHoldem != "Hold'em")
		{
			throw(new CParsingException(IDS_VARAINT_NOT_SUPPORTED, strTexas + strHoldem, this, new CPSNone(m_cParseFile)));
		}
		sm_cInputHand.SetGame(GAME_TEXUS_HOLDEM); 
		ReadText("-", strUnreadLine);
		sm_cInputHand.SetDate(GetDate(strUnreadLine));
		CParseState* pNewState = new CPSParadiseHeader2(m_cParseFile);
		delete this;
		return pNewState;
	}
	catch (CParsingException* pException)
	{	
		if(pException->IsSkipLine())
		{
			delete pException;
			throw(new CParsingException(IDS_HEADER_ERROR));
		}
		else
		{
			throw(pException);
		}
	}
}

PokerGames CPSParadiseHeader1::GetGame(CString& strUnreadLine) 
{
	strUnreadLine.TrimLeft(' ');   

	CString strGameType = strUnreadLine.SpanIncluding(LETTERS);
	if (strGameType != TEXAS_HOLDEM_TABLE)
	{
		throw(new CParsingException(IDS_VARAINT_NOT_SUPPORTED,  this, new CPSNone(m_cParseFile)));
	}
	strUnreadLine = strUnreadLine.Right(strUnreadLine.GetLength() - strGameType.GetLength());

	return GAME_TEXUS_HOLDEM;
}

CTime CPSParadiseHeader1::GetDate(CString& strUnreadLine) 
{
	int iYear = GetNextNumber(strUnreadLine);
	ReadText("/", strUnreadLine);
	int iMonth = GetNextNumber(strUnreadLine);
	ReadText("/", strUnreadLine);
	int iDay = GetNextNumber(strUnreadLine);
	ReadText("-", strUnreadLine);
	int iHour = GetNextNumber(strUnreadLine);
	ReadText(CHAR_COLON, strUnreadLine);
	int iMins = GetNextNumber(strUnreadLine);
	ReadText(CHAR_COLON, strUnreadLine);
	int iSecs = GetNextNumber(strUnreadLine);
	ReadText("(CST)", strUnreadLine);
	return CTime(iYear, iMonth, iDay, iHour, iMins, iSecs);
}

