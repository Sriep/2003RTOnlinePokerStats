// CryptologicLogNone.h: interface for the CCryptologicLogNone class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CryptologicLOGNONE_H__B7AD3784_4E05_40E4_B3DE_4B88D45E56D0__INCLUDED_)
#define AFX_CryptologicLOGNONE_H__B7AD3784_4E05_40E4_B3DE_4B88D45E56D0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ParseState.h"

class CCryptologicLogNone : public CParseState  
{
public:
	CCryptologicLogNone(CParseFile* cPF);
	virtual ~CCryptologicLogNone();
	virtual CParseState* Parse(const CString &strInLine);
	CString GetCryptologicLogGameNumber(const CString& strUnreadLine) const;
	bool IsCryptologicPokerNewHamd(const CString& strInLine) const;
};

inline CString CCryptologicLogNone::GetCryptologicLogGameNumber(const CString &strLine)	const
{
	CString strCryptologicPokerHandStart = "Dealer: Starting new hand: #";
	CString strGameNumber = strLine.Right(strLine.GetLength() - strCryptologicPokerHandStart.GetLength());
	strGameNumber = strGameNumber.SpanIncluding(NUMBERS);
	
	return strGameNumber;
}

inline bool CCryptologicLogNone::IsCryptologicPokerNewHamd(const CString& strInLine) const
{
	CString strCryptologicPokerHandStart = "Dealer: Starting new hand: #";
	return strInLine.Left(strCryptologicPokerHandStart.GetLength()) == strCryptologicPokerHandStart;
}



#endif // !defined(AFX_CryptologicLOGNONE_H__B7AD3784_4E05_40E4_B3DE_4B88D45E56D0__INCLUDED_)
