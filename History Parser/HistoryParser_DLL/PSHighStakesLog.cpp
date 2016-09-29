// PSHighStakesLog.cpp: implementation of the CPSHighStakesLog class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "HistoryParser_DLL.h"
#include "PSHighStakesLog.h"
#include "HighStakesLogNone.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPSHighStakesLog::CPSHighStakesLog(CParseFile* pPF)
: CParseState(pPF)
{

}

CPSHighStakesLog::~CPSHighStakesLog()
{

}

CParseState* CPSHighStakesLog::Parse(const CString &strInLine)
{
	CString strUnreadLine = strInLine;
	strUnreadLine.TrimRight('\x0D');

	if (!ReadIfNextWord("D: ", strUnreadLine))
	{
		return this;
	}

	if (HighStakesLogIgnoreLine(strUnreadLine))
	{
		return this;
	}
	strUnreadLine.TrimLeft(' ');

	if (strUnreadLine.IsEmpty())
		return this;
	CParseState* pNextState = ParseI(strUnreadLine, strInLine);

	if (this != (CPSHighStakesLog*) pNextState)
	{
		delete this;
	}
	return pNextState;
}



