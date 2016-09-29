// PSPokerRoomLogSmallBlind.h: interface for the CPSPokerRoomLogSmallBlind class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CPSryptologicLogBlind__INCLUDED_)
#define AFX_CPSryptologicLogBlind__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "PSCryptologicLog.h"

class CPSCryptologicLogBlind : public CPSCryptologicLog  
{
public:
	CPSCryptologicLogBlind(CParseFile* pPF);
	virtual ~CPSCryptologicLogBlind();
	virtual CParseState* ParseI(const CString &strInLine, const CString &strFullLine);
};

#endif // !defined(AFX_CPSryptologicLogBlind__INCLUDED_)
