// ParseFile.h: interface for the CParseHighStakesLogFile class.
//
//////////////////////////////////////////////////////////////////////
#pragma warning( disable : 4786 )

#if !defined(MAP_DEFS)
#define	 MAP_DEFS
#include <map>
using std::map;
typedef std::map <CString, int>::iterator StringIntMapIterator;
typedef std::map <CString, int>::const_iterator ConstStringIntMapIterator;
typedef std::map <CString, int> StringIntMap; 
//typedef std::map <CString*> CNickPtrList;
//typedef std::map <CString*>::iterator CNickPtrListIter;
#endif


#if !defined(AFX_PARSE_Cryptologic_LOG_FILE_H__516981A2_E165_4F8D_A2F9_7DACD5F44D0B__INCLUDED_)
#define AFX_PARSE_Cryptologic_LOG_FILE_H__516981A2_E165_4F8D_A2F9_7DACD5F44D0B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "ParseLogFile.h"

class CParserCryptologicLogFile  : public CParseLogFile   
{
public:
	CParserCryptologicLogFile();
	virtual ~CParserCryptologicLogFile();
	virtual int GetSite();
	int GetNumberOfHiddenCharactersPerLogLine()	const;

	//For Cryptologic sitel
	CString GetLastPlayer();
	CString GetLastButOnePlayer();
	CString GetLastBetRaiser();
	int GetNumPlayersLeft();
	void AddToNumberOfPlayers(int iAmount = 1);
	void AddToNumberLeftToActThisRound(int iAmoun = 1);
	void NewRound();
	void ProcessAction(PPlayerAction cAcation, CString strNick);  
	bool IsNextRound(const CString& strNick);
	void DUMPBetLEvels();

	virtual void NewHand();
protected:
	virtual CParseState* GetStartState();
	int iBetLevel; 
	StringIntMap mapNickBetLevel;
};

#endif // !defined(AFX_PARSE_Cryptologic_LOG_FILE_H__516981A2_E165_4F8D_A2F9_7DACD5F44D0B__INCLUDED_)
