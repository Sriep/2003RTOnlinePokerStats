// PSPartyPlayerAction.h: interface for the CPSPartyPlayerAction class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PSPARTYPLAYERACTION_H__29A27E38_B99F_48BC_AED5_02DBB4B85088__INCLUDED_)
#define AFX_PSPARTYPLAYERACTION_H__29A27E38_B99F_48BC_AED5_02DBB4B85088__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ParseState.h"

class CPSPartyPlayerAction : public CParseState  
{
public:
	CPSPartyPlayerAction(CParseFile* cPF);
	virtual ~CPSPartyPlayerAction();
	virtual CParseState* Parse(const CString &strInLine);

	virtual bool IsSummary(const CString &strInLine);
	virtual bool IsDealingNewCards(const CString &strInLine);

private:
	int ReadAmount(CString& strUnreadLine);

};

#endif // !defined(AFX_PSPARTYPLAYERACTION_H__29A27E38_B99F_48BC_AED5_02DBB4B85088__INCLUDED_)
