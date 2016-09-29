// PSStarsSumary2.cpp: implementation of the CPSStarsSumary2 class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PSStarsSumary2.h"

#include "PSStarsSumaryGereral.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPSStarsSumary2::CPSStarsSumary2(CParseFile* pPF)
: CParseState(pPF)
{

}

CPSStarsSumary2::~CPSStarsSumary2()
{

}

CParseState* CPSStarsSumary2::Parse(const CString &strInLine)
{
	CString strUnreadLine = strInLine;
	if (!IsNextWord(WORD_Board, strInLine))
	{
		return ChangeState(new CPSStarsSumaryGereral(m_cParseFile), strInLine);
	}
	else
	{
		CParseState* pNewState = new CPSStarsSumaryGereral(m_cParseFile);
		delete this;
		return pNewState;
	}
}
