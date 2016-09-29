// PSPokerRoomLogResult.h: interface for the CPSPokerRoomLogResult class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PSPokerRoomLOGRESULT_H__427B71C5_EACD_4546_8F04_A2A5EBA4C259__INCLUDED_)
#define AFX_PSPokerRoomLOGRESULT_H__427B71C5_EACD_4546_8F04_A2A5EBA4C259__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "PSPokerRoomLog.h"

class CPSPokerRoomLogResult : public CParseState  
{
public:
	CPSPokerRoomLogResult(CParseFile* cPF);
	virtual ~CPSPokerRoomLogResult();
	virtual CParseState* Parse(const CString &strInLine);
};

#endif // !defined(AFX_PSPokerRoomLOGRESULT_H__427B71C5_EACD_4546_8F04_A2A5EBA4C259__INCLUDED_)
