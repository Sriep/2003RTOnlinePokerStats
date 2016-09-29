// ParseFile.h: interface for the CParseFile class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PARSEFILE_H__516981A2_E165_4F8D_A2F9_7DACD5F44D0B__INCLUDED_)
#define AFX_PARSEFILE_H__516981A2_E165_4F8D_A2F9_7DACD5F44D0B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <iostream.h>
#include "ParseState.h"
#include "InputHand.h"
#include "PCard.h"
#include "PPlayerAction.h"
#include "PPokerSite.h"

class CParseState;
#define MAX_LINE_LENGTH 200

class CParseFile  
{
public:
	CParseFile();
	virtual ~CParseFile();

	virtual void ParseHandHistory(istream& cInStream);
	virtual void ParseLine(const CString& strInputLine); 
	virtual void SetDataSource();

	CInputHand& GetInputHand();  
	StringList& GetListNicks();
	StringListIterator& GetItterLastNicks();

	CString GetTableName() const; //Only used for log parsing
	virtual int GetSite();

	virtual void RefreshPlayers() {};  //only use overridden
	virtual void NewHand(){};	//only use overridden
	virtual bool IsLog();

protected:
	virtual CParseState* GetStartState();
	virtual void Setup();
	virtual void CloseDown();

	StringListIterator m_itterLastNicks;
	CParseState* m_pCurrentState;
	StringList m_listNicks;
	CInputHand m_cInputHand; 
	CString m_strTableName;
	
};



#endif // !defined(AFX_PARSEFILE_H__516981A2_E165_4F8D_A2F9_7DACD5F44D0B__INCLUDED_)
