// PSPartyGetSmallBlind.h: interface for the CPSPartyGetSmallBlind class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PSPARTYGETSMALLBLIND_H__F274370C_84C4_4B2C_89BF_E473A9514558__INCLUDED_)
#define AFX_PSPARTYGETSMALLBLIND_H__F274370C_84C4_4B2C_89BF_E473A9514558__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ParseState.h"

class CPSPartyGetSmallBlind : public CParseState  
{
public:
	virtual CParseState* Parse(const CString &strInLine);
	CPSPartyGetSmallBlind(CParseFile* cPF);
	virtual ~CPSPartyGetSmallBlind();

};

#endif // !defined(AFX_PSPARTYGETSMALLBLIND_H__F274370C_84C4_4B2C_89BF_E473A9514558__INCLUDED_)
