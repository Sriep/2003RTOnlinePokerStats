// PSParadiseSumary2.cpp: implementation of the CPSParadiseSumary2 class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PSParadiseSumary2.h"
#include "PSParadiseSumaryGereral.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPSParadiseSumary2::CPSParadiseSumary2(CParseFile* pPF)
: CParseState(pPF)
{

}

CPSParadiseSumary2::~CPSParadiseSumary2()
{

}

CParseState* CPSParadiseSumary2::Parse(const CString &strInLine)
{
	CString strUnreadLine = strInLine;
	if (!IsNextWord(WORD_Board, strInLine))
	{
		return ChangeState(new CPSParadiseSumaryGereral(m_cParseFile), strInLine);
	}
	else
	{
		CParseState* pNewState = new CPSParadiseSumaryGereral(m_cParseFile);
		delete this;
		return pNewState;
	}
}
