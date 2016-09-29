// PSStarsDealing.h: interface for the CPSStarsDealing class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PSStarsDEALING_H__393F8F10_4662_44C3_8DAA_452977562F75__INCLUDED_)
#define AFX_PSStarsDEALING_H__393F8F10_4662_44C3_8DAA_452977562F75__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ParseState.h"

class CPSStarsDealing : public CParseState  
{
public:
	CPSStarsDealing(CParseFile* cPF);
	virtual ~CPSStarsDealing();
	virtual CParseState* Parse(const CString &strInLine);

	void ParseInitalDeal(CString& strUnreadLine);
	void ParseFlopDeal(CString& strUnreadLine);
	void ParseTurnDeal(CString& strUnreadLine);
	void ParseRiverDeal(CString& strUnreadLine);
};

#endif // !defined(AFX_PSStarsDEALING_H__393F8F10_4662_44C3_8DAA_452977562F75__INCLUDED_)
