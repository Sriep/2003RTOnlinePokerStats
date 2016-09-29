// ParseFile.h: interface for the CParseHighStakesLogFile class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PARSE_HighStakes_LOG_FILE_H__516981A2_E165_4F8D_A2F9_7DACD5F44D0B__INCLUDED_)
#define AFX_PARSE_HighStakes_LOG_FILE_H__516981A2_E165_4F8D_A2F9_7DACD5F44D0B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "ParseLogFile.h"

class CParseHighStakesLogFile  : public CParseLogFile   
{
public:
	CParseHighStakesLogFile();
	virtual ~CParseHighStakesLogFile();
	virtual int GetSite();
	int GetNumberOfHiddenCharactersPerLogLine()	const;
protected:
	virtual CParseState* GetStartState();
};

#endif // !defined(AFX_PARSE_HighStakes_LOG_FILE_H__516981A2_E165_4F8D_A2F9_7DACD5F44D0B__INCLUDED_)
