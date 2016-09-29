// TrueLogNone.h: interface for the CTrueLogNone class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CTrueLogNone__INCLUDED_)
#define AFX_CTrueLogNone__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ParseState.h"

class CTrueLogNone : public CParseState  
{
public:
	CTrueLogNone(CParseFile* cPF);
	virtual ~CTrueLogNone();
	virtual CParseState* Parse(const CString &strInLine);
	CTime GetDate(CString& strUnreadLine);
};

inline CTime CTrueLogNone::GetDate(CString& strUnreadLine)	 
{
	GetNextWord(strUnreadLine);	   //Day of week
	int iMonth = GetMounthAsInt(GetNextWord(strUnreadLine));
	int iDay = GetNextNumber(strUnreadLine);
	int iYear =  GetNextNumber(strUnreadLine);
	ReadText("@", strUnreadLine);
	int iHour = GetNextNumber(strUnreadLine);
	ReadText(CHAR_COLON, strUnreadLine);
	int iMins = GetNextNumber(strUnreadLine);
	return CTime(iYear, iMonth, iDay, iHour, iMins, 0);
}


#endif // !defined(AFX_CTrueLogNone__INCLUDED_)
