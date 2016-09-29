// PSHighStakesLogPlayerFirxtAction.h: interface for the CPSHighStakesLogPlayerFirxtAction class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PSHighStakesLOGPLAYERFIRXTACTION_H__88695AA7_64F0_4706_A36F_7906893F3B47__INCLUDED_)
#define AFX_PSHighStakesLOGPLAYERFIRXTACTION_H__88695AA7_64F0_4706_A36F_7906893F3B47__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "PSHighStakesLog.h"

class CPSHighStakesLogPlayerFirstAction : public CPSHighStakesLog  
{
public:
	CPSHighStakesLogPlayerFirstAction(CParseFile* cPF);
	virtual ~CPSHighStakesLogPlayerFirstAction();
	virtual CParseState* ParseI(const CString &strInLine, const CString &strFullLine);
};

#endif // !defined(AFX_PSHighStakesLOGPLAYERFIRXTACTION_H__88695AA7_64F0_4706_A36F_7906893F3B47__INCLUDED_)
