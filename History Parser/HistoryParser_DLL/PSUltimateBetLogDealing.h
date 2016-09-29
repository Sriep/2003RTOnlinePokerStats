// PSUltimateBetLogDealing.h: interface for the CPSUltimateBetLogDealing class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PSUltimateBetLOGDEALING_H__EE325258_F0FC_4A96_A9D9_06769B3DEA3A__INCLUDED_)
#define AFX_PSUltimateBetLOGDEALING_H__EE325258_F0FC_4A96_A9D9_06769B3DEA3A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "PSUltimateBetLog.h"

class CPSUltimateBetLogDealing : public CPSUltimateBetLog  
{
public:
	CPSUltimateBetLogDealing(CParseFile* pPF);
	virtual ~CPSUltimateBetLogDealing();
	virtual CParseState* ParseI(const CString &strInLine, const CString &strFullLine);
};

#endif // !defined(AFX_PSUltimateBetLOGDEALING_H__EE325258_F0FC_4A96_A9D9_06769B3DEA3A__INCLUDED_)
