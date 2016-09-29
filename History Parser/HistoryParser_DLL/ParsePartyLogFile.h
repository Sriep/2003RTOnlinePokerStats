// ParseFile.h: interface for the CParsePartyLogFile class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PARSE_PARTY_LOG_FILE_H__516981A2_E165_4F8D_A2F9_7DACD5F44D0B__INCLUDED_)
#define AFX_PARSE_PARTY_LOG_FILE_H__516981A2_E165_4F8D_A2F9_7DACD5F44D0B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "ParseLogFile.h"

class CParsePartyLogFile  : public CParseLogFile   
{
public:
	CParsePartyLogFile();
	virtual ~CParsePartyLogFile();
	virtual int GetSite();

protected:
	virtual CParseState* GetStartState();
};

#endif // !defined(AFX_PARSE_PARTY_LOG_FILE_H__516981A2_E165_4F8D_A2F9_7DACD5F44D0B__INCLUDED_)
