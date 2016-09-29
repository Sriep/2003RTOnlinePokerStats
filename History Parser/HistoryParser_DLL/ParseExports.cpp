#include "stdafx.h"
#include <fstream.h>
#include "ParseExports.h"
#include "PPokerSite.h"
#include "RS_DBQueue.h"
#include "ParseLogFile.h"
#include "resource.h"

STDAPI ParseHandHistory(const CString& strFileName)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	ifstream fToParse(strFileName);
	if (fToParse.is_open())
	{
		CParseFile cParser;
		cParser.SetDataSource();
		cParser.ParseHandHistory(fToParse);
		fToParse.close();		
	}
	else
	{
		return 1;
	}
	return 0;
}

void LogStart(CTime& tBefore)
{
	tBefore = CTime::GetCurrentTime();
	CString strTimeStart = tBefore.Format("%#c");
	
	CString strText;
	strText.Format("Starting Parsing Table Time now %s\n", strTimeStart);

	ofstream fOutFile(SPY_DEAMON_LOG_FILE, ios::app , filebuf::sh_read || filebuf::sh_write);
	fOutFile.write(strText, strlen(strText));
	fOutFile.flush();
	fOutFile.close();
}

void LogFinish(CTime tBefore, long lPosBefore, long lPosAfter, int iHandsRead)
{
	CString strFileName;
	CTime tAfter = CTime::GetCurrentTime();
	CString strTimeFinish = tAfter.Format("%#c");
	CTimeSpan tsTimeTook = tAfter - tBefore;
	int iSecsPerHand = 0;
	if (iHandsRead > 0)
	{
		iSecsPerHand = (tsTimeTook.GetTotalMinutes()*60 + tsTimeTook.GetSeconds()) / iHandsRead;
	}
	
	CString strText;
	strText.Format("FinishedTime:%s: Lines:%d  Hands:%d  mins:%d  secs:%d Average %d secs per hand\n\n",
		strTimeFinish,
		lPosAfter -  lPosBefore,
		iHandsRead,
		tsTimeTook.GetTotalMinutes(),
		tsTimeTook.GetSeconds(),
		iSecsPerHand);

	ofstream fOutFile(SPY_DEAMON_LOG_FILE, ios::app , filebuf::sh_read || filebuf::sh_write);

	fOutFile.write(strText, strlen(strText));
	fOutFile.flush();
	fOutFile.close();
}


STDAPI ParseLogFile(HWND hwnd, int iSite, long* lFilePosition, const CString& strTableName)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	RS_DBQueue dbQueue;
	RS_DBQueue::QueueID qId = 0;
	CTime tBefore;
	LogStart(tBefore);
	long lStartPositionBefore = *lFilePosition;

	try
	{
		CParseLogFile* pParseLogFile = CParseLogFile::New(iSite);
		pParseLogFile->SetDataSource();

		if (NULL != pParseLogFile)
		{
			TRACE("About to wait for databse\n"); 
			CString strDescDBLock;
			strDescDBLock.Format("Parse Hands at %s, table name %s", PPokerSite::GetName(iSite), strTableName);
			qId = dbQueue.WaitToUseDB(RS_DBQueue::DB_QUEUE_LOWEST_PRIORITY, strDescDBLock);
			TRACE("Got permission to use database\n");
			
			pParseLogFile->ParseLogFile(hwnd, *lFilePosition, strTableName);

			dbQueue.FinishedUsingDB(qId);

			LogFinish(tBefore, lStartPositionBefore, *lFilePosition, pParseLogFile->GetHandsRead());
			return 0;
		}
		else
		{
			return ERROR_POKER_SITE_IMPLIMENTED;
		}
	}
	catch (CParsingException* pException)
	{
		dbQueue.FinishedUsingDB(qId);
		
		if (pException->IsError(IDS_PARADISE_HAND_JUMBLED))
		{
			delete(pException);
			return ERROR_PARADISE_HAND_JUMHBLED;
		}
		if (pException->IsCloseGame())
		{
			delete(pException);
			return ERROR_CLOSE_GAME_WINDOW;
		}
		else
		{
			delete(pException);
			return 1;
		}
	}
	catch (CDBException* pDBException)
	{
		pDBException->ReportError(MB_OK, IDS_DBERROR2); 
		dbQueue.FinishedUsingDB(qId);
		throw(pDBException);
	}
}




