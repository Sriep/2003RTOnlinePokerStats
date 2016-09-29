// PSParadiseDealToPlayer.cpp: implementation of the CPSParadiseDealToPlayer class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PSParadiseDealToPlayer.h"

#include "PSParadisePlayerAction.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPSParadiseDealToPlayer::CPSParadiseDealToPlayer(CParseFile* pPF)
: CParseState(pPF)
{

}

CPSParadiseDealToPlayer::~CPSParadiseDealToPlayer()
{

}

CParseState* CPSParadiseDealToPlayer::Parse(const CString &strInLine)
{
	CString strUnreadLine = strInLine;

	if(IsNextWord("Dealt to ", strInLine) && IsLastWord(']', strInLine))
	{
		return this;
	}
	CParseState* pNewState = new CPSParadisePlayerAction(m_cParseFile);
	delete this;
	return pNewState;
}
