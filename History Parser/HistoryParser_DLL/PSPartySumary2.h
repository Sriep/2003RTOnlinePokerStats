// PSPartySumary2.h: interface for the CPSPartySumary2 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PSPARTYSUMARY2_H__CE4086CB_1B76_4B7F_AEB8_3C4FB82A6A32__INCLUDED_)
#define AFX_PSPARTYSUMARY2_H__CE4086CB_1B76_4B7F_AEB8_3C4FB82A6A32__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ParseState.h"

class CPSPartySumary2 : public CParseState  
{
public:
	CPSPartySumary2(CParseFile* cPF);
	virtual ~CPSPartySumary2();
	virtual CParseState* Parse(const CString &strInLine);
};

#endif // !defined(AFX_PSPARTYSUMARY2_H__CE4086CB_1B76_4B7F_AEB8_3C4FB82A6A32__INCLUDED_)
