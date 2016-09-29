// PSCryptologicLogPlayerFirxtAction.h: interface for the CPSCryptologicLogPlayerFirxtAction class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PSCryptologicLOGPLAYERFIRXTACTION_H__88695AA7_64F0_4706_A36F_7906893F3B47__INCLUDED_)
#define AFX_PSCryptologicLOGPLAYERFIRXTACTION_H__88695AA7_64F0_4706_A36F_7906893F3B47__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "PSCryptologicLog.h"

class CPSCryptologicLogPlayerFirstAction : public CPSCryptologicLog  
{
public:
	CPSCryptologicLogPlayerFirstAction(CParseFile* cPF);
	virtual ~CPSCryptologicLogPlayerFirstAction();
	virtual CParseState* ParseI(const CString &strInLine, const CString &strFullLine);
};

#endif // !defined(AFX_PSCryptologicLOGPLAYERFIRXTACTION_H__88695AA7_64F0_4706_A36F_7906893F3B47__INCLUDED_)
