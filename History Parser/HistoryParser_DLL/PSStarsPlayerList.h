// PSStarsPlayerList.h: interface for the CPSStarsPlayerList class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PSStarsPLAYERLIST_H__3C498E62_92EC_44A1_AD57_5A914E196624__INCLUDED_)
#define AFX_PSStarsPLAYERLIST_H__3C498E62_92EC_44A1_AD57_5A914E196624__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ParseState.h"

class CPSStarsPlayerList : public CParseState  
{
public:
	virtual CParseState* Parse(const CString &strInLine);
	CPSStarsPlayerList(CParseFile* cPF);
	virtual ~CPSStarsPlayerList();

};

#endif // !defined(AFX_PSStarsPLAYERLIST_H__3C498E62_92EC_44A1_AD57_5A914E196624__INCLUDED_)
