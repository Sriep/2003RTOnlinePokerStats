// PSParadiseLogPlayerFirxtAction.h: interface for the CPSParadiseLogPlayerFirxtAction class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PSParadiseLOGPLAYERFIRXTACTION_H__88695AA7_64F0_4706_A36F_7906893F3B47__INCLUDED_)
#define AFX_PSParadiseLOGPLAYERFIRXTACTION_H__88695AA7_64F0_4706_A36F_7906893F3B47__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "PSParadiseLog.h"

class CPSParadiseLogPlayerFirstAction : public CPSParadiseLog  
{
public:
	CPSParadiseLogPlayerFirstAction(CParseFile* cPF);
	virtual ~CPSParadiseLogPlayerFirstAction();
	virtual CParseState* ParseI(const CString &strInLine, const CString &strFullLine);
};

#endif // !defined(AFX_PSParadiseLOGPLAYERFIRXTACTION_H__88695AA7_64F0_4706_A36F_7906893F3B47__INCLUDED_)
