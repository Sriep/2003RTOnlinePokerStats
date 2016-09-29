// PSPartyHeader3.cpp: implementation of the CPSPartyHeader3 class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PSPartyHeader3.h"

#include "PSPartyPlayerList.h"
#include "ParsingException.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPSPartyHeader3::CPSPartyHeader3(CParseFile* pPF)
: CParseState(pPF)
{

}

CPSPartyHeader3::~CPSPartyHeader3()
{

}

CParseState* CPSPartyHeader3::Parse(const CString &strInLine)
{
	try
	{
		CString strUnreadLine = strInLine;

		ReadText(WORD_Total, strUnreadLine);
		ReadText(WORD_number, strUnreadLine);
		ReadText(WORD_of, strUnreadLine);
		ReadText(WORD_players, strUnreadLine);
		ReadText(CHAR_COLON, strUnreadLine);

		sm_cInputHand.SetNumberOfPlayers(GetNextNumber(strUnreadLine));
		CParseState* pNewState = new CPSPartyPlayerList(m_cParseFile);
		delete this;
		return pNewState;
	}
	catch (CParsingException* pException)
	{	
		if(pException->IsSkipLine())
		{
			delete pException;
			throw(new CParsingException(IDS_HEADER_ERROR));
		}
		else
		{
			throw(pException);
		}
	}
}
