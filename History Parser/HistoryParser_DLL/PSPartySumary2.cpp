// PSPartySumary2.cpp: implementation of the CPSPartySumary2 class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PSPartySumary2.h"

#include "PSPartySumaryGereral.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPSPartySumary2::CPSPartySumary2(CParseFile* pPF)
: CParseState(pPF)
{

}

CPSPartySumary2::~CPSPartySumary2()
{

}

CParseState* CPSPartySumary2::Parse(const CString &strInLine)
{
	CString strUnreadLine = strInLine;
	if (!IsNextWord(WORD_Board, strInLine))
	{
		return ChangeState(new CPSPartySumaryGereral(m_cParseFile), strInLine);
	}
	else
	{
		CParseState* pNewState = new CPSPartySumaryGereral(m_cParseFile);
		delete this;
		return pNewState;
	}
}
