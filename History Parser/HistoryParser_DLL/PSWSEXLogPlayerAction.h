// PSWSEXLogPlayerAction.h: interface for the CPSWSEXLogPlayerAction class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PSWSEXLOGPLAYERACTION_H__864632CF_2402_42F8_8ED1_150A0231A3D8__INCLUDED_)
#define AFX_PSWSEXLOGPLAYERACTION_H__864632CF_2402_42F8_8ED1_150A0231A3D8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "PSWSEXLog.h"

class CPSWSEXLogPlayerAction : public CPSWSEXLog  
{
public:
	CPSWSEXLogPlayerAction(CParseFile* cPF);
	virtual ~CPSWSEXLogPlayerAction();
	virtual CParseState* ParseI(const CString &strInLine, const CString &strFullLine);

};

#endif // !defined(AFX_PSWSEXLOGPLAYERACTION_H__864632CF_2402_42F8_8ED1_150A0231A3D8__INCLUDED_)
