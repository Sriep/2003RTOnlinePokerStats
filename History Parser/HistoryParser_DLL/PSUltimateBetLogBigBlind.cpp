// PSUltimateBetLogBigBlind.cpp: implementation of the CPSUltimateBetLogBigBlind class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "HistoryParser_DLL.h"
#include "PSUltimateBetLogBigBlind.h"
#include "PSUltimateBetLogDealing.h"
#include "PSUltimateBetLogPlayerFirxtAction.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPSUltimateBetLogBigBlind::CPSUltimateBetLogBigBlind(CParseFile* pPF)
: CPSUltimateBetLog(pPF)
{


}

CPSUltimateBetLogBigBlind::~CPSUltimateBetLogBigBlind()
{

}

CParseState* CPSUltimateBetLogBigBlind::ParseI(const CString &strInLine, const CString &strFullLine)
{
	CString strUnreadLine = strInLine;

	if (IsLastWord("rejected posting big blind.", strUnreadLine))
	{
		return this;
	}

	ReverseReadText("has posted the big blind.", strUnreadLine);
	strUnreadLine.TrimLeft(' ');
	strUnreadLine.TrimRight(' ');

	sm_cInputHand.SetBigBlind(strUnreadLine, 0);
	if (sm_listNicks.size() <= 1)
	{
		sm_listNicks.push_back(strUnreadLine);
	}
	return new CPSUltimateBetLogPlayerFirstAction(m_cParseFile);
}

