// PSParadiseLogBigBlind.h: interface for the CPSParadiseLogBigBlind class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PSParadiseLOGBIGBLIND_H__71E8692B_77AF_4596_BF86_6581EBB09D91__INCLUDED_)
#define AFX_PSParadiseLOGBIGBLIND_H__71E8692B_77AF_4596_BF86_6581EBB09D91__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "PSParadiseLog.h"

class CPSParadiseLogBigBlind : public CPSParadiseLog  
{
public:
	CPSParadiseLogBigBlind(CParseFile* pPF);
	virtual ~CPSParadiseLogBigBlind();
	virtual CParseState* ParseI(const CString &strInLine, const CString &strFullLine);
};

#endif // !defined(AFX_PSParadiseLOGBIGBLIND_H__71E8692B_77AF_4596_BF86_6581EBB09D91__INCLUDED_)
