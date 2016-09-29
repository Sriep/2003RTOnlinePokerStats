// PSWSEXLogDealing.cpp: implementation of the CPSWSEXLogDealing class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "HistoryParser_DLL.h"
#include "PSWSEXLogDealing.h"
#include "PSNone.h"
#include "PSWSEXLogPlayerFirxtAction.h"
#include "PSWSEXLogPlayerAction.h"
#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPSWSEXLogDealing::CPSWSEXLogDealing(CParseFile* pPF)
: CPSWSEXLog(pPF)
{

}

CPSWSEXLogDealing::~CPSWSEXLogDealing()
{

}

CParseState* CPSWSEXLogDealing::ParseI(const CString& strInLine, const CString &strFullLine)
{

	CString strUnreadLine = strInLine;

	ReadText(CHAR_ASTERIX, strUnreadLine);
	ReadText(CHAR_ASTERIX, strUnreadLine);
	ReadText(WORD_Dealing, strUnreadLine);
	CString strRound = GetNextWord(strUnreadLine);

	if (strRound == WORD_down)
	{
		return new CPSWSEXLogPlayerFirstAction(m_cParseFile);
	}
	else if (strRound == WORD_Flop)
	{
		ParseFlopDeal(strUnreadLine);
	}
	else if (strRound == WORD_Turn)
	{
		ParseTurnDeal(strUnreadLine);
	}
	else if (strRound == WORD_River)
	{
		ParseRiverDeal(strUnreadLine);
	}
	else
	{
		throw(new CParsingException(IDS_UNEXPECTED_TEXT, this, new CPSNone(m_cParseFile)));
	}
	return  new CPSWSEXLogPlayerAction(m_cParseFile);
}


