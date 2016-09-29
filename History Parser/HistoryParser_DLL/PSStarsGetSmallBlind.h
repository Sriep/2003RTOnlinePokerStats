// PSStarsGetSmallBlind.h: interface for the CPSStarsGetSmallBlind class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PSStarsGETSMALLBLIND_H__F274370C_84C4_4B2C_89BF_E473A9514558__INCLUDED_)
#define AFX_PSStarsGETSMALLBLIND_H__F274370C_84C4_4B2C_89BF_E473A9514558__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ParseState.h"

class CPSStarsGetSmallBlind : public CParseState  
{
public:
	virtual CParseState* Parse(const CString &strInLine);
	CPSStarsGetSmallBlind(CParseFile* cPF);
	virtual ~CPSStarsGetSmallBlind();

};

#endif // !defined(AFX_PSStarsGETSMALLBLIND_H__F274370C_84C4_4B2C_89BF_E473A9514558__INCLUDED_)
