// PSUltimateBetLog.h: interface for the CPSUltimateBetLog class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PSUltimateBetLOG_H__16C7EAB6_3B1A_4D50_A737_A7EED60C50D7__INCLUDED_)
#define AFX_PSUltimateBetLOG_H__16C7EAB6_3B1A_4D50_A737_A7EED60C50D7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ParseState.h"

class CPSUltimateBetLog : public CParseState  
{
public:
	CPSUltimateBetLog(CParseFile* pPF);
	virtual ~CPSUltimateBetLog();
	virtual CParseState* Parse(const CString &strInLine);
	virtual CParseState* ParseI(const CString &strInLine, const CString &strFullLine) = 0;
	bool UltimateBetLogIgnoreLine(const CString& strInLine);
//	virtual CParseState* ChangeState(CParseState* pNewState, const CString& strInLine);
};

#endif // !defined(AFX_PSUltimateBetLOG_H__16C7EAB6_3B1A_4D50_A737_A7EED60C50D7__INCLUDED_)
