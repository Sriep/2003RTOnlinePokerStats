// PSPartyDealToPlayer.h: interface for the CPSPartyDealToPlayer class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PSPARTYDEALTOPLAYER_H__084B3332_9B15_4432_A55C_5A4A1549B8EB__INCLUDED_)
#define AFX_PSPARTYDEALTOPLAYER_H__084B3332_9B15_4432_A55C_5A4A1549B8EB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ParseState.h"

class CPSPartyDealToPlayer : public CParseState  
{
public:
	CPSPartyDealToPlayer(CParseFile* cPF);
	virtual ~CPSPartyDealToPlayer();
	virtual CParseState* Parse(const CString &strInLine);
};

#endif // !defined(AFX_PSPARTYDEALTOPLAYER_H__084B3332_9B15_4432_A55C_5A4A1549B8EB__INCLUDED_)
