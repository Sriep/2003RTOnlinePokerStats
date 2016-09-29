// ParseRoyalVegasLogFile.cpp: implementation of the CParseRoyalVegasLogFile class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ParseLabrokesLogFile.h"
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

CParseLabrokesLogFile::CParseLabrokesLogFile()
{
}

CParseLabrokesLogFile::~CParseLabrokesLogFile()
{

}

CParseState* CParseLabrokesLogFile::GetStartState()
{
	return new CRoyalVegasLogNone(this);
}


int CParseLabrokesLogFile::GetSite()
{
	return PPokerSite::POKER_SITE_LABROKES;
}

int CParseLabrokesLogFile::GetNumberOfHiddenCharactersPerLogLine()	const
{
	return 1;
}








