// PSParadiseDealToPlayer.h: interface for the CPSParadiseDealToPlayer class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PSParadiseDEALTOPLAYER_H__084B3332_9B15_4432_A55C_5A4A1549B8EB__INCLUDED_)
#define AFX_PSParadiseDEALTOPLAYER_H__084B3332_9B15_4432_A55C_5A4A1549B8EB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ParseState.h"

class CPSParadiseDealToPlayer : public CParseState  
{
public:
	CPSParadiseDealToPlayer(CParseFile* cPF);
	virtual ~CPSParadiseDealToPlayer();
	virtual CParseState* Parse(const CString &strInLine);
};

#endif // !defined(AFX_PSParadiseDEALTOPLAYER_H__084B3332_9B15_4432_A55C_5A4A1549B8EB__INCLUDED_)
