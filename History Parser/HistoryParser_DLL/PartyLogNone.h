// PartyLogNone.h: interface for the CPartyLogNone class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PARTYLOGNONE_H__B7AD3784_4E05_40E4_B3DE_4B88D45E56D0__INCLUDED_)
#define AFX_PARTYLOGNONE_H__B7AD3784_4E05_40E4_B3DE_4B88D45E56D0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ParseState.h"

class CPartyLogNone : public CParseState  
{
public:
	CPartyLogNone(CParseFile* cPF);
	virtual ~CPartyLogNone();
	virtual CParseState* Parse(const CString &strInLine);
	CString GetPartyLogGameNumber(const CString& strUnreadLine) const;
	bool IsPartyPokerNewHamd(const CString& strInLine) const;
};

inline CString CPartyLogNone::GetPartyLogGameNumber(const CString &strLine)	const
{
	CString strPartyPokerHandStart = "Dealer: Game #";
	CString strGameNumber = strLine.Right(strLine.GetLength() - strPartyPokerHandStart.GetLength());
	strGameNumber = strGameNumber.SpanIncluding(NUMBERS);
	
	return strGameNumber;
}

inline bool CPartyLogNone::IsPartyPokerNewHamd(const CString& strInLine) const
{
	CString strPartyPokerHandStart = "Dealer: Game #";
	return strInLine.Left(strPartyPokerHandStart.GetLength()) == strPartyPokerHandStart;
}



#endif // !defined(AFX_PARTYLOGNONE_H__B7AD3784_4E05_40E4_B3DE_4B88D45E56D0__INCLUDED_)
