// HistoryParserModel.cpp: implementation of the CHistoryParserModel class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "history parser.h"
#include "HistoryParserModel.h"
#include <io.h>
#include "PPokerObject.h"

#if !defined(LIST_DEFS)
#define	 LIST_DEFS
#include <list>
using std::list;
typedef std::list <CString>::iterator StringListIterator;
typedef std::list <CString>::const_iterator ConstStringListIterator;
typedef std::list <CString> StringList; 
typedef std::list <CString*> CNickPtrList;
typedef std::list <CString*>::iterator CNickPtrListIter;
#endif

#define MAX_LINE_LENGTH 200
#define NO_FILE_FOUND -1

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
typedef UINT (CALLBACK* LPFNDLLFUNC_READFILE)(const CString&);
//typedef UINT (CALLBACK* LPFNDLLFUNC_READFILEGETNICKS)(const CString&, int&, StringList&);
typedef UINT (CALLBACK* LPFNDLLFUNC_READFILEGETNICKS)(const CString&, StringList&);

CHistoryParserModel::CHistoryParserModel()
{

}

CHistoryParserModel::~CHistoryParserModel()
{
}

void CHistoryParserModel::ParseDirectory(const CString& strFindDir, const CString strCopyDir, CHistoryParserDlg& cViewWindow)
{
	int iTotalFiles = GetNumberOfFiles(strFindDir);
	int iNumFilesDone = 0;
	_finddata_t	sFileData;
	long  lNextFile = _findfirst(CString(strFindDir + "\\*.txt"), &sFileData); 
	while(lNextFile != NO_FILE_FOUND)
	{
		TRACE1("About to parse %s\n", sFileData.name);
		CString strOldFileName = strFindDir + "\\" + sFileData.name;
		UpdateView(strOldFileName, (iNumFilesDone*100)/iTotalFiles, cViewWindow);
		ParseFile(strOldFileName);
		iNumFilesDone++;
		CString strNewFileName = strCopyDir + "\\" + sFileData.name;
		TRACE2("Moving the file %s to %s\n", strOldFileName, strNewFileName);
		 
		_findclose(lNextFile);

		CFileStatus status;
		if (CFile::GetStatus(strNewFileName, status))
		{
			CFile::Remove(strNewFileName);
		}
		CFile::Rename(strOldFileName, strNewFileName);

		lNextFile = _findfirst(CString(strFindDir + "\\*.txt"), &sFileData); 

	}
	_findclose(lNextFile);
}

int CHistoryParserModel::GetNumberOfFiles(const CString& strFindDir)
{
	int iCount = 0;
	_finddata_t	sFileData;
	long  lNextFile = _findfirst(CString(strFindDir + "\\*.txt"), &sFileData); 
	if (lNextFile != NO_FILE_FOUND)
	{
		iCount++;
		while(NO_FILE_FOUND != _findnext(lNextFile, &sFileData)) 
		{
			iCount++;
		}
	}
	_findclose(lNextFile);
	return iCount;
}

void CHistoryParserModel::UpdateView(const CString& strNextFile, int pctDone, CHistoryParserDlg& cViewWindow)
{
	cViewWindow.m_cProgressBar.SetPos(pctDone);
	CString strStatus;
	strStatus.Format("Reading File %s", strNextFile);
	cViewWindow.m_cParsingStatus.SetWindowText(strStatus);
	cViewWindow.UpdateWindow();
}

void CHistoryParserModel::ParseFile(const CString& strFileName)
{
	HINSTANCE hinstDLL; 
	hinstDLL = AfxLoadLibrary ((LPCTSTR) HISTORY_PARSER_DLL); 
	LPFNDLLFUNC_READFILE lpfnParseHandHistory = (LPFNDLLFUNC_READFILE)GetProcAddress(hinstDLL, "ParseHandHistory"); 
	lpfnParseHandHistory(strFileName);
						   
}

void CHistoryParserModel::ParseLogFile(const CString& strFileName)
{
	//int iPos = 0;
	StringList listPlayers;
	HINSTANCE hinstDLL; 
	hinstDLL = AfxLoadLibrary ((LPCTSTR) HISTORY_PARSER_DLL); 
	LPFNDLLFUNC_READFILEGETNICKS lpfnParseLogFileGetPlayers = (LPFNDLLFUNC_READFILEGETNICKS)GetProcAddress(hinstDLL, "ParseParadiseLogFile"); 
	//lpfnParseLogFileGetPlayers(strFileName, iPos, listPlayers);
	lpfnParseLogFileGetPlayers(strFileName, listPlayers);
}

