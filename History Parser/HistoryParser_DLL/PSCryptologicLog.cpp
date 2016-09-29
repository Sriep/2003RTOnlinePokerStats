// PSCryptologicLog.cpp: implementation of the CPSCryptologicLog class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PSCryptologicLog.h"
#include "PSCryptologicLogSummary.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPSCryptologicLog::CPSCryptologicLog(CParseFile* pPF)
: CParseState(pPF)
{

}

CPSCryptologicLog::~CPSCryptologicLog()
{

}

CParseState* CPSCryptologicLog::Parse(const CString &strInLine)
{
	CString strUnreadLine = strInLine;

	if (!ReadIfNextWord("Dealer:", strUnreadLine))
	{
		return this;
	}

	strUnreadLine.TrimRight('\x0D');
	if (CryptologicLogIgnoreLine(strUnreadLine))
	{
		return this;
	}
	strUnreadLine.TrimLeft(' ');
	strUnreadLine.TrimRight('\x0D');

	CParseState* pNextState = ParseI(strUnreadLine, strInLine);

	if (this != (CPSCryptologicLog*) pNextState)
	{
		delete this;
	}
	return pNextState;
}



