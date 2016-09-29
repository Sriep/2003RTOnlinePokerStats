// PSPartyLogBigBlind.h: interface for the CPSPartyLogBigBlind class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PSPARTYLOGBIGBLIND_H__71E8692B_77AF_4596_BF86_6581EBB09D91__INCLUDED_)
#define AFX_PSPARTYLOGBIGBLIND_H__71E8692B_77AF_4596_BF86_6581EBB09D91__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "PSPartyLog.h"

class CPSPartyLogBigBlind : public CPSPartyLog  
{
public:
	CPSPartyLogBigBlind(CParseFile* pPF);
	virtual ~CPSPartyLogBigBlind();
	virtual CParseState* ParseI(const CString &strInLine, const CString &strFullLine);
};

#endif // !defined(AFX_PSPARTYLOGBIGBLIND_H__71E8692B_77AF_4596_BF86_6581EBB09D91__INCLUDED_)
