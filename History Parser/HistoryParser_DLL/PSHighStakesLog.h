// PSHighStakesLog.h: interface for the CPSHighStakesLog class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PSHighStakesLOG_H__16C7EAB6_3B1A_4D50_A737_A7EED60C50D7__INCLUDED_)
#define AFX_PSHighStakesLOG_H__16C7EAB6_3B1A_4D50_A737_A7EED60C50D7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ParseState.h"

class CPSHighStakesLog : public CParseState  
{
public:
	CPSHighStakesLog(CParseFile* pPF);
	virtual ~CPSHighStakesLog();
	virtual CParseState* Parse(const CString &strInLine);
	virtual CParseState* ParseI(const CString &strInLine, const CString &strFullLine) = 0;
	bool HighStakesLogIgnoreLine(const CString& strInLine);
};

inline bool CPSHighStakesLog::HighStakesLogIgnoreLine(const CString& strInLine)
{
	if(IsNextWord("Dealing Hole Cards", strInLine))
	{
		return true;		   
	}
	return IsLastWord("out", strInLine)
		|| IsLastWord("table", strInLine)
		|| 	IsLastWord("time", strInLine)
		|| 	IsLastWord("down", strInLine)
		|| 	IsLastWord("respond", strInLine)
		|| 	IsLastWord("reconnect", strInLine)
		|| 	IsLastWord("reconnected", strInLine);
}

#endif // !defined(AFX_PSHighStakesLOG_H__16C7EAB6_3B1A_4D50_A737_A7EED60C50D7__INCLUDED_)
