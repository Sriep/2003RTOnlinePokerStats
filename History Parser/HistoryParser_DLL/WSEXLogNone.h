// WSEXLogNone.h: interface for the CWSEXLogNone class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_WSEXLOGNONE_H____INCLUDED_)
#define AFX_WSEXLOGNONE_H____INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ParseState.h"

class CWSEXLogNone : public CParseState  
{
public:
	CWSEXLogNone(CParseFile* cPF);
	virtual ~CWSEXLogNone();
	virtual CParseState* Parse(const CString &strInLine);
};

#endif // !defined(AFX_WSEXLOGNONE_H____INCLUDED_)
