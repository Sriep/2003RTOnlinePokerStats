// PSPokerRoomLogPlayerFirxtAction.h: interface for the CPSPokerRoomLogPlayerFirxtAction class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PSPokerRoomLOGPLAYERFIRXTACTION_H__88695AA7_64F0_4706_A36F_7906893F3B47__INCLUDED_)
#define AFX_PSPokerRoomLOGPLAYERFIRXTACTION_H__88695AA7_64F0_4706_A36F_7906893F3B47__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "PSPokerRoomLog.h"

class CPSPokerRoomLogPlayerFirstAction : public CPSPokerRoomLog  
{
public:
	CPSPokerRoomLogPlayerFirstAction(CParseFile* cPF);
	virtual ~CPSPokerRoomLogPlayerFirstAction();
	virtual CParseState* ParseI(const CString &strInLine, const CString &strFullLine);
};

#endif // !defined(AFX_PSPokerRoomLOGPLAYERFIRXTACTION_H__88695AA7_64F0_4706_A36F_7906893F3B47__INCLUDED_)
