// PSCryptologicLogDealing.h: interface for the CPSCryptologicLogDealing class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CPSCryptologicLogAllFold__INCLUDED_)
#define AFX_CPSCryptologicLogAllFold__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "PSCryptologicLog.h"

class CPSCryptologicLogAllFold : public CPSCryptologicLog  
{
public:
	CPSCryptologicLogAllFold(CParseFile* pPF);
	virtual ~CPSCryptologicLogAllFold();
	virtual CParseState* ParseI(const CString &strInLine, const CString &strFullLine);

};


#endif // !defined(AFX_CPSCryptologicLogAllFold__INCLUDED_)
