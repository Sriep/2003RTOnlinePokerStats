// PSStarsSumary1.cpp: implementation of the CPSStarsSumary1 class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PSStarsSumary1.h"
#include "PSStarsSumary2.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPSStarsSumary1::CPSStarsSumary1(CParseFile* pPF)
: CParseState(pPF)
{

}

CPSStarsSumary1::~CPSStarsSumary1()
{

} 

CParseState* CPSStarsSumary1::Parse(const CString &strInLine)
{
	CString strUnreadLine = strInLine;
	ReadText("Total", strUnreadLine);
	ReadText("pot", strUnreadLine);
	ReadText(CHAR_DOLLAR, strUnreadLine);
	int iPot = GetNextNumber(strUnreadLine);
	sm_cInputHand.SetPot(iPot);

	ReadText(CHAR_BAR, strUnreadLine);
	ReadText(WORD_Rake, strUnreadLine);
	ReadText(CHAR_DOLLAR, strUnreadLine);
	int iRake = GetNextNumber(strUnreadLine);
	sm_cInputHand.SetRake(iRake);
	CParseState* pNewState = new CPSStarsSumary2(m_cParseFile);
	delete this;
	return pNewState;
}

