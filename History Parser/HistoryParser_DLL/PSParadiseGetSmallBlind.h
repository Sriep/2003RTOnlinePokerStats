// PSParadiseGetSmallBlind.h: interface for the CPSParadiseGetSmallBlind class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PSParadiseGETSMALLBLIND_H__F274370C_84C4_4B2C_89BF_E473A9514558__INCLUDED_)
#define AFX_PSParadiseGETSMALLBLIND_H__F274370C_84C4_4B2C_89BF_E473A9514558__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ParseState.h"

class CPSParadiseGetSmallBlind : public CParseState  
{
public:
	virtual CParseState* Parse(const CString &strInLine);
	CPSParadiseGetSmallBlind(CParseFile* cPF);
	virtual ~CPSParadiseGetSmallBlind();

};

#endif // !defined(AFX_PSParadiseGETSMALLBLIND_H__F274370C_84C4_4B2C_89BF_E473A9514558__INCLUDED_)
