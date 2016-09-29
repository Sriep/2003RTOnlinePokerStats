// PSHighStakesLogDealing.h: interface for the CPSHighStakesLogDealing class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PSHighStakesLOGDEALING_H__EE325258_F0FC_4A96_A9D9_06769B3DEA3A__INCLUDED_)
#define AFX_PSHighStakesLOGDEALING_H__EE325258_F0FC_4A96_A9D9_06769B3DEA3A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "PSHighStakesLog.h"

class CPSHighStakesLogDealing : public CPSHighStakesLog  
{
public:
	CPSHighStakesLogDealing(CParseFile* pPF);
	virtual ~CPSHighStakesLogDealing();
	virtual CParseState* ParseI(const CString &strInLine, const CString &strFullLine);

	void ParseFlopDeal(CString& strUnreadLine);
	void ParseTurnDeal(CString& strUnreadLine);
	void ParseRiverDeal(CString& strUnreadLine);
private:
	PokerRound m_eRound;
};

inline void CPSHighStakesLogDealing::ParseFlopDeal(CString& strUnreadLine)
{
	ReadText("Board cards [", strUnreadLine);
	PCard cFlopCard1 = ReadCard(strUnreadLine);
	PCard cFlopCard2 = ReadCard(strUnreadLine);
	PCard cFlopCard3 = ReadCard(strUnreadLine);
	sm_cInputHand.SetFlop(cFlopCard1, cFlopCard2, cFlopCard3);
}

inline void CPSHighStakesLogDealing::ParseTurnDeal(CString& strUnreadLine)
{
	ReverseReadText("]", strUnreadLine);
	PCard cTurnCard = ReverseReadCard(strUnreadLine);
	sm_cInputHand.SetTurn(cTurnCard);
}

inline void CPSHighStakesLogDealing::ParseRiverDeal(CString& strUnreadLine)
{
	ReverseReadText("]", strUnreadLine);
	PCard cRiverCard = ReverseReadCard(strUnreadLine);
	sm_cInputHand.SetRiver(cRiverCard);
}


#endif // !defined(AFX_PSHighStakesLOGDEALING_H__EE325258_F0FC_4A96_A9D9_06769B3DEA3A__INCLUDED_)
