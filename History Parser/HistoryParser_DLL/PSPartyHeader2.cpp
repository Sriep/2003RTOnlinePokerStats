// PSPartyHeader2.cpp: implementation of the CPSPartyHeader2 class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PSPartyHeader2.h"

#include "PSNone.h"
#include "ParsingException.h"
#include "PSPartyHeader3.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPSPartyHeader2::CPSPartyHeader2(CParseFile* pPF)
: CParseState(pPF)
{

}

CPSPartyHeader2::~CPSPartyHeader2()
{

}

CParseState* CPSPartyHeader2::Parse(const CString &strInLine)
{
	try
	{
		CString strUnreadLine = strInLine;

		ReadText(WORD_Table, strUnreadLine);

		sm_cInputHand.SetTableName(GetTableName(strUnreadLine));

		ReadText(CHAR_OPEN_BRACKET, strUnreadLine);
		ReadText(WORD_Real, strUnreadLine);
		ReadText(WORD_Money, strUnreadLine);
		ReadText(CHAR_CLOSE_BRACKET, strUnreadLine);
		ReadText(CHAR_DASH, strUnreadLine);
		ReadText(CHAR_DASH, strUnreadLine);
		ReadText(WORD_Seat, strUnreadLine);

		sm_cInputHand.SetButtonPostion(GetNextNumber(strUnreadLine));
		CParseState* pNewState = new CPSPartyHeader3(m_cParseFile);
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

CString CPSPartyHeader2::GetTableName(CString &strUnreadLine) 
{
	strUnreadLine.TrimLeft(' '); 
	int iIndexOpenBracket = strUnreadLine.Find('(');
	if (iIndexOpenBracket <= 0)
	{
		throw(new CParsingException(IDS_TABLE_NAME_NOT_FOUND, this, new CPSNone(m_cParseFile)));
	}

	CString strTableName = strUnreadLine.Left(iIndexOpenBracket);
	strUnreadLine = strUnreadLine.Right(strUnreadLine.GetLength() - iIndexOpenBracket);
	return strTableName;
}

