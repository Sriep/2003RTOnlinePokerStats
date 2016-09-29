// PSStarsDealToPlayer.h: interface for the CPSStarsDealToPlayer class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PSStarsDEALTOPLAYER_H__084B3332_9B15_4432_A55C_5A4A1549B8EB__INCLUDED_)
#define AFX_PSStarsDEALTOPLAYER_H__084B3332_9B15_4432_A55C_5A4A1549B8EB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ParseState.h"

class CPSStarsDealToPlayer : public CParseState  
{
public:
	CPSStarsDealToPlayer(CParseFile* cPF);
	virtual ~CPSStarsDealToPlayer();
	virtual CParseState* Parse(const CString &strInLine);
};

#endif // !defined(AFX_PSStarsDEALTOPLAYER_H__084B3332_9B15_4432_A55C_5A4A1549B8EB__INCLUDED_)
