// PSParadiseGetSmallBlind.cpp: implementation of the CPSParadiseGetSmallBlind class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PSParadiseGetSmallBlind.h"

#include "PSParadiseGetBigBlind.h"
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

CPSParadiseGetSmallBlind::CPSParadiseGetSmallBlind(CParseFile* pPF)
: CParseState(pPF)
{

}

CPSParadiseGetSmallBlind::~CPSParadiseGetSmallBlind()
{

}

CParseState* CPSParadiseGetSmallBlind::Parse(const CString &strInLine)
{
	CString strUnreadLine = strInLine;

	if (ParadiseIgnoreLine(strInLine))
	{
		return this;
	}

	if (strInLine == "*** SUMMARY ***")
	{
		throw(new CParsingException(IDS_NOTHING_GAME, this, new CPSNone(m_cParseFile)));
	}

	ReverseReadText(")", strUnreadLine);
	int iSmallBlind = ReverseGetNextNumber(strUnreadLine);
	ReverseReadText("$", strUnreadLine);
	ReverseReadText("(", strUnreadLine);

	ReverseReadText("Blind", strUnreadLine);
	ReverseReadText("Small", strUnreadLine);
	ReverseReadText("Post", strUnreadLine);
	ReverseReadText(":", strUnreadLine);
	strUnreadLine.TrimLeft(' ');
	strUnreadLine.TrimRight(' ');

	sm_cInputHand.SetSmallBlind(strUnreadLine, iSmallBlind);
	sm_itterLastNicks = Find(strUnreadLine);
	CParseState* pNewState = new CPSParadiseGetBigBlind(m_cParseFile);
	delete this;
	return pNewState;
}
