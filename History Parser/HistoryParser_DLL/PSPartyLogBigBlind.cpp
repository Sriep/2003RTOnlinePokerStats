// PSPartyLogBigBlind.cpp: implementation of the CPSPartyLogBigBlind class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "HistoryParser_DLL.h"
#include "PSPartyLogBigBlind.h"
#include "PSPartyLogDealing.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPSPartyLogBigBlind::CPSPartyLogBigBlind(CParseFile* pPF)
: CPSPartyLog(pPF)
{


}

CPSPartyLogBigBlind::~CPSPartyLogBigBlind()
{

}

CParseState* CPSPartyLogBigBlind::ParseI(const CString &strInLine, const CString &strFullLine)
{
	CString strUnreadLine = strInLine;

	if (IsNextWord("** Dealing down cards **", strUnreadLine))
	{
		return ChangeState(new CPSPartyLogDealing(m_cParseFile), strFullLine);
	}

	ReverseReadText('.', strUnreadLine);
	ReverseReadText(']', strUnreadLine);
	int iBigBlind = ReverseGetNextNumber(strUnreadLine);
	ReverseReadText('$', strUnreadLine);
	ReverseReadText('[', strUnreadLine);
	if (IsLastWord("dead", strUnreadLine))
	{
		ReverseReadText("dead", strUnreadLine);
		ReverseReadText("+", strUnreadLine);
	}
	ReverseReadText(WORD_blind, strUnreadLine);
	ReverseReadText(WORD_big, strUnreadLine);
	ReverseReadText(WORD_posts, strUnreadLine);

	strUnreadLine.TrimLeft(' ');
	strUnreadLine.TrimRight(' ');

	sm_cInputHand.SetBigBlind(strUnreadLine, iBigBlind);
	if (sm_listNicks.size() <= 1)
	{
		sm_listNicks.push_back(strUnreadLine);
	}
	return new CPSPartyLogBigBlind(m_cParseFile);
}

