// HistoryParserModel.h: interface for the CHistoryParserModel class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_HISTORYPARSERMODEL_H__0319D969_3132_4741_82C3_1480721F9A33__INCLUDED_)
#define AFX_HISTORYPARSERMODEL_H__0319D969_3132_4741_82C3_1480721F9A33__INCLUDED_

#include <fstream.h>
#include "History ParserDlg.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CParseState;

class CHistoryParserModel  
{
public:
	CHistoryParserModel();
	virtual ~CHistoryParserModel();	
	
	void ParseInputStream(istream& cInStream);
	void ParseFile(const CString& strFileName);
	void ParseLogFile(const CString& strFileName);
	void ParseDirectory(const CString& strFindDir, const CString strCopyDir, CHistoryParserDlg& cViewWindow);
	int GetNumberOfFiles(const CString& strFindDir);
	void UpdateView(const CString& strNextFile, int pctDone, CHistoryParserDlg& cViewWindow);

private:
	void ParseLine(const CString& strInputLine);
};

#endif // !defined(AFX_HISTORYPARSERMODEL_H__0319D969_3132_4741_82C3_1480721F9A33__INCLUDED_)
