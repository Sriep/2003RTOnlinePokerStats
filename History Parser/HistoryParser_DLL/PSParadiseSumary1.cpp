// PSParadiseSumary1.cpp: implementation of the CPSParadiseSumary1 class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PSParadiseSumary1.h"
#include "PSParadiseSumary2.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPSParadiseSumary1::CPSParadiseSumary1(CParseFile* pPF)
: CParseState(pPF)
{

}

CPSParadiseSumary1::~CPSParadiseSumary1()
{

} 

CParseState* CPSParadiseSumary1::Parse(const CString &strInLine)
{
	CString strUnreadLine = strInLine;
	ReadText(WORD_Pot, strUnreadLine);
	ReadText(CHAR_COLON, strUnreadLine);
	ReadText(CHAR_DOLLAR, strUnreadLine);
	int iPot = GetNextNumber(strUnreadLine);
	ReadText(CHAR_BAR, strUnreadLine);

	while (IsNextWord("Side", strUnreadLine))
	{
		ReadText("Side", strUnreadLine);
		ReadText("pot", strUnreadLine);
		GetNextNumber(strUnreadLine);
		ReadText(CHAR_COLON, strUnreadLine);
		ReadText(CHAR_DOLLAR, strUnreadLine);
		iPot += GetNextNumber(strUnreadLine);
		ReadText(CHAR_BAR, strUnreadLine);
	}

	sm_cInputHand.SetPot(iPot);

	ReadText(WORD_Rake, strUnreadLine);
	ReadText(CHAR_COLON, strUnreadLine);
	ReadText(CHAR_DOLLAR, strUnreadLine);
	int iRake = GetNextNumber(strUnreadLine);
	sm_cInputHand.SetRake(iRake);
	CParseState* pNewState = new CPSParadiseSumary2(m_cParseFile);
	delete this;
	return pNewState;
}

