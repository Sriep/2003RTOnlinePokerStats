// ParseWSEXLogFile.cpp: implementation of the CParseWSEXLogFile class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ParseWSEXLogFile.h"
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

CParseWSEXLogFile::CParseWSEXLogFile()
{
}

CParseWSEXLogFile::~CParseWSEXLogFile()
{

}

CParseState* CParseWSEXLogFile::GetStartState()
{
	return new CWSEXLogNone(this);
}


int CParseWSEXLogFile::GetSite()
{
	return PPokerSite::POKER_SITE_WSEX;
}







