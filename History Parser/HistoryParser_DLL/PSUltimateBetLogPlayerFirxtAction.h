// PSUltimateBetLogPlayerFirxtAction.h: interface for the CPSUltimateBetLogPlayerFirxtAction class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PSUltimateBetLOGPLAYERFIRXTACTION_H__88695AA7_64F0_4706_A36F_7906893F3B47__INCLUDED_)
#define AFX_PSUltimateBetLOGPLAYERFIRXTACTION_H__88695AA7_64F0_4706_A36F_7906893F3B47__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "PSUltimateBetLog.h"

class CPSUltimateBetLogPlayerFirstAction : public CPSUltimateBetLog  
{
public:
	CPSUltimateBetLogPlayerFirstAction(CParseFile* cPF);
	virtual ~CPSUltimateBetLogPlayerFirstAction();
	virtual CParseState* ParseI(const CString &strInLine, const CString &strFullLine);
};

#endif // !defined(AFX_PSUltimateBetLOGPLAYERFIRXTACTION_H__88695AA7_64F0_4706_A36F_7906893F3B47__INCLUDED_)
