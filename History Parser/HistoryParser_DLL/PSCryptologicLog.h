// PSCryptologicLog.h: interface for the CPSCryptologicLog class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PSCryptologicLOG_H__16C7EAB6_3B1A_4D50_A737_A7EED60C50D7__INCLUDED_)
#define AFX_PSCryptologicLOG_H__16C7EAB6_3B1A_4D50_A737_A7EED60C50D7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ParseState.h"
#include "ParseCryptologicLogFile.h"

class CPSCryptologicLog : public CParseState  
{
public:
	CPSCryptologicLog(CParseFile* pPF);
	virtual ~CPSCryptologicLog();
	virtual CParseState* Parse(const CString &strInLine);
	virtual CParseState* ParseI(const CString &strInLine, const CString &strFullLine) = 0;
	bool CryptologicLogIgnoreLine(const CString& strInLine);

	void SetToNextRound();
	CParserCryptologicLogFile* GetCryptologicLogFile();
};

inline bool CPSCryptologicLog::CryptologicLogIgnoreLine(const CString& strInLine)
{
	if(IsNextWord("Congratulations", strInLine))
	{
		return true;	    
	}
	if (-1 != strInLine.Find("Dealing "))
		return true;
	if (-1 != strInLine.Find("not called, return back"))
		return true;
	if (-1 != strInLine.Find("is not waiting"))
		return true;
	if (-1 != strInLine.Find("waiting for"))
		return true;
	if (-1 != strInLine.Find("joins"))
		return true;
	return IsLastWord("out", strInLine)
		|| IsLastWord("table", strInLine)
		|| IsLastWord("time", strInLine)
		|| IsLastWord("capped", strInLine)
		|| IsLastWord("act", strInLine)
		|| IsLastWord("out and folded.", strInLine)
		|| IsLastWord("started", strInLine)
		|| IsLastWord("available", strInLine)
		|| IsLastWord("back", strInLine);
}

inline 	void CPSCryptologicLog::SetToNextRound()
{
	sm_cInputHand.SetToNextRound();
	GetCryptologicLogFile()->NewRound();
}

inline 	CParserCryptologicLogFile* CPSCryptologicLog::GetCryptologicLogFile()
{
	return (CParserCryptologicLogFile*) m_cParseFile;
}



#endif // !defined(AFX_PSCryptologicLOG_H__16C7EAB6_3B1A_4D50_A737_A7EED60C50D7__INCLUDED_)
