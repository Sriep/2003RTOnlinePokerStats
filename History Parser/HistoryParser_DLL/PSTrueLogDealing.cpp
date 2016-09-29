// PSTrueLogDealing.cpp: implementation of the CPSTrueLogDealing class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "HistoryParser_DLL.h"
#include "PSTrueLogDealing.h"
#include "PSNone.h"
#include "PSTrueLogPlayerFirxtAction.h"
#include "PSTrueLogPlayerAction.h"
#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPSTrueLogDealing::CPSTrueLogDealing(CParseFile* pPF)
: CPSTrueLog(pPF)
{

}

CPSTrueLogDealing::~CPSTrueLogDealing()
{

}

CParseState* CPSTrueLogDealing::ParseI(const CString& strInLine, const CString &strFullLine)
{

	CString strUnreadLine = strInLine;

	ReadText("Dealing", strUnreadLine);
	CString strRound = GetNextWord(strUnreadLine);

	if (strRound == WORD_Flop)
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
	return  new CPSTrueLogPlayerAction(m_cParseFile);
}


