// PSParadiseLogBigBlind.cpp: implementation of the CPSParadiseLogBigBlind class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "HistoryParser_DLL.h"
#include "PSParadiseLogBigBlind.h"
#include "PSParadiseLogPlayerFirxtAction.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPSParadiseLogBigBlind::CPSParadiseLogBigBlind(CParseFile* pPF)
: CPSParadiseLog(pPF)
{


}

CPSParadiseLogBigBlind::~CPSParadiseLogBigBlind()
{

}

CParseState* CPSParadiseLogBigBlind::ParseI(const CString &strInLine, const CString &strFullLine)
{
	CString strUnreadLine = strInLine;

	if (IsNextWord("** DEALING POCKETS **", strUnreadLine))
	{
		return this;
	}

	ReverseReadText(WORD_blind, strUnreadLine);
	ReverseReadText(WORD_big, strUnreadLine);
	ReverseReadText("the", strUnreadLine);
	ReverseReadText(WORD_posts, strUnreadLine);

	strUnreadLine.TrimLeft(' ');
	strUnreadLine.TrimRight(' ');

	sm_cInputHand.SetBigBlind(strUnreadLine, 0);
	sm_listNicks.push_back(strUnreadLine);
	return new CPSParadiseLogPlayerFirstAction(m_cParseFile);
}

