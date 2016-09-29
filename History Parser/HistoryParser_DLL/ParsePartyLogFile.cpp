// ParsePartyLogFile.cpp: implementation of the CParsePartyLogFile class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ParsePartyLogFile.h"
#include "PartyLogNone.h"
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

CParsePartyLogFile::CParsePartyLogFile()
{
}

CParsePartyLogFile::~CParsePartyLogFile()
{

}

CParseState* CParsePartyLogFile::GetStartState()
{
	return  new CPartyLogNone(this);
}

int CParsePartyLogFile::GetSite()
{
	return PPokerSite::POKER_SITE_PARTY;
}






