// PSWSEXLogDealing.h: interface for the CPSWSEXLogDealing class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CWSEXLogSummary__INCLUDED_)
#define AFX_CWSEXLogSummary__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "PSWSEXLog.h"

class CPWSEXLogSummary : public CPSWSEXLog  
{
public:
	CPWSEXLogSummary(CParseFile* pPF);
	virtual ~CPWSEXLogSummary();
	virtual CParseState* ParseI(const CString &strInLine, const CString &strFullLine);

};


#endif // !defined(AFX_CWSEXLogSummary__INCLUDED_)
