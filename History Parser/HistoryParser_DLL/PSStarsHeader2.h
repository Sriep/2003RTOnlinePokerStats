// PSStarsHeader2.h: interface for the CPSStarsHeader2 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PSStarsHEADER2_H__9C17A682_2776_4936_860A_3F3A180F7E04__INCLUDED_)
#define AFX_PSStarsHEADER2_H__9C17A682_2776_4936_860A_3F3A180F7E04__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ParseState.h"

class CPSStarsHeader2 : public CParseState  
{
public:
	int GetButtonPosition(CString& strUnreadLine);
	CString GetTableName(CString& strUnreadLine);

	virtual CParseState* Parse(const CString &strInLine);
	CPSStarsHeader2(CParseFile* cPF);
	virtual ~CPSStarsHeader2();

};

#endif // !defined(AFX_PSStarsHEADER2_H__9C17A682_2776_4936_860A_3F3A180F7E04__INCLUDED_)
