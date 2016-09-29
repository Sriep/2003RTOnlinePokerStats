// PSParadiseLogResult.cpp: implementation of the CPSParadiseLogResult class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "HistoryParser_DLL.h"
#include "PSParadiseLogResult.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPSParadiseLogResult::CPSParadiseLogResult(CParseFile* pPF)
: CParseState(pPF)
{

}

CPSParadiseLogResult::~CPSParadiseLogResult()
{

}

CParseState* CPSParadiseLogResult::Parse(const CString &strInLine)
{
	CString strUnreadLine = strInLine;
	if (!ReadIfNextWord("»#", strUnreadLine))
	{
		return this;
	}

	int iPosColon = strUnreadLine.Find(':');
	if (iPosColon <1)
	{
		return this;
	}

	strUnreadLine = strUnreadLine.Right(strUnreadLine.GetLength() - iPosColon - 1);
	int iAmount = 0;
	CString strNick;
	if (ReadIfNextWord("Take it down,", strUnreadLine))
	{
		int iPosAmount = strUnreadLine.Find("($");
		if (iPosAmount <1)
		{
			return this;
		}

		strNick = strUnreadLine.Left(iPosAmount);
		strNick.TrimLeft(' ');
		strNick.TrimRight(' ');

		strUnreadLine = strUnreadLine.Right(strUnreadLine.GetLength() - iPosAmount);
		ReadText("($", strUnreadLine);
		iAmount = GetNextNumber(strUnreadLine);
	}
	else
	{
		int iPosWins = strUnreadLine.Find("wins");
		if (iPosWins <1)
		{
			return this;
		}

		strNick = strUnreadLine.Left(iPosWins);
		strNick.TrimLeft(' ');
		strNick.TrimRight(' ');

		strUnreadLine = strUnreadLine.Right(strUnreadLine.GetLength() - iPosWins);
		ReadText("wins", strUnreadLine);
		ReadText("($", strUnreadLine);
		iAmount = GetNextNumber(strUnreadLine);
	}
	sm_cInputHand.SetPlayerProfitLoss(strNick, iAmount);

	return this;
}

