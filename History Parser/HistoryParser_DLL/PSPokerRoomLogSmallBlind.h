// PSPokerRoomLogSmallBlind.h: interface for the CPSPokerRoomLogSmallBlind class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PSPokerRoomLOGSMALLBLIND_H__FE0E4668_9521_4279_81B5_13BF3A882A81__INCLUDED_)
#define AFX_PSPokerRoomLOGSMALLBLIND_H__FE0E4668_9521_4279_81B5_13BF3A882A81__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "PSPokerRoomLog.h"

class CPSPokerRoomLogSmallBlind : public CPSPokerRoomLog  
{
public:
	CPSPokerRoomLogSmallBlind(CParseFile* pPF);
	virtual ~CPSPokerRoomLogSmallBlind();
	virtual CParseState* ParseI(const CString &strInLine, const CString &strFullLine);
};

#endif // !defined(AFX_PSPokerRoomLOGSMALLBLIND_H__FE0E4668_9521_4279_81B5_13BF3A882A81__INCLUDED_)
