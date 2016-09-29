// PSTrueLog.cpp: implementation of the CPSTrueLog class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "HistoryParser_DLL.h"
#include "PSTrueLog.h"
#include "TrueLogNone.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPSTrueLog::CPSTrueLog(CParseFile* pPF)
: CParseState(pPF)
{

}

CPSTrueLog::~CPSTrueLog()
{

}

CParseState* CPSTrueLog::Parse(const CString &strInLine)
{
	CString strUnreadLine = strInLine;

	if (TrueLogIgnoreLine(strUnreadLine))
	{
		return this;
	}
	strUnreadLine.TrimLeft(' ');
	strUnreadLine.TrimRight('\x0D');
	CParseState* pNextState;
	pNextState = ParseI(strUnreadLine, strInLine);

	if (this != (CPSTrueLog*) pNextState)
	{
		delete this;
	}
	return pNextState;
}



