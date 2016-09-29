// PSWSEXLogDealing.h: interface for the CPSWSEXLogDealing class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PSWSEXLOGDEALING_H__EE325258_F0FC_4A96_A9D9_06769B3DEA3A__INCLUDED_)
#define AFX_PSWSEXLOGDEALING_H__EE325258_F0FC_4A96_A9D9_06769B3DEA3A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "PSWSEXLog.h"

class CPSWSEXLogDealing : public CPSWSEXLog  
{
public:
	CPSWSEXLogDealing(CParseFile* pPF);
	virtual ~CPSWSEXLogDealing();
	virtual CParseState* ParseI(const CString &strInLine, const CString &strFullLine);

	void ParseFlopDeal(CString& strUnreadLine);
	void ParseTurnDeal(CString& strUnreadLine);
	void ParseRiverDeal(CString& strUnreadLine);
};

inline void CPSWSEXLogDealing::ParseFlopDeal(CString& strUnreadLine)
{
	ReadText(CHAR_ASTERIX, strUnreadLine);
	ReadText(CHAR_ASTERIX, strUnreadLine);
	ReadText(CHAR_OPEN_SQ_BRACKET, strUnreadLine);
	PCard cFlopCard1 = ReadCard(strUnreadLine);
	ReadText(CHAR_COMMA, strUnreadLine);
	PCard cFlopCard2 = ReadCard(strUnreadLine);
	ReadText(CHAR_COMMA, strUnreadLine);
	PCard cFlopCard3 = ReadCard(strUnreadLine);
	ReadText(CHAR_CLOSE_SQ_BRACKET, strUnreadLine);

	sm_cInputHand.SetFlop(cFlopCard1, cFlopCard2, cFlopCard3);
}

inline void CPSWSEXLogDealing::ParseTurnDeal(CString& strUnreadLine)
{
	ReadText(CHAR_ASTERIX, strUnreadLine);
	ReadText(CHAR_ASTERIX, strUnreadLine);
	ReadText(CHAR_OPEN_SQ_BRACKET, strUnreadLine);
	PCard cTurnCard = ReadCard(strUnreadLine);
	ReadText(CHAR_CLOSE_SQ_BRACKET, strUnreadLine);

	sm_cInputHand.SetTurn(cTurnCard);
}

inline void CPSWSEXLogDealing::ParseRiverDeal(CString& strUnreadLine)
{
	ReadText(CHAR_ASTERIX, strUnreadLine);
	ReadText(CHAR_ASTERIX, strUnreadLine);
	ReadText(CHAR_OPEN_SQ_BRACKET, strUnreadLine);
	PCard cRiverCard = ReadCard(strUnreadLine);
	ReadText(CHAR_CLOSE_SQ_BRACKET, strUnreadLine);

	sm_cInputHand.SetRiver(cRiverCard);
}


#endif // !defined(AFX_PSWSEXLOGDEALING_H__EE325258_F0FC_4A96_A9D9_06769B3DEA3A__INCLUDED_)
