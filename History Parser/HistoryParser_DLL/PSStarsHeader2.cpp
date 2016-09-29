// PSStarsHeader2.cpp: implementation of the CPSStarsHeader2 class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PSStarsHeader2.h"

#include "PSNone.h"
#include "ParsingException.h"
#include "PSStarsPlayerList.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPSStarsHeader2::CPSStarsHeader2(CParseFile* pPF)
: CParseState(pPF)
{

}

CPSStarsHeader2::~CPSStarsHeader2()
{

}

CParseState* CPSStarsHeader2::Parse(const CString &strInLine)
{
	try
	{
		CString strUnreadLine = strInLine;

		ReadText(WORD_Table, strUnreadLine);
		ReadText("'", strUnreadLine);
		sm_cInputHand.SetTableName(GetTableName(strUnreadLine));
		ReadText("'", strUnreadLine);
		ReadText(WORD_Seat, strUnreadLine);
		ReadText("#", strUnreadLine);

		sm_cInputHand.SetButtonPostion(GetNextNumber(strUnreadLine));
		CParseState* pNewState = new CPSStarsPlayerList(m_cParseFile);
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

CString CPSStarsHeader2::GetTableName(CString &strUnreadLine) 
{
	strUnreadLine.TrimLeft(' '); 
	int iIndexQuote = strUnreadLine.Find('\'');
	if (iIndexQuote <= 0)
	{
		throw(new CParsingException(IDS_TABLE_NAME_NOT_FOUND, this, new CPSNone(m_cParseFile)));
	}

	CString strTableName = strUnreadLine.Left(iIndexQuote);
	strUnreadLine = strUnreadLine.Right(strUnreadLine.GetLength() - iIndexQuote);
	return strTableName;
}

