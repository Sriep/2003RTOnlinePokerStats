// ParseLogFile.cpp: implementation of the CParseLogFile class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ParseLogFile.h"
#include "PlayerList.h"
#include "ParserParadiseLogFile.h"
#include "ParsePartyLogFile.h"
#include "ParseUltimateBetLogFile.h"
#include "ParseRoyalVegasLogFile.h"
#include "ParseTruePokerLogFile.h"
#include "ParseLabrokesLogFile.h"
#include "ParseHighStakesLogFile.h"
#include "ParseCryptologicLogFile.h"
#include "ParseWSEXLogFile.h"
#include "ParsePokerClubLogFile.h" 
#include "ParserPokerRoomLogFile.h"
#include "RSCurrentPlayers.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CParseLogFile::CParseLogFile()
:	m_bFoundAllPlayers(false),
	m_bNewHand(false),
	m_hwndDealerText(NULL),
	m_iHandsRead(0)
{

}

CParseLogFile::~CParseLogFile()
{

}

bool CParseLogFile::HasFoundAllPlayersInHand() const
{
	return m_bFoundAllPlayers;
}

void CParseLogFile::SetAllPlayersInHandFound(bool bVal)
{
	m_bFoundAllPlayers = bVal;
}

void CParseLogFile::RefreshPlayers()
{
	//ASSERT(m_listNicks.size() > 2);
	TRACE("Number players is %d\n", m_listNicks.size());
	m_listNicksLastHand = m_listNicks;


}

void CParseLogFile::SavePlayersList()
{
	//ASSERT(m_listNicksLastHand.size() > 2);
	if (m_listNicksLastHand.size() > MIN_NUMBER_OF_PLAYERS)
	{
		CPlayerList::Set(m_hwndDealerText, GetSite(), m_listNicksLastHand);
		RSCurrentPlayers rsCP;
		rsCP.RefreshPlayerList(m_hwndDealerText, GetSite(), m_listNicksLastHand, GetTableName());
	}
	else
	{
		if (m_listNicksLastHand.size() > 0)
		{
			throw(new CParsingException(IDS_NOT_ENOUGH_PLAYERS));
		}
	}
}

void CParseLogFile::NewHand()
{
	m_bNewHand = true;
	m_iHandsRead++;
}

CParseLogFile* CParseLogFile::New(int iSite)
{
	switch(iSite)		 
	{
	case PPokerSite::POKER_SITE_PARTY:
		return new CParsePartyLogFile();
	case PPokerSite::POKER_SITE_PARADISE:
		return new CParserParadiseLogFile();
	case PPokerSite::POKER_SITE_ULTIMATE_BET:
		return new CParseUltimateBetLogFile();
	case PPokerSite::POKER_SITE_ROYAL_VEGAS: 
		return new CParseRoyalVegasLogFile();
	case PPokerSite::POKER_SITE_TRUE:
		return new CParseTruePokeLogFile();
	case PPokerSite::POKER_SITE_WSEX:  
		return new CParseWSEXLogFile();
	case PPokerSite::POKER_SITE_LABROKES:
		return new CParseLabrokesLogFile();
	case PPokerSite::POKER_SITE_HIGH_STAKES:
		return new CParseHighStakesLogFile();
	case PPokerSite::POKER_SITE_POKER_CLUB:
		return new CParsePokerClubLogFile();
	case PPokerSite::POKER_SITE_POKER_ROOM:
		return new CParserPokerRoomLogFile();
	case PPokerSite::POKER_SITE_CRYPTOLOGIC:
		return new CParserCryptologicLogFile();
	default:
		ASSERT(FALSE); //Not implimented
		return NULL;
	}
}

void CParseLogFile::ParseLogFile(HWND hwnd, long& lFilePosition, const  CString& strTableName)
{
	m_strTableName =  strTableName;
	m_hwndDealerText = hwnd;
	m_pCurrentState = GetStartState();
	TRACE1("Starting parsing log for table %s\n", strTableName);
	CSharedMemory cSM;
	int iChReadInThisHand = 0;
	CString strInputLine;
	try
	{
		cSM.OpenSharedMemory(PPokerSite::GetDealerTextName(hwnd, GetSite()), PAGE_READONLY);
		Setup();
		cSM.Seek(lFilePosition);
		TRACE("About to start at postion %d\n", lFilePosition);
		BOOL bFirst = true;
		while (!cSM.Eof())
		{
			strInputLine = cSM.ReadLine();
			if (bFirst)
			{
				bFirst = false;
				TRACE("First Line to parse is --- %s\n", strInputLine);
			}
			iChReadInThisHand += strInputLine.GetLength() + GetNumberOfHiddenCharactersPerLogLine();
			ParseLine(strInputLine);
			if (m_bNewHand)
			{
				TRACE("New Hand added, last line was -- %s\n", strInputLine);
				lFilePosition += iChReadInThisHand - strInputLine.GetLength() - GetNumberOfHiddenCharactersPerLogLine(); 
				iChReadInThisHand = 0;
				m_bNewHand = false;
			}

		}
		CloseDown();
		SavePlayersList();
	}
	catch (CParsingException* pException)
	{
		cSM.CloseSharedMemory(); 
		if (pException->IsCloseGame() || pException->IsExitProgram() )
		{
			throw(pException);
		}
		else
		{
			lFilePosition += iChReadInThisHand - strInputLine.GetLength() - GetNumberOfHiddenCharactersPerLogLine(); 
		}
	}
	TRACE("File Position %d and Shared Memory position %d\n", lFilePosition, cSM.GetPositon());
	cSM.CloseSharedMemory();  
}


bool CParseLogFile::IsLog()
{
	return true;
}

int CParseLogFile::GetNumberOfHiddenCharactersPerLogLine()	const
{
	return 2;
}






