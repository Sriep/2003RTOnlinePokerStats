// ParseTruePokeLogFile.cpp: implementation of the CParseTruePokeLogFile class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ParseTruePokerLogFile.h"
#include "TrueLogNone.h"
#include "SharedMemory.h"
#include "PPokerSite.h"
#include <io.h>
#include <fstream.h>

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
 
CString CParseTruePokeLogFile::sm_strTheLastLogFileName = "";

CParseTruePokeLogFile::CParseTruePokeLogFile()
{
}

CParseTruePokeLogFile::~CParseTruePokeLogFile()
{

}

void CParseTruePokeLogFile::ParseLogFile(HWND hwnd, long& lFilePosition, const CString& strTableName)
{
	m_strTableName =  strTableName;
	CString strLogFileName = GetTruePokerLogFileName(strTableName);
	if (sm_strTheLastLogFileName != strLogFileName)
	{
		lFilePosition = 0;	
	}
	sm_strTheLastLogFileName = strLogFileName;
	TRACE1("Reading True Poker log file %s\n", strLogFileName);
	ifstream fTrueLog(strLogFileName);
	if (fTrueLog.is_open())
	{
		try
		{
			m_pCurrentState = GetStartState();	   
			Setup();
			fTrueLog.seekg(lFilePosition, ios::beg);
			TRACE("About to start at postion %d\n", lFilePosition);
			int iChReadInThisHand = 0;
			BOOL bFirst = true;
			char pchInputLine[MAX_LINE_LENGTH];
			while (!fTrueLog.eof())
			{
				fTrueLog.getline(pchInputLine, MAX_LINE_LENGTH);
				if (bFirst)
				{
					bFirst = false;
					TRACE("First Line to parse is --- %s\n", pchInputLine);
				}
				iChReadInThisHand += strlen(pchInputLine) + 2;//GetNumberOfHiddenCharactersPerLogLine();
				ParseLine(pchInputLine);
				if (m_bNewHand)
				{
					TRACE("New Hand added, last line was -- %s\n", pchInputLine);
					lFilePosition += iChReadInThisHand - strlen(pchInputLine) - 1;//GetNumberOfHiddenCharactersPerLogLine(); 
					iChReadInThisHand = 0;
					m_bNewHand = false;
				}
			}
			CloseDown();
			SavePlayersList();
		}
		catch (CParsingException* pException)
		{
			fTrueLog.close();		
			throw(pException);
		}
		fTrueLog.close();		
	}
}


int CParseTruePokeLogFile::GetSite()
{
	return PPokerSite::POKER_SITE_TRUE;
}

CString CParseTruePokeLogFile::GetTruePokerLogFileName(const CString& strTableName)
{
    struct _finddata_t dataFile;;
    long hFile;

	CString strSearchFormat = TRUE_POKER_LOG_FILE_PATH;
	strSearchFormat += "TP Play Log*.txt";	
    if( (hFile = _findfirst( strSearchFormat, &dataFile )) == -1L )
	{
      return CString("");
	}
	CString strLatestFile;
	time_t  tLastWrite = 0;

    do
    {
        if (MatchesTable(&dataFile, strTableName))
		{
			if (tLastWrite < dataFile.time_write)
			{
				tLastWrite = dataFile.time_write;
				strLatestFile = dataFile.name;
			}
		}
    }  while(_findnext(hFile, &dataFile) == 0) ;
    _findclose(hFile);
	CString strFillPathName = TRUE_POKER_LOG_FILE_PATH;
	strFillPathName += strLatestFile;
	return strFillPathName;
}

BOOL CParseTruePokeLogFile::MatchesTable(_finddata_t* pdataFile, const CString& strTableName)
{
	CString strFillPathName = TRUE_POKER_LOG_FILE_PATH;
	CString strFileName = strFillPathName + pdataFile->name;
	ifstream fTrueLog(strFileName);
	if (fTrueLog.is_open())
	{
		try
		{
			char pchInputLine[MAX_LINE_LENGTH];
			fTrueLog.getline(pchInputLine, MAX_LINE_LENGTH);
			if (!fTrueLog.eof())
			{
				fTrueLog.getline(pchInputLine, MAX_LINE_LENGTH);
				for (int i = 1 ; i < strTableName.GetLength() ; i++)
				{
					if (strTableName.GetAt(i) != pchInputLine[i])
						return false;
				}
				return true;
			}
			else
			{
				fTrueLog.close();
				return false;
			}
		}

		catch (...)
		{
		}
		fTrueLog.close();
	}
	return false;
}

CParseState* CParseTruePokeLogFile::GetStartState()
{
	return new CTrueLogNone(this);
}

int CParseTruePokeLogFile::GetNumberOfHiddenCharactersPerLogLine()	const
{
	return 1;
}

