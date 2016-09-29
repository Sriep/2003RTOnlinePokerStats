// PSPartyHeader3.h: interface for the CPSPartyHeader3 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PSPARTYHEADER3_H__9AADAABF_E63B_4A64_B5C7_DE958FF2808F__INCLUDED_)
#define AFX_PSPARTYHEADER3_H__9AADAABF_E63B_4A64_B5C7_DE958FF2808F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ParseState.h"

class CPSPartyHeader3 : public CParseState  
{
public:
	virtual CParseState* Parse(const CString &strInLine);
	CPSPartyHeader3(CParseFile* cPF);
	virtual ~CPSPartyHeader3();

};

#endif // !defined(AFX_PSPARTYHEADER3_H__9AADAABF_E63B_4A64_B5C7_DE958FF2808F__INCLUDED_)
