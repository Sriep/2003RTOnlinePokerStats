// PSPartyLog.h: interface for the CPSPartyLog class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PSPARTYLOG_H__16C7EAB6_3B1A_4D50_A737_A7EED60C50D7__INCLUDED_)
#define AFX_PSPARTYLOG_H__16C7EAB6_3B1A_4D50_A737_A7EED60C50D7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ParseState.h"

class CPSPartyLog : public CParseState  
{
public:
	CPSPartyLog(CParseFile* pPF);
	virtual ~CPSPartyLog();
	virtual CParseState* Parse(const CString &strInLine);
	virtual CParseState* ParseI(const CString &strInLine, const CString &strFullLine) = 0;
	bool PartyLogIgnoreLine(const CString& strInLine);
};

inline bool CPSPartyLog::PartyLogIgnoreLine(const CString& strInLine)
{
	if(IsNextWord("Congratulations", strInLine))
	{
		return true;
	}
	return IsLastWord("out.", strInLine)
		|| IsLastWord("table.", strInLine)
		|| 	IsLastWord("time.", strInLine)
		|| IsLastWord("capped", strInLine);
}

#endif // !defined(AFX_PSPARTYLOG_H__16C7EAB6_3B1A_4D50_A737_A7EED60C50D7__INCLUDED_)
