// PSPartyGetBigBlind.h: interface for the CPSPartyGetBigBlind class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PSPARTYGETBIGBLIND_H__D1E54D42_A789_43C1_A308_CD456372E72A__INCLUDED_)
#define AFX_PSPARTYGETBIGBLIND_H__D1E54D42_A789_43C1_A308_CD456372E72A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ParseState.h"

class CPSPartyGetBigBlind : public CParseState  
{
public:
	CPSPartyGetBigBlind(CParseFile* cPF);
	virtual ~CPSPartyGetBigBlind();
	virtual CParseState* Parse(const CString &strInLine);
};

#endif // !defined(AFX_PSPARTYGETBIGBLIND_H__D1E54D42_A789_43C1_A308_CD456372E72A__INCLUDED_)
