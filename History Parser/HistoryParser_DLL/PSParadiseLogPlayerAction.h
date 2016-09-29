// PSParadiseLogPlayerAction.h: interface for the CPSParadiseLogPlayerAction class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PSParadiseLOGPLAYERACTION_H__864632CF_2402_42F8_8ED1_150A0231A3D8__INCLUDED_)
#define AFX_PSParadiseLOGPLAYERACTION_H__864632CF_2402_42F8_8ED1_150A0231A3D8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "PSParadiseLog.h"

class CPSParadiseLogPlayerAction : public CPSParadiseLog  
{
public:
	CPSParadiseLogPlayerAction(CParseFile* cPF);
	virtual ~CPSParadiseLogPlayerAction();
	virtual CParseState* ParseI(const CString &strInLine, const CString &strFullLine);

};

#endif // !defined(AFX_PSParadiseLOGPLAYERACTION_H__864632CF_2402_42F8_8ED1_150A0231A3D8__INCLUDED_)
