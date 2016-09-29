// PSUltimateBetLogPlayerAction.h: interface for the CPSUltimateBetLogPlayerAction class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PSUltimateBetLOGPLAYERACTION_H__864632CF_2402_42F8_8ED1_150A0231A3D8__INCLUDED_)
#define AFX_PSUltimateBetLOGPLAYERACTION_H__864632CF_2402_42F8_8ED1_150A0231A3D8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "PSUltimateBetLog.h"

class CPSUltimateBetLogPlayerAction : public CPSUltimateBetLog  
{
public:
	CPSUltimateBetLogPlayerAction(CParseFile* cPF);
	virtual ~CPSUltimateBetLogPlayerAction();
	virtual CParseState* ParseI(const CString &strInLine, const CString &strFullLine);

};

#endif // !defined(AFX_PSUltimateBetLOGPLAYERACTION_H__864632CF_2402_42F8_8ED1_150A0231A3D8__INCLUDED_)
