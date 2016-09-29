// PSTrueLogBigBlind.cpp: implementation of the CPSTrueLogBigBlind class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "HistoryParser_DLL.h"
#include "PSTrueLogBigBlind.h"
#include "PSTrueLogPlayerCards.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPSTrueLogBigBlind::CPSTrueLogBigBlind(CParseFile* pPF)
: CPSTrueLog(pPF)
{


}

CPSTrueLogBigBlind::~CPSTrueLogBigBlind()
{

}

CParseState* CPSTrueLogBigBlind::ParseI(const CString &strInLine, const CString &strFullLine)
{
	CString strUnreadLine = strInLine;

	int iBigBlind = ReverseGetNextNumber(strUnreadLine);
	ReverseReadText("posts the big blind", strUnreadLine);

	strUnreadLine.TrimLeft(' ');
	strUnreadLine.TrimRight(' ');

	sm_cInputHand.SetBigBlind(strUnreadLine, iBigBlind);
	sm_listNicks.push_back(strUnreadLine);
	return new CPSTrueLogPlayerCards(m_cParseFile);
}

