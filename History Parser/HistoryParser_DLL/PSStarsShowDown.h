// PSStarsShowDown.h: interface for the CPSStarsShowDown class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PSSTARSSHOWDOWN_H__126A5ED4_BE24_4DE9_BAC9_636089226DBE__INCLUDED_)
#define AFX_PSSTARSSHOWDOWN_H__126A5ED4_BE24_4DE9_BAC9_636089226DBE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ParseState.h"

class CPSStarsShowDown : public CParseState  
{
public:
	CPSStarsShowDown(CParseFile* cPF);
	virtual ~CPSStarsShowDown();
	virtual CParseState* Parse(const CString &strInLine);
	CString ReadPredfinedNickPlusAction(CString& strUnreadLine);
};

#endif // !defined(AFX_PSSTARSSHOWDOWN_H__126A5ED4_BE24_4DE9_BAC9_636089226DBE__INCLUDED_)
