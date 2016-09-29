// PSPartyPlayerList.h: interface for the CPSPartyPlayerList class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PSPARTYPLAYERLIST_H__3C498E62_92EC_44A1_AD57_5A914E196624__INCLUDED_)
#define AFX_PSPARTYPLAYERLIST_H__3C498E62_92EC_44A1_AD57_5A914E196624__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ParseState.h"

class CPSPartyPlayerList : public CParseState  
{
public:
	virtual CParseState* Parse(const CString &strInLine);
	CPSPartyPlayerList(CParseFile* cPF);
	virtual ~CPSPartyPlayerList();

};

#endif // !defined(AFX_PSPARTYPLAYERLIST_H__3C498E62_92EC_44A1_AD57_5A914E196624__INCLUDED_)
