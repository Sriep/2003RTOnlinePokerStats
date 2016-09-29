// ParseFile.h: interface for the CParseUltimateBetLogFile class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PARSE_ULTIMATE_BET_LOG_FILE_H__INCLUDED_)
#define AFX_PARSE_ULTIMATE_BET_LOG_FILE_H__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "ParseLogFile.h"

class CParseUltimateBetLogFile  : public CParseLogFile   
{
public:
	CParseUltimateBetLogFile();
	virtual ~CParseUltimateBetLogFile();
	virtual int GetSite();
	int GetNumberOfHiddenCharactersPerLogLine()	const;
protected:
	virtual CParseState* GetStartState();
};

#endif // !defined(AFX_PARSE_ULTIMATE_BET_LOG_FILE_H__INCLUDED_)
