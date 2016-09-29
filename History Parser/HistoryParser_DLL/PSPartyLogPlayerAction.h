// PSPartyLogPlayerAction.h: interface for the CPSPartyLogPlayerAction class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PSPARTYLOGPLAYERACTION_H__864632CF_2402_42F8_8ED1_150A0231A3D8__INCLUDED_)
#define AFX_PSPARTYLOGPLAYERACTION_H__864632CF_2402_42F8_8ED1_150A0231A3D8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "PSPartyLog.h"

class CPSPartyLogPlayerAction : public CPSPartyLog  
{
public:
	CPSPartyLogPlayerAction(CParseFile* cPF);
	virtual ~CPSPartyLogPlayerAction();
	virtual CParseState* ParseI(const CString &strInLine, const CString &strFullLine);

};

#endif // !defined(AFX_PSPARTYLOGPLAYERACTION_H__864632CF_2402_42F8_8ED1_150A0231A3D8__INCLUDED_)
