// ParseRoyalVegasLogFile.cpp: implementation of the CParseRoyalVegasLogFile class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ParseRoyalVegasLogFile.h"
#include "RoyalVegasLogNone.h"
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

CParseRoyalVegasLogFile::CParseRoyalVegasLogFile()
{
}

CParseRoyalVegasLogFile::~CParseRoyalVegasLogFile()
{

}

CParseState* CParseRoyalVegasLogFile::GetStartState()
{
	return new CRoyalVegasLogNone(this);
}


int CParseRoyalVegasLogFile::GetSite()
{
	return PPokerSite::POKER_SITE_ROYAL_VEGAS;
}

int CParseRoyalVegasLogFile::GetNumberOfHiddenCharactersPerLogLine()	const
{
	return 1;
}






