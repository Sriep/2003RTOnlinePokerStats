// PSWSEXLogBigBlind.h: interface for the CPSWSEXLogBigBlind class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PSWSEXLOGBIGBLIND_H__71E8692B_77AF_4596_BF86_6581EBB09D91__INCLUDED_)
#define AFX_PSWSEXLOGBIGBLIND_H__71E8692B_77AF_4596_BF86_6581EBB09D91__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "PSWSEXLog.h"

class CPSWSEXLogBigBlind : public CPSWSEXLog  
{
public:
	CPSWSEXLogBigBlind(CParseFile* pPF);
	virtual ~CPSWSEXLogBigBlind();
	virtual CParseState* ParseI(const CString &strInLine, const CString &strFullLine);
};

#endif // !defined(AFX_PSWSEXLOGBIGBLIND_H__71E8692B_77AF_4596_BF86_6581EBB09D91__INCLUDED_)
