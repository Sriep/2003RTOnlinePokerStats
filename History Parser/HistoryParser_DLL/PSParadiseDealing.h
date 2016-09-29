// PSParadiseDealing.h: interface for the CPSParadiseDealing class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PSParadiseDEALING_H__393F8F10_4662_44C3_8DAA_452977562F75__INCLUDED_)
#define AFX_PSParadiseDEALING_H__393F8F10_4662_44C3_8DAA_452977562F75__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ParseState.h"

class CPSParadiseDealing : public CParseState  
{
public:
	CPSParadiseDealing(CParseFile* cPF);
	virtual ~CPSParadiseDealing();
	virtual CParseState* Parse(const CString &strInLine);

	void ParseFlopDeal(CString& strUnreadLine);
	void ParseTurnDeal(CString& strUnreadLine);
	void ParseRiverDeal(CString& strUnreadLine);
};

#endif // !defined(AFX_PSParadiseDEALING_H__393F8F10_4662_44C3_8DAA_452977562F75__INCLUDED_)
