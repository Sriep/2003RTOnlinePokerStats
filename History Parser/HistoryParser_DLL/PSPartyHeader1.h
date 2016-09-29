// PSPartyHeader1.h: interface for the CPSPartyHeader1 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PSPARTYHEADER1_H__4EC2C35F_2AC7_4632_B28B_77892B6D52AD__INCLUDED_)
#define AFX_PSPARTYHEADER1_H__4EC2C35F_2AC7_4632_B28B_77892B6D52AD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ParseState.h"

class CPSPartyHeader1 : public CParseState  
{
public:
	virtual CParseState* Parse(const CString& pcchInLine);
	CPSPartyHeader1(CParseFile* cPF);
	virtual ~CPSPartyHeader1();

private:
	CTime GetDate(CString& strUnreadLine);
	PokerGames GetGame(CString& strUnreadLine);

	static const CString TEXAS_HOLDEM_TABLE;
};

#endif // !defined(AFX_PSPARTYHEADER1_H__4EC2C35F_2AC7_4632_B28B_77892B6D52AD__INCLUDED_)
