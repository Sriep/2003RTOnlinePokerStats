// ParseState.h: interface for the CParseState class.
//
//////////////////////////////////////////////////////////////////////

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

#if !defined(AFX_PARSESTATE_H__018AB3BC_E95B_40C0_87A4_D33DD46661E0__INCLUDED_)
#define AFX_PARSESTATE_H__018AB3BC_E95B_40C0_87A4_D33DD46661E0__INCLUDED_
  
#include "InputHand.h"
#include "PCard.h"
#include "PPlayerAction.h"
#include "ParseFile.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


	//static CInputHand sm_cInputHand;  
	//static StringList sm_listNicks;
	//static StringListIterator sm_itterLastNicks;
#define  sm_cInputHand m_cParseFile->GetInputHand()
#define  sm_listNicks m_cParseFile->GetListNicks()
#define  sm_itterLastNicks m_cParseFile->GetItterLastNicks()

class CParseFile;

class CParseState  
{
public:
	static bool IsNumber(char ichar);
	CParseState(CParseFile* cPF);
	virtual ~CParseState();

	virtual CParseState* Parse(const CString& pcchInLine) = 0;
	//static void Setup();
	//static void CloseDown();

protected:
	bool IsNextWord(const CString& strToLookFor, CString strSource) const;
	bool ReadIfNextWord(const CString& strToLookFor, CString& strSource) const;
	bool ReverseReadIfNextWord(const CString& strToLookFor, CString& strSource) const;
	
	bool IsLastWord(const CString &strToLookFor, CString strSource) const;
	bool FindText(const CString& strToFind, CString&  strUnreadLine) const;
	void ReadText(const CString &strText, CString& strUnreadLine);
	CString GetNextWord(CString& strUnreadLine);
	long GetNextNumber(CString& strUnreadLine);

	void ReverseReadText(const CString& strText, CString& strUnreadLine) const;
	CString ReverseGetNextWord(CString& strUnreadLine);
	int ReverseGetNextNumber(CString& strUnreadLine);
	PCard ReverseReadCard(CString& strUnreadLine);
	PCard ReadCard(CString& strUnreadLine);
	PPlayerAction ReverseReadAction(CString& strUnreadLine);
	bool StarsIgnoreLine(const CString& strInLine);
	bool PartyIgnoreLine(const CString& strInLine);	  
	bool ParadiseIgnoreLine(const CString& strInLine);
	int GetMounthAsInt(const CString& strMounth); 
	virtual CParseState* ChangeState(CParseState* pNewState, const CString& strInLine);

	CString ReverseSpanIncluding(const CString& strTheString, const CString& strToLookFor);

	static const CString NUMBERS;
	static const CString LETTERS; 
	static const CString VALID_NICK_CHARS;
	static const char* CHAR_DASH;
	static const char* CHAR_FOWARD_SLASH;
	static const char* CHAR_COLON;
	static const char* CHAR_OPEN_BRACKET;
	static const char* CHAR_CLOSE_BRACKET;
	static const char* CHAR_SPACE;
	static const char* CHAR_DOLLAR;
	static const char* CHAR_ASTERIX;
	static const char* CHAR_COMMA;
	static const char* CHAR_OPEN_SQ_BRACKET;
	static const char* CHAR_CLOSE_SQ_BRACKET;
	static const char* CHAR_BAR;
	static const char* WORD_Table;
	static const char* WORD_Real;
	static const char* WORD_Money;
	static const char* WORD_Seat;
	static const char* WORD_is;
	static const char* WORD_the;
	static const char* WORD_button;
	static const char* WORD_Total;
	static const char* WORD_number;
	static const char* WORD_of;
	static const char* WORD_players;
	static const char* WORD_blind;
	static const char* WORD_small;
	static const char* WORD_big;
	static const char* WORD_posts;
	static const char* WORD_Dealing;
	static const char* WORD_down;
	static const char* WORD_cards;
	static const char* WORD_Dealt;
	static const char* WORD_to;
	static const char* WORD_Flop;
	static const char* WORD_Turn;
	static const char* WORD_River;
	static const char* WORD_Main;
	static const char* WORD_Side;
	static const char* WORD_Pot;
	static const char* WORD_Rake;
	static const char* WORD_Board;

	//static CInputHand sm_cInputHand;  
	//static StringList sm_listNicks;
	//static StringListIterator sm_itterLastNicks;

	StringListIterator Find(const CString& strNick);   
	CString ReadNick(CString& strUnreadLine);
	CString ReadLongNick(CString& strUnreadLine);
	bool IsNickInNickList(const CString& strNick);
	CParseFile* m_cParseFile;
};


#endif // !defined(AFX_PARSESTATE_H__018AB3BC_E95B_40C0_87A4_D33DD46661E0__INCLUDED_)

