// PSParadiseHeader1.h: interface for the CPSParadiseHeader1 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PSParadiseHEADER1_H__4EC2C35F_2AC7_4632_B28B_77892B6D52AD__INCLUDED_)
#define AFX_PSParadiseHEADER1_H__4EC2C35F_2AC7_4632_B28B_77892B6D52AD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ParseState.h"

class CPSParadiseHeader1 : public CParseState  
{
public:
	virtual CParseState* Parse(const CString& pcchInLine);
	CPSParadiseHeader1(CParseFile* cPF);
	virtual ~CPSParadiseHeader1();

private:
	CTime GetDate(CString& strUnreadLine);
	//static int GetMounthAsInt(const CString& strMounth);
	PokerGames GetGame(CString& strUnreadLine);

	static const CString TEXAS_HOLDEM_TABLE;
};

#endif // !defined(AFX_PSParadiseHEADER1_H__4EC2C35F_2AC7_4632_B28B_77892B6D52AD__INCLUDED_)
