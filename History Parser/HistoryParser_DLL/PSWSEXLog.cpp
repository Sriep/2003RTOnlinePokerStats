// PSWSEXLog.cpp: implementation of the CPSWSEXLog class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PSWSEXLog.h"
#include "PSWSEXLogSummary.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPSWSEXLog::CPSWSEXLog(CParseFile* pPF)
: CParseState(pPF)
{

}

CPSWSEXLog::~CPSWSEXLog()
{

}

CParseState* CPSWSEXLog::Parse(const CString &strInLine)
{
	CString strUnreadLine = strInLine;

	if (!ReadIfNextWord("Dealer:", strUnreadLine))
	{
		return this;
	}

	strUnreadLine.TrimRight('\x0D');
	if (WSEXLogIgnoreLine(strUnreadLine))
	{
		return this;
	}
	strUnreadLine.TrimLeft(' ');
	strUnreadLine.TrimRight('\x0D');

	CParseState* pNextState = ParseI(strUnreadLine, strInLine);

	if (this != (CPSWSEXLog*) pNextState)
	{
		delete this;
	}
	return pNextState;
}



