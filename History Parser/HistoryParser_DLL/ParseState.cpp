// ParseState.cpp: implementation of the CParseState class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ParseState.h"
#include "ParsingException.h"
#include "PSNone.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

//CInputHand CParseState::sm_cInputHand;
const CString CParseState::NUMBERS = "0123456789,.";
const CString CParseState::LETTERS = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ.()[]";
const CString CParseState::VALID_NICK_CHARS = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_";
const char* CParseState::CHAR_DASH = "-";
const char* CParseState::CHAR_FOWARD_SLASH = "/";
const char* CParseState::CHAR_COLON = ":";
const char* CParseState::CHAR_OPEN_BRACKET = "(";
const char* CParseState::CHAR_CLOSE_BRACKET = ")";
const char* CParseState::CHAR_SPACE = " ";
const char* CParseState::CHAR_DOLLAR = "$";
const char* CParseState::CHAR_ASTERIX = "*";
const char* CParseState::CHAR_COMMA = ",";
const char* CParseState::CHAR_OPEN_SQ_BRACKET = "[";
const char* CParseState::CHAR_CLOSE_SQ_BRACKET = "]";
const char* CParseState::CHAR_BAR = "|";

const char* CParseState::WORD_Table = "Table";
const char* CParseState::WORD_Real = "Real";
const char* CParseState::WORD_Money = "Money";
const char* CParseState::WORD_Seat = "Seat";
const char* CParseState::WORD_is = "is";
const char* CParseState::WORD_the = "the";
const char* CParseState::WORD_button = "button";
const char* CParseState::WORD_Total = "Total";
const char* CParseState::WORD_number = "number";
const char* CParseState::WORD_of = "of";
const char* CParseState::WORD_players = "players";
const char* CParseState::WORD_blind = "blind";
const char* CParseState::WORD_small = "small";
const char* CParseState::WORD_big = "big";
const char* CParseState::WORD_posts = "posts";
const char* CParseState::WORD_Dealing = "Dealing";
const char* CParseState::WORD_down = "down";
const char* CParseState::WORD_cards = "cards";
const char* CParseState::WORD_Dealt = "Dealt";
const char* CParseState::WORD_to = "to";
const char* CParseState::WORD_Flop = "Flop";
const char* CParseState::WORD_Turn = "Turn";
const char* CParseState::WORD_River = "River";
const char* CParseState::WORD_Main = "Main";
const char* CParseState::WORD_Side = "Side";
const char* CParseState::WORD_Pot = "Pot";
const char* CParseState::WORD_Rake = "Rake";
const char* CParseState::WORD_Board = "Board";

//StringList CParseState::sm_listNicks;
//StringListIterator CParseState::sm_itterLastNicks;

CParseState::CParseState(CParseFile* pPF)
: m_cParseFile(pPF)
{
}


CParseState::~CParseState()
{

}

CParseState* CParseState::ChangeState(CParseState* pNewState, const CString& strInLine)
{
	try
	{
		CParseState* pRetState = pNewState->Parse(strInLine);
		return pRetState;
	}
	catch (CParsingException* pParseException)
	{
		delete pNewState;
		delete pParseException;
		return this;
	}	
}


