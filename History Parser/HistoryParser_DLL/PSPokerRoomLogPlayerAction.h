// PSPokerRoomLogPlayerAction.h: interface for the CPSPokerRoomLogPlayerAction class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PSPokerRoomLOGPLAYERACTION_H__864632CF_2402_42F8_8ED1_150A0231A3D8__INCLUDED_)
#define AFX_PSPokerRoomLOGPLAYERACTION_H__864632CF_2402_42F8_8ED1_150A0231A3D8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "PSPokerRoomLog.h"

class CPSPokerRoomLogPlayerAction : public CPSPokerRoomLog  
{
public:
	CPSPokerRoomLogPlayerAction(CParseFile* cPF);
	virtual ~CPSPokerRoomLogPlayerAction();
	virtual CParseState* ParseI(const CString &strInLine, const CString &strFullLine);

};

#endif // !defined(AFX_PSPokerRoomLOGPLAYERACTION_H__864632CF_2402_42F8_8ED1_150A0231A3D8__INCLUDED_)
