// PSParadiseLogResult.h: interface for the CPSParadiseLogResult class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PSPARADISELOGRESULT_H__427B71C5_EACD_4546_8F04_A2A5EBA4C259__INCLUDED_)
#define AFX_PSPARADISELOGRESULT_H__427B71C5_EACD_4546_8F04_A2A5EBA4C259__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "PSParadiseLog.h"

class CPSParadiseLogResult : public CParseState  
{
public:
	CPSParadiseLogResult(CParseFile* cPF);
	virtual ~CPSParadiseLogResult();
	virtual CParseState* Parse(const CString &strInLine);
};

#endif // !defined(AFX_PSPARADISELOGRESULT_H__427B71C5_EACD_4546_8F04_A2A5EBA4C259__INCLUDED_)
