// PSRoyalVegasLog.h: interface for the CPSRoyalVegasLog class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PSRoyalVegasLOG_H__16C7EAB6_3B1A_4D50_A737_A7EED60C50D7__INCLUDED_)
#define AFX_PSRoyalVegasLOG_H__16C7EAB6_3B1A_4D50_A737_A7EED60C50D7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ParseState.h"

class CPSRoyalVegasLog : public CParseState  
{
public:
	CPSRoyalVegasLog(CParseFile* pPF);
	virtual ~CPSRoyalVegasLog();
	virtual CParseState* Parse(const CString &strInLine);
	virtual CParseState* ParseI(const CString &strInLine, const CString &strFullLine) = 0;
	bool RoyalVegasLogIgnoreLine(const CString& strInLine);
};

inline bool CPSRoyalVegasLog::RoyalVegasLogIgnoreLine(const CString& strInLine)
{
	if(IsNextWord("Dealing Hole Cards", strInLine))
	{
		return true;		   
	}
	if(IsNextWord("Extra chips returned", strInLine))
	{
		return true;		   
	}	   
	if (-1 != strInLine.Find("did not act in time and was"))
		return true;
	return IsLastWord("out", strInLine)			 
		|| IsLastWord("table", strInLine)
		|| IsLastWord("time", strInLine)
		|| IsLastWord("down", strInLine)
		|| IsLastWord("respond", strInLine)
		|| IsLastWord("reconnect", strInLine)
		|| IsLastWord("reconnected", strInLine)
		|| IsLastWord(" passed", strInLine);
}

#endif // !defined(AFX_PSRoyalVegasLOG_H__16C7EAB6_3B1A_4D50_A737_A7EED60C50D7__INCLUDED_)
