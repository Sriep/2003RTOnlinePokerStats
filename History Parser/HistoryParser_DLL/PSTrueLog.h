// PSTrueLog.h: interface for the CPSTrueLog class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CPSTrueLog__INCLUDED_)
#define AFX_CPSTrueLog__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ParseState.h"

class CPSTrueLog : public CParseState  
{
public:
	CPSTrueLog(CParseFile* pPF);
	virtual ~CPSTrueLog();
	virtual CParseState* Parse(const CString &strInLine);
	virtual CParseState* ParseI(const CString &strInLine, const CString &strFullLine) = 0;
	bool TrueLogIgnoreLine(const CString& strInLine);
};

inline bool CPSTrueLog::TrueLogIgnoreLine(const CString& strInLine)
{
	 
	if (-1 != strInLine.Find("was returned"))
		return true;

	return IsLastWord("reconnected", strInLine)
		|| IsLastWord("table", strInLine)
		|| IsLastWord("button", strInLine)
		|| IsLastWord("button.", strInLine)
		|| IsLastWord("has timed out and will now be folded", strInLine)
		|| IsLastWord("sat out", strInLine);
}

#endif // !defined(AFX_CPSTrueLog__INCLUDED_)
