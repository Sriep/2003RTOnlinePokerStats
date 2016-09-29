// PSUltimateBetLogBigBlind.h: interface for the CPSUltimateBetLogBigBlind class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PSUltimateBetLOGBIGBLIND_H__71E8692B_77AF_4596_BF86_6581EBB09D91__INCLUDED_)
#define AFX_PSUltimateBetLOGBIGBLIND_H__71E8692B_77AF_4596_BF86_6581EBB09D91__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "PSUltimateBetLog.h"

class CPSUltimateBetLogBigBlind : public CPSUltimateBetLog  
{
public:
	CPSUltimateBetLogBigBlind(CParseFile* pPF);
	virtual ~CPSUltimateBetLogBigBlind();
	virtual CParseState* ParseI(const CString &strInLine, const CString &strFullLine);
};

#endif // !defined(AFX_PSUltimateBetLOGBIGBLIND_H__71E8692B_77AF_4596_BF86_6581EBB09D91__INCLUDED_)
