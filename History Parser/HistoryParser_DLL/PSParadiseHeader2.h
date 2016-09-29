// PSParadiseHeader2.h: interface for the CPSParadiseHeader2 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PSParadiseHEADER2_H__9C17A682_2776_4936_860A_3F3A180F7E04__INCLUDED_)
#define AFX_PSParadiseHEADER2_H__9C17A682_2776_4936_860A_3F3A180F7E04__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ParseState.h"

class CPSParadiseHeader2 : public CParseState  
{
public:
	int GetButtonPosition(CString& strUnreadLine);
	CString GetTableName(CString& strUnreadLine);

	virtual CParseState* Parse(const CString &strInLine);
	CPSParadiseHeader2(CParseFile* cPF);
	virtual ~CPSParadiseHeader2();

};

#endif // !defined(AFX_PSParadiseHEADER2_H__9C17A682_2776_4936_860A_3F3A180F7E04__INCLUDED_)
