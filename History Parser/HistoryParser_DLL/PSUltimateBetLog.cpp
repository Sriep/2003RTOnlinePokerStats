// PSUltimateBetLog.cpp: implementation of the CPSUltimateBetLog class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "HistoryParser_DLL.h"
#include "PSUltimateBetLog.h"
#include "UltimateBetLogNone.h"
#include "PSUltimateBetLogShowdown.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPSUltimateBetLog::CPSUltimateBetLog(CParseFile* pPF)
: CParseState(pPF)
{

}

CPSUltimateBetLog::~CPSUltimateBetLog()
{

}

CParseState* CPSUltimateBetLog::Parse(const CString &strInLine)
{
	CString strUnreadLine = strInLine;
	strUnreadLine.TrimRight('\x0D');

	if (!ReadIfNextWord("Dealer: ", strUnreadLine))
	{
		return this;
	}
	CParseState* pNextState = NULL;

	if (UltimateBetLogIgnoreLine(strUnreadLine))
	{
		return this;
	}
	strUnreadLine.TrimLeft(' ');
	strUnreadLine.TrimRight('\x0D');
	pNextState = ParseI(strUnreadLine, strInLine);

	if (this != (CPSUltimateBetLog*) pNextState)
	{
		delete this;
	}
	return pNextState;
}

bool CPSUltimateBetLog::UltimateBetLogIgnoreLine(const CString& strInLine)
{
	
	if(IsNextWord("Congratulations", strInLine)
		|| IsNextWord("Waiting for others to post.", strInLine)
		|| IsNextWord("Asking ", strInLine)
		|| IsNextWord("to respond.", strInLine))
	{
		return true;
	}

	if(strInLine.Find("table at seat") != -1)
	{
		return true;
	}

	return IsLastWord("out.", strInLine)
		|| IsLastWord("table.", strInLine)
		|| 	IsLastWord("time.", strInLine)
		|| IsLastWord("play now.", strInLine)
		|| IsLastWord("the game.", strInLine)
		|| IsLastWord(" time.", strInLine) 
		|| IsLastWord("reconnect.", strInLine)
		|| IsLastWord("reconnected.", strInLine)
		|| IsLastWord("respond.", strInLine)
		|| IsLastWord("soon leave.", strInLine)
		|| IsLastWord("rebuy.", strInLine);
}


