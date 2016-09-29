// PSRoyalVegasLogDealing.h: interface for the CPSRoyalVegasLogDealing class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PSRoyalVegasLOGDEALING_H__EE325258_F0FC_4A96_A9D9_06769B3DEA3A__INCLUDED_)
#define AFX_PSRoyalVegasLOGDEALING_H__EE325258_F0FC_4A96_A9D9_06769B3DEA3A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "PSRoyalVegasLog.h"

class CPSRoyalVegasLogDealing : public CPSRoyalVegasLog  
{
public:
	CPSRoyalVegasLogDealing(CParseFile* pPF);
	virtual ~CPSRoyalVegasLogDealing();
	virtual CParseState* ParseI(const CString &strInLine, const CString &strFullLine);

	void ParseFlopDeal(CString& strUnreadLine);
	void ParseTurnDeal(CString& strUnreadLine);
	void ParseRiverDeal(CString& strUnreadLine);
};

inline void CPSRoyalVegasLogDealing::ParseFlopDeal(CString& strUnreadLine)
{
	PCard cFlopCard1 = ReadCard(strUnreadLine);
	PCard cFlopCard2 = ReadCard(strUnreadLine);
	PCard cFlopCard3 = ReadCard(strUnreadLine);

	sm_cInputHand.SetFlop(cFlopCard1, cFlopCard2, cFlopCard3);
}

inline void CPSRoyalVegasLogDealing::ParseTurnDeal(CString& strUnreadLine)
{
	PCard cTurnCard = ReadCard(strUnreadLine);

	sm_cInputHand.SetTurn(cTurnCard);
}

inline void CPSRoyalVegasLogDealing::ParseRiverDeal(CString& strUnreadLine)
{
	PCard cRiverCard = ReadCard(strUnreadLine);

	sm_cInputHand.SetRiver(cRiverCard);
}


#endif // !defined(AFX_PSRoyalVegasLOGDEALING_H__EE325258_F0FC_4A96_A9D9_06769B3DEA3A__INCLUDED_)
