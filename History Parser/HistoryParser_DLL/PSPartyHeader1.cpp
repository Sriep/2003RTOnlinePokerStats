// PSPartyHeader1.cpp: implementation of the CPSPartyHeader1 class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PSPartyHeader1.h"
#include "PSNone.h"
#include "ParsingException.h"
#include "PSPartyHeader2.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

const CString CPSPartyHeader1::TEXAS_HOLDEM_TABLE = "TexasHTGameTable";

CPSPartyHeader1::CPSPartyHeader1(CParseFile* pPF)
: CParseState(pPF)
{

}

CPSPartyHeader1::~CPSPartyHeader1()
{

}

CParseState* CPSPartyHeader1::Parse(const CString &strInLine)
{
	try
	{
		CString strUnreadLine = strInLine;
		sm_listNicks.clear();

		sm_cInputHand.SetSmallBet(GetNextNumber(strUnreadLine));
		ReadText(CHAR_FOWARD_SLASH, strUnreadLine);
		sm_cInputHand.SetBigBet(GetNextNumber(strUnreadLine));
		sm_cInputHand.SetGame(GetGame(strUnreadLine));
		ReadText(CHAR_DASH, strUnreadLine);
		sm_cInputHand.SetDate(GetDate(strUnreadLine));
		CParseState* pNewState = new CPSPartyHeader2(m_cParseFile);
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

PokerGames CPSPartyHeader1::GetGame(CString& strUnreadLine) 
{
	strUnreadLine.TrimLeft(' ');   

	CString strGameType = strUnreadLine.SpanIncluding(LETTERS);
	if (strGameType != "TexasHTGameTable")
	{
		throw(new CParsingException(IDS_NOT_TEXAS_HOLDEM,  this, new CPSNone(m_cParseFile)));
	}
	strUnreadLine = strUnreadLine.Right(strUnreadLine.GetLength() - strGameType.GetLength());
	if (IsNextWord("(Limit)", strUnreadLine))
	{
		ReadText("(Limit)", strUnreadLine);
	}

	return GAME_TEXUS_HOLDEM;
}

CTime CPSPartyHeader1::GetDate(CString& strUnreadLine) 
{
	GetNextWord(strUnreadLine);	   //Day of week
	int iMonth = GetMounthAsInt(GetNextWord(strUnreadLine));
	int iDay = GetNextNumber(strUnreadLine);
	int iHour = GetNextNumber(strUnreadLine);
	ReadText(CHAR_COLON, strUnreadLine);
	int iMins = GetNextNumber(strUnreadLine);
	ReadText(CHAR_COLON, strUnreadLine);
	int iSecs = GetNextNumber(strUnreadLine);
	//ReadText("EDT", strUnreadLine);
	int iYear =  ReverseGetNextNumber(strUnreadLine);
	return CTime(iYear, iMonth, iDay, iHour, iMins, iSecs);
}

