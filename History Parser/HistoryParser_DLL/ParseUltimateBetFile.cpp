// ParsePartyLogFile.cpp: implementation of the CParseUltimateBetLogFile class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ParseUltimateBetLogFile.h"
#include "UltimateBetLogNone.h"
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

CParseUltimateBetLogFile::CParseUltimateBetLogFile()
{
}

CParseUltimateBetLogFile::~CParseUltimateBetLogFile()
{

}

CParseState* CParseUltimateBetLogFile::GetStartState()
{
	return new CUltimateBetLogNone(this);
}

int CParseUltimateBetLogFile::GetSite()
{
	return PPokerSite::POKER_SITE_ULTIMATE_BET;
}


int CParseUltimateBetLogFile::GetNumberOfHiddenCharactersPerLogLine()	const
{
	return 1;
}








