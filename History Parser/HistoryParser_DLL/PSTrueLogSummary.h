// PSTrueLogBigBlind.h: interface for the CPSTrueLogBigBlind class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CPSTrueLogSummary__INCLUDED_)
#define AFX_CPSTrueLogSummary__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "PSTrueLog.h"

class CPSTrueLogSummary : public CPSTrueLog  
{
public:
	CPSTrueLogSummary(CParseFile* pPF);
	virtual ~CPSTrueLogSummary();
	virtual CParseState* ParseI(const CString &strInLine, const CString &strFullLine);
};

#endif // !defined(AFX_CPSTrueLogSummary__INCLUDED_)
