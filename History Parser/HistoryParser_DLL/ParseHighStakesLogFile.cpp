// ParseHighStakesLogFile.cpp: implementation of the CParseHighStakesLogFile class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ParseHighStakesLogFile.h"
#include "HighStakesLogNone.h"
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

CParseHighStakesLogFile::CParseHighStakesLogFile()
{
}

CParseHighStakesLogFile::~CParseHighStakesLogFile()
{

}

CParseState* CParseHighStakesLogFile::GetStartState()
{
	return new CHighStakesLogNone(this);
}


int CParseHighStakesLogFile::GetSite()
{
	return PPokerSite::POKER_SITE_HIGH_STAKES;
}

int CParseHighStakesLogFile::GetNumberOfHiddenCharactersPerLogLine()	const
{
	return 1;
}





