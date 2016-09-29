// PSPartyLogSmallBlind.h: interface for the CPSPartyLogSmallBlind class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PSPARTYLOGSMALLBLIND_H__FE0E4668_9521_4279_81B5_13BF3A882A81__INCLUDED_)
#define AFX_PSPARTYLOGSMALLBLIND_H__FE0E4668_9521_4279_81B5_13BF3A882A81__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "PSPartyLog.h"

class CPSPartyLogSmallBlind : public CPSPartyLog  
{
public:
	CPSPartyLogSmallBlind(CParseFile* pPF);
	virtual ~CPSPartyLogSmallBlind();
	virtual CParseState* ParseI(const CString &strInLine, const CString &strFullLine);
};

#endif // !defined(AFX_PSPARTYLOGSMALLBLIND_H__FE0E4668_9521_4279_81B5_13BF3A882A81__INCLUDED_)
