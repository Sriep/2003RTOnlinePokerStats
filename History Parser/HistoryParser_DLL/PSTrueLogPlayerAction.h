// PSTrueLogPlayerAction.h: interface for the CPSTrueLogPlayerAction class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CPSTrueLogPlayerAction__INCLUDED_)
#define AFX_CPSTrueLogPlayerAction__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "PSTrueLog.h"

class CPSTrueLogPlayerAction : public CPSTrueLog  
{
public:
	CPSTrueLogPlayerAction(CParseFile* cPF);
	virtual ~CPSTrueLogPlayerAction();
	virtual CParseState* ParseI(const CString &strInLine, const CString &strFullLine);

};

#endif // !defined(AFX_CPSTrueLogPlayerAction__INCLUDED_)
