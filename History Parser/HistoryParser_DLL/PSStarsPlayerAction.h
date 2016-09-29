// PSStarsPlayerAction.h: interface for the CPSStarsPlayerAction class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PSStarsPLAYERACTION_H__29A27E38_B99F_48BC_AED5_02DBB4B85088__INCLUDED_)
#define AFX_PSStarsPLAYERACTION_H__29A27E38_B99F_48BC_AED5_02DBB4B85088__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ParseState.h"

class CPSStarsPlayerAction : public CParseState  
{
public:
	CPSStarsPlayerAction(CParseFile* cPF);
	virtual ~CPSStarsPlayerAction();
	virtual CParseState* Parse(const CString &strInLine);

	virtual bool IsSummary(const CString &strInLine);
	virtual bool IsDealingNewCards(const CString &strInLine);

private:
	int ReadAmount(CString& strUnreadLine);
	//CString ReadPredfinedNickPlusAction(CString& strUnreadLine, PPlayerAction& cAction);
};

#endif // !defined(AFX_PSStarsPLAYERACTION_H__29A27E38_B99F_48BC_AED5_02DBB4B85088__INCLUDED_)
