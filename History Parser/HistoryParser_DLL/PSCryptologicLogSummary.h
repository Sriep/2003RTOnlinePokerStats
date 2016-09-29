// PSCryptologicLogDealing.h: interface for the CPSCryptologicLogDealing class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CCryptologicLogSummary__INCLUDED_)
#define AFX_CCryptologicLogSummary__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "PSCryptologicLog.h"

class CPSCryptologicLogSummary : public CPSCryptologicLog  
{
public:
	CPSCryptologicLogSummary(CParseFile* pPF);
	virtual ~CPSCryptologicLogSummary();
	virtual CParseState* ParseI(const CString &strInLine, const CString &strFullLine);

};


#endif // !defined(AFX_CCryptologicLogSummary__INCLUDED_)
