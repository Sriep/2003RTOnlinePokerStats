// UltimateBetLogNone.h: interface for the CUltimateBetLogNone class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UltimateBetLOGNONE_H__B7AD3784_4E05_40E4_B3DE_4B88D45E56D0__INCLUDED_)
#define AFX_UltimateBetLOGNONE_H__B7AD3784_4E05_40E4_B3DE_4B88D45E56D0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ParseState.h"

class CUltimateBetLogNone : public CParseState  
{
public:
	CUltimateBetLogNone(CParseFile* cPF);
	virtual ~CUltimateBetLogNone();
	virtual CParseState* Parse(const CString &strInLine);
	CString GetUltimateBetLogGameNumber(CString& strUnreadLine) ;
	bool IsUltimateBetPokerNewHamd(const CString& strInLine) const;
	CTime GetDate(CString& strUnreadLine); 
};

inline CTime CUltimateBetLogNone::GetDate(CString& strUnreadLine) 
{
	int iDay = GetNextNumber(strUnreadLine);
	ReadText("/", strUnreadLine);

	CString strMounth;
	strMounth = strUnreadLine.SpanExcluding("//");   
	ReadText(strMounth, strUnreadLine);
	ReadText("/", strUnreadLine);
	int iMonth = GetMounthAsInt(strMounth);

	int iYear = GetNextNumber(strUnreadLine) + 2000;
	/*	 They have put the time on the next line.
	int iHour = GetNextNumber(strUnreadLine);
	ReadText(':', strUnreadLine);
	int iMins = GetNextNumber(strUnreadLine);
	ReadText(':', strUnreadLine);
	int iSecs = GetNextNumber(strUnreadLine);

	return CTime(iYear, iMonth, iDay, iHour, iMins, iSecs);
	*/
	return CTime(iYear, iMonth, iDay, 0, 0, 0);
}

inline CString CUltimateBetLogNone::GetUltimateBetLogGameNumber(CString& strLine) 
{
	CString strGameNumber; 
	strGameNumber = GetNextWord(strLine);
	//strGameNumber = strGameNumber.Right(strGameNumber.Find('')-1);
	strGameNumber.Remove(':');
	strGameNumber.Remove('-');
	return strGameNumber;
}

#endif // !defined(AFX_UltimateBetLOGNONE_H__B7AD3784_4E05_40E4_B3DE_4B88D45E56D0__INCLUDED_)
