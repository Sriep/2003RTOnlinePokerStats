// PSTrueLogDealing.h: interface for the CPSTrueLogDealing class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CPSTrueLogDealing__INCLUDED_)
#define AFX_CPSTrueLogDealing__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "PSTrueLog.h"

class CPSTrueLogDealing : public CPSTrueLog  
{
public:
	CPSTrueLogDealing(CParseFile* pPF);
	virtual ~CPSTrueLogDealing();
	virtual CParseState* ParseI(const CString &strInLine, const CString &strFullLine);

	void ParseFlopDeal(CString& strUnreadLine);
	void ParseTurnDeal(CString& strUnreadLine);
	void ParseRiverDeal(CString& strUnreadLine);
};

inline void CPSTrueLogDealing::ParseFlopDeal(CString& strUnreadLine)
{
	ReadText(CHAR_OPEN_SQ_BRACKET, strUnreadLine);
	PCard cFlopCard1 = ReadCard(strUnreadLine);
	ReadText(CHAR_COMMA, strUnreadLine);
	PCard cFlopCard2 = ReadCard(strUnreadLine);
	ReadText(CHAR_COMMA, strUnreadLine);
	PCard cFlopCard3 = ReadCard(strUnreadLine);

	sm_cInputHand.SetFlop(cFlopCard1, cFlopCard2, cFlopCard3);
}

inline void CPSTrueLogDealing::ParseTurnDeal(CString& strUnreadLine)
{
	ReadText(CHAR_OPEN_SQ_BRACKET, strUnreadLine);
	PCard cTurnCard = ReadCard(strUnreadLine);

	sm_cInputHand.SetTurn(cTurnCard);
}

inline void CPSTrueLogDealing::ParseRiverDeal(CString& strUnreadLine)
{
	ReadText(CHAR_OPEN_SQ_BRACKET, strUnreadLine);
	PCard cRiverCard = ReadCard(strUnreadLine);

	sm_cInputHand.SetRiver(cRiverCard);
}


#endif // !defined(AFX_CPSTrueLogDealing__INCLUDED_)
