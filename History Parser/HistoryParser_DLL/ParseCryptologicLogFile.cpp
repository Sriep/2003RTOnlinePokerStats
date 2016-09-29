// ParseHighStakesLogFile.cpp: implementation of the CParseHighStakesLogFile class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ParseCryptologicLogFile.h"
#include "CryptologicLogNone.h"
#include "SharedMemory.h"
#include "PPokerSite.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CParserCryptologicLogFile::CParserCryptologicLogFile()
{
}

CParserCryptologicLogFile::~CParserCryptologicLogFile()
{

}

CParseState* CParserCryptologicLogFile::GetStartState()
{
	return new CCryptologicLogNone(this);
}


int CParserCryptologicLogFile::GetSite()
{
	return PPokerSite::POKER_SITE_CRYPTOLOGIC;
}

int CParserCryptologicLogFile::GetNumberOfHiddenCharactersPerLogLine()	const
{
	return 1;
}

CString CParserCryptologicLogFile::GetLastPlayer() 
{ 
	return m_listNicks.back();
}

CString CParserCryptologicLogFile::GetLastButOnePlayer() 
{ 
	StringListIterator iter = m_listNicks.end();
	iter--;
	ASSERT(*iter == GetLastPlayer());
	iter--;
	return *iter;
}

void CParserCryptologicLogFile::NewRound()
{
	iBetLevel = 0;
	for (StringIntMapIterator iIter = mapNickBetLevel.begin() ; iIter != mapNickBetLevel.end() ; iIter++ )
	{
		(*iIter).second = -1;
	}
}

void CParserCryptologicLogFile::ProcessAction(PPlayerAction cAction,  CString strNick)
{
	StringIntMapIterator iter = mapNickBetLevel.find(strNick);
	if (cAction == PPlayerAction::ACTION_FOLD)
	{
		if (iter != mapNickBetLevel.end())
			mapNickBetLevel.erase(iter);
		return;
	}
	
	if (cAction == PPlayerAction::ACTION_BET || cAction == PPlayerAction::ACTION_RAISE)
	{
		iBetLevel++;
	}

	if (iter == mapNickBetLevel.end())
	{
	
		if (cAction == PPlayerAction::ACTION_POST)
		{
			mapNickBetLevel.insert(StringIntMap::value_type(strNick, -1));
		}
		else if (cAction == PPlayerAction::ACTION_CHECK)
		{
			mapNickBetLevel.insert(StringIntMap::value_type(strNick, 0));
		}
		else
		{
			mapNickBetLevel.insert(StringIntMap::value_type(strNick, iBetLevel));
		}
	}
	else
	{
		(*iter).second = iBetLevel;
	}

	TRACE1("Current Bet Level %d\n", iBetLevel);
	DUMPBetLEvels();
}

bool CParserCryptologicLogFile::IsNextRound(const CString& strNick)
{
	DUMPBetLEvels();
	ConstStringIntMapIterator iter = mapNickBetLevel.find(strNick);
	ASSERT(iter != mapNickBetLevel.end());
	int iNickBetLevel = (*iter).second;
	CString test = 	(*iter).first;
	return iNickBetLevel == iBetLevel; 
} 

void CParserCryptologicLogFile::DUMPBetLEvels()
{
	for (StringIntMapIterator iIter = mapNickBetLevel.begin() ; iIter != mapNickBetLevel.end() ; iIter++ )
	{
		TRACE2("Bet level %s is %i\n",(*iIter).first,(*iIter).second);  
	}
}

void CParserCryptologicLogFile::NewHand()
{
	CParseLogFile::NewHand();
	mapNickBetLevel.clear();
	iBetLevel = 1;
}







