// PSPartyLogPlayerFirxtAction.h: interface for the CPSPartyLogPlayerFirxtAction class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PSPARTYLOGPLAYERFIRXTACTION_H__88695AA7_64F0_4706_A36F_7906893F3B47__INCLUDED_)
#define AFX_PSPARTYLOGPLAYERFIRXTACTION_H__88695AA7_64F0_4706_A36F_7906893F3B47__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "PSPartyLog.h"

class CPSPartyLogPlayerFirstAction : public CPSPartyLog  
{
public:
	CPSPartyLogPlayerFirstAction(CParseFile* cPF);
	virtual ~CPSPartyLogPlayerFirstAction();
	virtual CParseState* ParseI(const CString &strInLine, const CString &strFullLine);
};

#endif // !defined(AFX_PSPARTYLOGPLAYERFIRXTACTION_H__88695AA7_64F0_4706_A36F_7906893F3B47__INCLUDED_)
