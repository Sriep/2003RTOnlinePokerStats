// PSWSEXLogPlayerFirxtAction.h: interface for the CPSWSEXLogPlayerFirxtAction class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PSWSEXLOGPLAYERFIRXTACTION_H__88695AA7_64F0_4706_A36F_7906893F3B47__INCLUDED_)
#define AFX_PSWSEXLOGPLAYERFIRXTACTION_H__88695AA7_64F0_4706_A36F_7906893F3B47__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "PSWSEXLog.h"

class CPSWSEXLogPlayerFirstAction : public CPSWSEXLog  
{
public:
	CPSWSEXLogPlayerFirstAction(CParseFile* cPF);
	virtual ~CPSWSEXLogPlayerFirstAction();
	virtual CParseState* ParseI(const CString &strInLine, const CString &strFullLine);
};

#endif // !defined(AFX_PSWSEXLOGPLAYERFIRXTACTION_H__88695AA7_64F0_4706_A36F_7906893F3B47__INCLUDED_)
