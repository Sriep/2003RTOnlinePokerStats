// PSParadiseGetBigBlind.cpp: implementation of the CPSParadiseGetBigBlind class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PSParadiseGetBigBlind.h"

#include "PSParadisePlayerAction.h"
#include "PSNone.h"
#include "ParsingException.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPSParadiseGetBigBlind::CPSParadiseGetBigBlind(CParseFile* pPF)
: CParseState(pPF)
{

}

CPSParadiseGetBigBlind::~CPSParadiseGetBigBlind()
{

}

CParseState* CPSParadiseGetBigBlind::Parse(const CString &strInLine)
{
	CString strUnreadLine = strInLine;

	if (ParadiseIgnoreLine(strInLine))
	{
		return this;
	}

	if (strInLine == "Dealing...") //IsNextWord("Dealing...", strUnreadLine))
	{
		CParseState* pNewState = new CPSParadisePlayerAction(m_cParseFile);
		delete this;
		return pNewState;
	}

	if (strInLine == "*** SUMMARY ***")
	{
		throw(new CParsingException(IDS_NOTHING_GAME, this, new CPSNone(m_cParseFile)));
	}

	CString strNick = ReadLongNick(strUnreadLine);
	
	if (IsNextWord("said", strUnreadLine))
	{
		return this;
	}
	ReverseReadText(")", strUnreadLine);
	int iBigBlind = ReverseGetNextNumber(strUnreadLine);

	if ( strInLine.Find(": Post Big Blind ($") >= 0)
	{
		sm_cInputHand.SetBigBlind(strNick, iBigBlind);
		sm_itterLastNicks = Find(strNick);
		return this;
	}
	else if (strInLine.Find("Post") >= 0 )
	{
		sm_cInputHand.AddPlayerAction(strNick, PPlayerAction(PPlayerAction::ACTION_POST), iBigBlind);
		return this;
	}
	else
	{
		return ChangeState(new CPSParadisePlayerAction(m_cParseFile), strInLine);	
	}
}
