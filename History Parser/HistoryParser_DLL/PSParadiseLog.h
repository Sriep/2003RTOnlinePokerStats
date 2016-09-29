// PSParadiseLog.h: interface for the CPSParadiseLog class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PSParadiseLOG_H__16C7EAB6_3B1A_4D50_A737_A7EED60C50D7__INCLUDED_)
#define AFX_PSParadiseLOG_H__16C7EAB6_3B1A_4D50_A737_A7EED60C50D7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ParseState.h"

class CPSParadiseLog : public CParseState  
{
public:
	CPSParadiseLog(CParseFile* pPF);
	virtual ~CPSParadiseLog();
	virtual CParseState* Parse(const CString &strInLine);
	virtual CParseState* ParseI(const CString &strInLine, const CString &strFullLine) = 0;
	bool ParadiseLogIgnoreLine(const CString& strInLine);
};

inline bool CPSParadiseLog::ParadiseLogIgnoreLine(const CString& strInLine)
{
	if(IsNextWord("Congratulations", strInLine)
		|| IsNextWord("To get", strInLine)
		|| IsNextWord("»Dealer: Please remember", strInLine)
		|| IsNextWord("»Dealer: Our fairness", strInLine)
		|| IsNextWord("»Dealer: If you do", strInLine) )
	{
		return true;
	}

	return IsLastWord("out", strInLine)
		|| IsLastWord("table", strInLine)			 
		|| IsLastWord("time", strInLine)	   
		|| IsLastWord("turn.", strInLine)
		|| IsLastWord("turn", strInLine)
		|| IsLastWord("button", strInLine)
		|| IsLastWord("starting up.", strInLine)
		|| IsLastWord("starting up", strInLine)
		|| IsLastWord("down.", strInLine)
		|| IsLastWord("down.", strInLine)
		|| IsLastWord("'", strInLine)
		|| IsLastWord("capped", strInLine)
		|| IsLastWord("blinds", strInLine)
		|| IsLastWord("!", strInLine);
}


#endif // !defined(AFX_PSParadiseLOG_H__16C7EAB6_3B1A_4D50_A737_A7EED60C50D7__INCLUDED_)
