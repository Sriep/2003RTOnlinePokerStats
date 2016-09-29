// ParserPokerRoomLogFile.cpp: implementation of the CParserPokerRoomLogFile class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ParserPokerRoomLogFile.h"
#include "PSPokerRoomLogSmallBlind.h"
#include "SharedMemory.h"
#include "PPokerSite.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

#define POKER_ROOM_NEW_TEXT_BLOCK_MARKER "@@END_OF_POKER_ROOM_TEXT_BLOCK@@"
#define BLOCKS_TO_SKIP 60
#define NEWHAND_MARKER "----------------------------  "

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CParserPokerRoomLogFile::CParserPokerRoomLogFile()
: m_bAtStartOfNextHand(false)
{
}

CParserPokerRoomLogFile::~CParserPokerRoomLogFile()
{

}

void CParserPokerRoomLogFile::ParseLogFile(HWND hwnd, long& lFilePosition, const  CString& strTableName)
{
	m_strTableName =  strTableName;
	m_hwndDealerText = hwnd;
	
	CSharedMemory cSM;
	cSM.OpenSharedMemory(PPokerSite::GetDealerTextName(hwnd, PPokerSite::POKER_SITE_POKER_ROOM), PAGE_READONLY);

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



CString CParserPokerRoomLogFile::ReadNextHand(istrstream& cInStream, CString &strNextHand)
{
	TRACE("CParserPokerRoomLogFile::ReadNextHand\n");
	char pchInputLine  [MAX_LINE_LENGTH]; 
	CString strGameNumber = "";
	if (!m_bAtStartOfNextHand && !FindStartOfNextHand(cInStream))
		return CString("");
	m_bAtStartOfNextHand = false;
	cInStream.getline(pchInputLine, MAX_LINE_LENGTH);
	while (!cInStream.eof() 
		&& 0 != strcmp(pchInputLine, NEWHAND_MARKER))
	{
		if (0 == strcmp(pchInputLine, POKER_ROOM_NEW_TEXT_BLOCK_MARKER))
		{
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
			if (0 == strncmp(pchInputLine, "Hand #", 6) )
			{
				TRACE("In ReadNextHand, hand number read\n");
				strGameNumber = GetGameNumber(pchInputLine + 6, ' ');
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

void CParserPokerRoomLogFile::SkipBlocks(istrstream& cInStream, int iNumOfBLocksToSkip)
{
	char pchInputLine  [MAX_LINE_LENGTH]; 
	
	for ( int iBlockedSkipped = 0 ; iBlockedSkipped < iNumOfBLocksToSkip ; iBlockedSkipped++ ) 
	{
		cInStream.getline(pchInputLine, MAX_LINE_LENGTH);
		while (!cInStream.eof() && 0 != strcmp(pchInputLine, POKER_ROOM_NEW_TEXT_BLOCK_MARKER)	)
		{
			cInStream.getline(pchInputLine, MAX_LINE_LENGTH);
		}
		if (cInStream.eof())
			return;
	}
}

void CParserPokerRoomLogFile::ParseHand(istrstream& cInStream, const CString& strGameNumber)
{
	m_pCurrentState = new CPSPokerRoomLogSmallBlind(this);
	m_cInputHand.SetPokerSite(PPokerSite::POKER_SITE_POKER_ROOM);
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
			if (pException->IsError(IDS_NOT_ENOUGH_PLAYERS))
			{
				if (GetListNicks().size() > MIN_NUMBER_OF_PLAYERS)
					return;
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
	if (m_listNicks.size() <= 5)
		return; //Assume that all 5 or less hands are errors.
	m_cInputHand.WriteToDataBase();
	NewHand();
	RefreshPlayers();
}

bool CParserPokerRoomLogFile::FindStartOfNextHand(istrstream& cInStream)
{
	TRACE("Stat if CParserPokerRoomLogFile::FindStartOfNextHand\n");
	char pchInputLine  [MAX_LINE_LENGTH] = ""; 
	cInStream.getline(pchInputLine, MAX_LINE_LENGTH); 
	while (!cInStream.eof() && 0 == strcmp(pchInputLine, POKER_ROOM_NEW_TEXT_BLOCK_MARKER))
	{
		cInStream.getline(pchInputLine, MAX_LINE_LENGTH);
	}

	while (!cInStream.eof() && 0 != strcmp(pchInputLine, NEWHAND_MARKER)	)
	{
		cInStream.getline(pchInputLine, MAX_LINE_LENGTH); 
		if (0 == strcmp(pchInputLine, POKER_ROOM_NEW_TEXT_BLOCK_MARKER))
			SkipBlocks(cInStream, BLOCKS_TO_SKIP);
	}
	return !cInStream.eof();
}


bool CParserPokerRoomLogFile::HasHandBeenRead(const CString& strGameNumber)
{
	CDatabase  dbLogDatabase;
	if ( !dbLogDatabase.Open(PPokerSite::GetLoggingDataSource(PPokerSite::POKER_SITE_POKER_ROOM), 
								false, 
								false, 
								PPokerSite::GetLoggingSQLConnectString(PPokerSite::POKER_SITE_POKER_ROOM)) )
	{
		throw(new CParsingException("Error opening Poker Data database"));
	}
	CPDHandRecordset rsLogHands(&dbLogDatabase);
	if (rsLogHands.HasHandBeenRead(strGameNumber, PPokerSite::POKER_SITE_POKER_ROOM))
		return true;


	CDatabase  dbCurrentDatabase;
	if ( !dbCurrentDatabase.Open(PPokerSite::GetCurrentDataSource(PPokerSite::POKER_SITE_POKER_ROOM), 
									false, 
									false, 
									PPokerSite::GetCurrentSQLConnectString(PPokerSite::POKER_SITE_POKER_ROOM)) )
	{
		throw(new CParsingException("Error opening Poker Data database"));
	}
	CPDHandRecordset rsCurrentHands(&dbCurrentDatabase);
	return rsCurrentHands.HasHandBeenRead(strGameNumber, PPokerSite::POKER_SITE_POKER_ROOM);
}

void CParserPokerRoomLogFile::ParseLine(const CString &strInputLine)
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
		throw(pException);	 //Zero tolerance for PokerRoom logs
	}
	ASSERT(m_pCurrentState != NULL);
}

int CParserPokerRoomLogFile::GetSite()
{
	return PPokerSite::POKER_SITE_POKER_ROOM;
}

