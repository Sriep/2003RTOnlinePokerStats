// PSRoyalVegasLogDealing.cpp: implementation of the CPSRoyalVegasLogDealing class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "HistoryParser_DLL.h"
#include "PSRoyalVegasLogDealing.h"
#include "PSNone.h"
#include "PSRoyalVegasLogPlayerFirxtAction.h"
#include "PSRoyalVegasLogPlayerAction.h"
#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPSRoyalVegasLogDealing::CPSRoyalVegasLogDealing(CParseFile* pPF)
: CPSRoyalVegasLog(pPF)
{

}

CPSRoyalVegasLogDealing::~CPSRoyalVegasLogDealing()
{

}

CParseState* CPSRoyalVegasLogDealing::ParseI(const CString& strInLine, const CString &strFullLine)
{

	CString strUnreadLine = strInLine;

	ReadText("Dealing the" , strUnreadLine);

	if (ReadIfNextWord("Flop(", strUnreadLine))
	{
		ParseFlopDeal(strUnreadLine);
	}
	else if (ReadIfNextWord("turn(", strUnreadLine))
	{
		ParseTurnDeal(strUnreadLine);
	}
	else if (ReadIfNextWord("river(", strUnreadLine))
	{
		ParseRiverDeal(strUnreadLine);
	}
	else
	{
		throw(new CParsingException(IDS_UNEXPECTED_TEXT, this, new CPSNone(m_cParseFile)));
	}
	return  new CPSRoyalVegasLogPlayerAction(m_cParseFile);
}


