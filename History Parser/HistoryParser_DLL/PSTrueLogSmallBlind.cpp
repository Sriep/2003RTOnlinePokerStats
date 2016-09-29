// PSTrueLogSmallBlind.cpp: implementation of the CPSTrueLogSmallBlind class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "HistoryParser_DLL.h"
#include "PSTrueLogSmallBlind.h"
#include "PSTrueLogBigBlind.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPSTrueLogSmallBlind::CPSTrueLogSmallBlind(CParseFile* pPF)
: CPSTrueLog(pPF)
{

}

CPSTrueLogSmallBlind::~CPSTrueLogSmallBlind()
{

}

CParseState* CPSTrueLogSmallBlind::ParseI(const CString &strInLine, const CString &strFullLine)
{
	if (NotSmallBlindYet(strInLine))
	{
		return this;
	}
	
	CString strUnreadLine = strInLine;

	int iSmallBlind = ReverseGetNextNumber(strUnreadLine);
	ReverseReadText("posts the small blind", strUnreadLine);

	strUnreadLine.TrimLeft(' ');
	strUnreadLine.TrimRight(' ');

	sm_cInputHand.SetSmallBlind(strUnreadLine, iSmallBlind);
	sm_listNicks.push_back(strUnreadLine);
	
	return new CPSTrueLogBigBlind(m_cParseFile);
}
