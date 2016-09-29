// PSWSEXLogPlayerAction.h: interface for the CPSWSEXLogPlayerAction class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PSCPCryptologicLogPlayerAction_H__864632CF_2402_42F8_8ED1_150A0231A3D8__INCLUDED_)
#define AFX_PSCPCryptologicLogPlayerAction_H__864632CF_2402_42F8_8ED1_150A0231A3D8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "PSCryptologicLog.h"

class CPSCryptologicLogPlayerAction : public CPSCryptologicLog  
{
public:
	CPSCryptologicLogPlayerAction(CParseFile* cPF);
	virtual ~CPSCryptologicLogPlayerAction();
	virtual CParseState* ParseI(const CString &strInLine, const CString &strFullLine);
	void ParseFlopDeal(CString& strUnreadLine);
	void ParseTurnDeal(CString& strUnreadLine);
	void ParseRiverDeal(CString& strUnreadLine);

};

inline void CPSCryptologicLogPlayerAction::ParseFlopDeal(CString& strUnreadLine)
{
	ReverseReadText("]", strUnreadLine);
	PCard cFlopCard1 = ReadCard(strUnreadLine);
	PCard cFlopCard2 = ReadCard(strUnreadLine);
	PCard cFlopCard3 = ReadCard(strUnreadLine);

	sm_cInputHand.SetFlop(cFlopCard1, cFlopCard2, cFlopCard3);
}

inline void CPSCryptologicLogPlayerAction::ParseTurnDeal(CString& strUnreadLine)
{
	ReadText(CHAR_OPEN_SQ_BRACKET, strUnreadLine);
	PCard cTurnCard = ReadCard(strUnreadLine);

	sm_cInputHand.SetTurn(cTurnCard);
}

inline void CPSCryptologicLogPlayerAction::ParseRiverDeal(CString& strUnreadLine)
{
	ReadText(CHAR_OPEN_SQ_BRACKET, strUnreadLine);
	PCard cRiverCard = ReadCard(strUnreadLine);

	sm_cInputHand.SetRiver(cRiverCard);
}


#endif // !defined(AFX_PSCPCryptologicLogPlayerAction_H__864632CF_2402_42F8_8ED1_150A0231A3D8__INCLUDED_)
