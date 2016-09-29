// PSHighStakesLogPlayerAction.h: interface for the CPSHighStakesLogPlayerAction class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PSHighStakesLOGPLAYERACTION_H__864632CF_2402_42F8_8ED1_150A0231A3D8__INCLUDED_)
#define AFX_PSHighStakesLOGPLAYERACTION_H__864632CF_2402_42F8_8ED1_150A0231A3D8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "PSHighStakesLog.h"

class CPSHighStakesLogPlayerAction : public CPSHighStakesLog  
{
public:
	CPSHighStakesLogPlayerAction(CParseFile* cPF);
	virtual ~CPSHighStakesLogPlayerAction();
	virtual CParseState* ParseI(const CString &strInLine, const CString &strFullLine);

	bool IsSummaryLine(const CString& strAction) const;

};

inline bool CPSHighStakesLogPlayerAction::IsSummaryLine(const CString& strAction) const
{
	return strAction == "shows" || strAction == "mucked" || strAction == "wins"	;
}

#endif // !defined(AFX_PSHighStakesLOGPLAYERACTION_H__864632CF_2402_42F8_8ED1_150A0231A3D8__INCLUDED_)
