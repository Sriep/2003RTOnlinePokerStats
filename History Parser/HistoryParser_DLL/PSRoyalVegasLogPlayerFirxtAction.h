// PSRoyalVegasLogPlayerFirxtAction.h: interface for the CPSRoyalVegasLogPlayerFirxtAction class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PSRoyalVegasLOGPLAYERFIRXTACTION_H__88695AA7_64F0_4706_A36F_7906893F3B47__INCLUDED_)
#define AFX_PSRoyalVegasLOGPLAYERFIRXTACTION_H__88695AA7_64F0_4706_A36F_7906893F3B47__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "PSRoyalVegasLog.h"

class CPSRoyalVegasLogPlayerFirstAction : public CPSRoyalVegasLog  
{
public:
	CPSRoyalVegasLogPlayerFirstAction(CParseFile* cPF);
	virtual ~CPSRoyalVegasLogPlayerFirstAction();
	virtual CParseState* ParseI(const CString &strInLine, const CString &strFullLine);
};

#endif // !defined(AFX_PSRoyalVegasLOGPLAYERFIRXTACTION_H__88695AA7_64F0_4706_A36F_7906893F3B47__INCLUDED_)
