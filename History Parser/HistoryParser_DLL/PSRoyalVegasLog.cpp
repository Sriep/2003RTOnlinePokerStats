// PSRoyalVegasLog.cpp: implementation of the CPSRoyalVegasLog class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "HistoryParser_DLL.h"
#include "PSRoyalVegasLog.h"
#include "RoyalVegasLogNone.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPSRoyalVegasLog::CPSRoyalVegasLog(CParseFile* pPF)
: CParseState(pPF)
{

}

CPSRoyalVegasLog::~CPSRoyalVegasLog()
{

}

CParseState* CPSRoyalVegasLog::Parse(const CString &strInLine)
{
	CString strUnreadLine = strInLine;
	strUnreadLine.TrimRight('\x0D');

	if (!ReadIfNextWord(">", strUnreadLine))
	{
		return this;
	}

	if (RoyalVegasLogIgnoreLine(strUnreadLine))
	{
		return this;
	}
	strUnreadLine.TrimLeft(' ');
	CParseState* pNextState = ParseI(strUnreadLine, strInLine);

	if (this != (CPSRoyalVegasLog*) pNextState)
	{
		delete this;
	}
	return pNextState;
}



