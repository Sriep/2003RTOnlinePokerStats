// PSUltimateBetLogDealing.cpp: implementation of the CPSUltimateBetLogDealing class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "HistoryParser_DLL.h"
#include "PSUltimateBetLogDealing.h"
#include "PSNone.h"
#include "PSUltimateBetLogPlayerFirxtAction.h"
#include "PSUltimateBetLogPlayerAction.h"
#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPSUltimateBetLogDealing::CPSUltimateBetLogDealing(CParseFile* pPF)
: CPSUltimateBetLog(pPF)
{

}

CPSUltimateBetLogDealing::~CPSUltimateBetLogDealing()
{

}

CParseState* CPSUltimateBetLogDealing::ParseI(const CString& strInLine, const CString &strFullLine)
{

	CString strUnreadLine = strInLine;

	ReadText("Dealing ", strUnreadLine);
	CString strRound = GetNextWord(strUnreadLine);

	if (strRound == "flop:")
	{
		sm_cInputHand.SetFlopCard(ReadCard(strUnreadLine));
	}
	else if (strRound == "turn:")
	{
		sm_cInputHand.SetTurn(ReadCard(strUnreadLine));
	}
	else if (strRound == "river:")
	{
		sm_cInputHand.SetRiver(ReadCard(strUnreadLine));
	}
	else
	{
		throw(new CParsingException(IDS_UNEXPECTED_TEXT, this, new CPSNone(m_cParseFile)));
	}
	return  new CPSUltimateBetLogPlayerAction(m_cParseFile);
}

