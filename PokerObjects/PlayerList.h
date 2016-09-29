// PlayerList.h: interface for the CPlayerList class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PLAYERLIST_H__42174381_4A4A_4889_8AEA_BAB3EE6DCB37__INCLUDED_)
#define AFX_PLAYERLIST_H__42174381_4A4A_4889_8AEA_BAB3EE6DCB37__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined(LIST_DEFS)
#define	 LIST_DEFS
#include <list>
using std::list;
typedef std::list <CString>::iterator StringListIterator;
typedef std::list <CString>::const_iterator ConstStringListIterator;
typedef std::list <CString> StringList; 
typedef std::list <CString*> CNickPtrList;
typedef std::list <CString*>::iterator CNickPtrListIter;
#endif

#include "SharedMemory.h"

class CPlayerList : public CSharedMemory  
{
public:
	CPlayerList();
	virtual ~CPlayerList();
	
	void SetPlayerList(StringList list);
	StringList GetPlayerList();
	CPlayerList(HWND hwnd, int iSiteId);
	static StringList Get(HWND hwnd, int iSiteId);
	static void Set(HWND hwnd, int iSiteId, StringList listPlayers);
};

#endif // !defined(AFX_PLAYERLIST_H__42174381_4A4A_4889_8AEA_BAB3EE6DCB37__INCLUDED_)
