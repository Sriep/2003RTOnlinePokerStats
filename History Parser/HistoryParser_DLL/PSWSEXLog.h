// PSWSEXLog.h: interface for the CPSWSEXLog class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PSWSEXLOG_H__16C7EAB6_3B1A_4D50_A737_A7EED60C50D7__INCLUDED_)
#define AFX_PSWSEXLOG_H__16C7EAB6_3B1A_4D50_A737_A7EED60C50D7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ParseState.h"

class CPSWSEXLog : public CParseState  
{
public:
	CPSWSEXLog(CParseFile* pPF);
	virtual ~CPSWSEXLog();
	virtual CParseState* Parse(const CString &strInLine);
	virtual CParseState* ParseI(const CString &strInLine, const CString &strFullLine) = 0;
	bool WSEXLogIgnoreLine(const CString& strInLine);
};

inline bool CPSWSEXLog::WSEXLogIgnoreLine(const CString& strInLine)
{
	if(IsNextWord("Congratulations", strInLine))
	{
		return true;	    
	}
	if (-1 != strInLine.Find("not called, return back"))
		return true;
	if (-1 != strInLine.Find("is not waiting"))
		return true;
	if (-1 != strInLine.Find("waiting for"))
		return true;
	if (-1 != strInLine.Find("tournament table"))
		return true;
	return IsLastWord("out", strInLine)
		|| IsLastWord("table", strInLine)
		|| 	IsLastWord("time", strInLine)
		|| IsLastWord("capped", strInLine)
		|| IsLastWord("act", strInLine)
		|| IsLastWord("out and folded.", strInLine)
		|| IsLastWord("started", strInLine)
		|| IsLastWord("available", strInLine)
		|| IsLastWord("back", strInLine);
}

#endif // !defined(AFX_PSWSEXLOG_H__16C7EAB6_3B1A_4D50_A737_A7EED60C50D7__INCLUDED_)
