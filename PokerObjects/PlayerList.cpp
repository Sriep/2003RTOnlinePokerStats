// PlayerList.cpp: implementation of the CPlayerList class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PlayerList.h"
#include "PPokerSite.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPlayerList::CPlayerList()
{

}

CPlayerList::CPlayerList(HWND hwnd, int iSiteId)
{
	OpenSharedMemory(PPokerSite::GetPlayerListName(hwnd, iSiteId), FILE_MAP_ALL_ACCESS, 4096);
}

CPlayerList::~CPlayerList()
{

}

StringList CPlayerList::GetPlayerList() 
{
	StringList strListRV;
	if (!IsValid())
		return strListRV;

	ResetPosition();
	while (!Eof())
	{
		CString strPlayer = ReadLine();
		if (!strPlayer.IsEmpty())
		{
			strListRV.push_back(strPlayer);
		}
	}
	return strListRV;

}

void CPlayerList::SetPlayerList(StringList list)
{
	Clear();
	ResetPosition();
	for ( ConstStringListIterator iIter = list.begin() ; iIter != list.end() ; iIter++ )
	{
		CString strNick = *iIter;
		strNick += '\n';
		Append(strNick);
	}
}

void CPlayerList::Set(HWND hwnd, int iSiteId, StringList listPlayers)
{
	CPlayerList cPL(hwnd, iSiteId);
	cPL.SetPlayerList(listPlayers);
}

StringList CPlayerList::Get(HWND hwnd, int iSiteId)
{
	CPlayerList cPL(hwnd, iSiteId);
	return cPL.GetPlayerList();
}

