// PSStarsHeader1.cpp: implementation of the CPSStarsHeader1 class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PSStarsHeader1.h"
#include "PSNone.h"
#include "ParsingException.h"
#include "PSStarsHeader2.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

const CString CPSStarsHeader1::TEXAS_HOLDEM_TABLE = "TexasHTGameTable";

CPSStarsHeader1::CPSStarsHeader1(CParseFile* pPF)
: CParseState(pPF)
{

}

CPSStarsHeader1::~CPSStarsHeader1()
{

}

CParseState* CPSStarsHeader1::Parse(const CString &strInLine)
{
	try
	{
		CString strUnreadLine = strInLine;
		sm_listNicks.clear();


		ReadText("PokerStars", strUnreadLine);
		ReadText("Game", strUnreadLine);
		ReadText("#", strUnreadLine);
		sm_cInputHand.SetGameNumber(GetNextNumber(strUnreadLine)); 
		ReadText(":", strUnreadLine);
		CString strGame = GetNextWord(strUnreadLine);
		CString strLimit = GetNextWord(strUnreadLine);
		if (strGame != "Hold'em" || strLimit != "Limit")
		{
			throw(new CParsingException(IDS_VARAINT_NOT_SUPPORTED, strGame + strLimit, this, new CPSNone(m_cParseFile)));
		}
		sm_cInputHand.SetGame(GAME_TEXUS_HOLDEM); 

		ReadText("(", strUnreadLine);
		ReadText("$", strUnreadLine);
		sm_cInputHand.SetSmallBet(GetNextNumber(strUnreadLine));
		ReadText("/", strUnreadLine);
		ReadText("$", strUnreadLine);
		sm_cInputHand.SetBigBet(GetNextNumber(strUnreadLine));
		ReadText(")", strUnreadLine);
		ReadText("-", strUnreadLine);

		sm_cInputHand.SetDate(GetDate(strUnreadLine));
		CParseState* pNewState = new CPSStarsHeader2(m_cParseFile);
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

CTime CPSStarsHeader1::GetDate(CString& strUnreadLine) 
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
	ReadText("(EST)", strUnreadLine);
	return CTime(iYear, iMonth, iDay, iHour, iMins, iSecs);
}

