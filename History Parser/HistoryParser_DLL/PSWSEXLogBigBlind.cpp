// PSWSEXLogBigBlind.cpp: implementation of the CPSWSEXLogBigBlind class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "HistoryParser_DLL.h"
#include "PSWSEXLogBigBlind.h"
#include "PSWSEXLogPlayerFirxtAction.h"
#ifdef _DEBUG

#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPSWSEXLogBigBlind::CPSWSEXLogBigBlind(CParseFile* pPF)
: CPSWSEXLog(pPF)
{


}

CPSWSEXLogBigBlind::~CPSWSEXLogBigBlind()
{

}

CParseState* CPSWSEXLogBigBlind::ParseI(const CString &strInLine, const CString &strFullLine)
{
	CString strUnreadLine = strInLine;

	if (IsNextWord("DEALING POCKETS", strUnreadLine))
	{
		return new CPSWSEXLogPlayerFirstAction(m_cParseFile);
	}

	int iBigBlind = ReverseGetNextNumber(strUnreadLine);
	ReverseReadText('$', strUnreadLine);
	if (IsLastWord("dead", strUnreadLine))
	{
		ReverseReadText("+ dead", strUnreadLine);
	}
	ReverseReadText("posts the big blind", strUnreadLine);

	strUnreadLine.TrimLeft(' ');
	strUnreadLine.TrimRight(' ');

	sm_cInputHand.SetBigBlind(strUnreadLine, iBigBlind);
	if (sm_listNicks.size() <= 1)
	{
		sm_listNicks.push_back(strUnreadLine);
	}
	return new CPSWSEXLogBigBlind(m_cParseFile);
}

