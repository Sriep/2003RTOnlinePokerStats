// PSParadiseLog.cpp: implementation of the CPSParadiseLog class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "HistoryParser_DLL.h"
#include "PSParadiseLog.h"
#include "PSParadiseLogResult.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPSParadiseLog::CPSParadiseLog(CParseFile* pPF)
: CParseState(pPF)
{

}

CPSParadiseLog::~CPSParadiseLog()
{

}

CParseState* CPSParadiseLog::Parse(const CString &strInLine)
{
	CParseState* pNextState = NULL;
	CString strUnreadLine = strInLine;
	strUnreadLine.TrimRight('\x0D');

	if (!ReadIfNextWord("»Dealer:", strUnreadLine))
	{
		if (IsNextWord("»#", strUnreadLine))
		{
			CParseState* pNewState = new  CPSParadiseLogResult(m_cParseFile);
			pNextState = ChangeState(pNewState,  strInLine);
			if (this != (CPSParadiseLog*) pNextState)
			{
				delete this;
			}
			return pNextState;
		}
		return this;
	}
	strUnreadLine.TrimLeft(' ');

	if (ParadiseLogIgnoreLine(strUnreadLine))
	{
		TRACE("Ignoring line %s\n", strInLine);
		return this;
	}

	if (strUnreadLine.Left(strlen("** DEALING POCKETS **")) == "** DEALING POCKETS **")
	{
		return this;
	}

	strUnreadLine.TrimLeft(' ');
	strUnreadLine.TrimRight('\x0D');
	
	pNextState = ParseI(strUnreadLine, strInLine);
	if (this != (CPSParadiseLog*) pNextState)
	{
		delete this;
	}
	return pNextState;
}



