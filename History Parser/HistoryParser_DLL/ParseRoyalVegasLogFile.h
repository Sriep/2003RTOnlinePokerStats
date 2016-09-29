// ParseFile.h: interface for the CParseRoyalVegasLogFile class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PARSE_RoyalVegas_LOG_FILE_H__516981A2_E165_4F8D_A2F9_7DACD5F44D0B__INCLUDED_)
#define AFX_PARSE_RoyalVegas_LOG_FILE_H__516981A2_E165_4F8D_A2F9_7DACD5F44D0B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "ParseLogFile.h"

class CParseRoyalVegasLogFile  : public CParseLogFile   
{
public:
	CParseRoyalVegasLogFile();
	virtual ~CParseRoyalVegasLogFile();
	virtual int GetSite();
	int GetNumberOfHiddenCharactersPerLogLine()	const;
protected:
	virtual CParseState* GetStartState();
};

#endif // !defined(AFX_PARSE_RoyalVegas_LOG_FILE_H__516981A2_E165_4F8D_A2F9_7DACD5F44D0B__INCLUDED_)
