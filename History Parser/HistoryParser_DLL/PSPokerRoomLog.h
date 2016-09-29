// PSPokerRoomLog.h: interface for the CPSPokerRoomLog class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PSPokerRoomLOG_H__16C7EAB6_3B1A_4D50_A737_A7EED60C50D7__INCLUDED_)
#define AFX_PSPokerRoomLOG_H__16C7EAB6_3B1A_4D50_A737_A7EED60C50D7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ParseState.h"

class CPSPokerRoomLog : public CParseState  
{
public:
	CPSPokerRoomLog(CParseFile* pPF);
	virtual ~CPSPokerRoomLog();
	virtual CParseState* Parse(const CString &strInLine);
	virtual CParseState* ParseI(const CString &strInLine, const CString &strFullLine) = 0;
	bool PokerRoomLogIgnoreLine(const CString& strInLine);
};

inline bool CPSPokerRoomLog::PokerRoomLogIgnoreLine(const CString& strInLine)
{
	if(IsNextWord("Remaining", strInLine))
	//	|| IsNextWord("To get", strInLine)
	//	|| IsNextWord("»Dealer: Please remember", strInLine)
	//	|| IsNextWord("»Dealer: Our fairness", strInLine)
	//	|| IsNextWord("»Dealer: If you do", strInLine) )
	{
		return true;
	}
	if (strInLine.IsEmpty() || strInLine == "----------------------------")
		return true;   

	return IsLastWord("out.", strInLine)
		|| IsLastWord("table.", strInLine)			 
		|| IsLastWord("time.", strInLine)	   
		|| IsLastWord("turn.", strInLine)
		|| IsLastWord("game.", strInLine)
		|| IsLastWord("starting up.", strInLine)
		|| IsLastWord("dealer.", strInLine)
		|| IsLastWord("down.", strInLine)
		|| IsLastWord("down", strInLine)
		|| IsLastWord("connection.", strInLine)
		|| IsLastWord("'", strInLine)
		|| IsLastWord("capped.", strInLine)
		|| IsLastWord("leaves.", strInLine)
		|| IsLastWord("in.", strInLine)
		|| IsLastWord("online.", strInLine)
		|| IsLastWord("!", strInLine);
}


#endif // !defined(AFX_PSPokerRoomLOG_H__16C7EAB6_3B1A_4D50_A737_A7EED60C50D7__INCLUDED_)
