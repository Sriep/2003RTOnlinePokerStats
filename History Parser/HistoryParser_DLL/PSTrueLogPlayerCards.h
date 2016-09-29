// PSTrueLogBigBlind.h: interface for the CPSTrueLogBigBlind class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CPSTrueLogPlayerCards__INCLUDED_)
#define AFX_CPSTrueLogPlayerCards__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "PSTrueLog.h"

class CPSTrueLogPlayerCards : public CPSTrueLog  
{
public:
	CPSTrueLogPlayerCards(CParseFile* pPF);
	virtual ~CPSTrueLogPlayerCards();
	virtual CParseState* ParseI(const CString &strInLine, const CString &strFullLine);
};

#endif // !defined(AFX_CPSTrueLogPlayerCards__INCLUDED_)
