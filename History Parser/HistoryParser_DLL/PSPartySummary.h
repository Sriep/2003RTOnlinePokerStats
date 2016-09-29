// PSPartySummary.h: interface for the CPSPartySummary class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PSPARTYSUMMARY_H__81978834_3CD6_4903_B80A_3026C0BF9227__INCLUDED_)
#define AFX_PSPARTYSUMMARY_H__81978834_3CD6_4903_B80A_3026C0BF9227__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ParseState.h"

class CPSPartySummary : public CParseState  
{
public:
	CPSPartySummary(CParseFile* cPF);
	virtual ~CPSPartySummary();
	virtual CParseState* Parse(const CString &strInLine);
};

#endif // !defined(AFX_PSPARTYSUMMARY_H__81978834_3CD6_4903_B80A_3026C0BF9227__INCLUDED_)
