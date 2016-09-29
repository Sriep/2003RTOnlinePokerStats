// ParseFile.h: interface for the CParseTruePokeLogFile class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PARSE_TruePoke_LOG_FILE_H__516981A2_E165_4F8D_A2F9_7DACD5F44D0B__INCLUDED_)
#define AFX_PARSE_TruePoke_LOG_FILE_H__516981A2_E165_4F8D_A2F9_7DACD5F44D0B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "ParseLogFile.h"
//#include <fstream.h>
#include <io.h>

class CParseTruePokeLogFile  : public CParseLogFile   
{
public:
	CParseTruePokeLogFile();
	virtual ~CParseTruePokeLogFile();

	virtual void ParseLogFile(HWND hwnd, long& lFilePositionconst, const CString& strTableName);
	virtual int GetSite();
	CParseState* GetStartState();
	int GetNumberOfHiddenCharactersPerLogLine()	const;
protected:

private:
	CString GetTruePokerLogFileName(const CString& strTableName);
	static BOOL MatchesTable(_finddata_t* pdataFile, const CString& strTableName);
	static CString sm_strTheLastLogFileName;
};

#endif // !defined(AFX_PARSE_TruePoke_LOG_FILE_H__516981A2_E165_4F8D_A2F9_7DACD5F44D0B__INCLUDED_)
