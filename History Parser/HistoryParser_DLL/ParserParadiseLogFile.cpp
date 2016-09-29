// ParserParadiseLogFile.cpp: implementation of the CParserParadiseLogFile class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ParserParadiseLogFile.h"
#include "PSParadiseLogSmallBlind.h"
#include "SharedMemory.h"
#include "PPokerSite.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

#define PARADISE_NEW_TEXT_BLOCK_MARKER "End of Paradise poker text --- End of Paradise poker text"
#define BLOCKS_TO_SKIP 110

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CParserParadiseLogFile::CParserParadiseLogFile()
: m_bAtStartOfNextHand(false)
{
}

CParserParadiseLogFile::~CParserParadiseLogFile()
{

}

void CParserParadiseLogFile::ParseLogFile(HWND hwnd, long& lFilePosition, const  CString& strTableName)
{
	m_strTableName =  strTableName;
	m_hwndDealerText = hwnd;
	
	CSharedMemory cSM;
	cSM.OpenSharedMemory(PPokerSite::GetDealerTextName(hwnd, PPokerSite::POKER_SITE_PARADISE), PAGE_READONLY);

	cSM.Seek(lFilePosition);
	CString strNextHand = "";
	istrstream streamSM((char*)cSM.GerPtrNext());
	SkipBlocks(streamSM, 1);
	CString strHandNumber = ReadNextHand(streamSM, strNextHand);

	while (!strHandNumber.IsEmpty())
	{
		Setup();
		istrstream cInStream(strNextHand.GetBuffer(1), strNextHand.GetLength());
		ParseHand(cInStream, strHandNumber);
		CloseDown();
		strNextHand = "";
		strHandNumber = ReadNextHand(streamSM, strNextHand);
	}
	lFilePosition = cSM.GetPositon();
	cSM.Clear();
	SavePlayersList();
	cSM.CloseSharedMemory();
}



CString CParserParadiseLogFile::ReadNextHand(istrstream& cInStream, CString &strNextHand)
{
	TRACE("CParserParadiseLogFile::ReadNextHand\n");
	char pchInputLine  [MAX_LINE_LENGTH]; 
	CString strGameNumber = "";
	if (!m_bAtStartOfNextHand && !FindStartOfNextHand(cInStream))
		return CString("");
	m_bAtStartOfNextHand = false;
	while (!cInStream.eof() 
		&& 0 != strcmp(pchInputLine, "»Dealer: Starting a new hand...")	)
	{
		if (0 == strcmp(pchInputLine, PARADISE_NEW_TEXT_BLOCK_MARKER))
		{
			//TRACE("In ReadNextHand, \"End of Paradise poker\" text fone\n");
			//strNextHand =  "";
			//if (!FindStartOfNextHand(cInStream))
			//	return CString("");
			SkipBlocks(cInStream, BLOCKS_TO_SKIP);

			TRACE("In ReadNextHand, \"End of PokerRoom poker\" text fone\n");
			strNextHand =  "";
			if (cInStream.eof() || !FindStartOfNextHand(cInStream))
				return CString("");
		}
		else
		{
			strNextHand += pchInputLine;
			strNextHand +=  "\n";
			if (0 == strncmp(pchInputLine, "»#", 2) )
			{
				TRACE("In ReadNextHand, hand number read\n");
				strGameNumber = GetGameNumber(pchInputLine + 2, ':');
				if (HasHandBeenRead(strGameNumber))
				{
					TRACE1("In ReadNextHand, hand number %s has already been read\n", strGameNumber);
					strNextHand =  "";
					if (!FindStartOfNextHand(cInStream))
						return CString("");
				}
			}
		}
		
		cInStream.getline(pchInputLine, MAX_LINE_LENGTH);
	}
	if (cInStream.eof())
	{	
		strNextHand = "";
	}
	else
	{
		m_bAtStartOfNextHand = true;
	}

	TRACE("In ReadNextHand returning with new hand\n");
	return strGameNumber;
}

void CParserParadiseLogFile::SkipBlocks(istrstream& cInStream, int iNumOfBLocksToSkip)
{
	char pchInputLine  [MAX_LINE_LENGTH]; 
	
	for ( int iBlockedSkipped = 0 ; iBlockedSkipped < iNumOfBLocksToSkip ; iBlockedSkipped++ ) 
	{
		while (!cInStream.eof() && 0 != strcmp(pchInputLine, PARADISE_NEW_TEXT_BLOCK_MARKER)	)
		{
			cInStream.getline(pchInputLine, MAX_LINE_LENGTH);
		}
		if (cInStream.eof())
			return;
	}
}

void CParserParadiseLogFile::ParseHand(istrstream& cInStream, const CString& strGameNumber)
{
	m_pCurrentState = new CPSParadiseLogSmallBlind(this);
	m_cInputHand.SetPokerSite(PPokerSite::POKER_SITE_PARADISE);
	m_cInputHand.SetIncomplete();
	try
	{
		m_cInputHand.SetGameNumber(strGameNumber);
	}
	catch (CParsingException* pException)
	{
		if (pException->IsCloseGame())
		{
			throw(pException);
		}
		return;
	}
	catch (...)
	{
		return;
	}
	GetListNicks().clear();

	char pchInputLine  [MAX_LINE_LENGTH]; 
	
	
	while (!cInStream.eof())
	{
		try	
		{
			cInStream.getline(pchInputLine, MAX_LINE_LENGTH);
			ParseLine(pchInputLine);
		}
		catch (CParsingException* pException)
		{
			if (pException->IsError(IDS_PARADISE_HAND_JUMBLED))
			{
				CloseDown();
				m_cInputHand.AddJumbledHand(strGameNumber);
			}			
			if (pException->IsCloseGame())
			{
				throw(pException);
			}
			return;
		}
		catch (...)
		{
			//ASSERT(false);
			return;
		}
	}
	m_cInputHand.WriteToDataBase();
	NewHand();
	RefreshPlayers();
}

bool CParserParadiseLogFile::FindStartOfNextHand(istrstream& cInStream)
{
	TRACE("Stat if CParserParadiseLogFile::FindStartOfNextHand\n");
	char pchInputLine  [MAX_LINE_LENGTH] = ""; 

	while (!cInStream.eof() && 0 == strcmp(pchInputLine, PARADISE_NEW_TEXT_BLOCK_MARKER))
	{
		cInStream.getline(pchInputLine, MAX_LINE_LENGTH);
	}

	while (!cInStream.eof() && 0 != strcmp(pchInputLine, "»Dealer: Starting a new hand...")	)
	{
		cInStream.getline(pchInputLine, MAX_LINE_LENGTH); 
		if (0 == strcmp(pchInputLine, PARADISE_NEW_TEXT_BLOCK_MARKER))
			SkipBlocks(cInStream, BLOCKS_TO_SKIP);
	}
	return !cInStream.eof();
}
/*
CString CParserParadiseLogFile::GetGameNumber(LPSTR pchInputLine)
{
	char* pchEndOfHandNumber = 	strchr(pchInputLine, ':');
	if (pchEndOfHandNumber != NULL)
	{
		CString strHandNumber ="";
		for (char* pch = pchInputLine ; pch != pchEndOfHandNumber ; pch++ )
		{
			if (*pch != ',')
			{
				strHandNumber += *pch;	
			}
		}
		return strHandNumber;
	}
	return CString("0");
} */

bool CParserParadiseLogFile::HasHandBeenRead(const CString& strGameNumber)
{
	//CPDHandRecordset rsHands(m_cInputHand.GetDatabase());
	//return rsHands.HasHandBeenRead(strGameNumber, PPokerSite::POKER_SITE_PARADISE);

	CDatabase  dbLogDatabase;
	if ( !dbLogDatabase.Open(PPokerSite::GetLoggingDataSource(PPokerSite::POKER_SITE_PARADISE), 
								false, 
								false, 
								PPokerSite::GetLoggingSQLConnectString(PPokerSite::POKER_SITE_PARADISE)) )
	{
		throw(new CParsingException("Error opening Poker Data database"));
	}
	CPDHandRecordset rsLogHands(&dbLogDatabase);
	if (rsLogHands.HasHandBeenRead(strGameNumber, PPokerSite::POKER_SITE_PARADISE))
		return true;


	CDatabase  dbCurrentDatabase;
	if ( !dbCurrentDatabase.Open(PPokerSite::GetCurrentDataSource(PPokerSite::POKER_SITE_PARADISE), 
									false, 
									false, 
									PPokerSite::GetCurrentSQLConnectString(PPokerSite::POKER_SITE_PARADISE)) )
	{
		throw(new CParsingException("Error opening Poker Data database"));
	}
	CPDHandRecordset rsCurrentHands(&dbCurrentDatabase);
	return rsCurrentHands.HasHandBeenRead(strGameNumber, PPokerSite::POKER_SITE_PARADISE);
}

void CParserParadiseLogFile::ParseLine(const CString &strInputLine)
{
	try
	{
		m_pCurrentState = m_pCurrentState->Parse(strInputLine);
	}
	catch (CParsingException* pException)
	{							
		ASSERT(!pException->IsSkipFile());
		CloseDown();
		if (pException->GetCurrentParseState())
		{
			delete(pException->GetCurrentParseState());
		}
		else
		{
			delete m_pCurrentState;
		}
		m_pCurrentState = new CPSNone(this);
		throw(pException);	 //Zero tolerance for Paradise logs
	}
	ASSERT(m_pCurrentState != NULL);
}

int CParserParadiseLogFile::GetSite()
{
	return PPokerSite::POKER_SITE_PARADISE;
}

