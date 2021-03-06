// ParserParadiseLogFile.h: interface for the CParserParadiseLogFile class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PARSERPARADISELOGFILE_H__45B7785D_3950_41EE_9C2A_21C8EC95CFB9__INCLUDED_)
#define AFX_PARSERPARADISELOGFILE_H__45B7785D_3950_41EE_9C2A_21C8EC95CFB9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ParseFile.h"
#include <fstream.h>
#include <strstrea.h>
#include "ParseLogFile.h"

class CParserParadiseLogFile : public CParseLogFile  
{
public:
	bool HasHandBeenRead(const CString& strGameNumber);
	//static CString GetGameNumber(LPSTR pchInputLine);
	virtual void ParseLogFile(HWND hwnd, long& lFilePositionconst, const CString& strTableName);
	CParserParadiseLogFile();
	virtual ~CParserParadiseLogFile();
	virtual void ParseLine(const CString& strInputLine);
	virtual int GetSite();

	bool FindStartOfNextHand(istrstream& cInStream);
	virtual void ParseHand(istrstream& cInStream, const CString& strGameNumber);
	CString ReadNextHand(istrstream& cInStream, CString& strNextHand);

private:
	void SkipBlocks(istrstream& cInStream, int iNumBlocksToSkip);
	bool m_bAtStartOfNextHand;
};

#endif // !defined(AFX_PARSERPARADISELOGFILE_H__45B7785D_3950_41EE_9C2A_21C8EC95CFB9__INCLUDED_)
