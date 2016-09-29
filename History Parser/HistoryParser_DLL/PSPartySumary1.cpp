// PSPartySumary1.cpp: implementation of the CPSPartySumary1 class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PSPartySumary1.h"
#include "PSPartySumary2.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPSPartySumary1::CPSPartySumary1(CParseFile* pPF)
: CParseState(pPF)
{

}

CPSPartySumary1::~CPSPartySumary1()
{

} 

CParseState* CPSPartySumary1::Parse(const CString &strInLine)
{
	CString strUnreadLine = strInLine;
	ReadText("Main", strUnreadLine);
	ReadText(WORD_Pot, strUnreadLine);
	ReadText(CHAR_COLON, strUnreadLine);
	ReadText(CHAR_DOLLAR, strUnreadLine);
	int iPot = GetNextNumber(strUnreadLine);
	ReadText(CHAR_BAR, strUnreadLine);

	while (IsNextWord("Side", strUnreadLine))
	{
		ReadText("Side", strUnreadLine);
		ReadText(WORD_Pot, strUnreadLine);
		GetNextNumber(strUnreadLine);
		ReadText(CHAR_COLON, strUnreadLine);
		ReadText(CHAR_DOLLAR, strUnreadLine);
		iPot += GetNextNumber(strUnreadLine);
		ReadText(CHAR_BAR, strUnreadLine);
	}

	sm_cInputHand.SetPot(iPot);

	if (IsNextWord(CHAR_BAR, strUnreadLine))
	{
		ReadText(CHAR_BAR, strUnreadLine);
	}

	ReadText(WORD_Rake, strUnreadLine);
	ReadText(CHAR_COLON, strUnreadLine);
	ReadText(CHAR_DOLLAR, strUnreadLine);
	int iRake = GetNextNumber(strUnreadLine);
	sm_cInputHand.SetRake(iRake);
	CParseState* pNewState = new CPSPartySumary2(m_cParseFile);
	delete this;
	return pNewState;

}

