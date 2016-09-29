// PSTrueLogSmallBlind.h: interface for the CPSTrueLogSmallBlind class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CPSTrueLogSmallBlind__INCLUDED_)
#define AFX_CPSTrueLogSmallBlind__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "PSTrueLog.h"

class CPSTrueLogSmallBlind : public CPSTrueLog  
{
public:
	CPSTrueLogSmallBlind(CParseFile* pPF);
	virtual ~CPSTrueLogSmallBlind();
	virtual CParseState* ParseI(const CString &strInLine, const CString &strFullLine);
	bool NotSmallBlindYet(const CString& strInLine) const;
};

inline bool CPSTrueLogSmallBlind::NotSmallBlindYet(const CString& strInLine) const
{
	if (-1 != strInLine.Find("has the dealer button") )
	   return true;
	if (strInLine.IsEmpty())
	   return true;
	if (-1 != strInLine.Find("** Game #"))
	   return true;
	return false;
}

#endif // !defined(AFX_CPSTrueLogSmallBlind__INCLUDED_)
