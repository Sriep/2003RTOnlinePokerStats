// PSTrueLogBigBlind.h: interface for the CPSTrueLogBigBlind class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CPSTrueLogBigBlind__INCLUDED_)
#define AFX_CPSTrueLogBigBlind__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "PSTrueLog.h"

class CPSTrueLogBigBlind : public CPSTrueLog  
{
public:
	CPSTrueLogBigBlind(CParseFile* pPF);
	virtual ~CPSTrueLogBigBlind();
	virtual CParseState* ParseI(const CString &strInLine, const CString &strFullLine);
};

#endif // !defined(AFX_CPSTrueLogBigBlind__INCLUDED_)
