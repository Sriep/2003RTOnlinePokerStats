// PSParadisePlayerList.h: interface for the CPSParadisePlayerList class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PSParadisePLAYERLIST_H__3C498E62_92EC_44A1_AD57_5A914E196624__INCLUDED_)
#define AFX_PSParadisePLAYERLIST_H__3C498E62_92EC_44A1_AD57_5A914E196624__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ParseState.h"

class CPSParadisePlayerList : public CParseState  
{
public:
	virtual CParseState* Parse(const CString &strInLine);
	CPSParadisePlayerList(CParseFile* cPF);
	virtual ~CPSParadisePlayerList();

};

#endif // !defined(AFX_PSParadisePLAYERLIST_H__3C498E62_92EC_44A1_AD57_5A914E196624__INCLUDED_)
