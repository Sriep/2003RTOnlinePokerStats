// PSTrueLogPlayerFirxtAction.h: interface for the CPSTrueLogPlayerFirxtAction class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CPSTrueLogPlayerFirstAction__INCLUDED_)
#define AFX_CPSTrueLogPlayerFirstAction__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "PSTrueLog.h"

class CPSTrueLogPlayerFirstAction : public CPSTrueLog  
{
public:
	CPSTrueLogPlayerFirstAction(CParseFile* cPF);
	virtual ~CPSTrueLogPlayerFirstAction();
	virtual CParseState* ParseI(const CString &strInLine, const CString &strFullLine);
};

#endif // !defined(AFX_CPSTrueLogPlayerFirstAction__INCLUDED_)
									  