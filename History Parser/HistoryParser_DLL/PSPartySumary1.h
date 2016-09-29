// PSPartySumary1.h: interface for the CPSPartySumary1 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PSPARTYSUMARY1_H__01C751C1_0B7F_4640_9B22_9D24364648F6__INCLUDED_)
#define AFX_PSPARTYSUMARY1_H__01C751C1_0B7F_4640_9B22_9D24364648F6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ParseState.h"

class CPSPartySumary1 : public CParseState  
{
public:
	CPSPartySumary1(CParseFile* cPF);
	virtual ~CPSPartySumary1();
	virtual CParseState* Parse(const CString &strInLine);
};

#endif // !defined(AFX_PSPARTYSUMARY1_H__01C751C1_0B7F_4640_9B22_9D24364648F6__INCLUDED_)
