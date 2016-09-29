// PSPartyHeader2.h: interface for the CPSPartyHeader2 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PSPARTYHEADER2_H__9C17A682_2776_4936_860A_3F3A180F7E04__INCLUDED_)
#define AFX_PSPARTYHEADER2_H__9C17A682_2776_4936_860A_3F3A180F7E04__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ParseState.h"

class CPSPartyHeader2 : public CParseState  
{
public:
	int GetButtonPosition(CString& strUnreadLine);
	CString GetTableName(CString& strUnreadLine);

	virtual CParseState* Parse(const CString &strInLine);
	CPSPartyHeader2(CParseFile* cPF);
	virtual ~CPSPartyHeader2();

};

#endif // !defined(AFX_PSPARTYHEADER2_H__9C17A682_2776_4936_860A_3F3A180F7E04__INCLUDED_)
