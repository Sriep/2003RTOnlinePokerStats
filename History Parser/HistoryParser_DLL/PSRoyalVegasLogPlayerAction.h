// PSRoyalVegasLogPlayerAction.h: interface for the CPSRoyalVegasLogPlayerAction class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PSRoyalVegasLOGPLAYERACTION_H__864632CF_2402_42F8_8ED1_150A0231A3D8__INCLUDED_)
#define AFX_PSRoyalVegasLOGPLAYERACTION_H__864632CF_2402_42F8_8ED1_150A0231A3D8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "PSRoyalVegasLog.h"

class CPSRoyalVegasLogPlayerAction : public CPSRoyalVegasLog  
{
public:
	CPSRoyalVegasLogPlayerAction(CParseFile* cPF);
	virtual ~CPSRoyalVegasLogPlayerAction();
	virtual CParseState* ParseI(const CString &strInLine, const CString &strFullLine);

	bool IsSummaryLine(const CString& strAction) const;

};

inline bool CPSRoyalVegasLogPlayerAction::IsSummaryLine(const CString& strAction) const
{
	return strAction == "shows" || strAction == "mucked" || strAction == "wins"	;
}

#endif // !defined(AFX_PSRoyalVegasLOGPLAYERACTION_H__864632CF_2402_42F8_8ED1_150A0231A3D8__INCLUDED_)
