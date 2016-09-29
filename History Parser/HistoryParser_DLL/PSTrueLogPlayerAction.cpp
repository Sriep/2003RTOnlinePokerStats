// PSTrueLogPlayerAction.cpp: implementation of the CPSTrueLogPlayerAction class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "HistoryParser_DLL.h"
#include "PSTrueLogPlayerAction.h"
#include "PSTrueLogDealing.h"
#include "TrueLogNone.h"
#include "PSTrueLogSummary.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPSTrueLogPlayerAction::CPSTrueLogPlayerAction(CParseFile* cPF)
: CPSTrueLog(cPF)
{

}

CPSTrueLogPlayerAction::~CPSTrueLogPlayerAction()
{

}

CParseState* CPSTrueLogPlayerAction::ParseI(const CString &strInLine, const CString &strFullLine)
{
	CString strUnreadLine = strInLine;

	if (strInLine.Left(strlen("Dealing")) == "Dealing")
	{
		return ChangeState(new CPSTrueLogDealing(m_cParseFile), strFullLine);
	}

	CString strNick = ReadLongNick(strUnreadLine);
	if (strNick.IsEmpty())
	{
		ASSERT(FALSE);
		throw(new CParsingException(IDS_NICK_NOT_FOUND));
	}

	CString strAction = GetNextWord(strUnreadLine);
	if (strAction == "shows" || strAction == "mucks")
	{
		return new CPSTrueLogSummary(m_cParseFile);
		//return ChangeState(new CPSTrueLogSummary(m_cParseFile), strFullLine);
	}

	PPlayerAction cAction;

	if (strAction == "has")	  //timed out
	{
		cAction = PPlayerAction(PPlayerAction::ACTION_FOLD);	
	}
	else if (strAction == "goes")		  //all in
	{
		ReadText("all in,", strUnreadLine);
		strAction = GetNextWord(strUnreadLine);
		cAction =  PPlayerAction(strAction);
		if (cAction == PPlayerAction(PPlayerAction::ACTION_NONE))
		{
			ASSERT(FALSE);
			throw(new CParsingException("Ture poker, player action not found"));
		}
	}
	else
	{
		cAction =  PPlayerAction(strAction);
		if (cAction == PPlayerAction(PPlayerAction::ACTION_NONE))
		{
			ASSERT(FALSE);
			throw(new CParsingException("Ture poker, player action not found"));
		}
	}
	
	int iAmount = 0;
	strUnreadLine.TrimRight(' ');
	if (!strUnreadLine.IsEmpty() && IsNumber(strUnreadLine[strUnreadLine.GetLength() - 1])) 
	{
		iAmount = ReverseGetNextNumber(strUnreadLine);
	}

	strUnreadLine.TrimLeft(' ');
	strUnreadLine.TrimRight(' ');
	sm_cInputHand.AddPlayerAction(strNick, cAction, iAmount);
	return  new CPSTrueLogPlayerAction(m_cParseFile);
}




