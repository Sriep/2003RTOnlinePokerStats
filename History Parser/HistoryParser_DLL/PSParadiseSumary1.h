// PSParadiseSumary1.h: interface for the CPSParadiseSumary1 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PSParadiseSUMARY1_H__01C751C1_0B7F_4640_9B22_9D24364648F6__INCLUDED_)
#define AFX_PSParadiseSUMARY1_H__01C751C1_0B7F_4640_9B22_9D24364648F6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ParseState.h"

class CPSParadiseSumary1 : public CParseState  
{
public:
	CPSParadiseSumary1(CParseFile* cPF);
	virtual ~CPSParadiseSumary1();
	virtual CParseState* Parse(const CString &strInLine);
};

#endif // !defined(AFX_PSParadiseSUMARY1_H__01C751C1_0B7F_4640_9B22_9D24364648F6__INCLUDED_)
