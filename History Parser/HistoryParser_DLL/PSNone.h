// PSNone.h: interface for the CPSNone class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PSNONE_H__66AD57F8_3C45_4E54_9CB9_C7AF26396342__INCLUDED_)
#define AFX_PSNONE_H__66AD57F8_3C45_4E54_9CB9_C7AF26396342__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ParseState.h"

class CPSNone : public CParseState  
{
public:
	bool IsParadisePokerStart(const CString& strInLine) const;
	bool IsPartyPokerStart(const CString& strInLine) const;
	long GetGameNumber(const CString& strUnreadLine);
	CPSNone(CParseFile* cPF);
	virtual ~CPSNone();
	virtual  CParseState* Parse(const CString& pcchInLine);

	static const CString POKERSTARS_START;
	static const CString PARTYPOKER_START;
	static const CString PARADISEPOKER_START;
	static const CString TRUEPOKER_START;

protected:

};

inline long CPSNone::GetGameNumber(const CString &strLine)
{
	CString strGameNumber = strLine.Right(strLine.GetLength() - PARTYPOKER_START.GetLength());
	strGameNumber = strGameNumber.SpanIncluding(NUMBERS);
	
	return atol(strGameNumber);
}

inline bool CPSNone::IsPartyPokerStart(const CString& strInLine) const
{
	return strInLine.Left(PARTYPOKER_START.GetLength()) == PARTYPOKER_START;
}

inline bool CPSNone::IsParadisePokerStart(const CString &strInLine) const
{
	return strInLine.Left(PARADISEPOKER_START.GetLength()) == PARADISEPOKER_START;
}


#endif // !defined(AFX_PSNONE_H__66AD57F8_3C45_4E54_9CB9_C7AF26396342__INCLUDED_)
