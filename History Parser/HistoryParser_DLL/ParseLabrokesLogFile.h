// ParseLabrokesLogFile.h: interface for the CParseRoyalVegasLogFile class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PARSE_CParseLabrokesLogFile__INCLUDED_)
#define AFX_PARSE_CParseLabrokesLogFile__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "ParseLogFile.h"

class CParseLabrokesLogFile  : public CParseLogFile   
{
public:
	CParseLabrokesLogFile();
	virtual ~CParseLabrokesLogFile();
	virtual int GetSite();
	int GetNumberOfHiddenCharactersPerLogLine()	const;
protected:
	virtual CParseState* GetStartState();
};

#endif // !defined(AFX_PARSE_CParseLabrokesLogFile__INCLUDED_)
