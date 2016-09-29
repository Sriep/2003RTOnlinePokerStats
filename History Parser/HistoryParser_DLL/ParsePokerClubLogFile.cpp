// ParsePokerClubLogFile.cpp: implementation of the CParsePokerClubLogFile class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ParsePokerClubLogFile.h"
#include "WSEXLogNone.h"
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

CParsePokerClubLogFile::CParsePokerClubLogFile()
{
}

CParsePokerClubLogFile::~CParsePokerClubLogFile()
{

}

CParseState* CParsePokerClubLogFile::GetStartState()
{
	return new CWSEXLogNone(this);
}


int CParsePokerClubLogFile::GetSite()
{
	return PPokerSite::POKER_SITE_POKER_CLUB;
}







