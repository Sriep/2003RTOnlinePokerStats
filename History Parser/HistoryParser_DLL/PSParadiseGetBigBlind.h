// PSParadiseGetBigBlind.h: interface for the CPSParadiseGetBigBlind class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PSParadiseGETBIGBLIND_H__D1E54D42_A789_43C1_A308_CD456372E72A__INCLUDED_)
#define AFX_PSParadiseGETBIGBLIND_H__D1E54D42_A789_43C1_A308_CD456372E72A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ParseState.h"

class CPSParadiseGetBigBlind : public CParseState  
{
public:
	CPSParadiseGetBigBlind(CParseFile* cPF);
	virtual ~CPSParadiseGetBigBlind();
	virtual CParseState* Parse(const CString &strInLine);
};

#endif // !defined(AFX_PSParadiseGETBIGBLIND_H__D1E54D42_A789_43C1_A308_CD456372E72A__INCLUDED_)
