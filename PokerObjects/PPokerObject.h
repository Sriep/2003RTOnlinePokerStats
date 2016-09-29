// PPokerObject.h: interface for the PPokerObject class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PPOKEROBJECT_H__36E025F9_1F87_47B8_83BE_B7E11E19ACBE__INCLUDED_)
#define AFX_PPOKEROBJECT_H__36E025F9_1F87_47B8_83BE_B7E11E19ACBE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "PPlayerAction.h"

#if defined(_DEBUG)
#define FISHING_DLL "Fishingd.dll"
#define HISTORY_ANALYSER_DLL "HistoryAnalyserDLLd.dll"
#define HISTORY_PARSER_DLL "HistoryParser_DLLd.dll"
#define SPY_CONSUL_DLL "SpyConsul_DLLd.dll"
#else
#define FISHING_DLL "Fishing.dll"
#define HISTORY_ANALYSER_DLL "HistoryAnalyserDLL.dll"
#define HISTORY_PARSER_DLL "HistoryParser_DLL.dll"
#define SPY_CONSUL_DLL "SpyConsul_DLL.dll"
#endif

//#define POKER_DATA_CONNECT_STRING  "ODBC;DSN=PokerData"
//#define POKER_DATA_CONNECT_STRING  "ODBC;DSN=PokerData;UID=sa;PWD=;"
#define LIVE_POKER_DATA_CONNECT_STRING  "ODBC;DSN=LivePokerData;UID=sa;PWD=;"
#define POKER_RESULTS_CONNECT_STRING  "ODBC;DSN=PokerResults;UID=sa;PWD=;"
#define ERROR_CLOSE_GAME_WINDOW 2
#define ERROR_POKER_SITE_IMPLIMENTED 3
#define ERROR_PARADISE_HAND_JUMHBLED 4
#define TRUE_POKER_LOG_FILE_PATH  "C:\\Poker\\Data\\"
#define TRUE_POKER_STORE_OLD_LOG_FILES "C:\\Poker\\Data\\TruePokerDone\\"
#define TRUE_POKER_NICK "SriepTShrimp"
#define ROYAL_POKER_SCREEN_NAME "Sriep"
#define LABROKES_SCREEN_NAME "Ssreip"
#define MAX_WINDOW_CAPTION_SIZE 256
#define SPY_DEAMON_LOG_FILE "C:\\Poker\\Data\\SpyDeamon.log"
#define MIN_NUMBER_OF_PLAYERS 3
#define PARADISE_MIN_NUMBER_OF_PLAYERS 7
#define CLEAR_LOG_TIMEOUT 120

class PPokerObject  
{
public:
#include "PSUIT.h"	  //class PSuit 
	friend PSuit;
#include "PRANK.h"	  //class PRank
	friend PRank;

	PPokerObject();
	virtual ~PPokerObject();
	static PSuit makeSuit(int iHashValue);
	static PRank makeRank(int iHashValue);

protected:
	static PRank NO_RANK;
	static PRank TWO;
	static PRank THREE;
	static PRank FOUR;
	static PRank FIVE;
	static PRank SIX;
	static PRank SEVEN;
	static PRank EIGHT;
	static PRank NINE;
	static PRank TEN;
	static PRank JACK;
	static PRank QUEEN;
	static PRank KING;
	static PRank ACE;
	static PRank NUM_RANKS;
	static PSuit NO_SUIT;
	static PSuit SPADES;
	static PSuit HEARTS;
	static PSuit DIAMONDS;
	static PSuit CLUBS;
	static const int NUM_CARDS;
	static const int NUM_HOLDEM_HANDS;
	static const int NUMM_CARDS_POKER_HAND;
	static PPlayerAction ACTION_NONE;
	static PPlayerAction POST;
	static PPlayerAction MUCK;
	static PPlayerAction FOLD;
	static PPlayerAction CHECK;
	static PPlayerAction CALL;
	static PPlayerAction BET;
	static PPlayerAction RAISE;
	static PPlayerAction NUM_OF_ACTIONS;

};

inline PPokerObject::PRank PPokerObject::makeRank(int iHashValue)
{
	return PRank(iHashValue);
}

inline PPokerObject::PSuit PPokerObject::makeSuit(int iHashValue)
{
	return PSuit(iHashValue);
}

inline PPokerObject::PRank PPokerObject::PRank::charToRank(unsigned char chRank)
{
	switch (chRank)
	{
	case '2':
		return TWO;
	case '3':
		return THREE;
	case '4':
		return FOUR;
	case '5':
		return FIVE; 
	case '6':
		return SIX;	
	case '7':
		return SEVEN;
	case '8':
		return EIGHT;
	case '9':
		return NINE;
	case 'T':
	case 't':
	case '1':
		return TEN;	
	case 'J':
		return JACK;
	case 'Q':
		return QUEEN;
	case 'K':
		return KING;
	case 'A':
		return ACE;	
	default:
		//ASSERT(FALSE);
		throw("INVALID RANK");
	};
}

inline CString PPokerObject::PRank::asString() const
{
	switch (m_eRank)
	{
	case RANK_TWO:
		return CString("2"); 
	case RANK_THREE:
		return CString("3");
	case RANK_FOUR:
		return CString("4");
	case RANK_FIVE:
		return CString("5");
	case RANK_SIX:
		return CString("6"); 
	case RANK_SEVEN:
		return CString("7");	
	case RANK_EIGHT:
		return CString("8");
	case RANK_NINE:
		return CString("9");
	case RANK_TEN:
		return CString("T");
	case RANK_JACK:
		return CString("J");
	case RANK_QUEEN:
		return CString("Q");	
	case RANK_KING:
		return CString("K");
	case RANK_ACE:
		return CString("A");
	default:
		//ASSERT(FALSE);
		return CString("");
	};
}

inline void  PPokerObject::PRank::DUMP() const
{
	TRACE(asString());
}


inline PPokerObject::PRank PPokerObject::PRank::stringToRank(const CString& strRank)
{
	if (strRank == "Ace")
		return ACE;
	else if (strRank ==  "King")
		return KING;
	else if (strRank ==  "Queen")
		return QUEEN;
	else if (strRank ==  "Jack")
		return JACK; 
	else if (strRank ==  "Ten")
		return TEN; 
	
	return	charToRank(strRank.GetAt(0));
}

inline bool PPokerObject::PRank::operator!=(const PRank& rRank) const
{
	return m_eRank != rRank.m_eRank;
}

inline bool PPokerObject::PRank::operator==(const PRank& rRank) const
{
	return m_eRank == rRank.m_eRank;
}

inline PPokerObject::PRank& PPokerObject::PRank::operator=(const PRank& rRank)
{
	m_eRank = rRank.m_eRank;
	return *this;
}

inline bool PPokerObject::PRank::operator<(const PRank& rRank) const	
{
	return m_eRank < rRank.m_eRank;
}

inline bool PPokerObject::PRank::operator<=(const PRank& rRank) const	
{
	return m_eRank <= rRank.m_eRank;
}

inline bool PPokerObject::PRank::operator>(const PRank& rRank) const  
{
	return m_eRank > rRank.m_eRank;
}

inline bool PPokerObject::PRank::operator>=(const PRank& rRank) const 
{
	return m_eRank >= rRank.m_eRank;
}

inline int PPokerObject::PRank::operator-(const PRank& sRank) const
{
	return m_eRank - sRank.m_eRank;
}

inline int PPokerObject::PRank::distance(const PRank& rRank1, const PRank& rRank2) 
{
	if (rRank1 == ACE)
	{
		return __min(abs(ACE - rRank2), abs(TWO - rRank2) + 1);
	}

	if (rRank1 == ACE)
	{
		return __min(abs(ACE - rRank1), abs(TWO - rRank1) + 1);
	} 

	return abs(rRank1 - rRank2);
}

inline int PPokerObject::PRank::getHashValue() const
{
	return (int) m_eRank;
}

inline PPokerObject::PRank::PRank(int iHashValue)
{
	m_eRank	= (RANK) iHashValue;
}

inline PPokerObject::PRank& PPokerObject::PRank::operator++() 
{
	if (m_eRank == RANK_NO_RANK || m_eRank == RANK_NUM_RANKS)
	{
		m_eRank = RANK_NO_RANK;
	}
	else
	{
		m_eRank = (PPokerObject::PRank::RANK) ((int)m_eRank + 1) ;
	}
	return *this;

}

inline PPokerObject::PRank& PPokerObject::PRank::operator--() 
{
	if (m_eRank == RANK_NO_RANK || m_eRank == RANK_NUM_RANKS)
	{
		m_eRank = RANK_NO_RANK;
	}
	else
	{
		m_eRank = (PPokerObject::PRank::RANK) ((int)m_eRank - 1) ;
	}
	return *this;
}


inline PPokerObject::PRank::operator int() const
{
	return (int)m_eRank;
}  

inline PPokerObject::PRank& PPokerObject::PRank::operator+=(int iIncrement)
{
	if (m_eRank == RANK_NO_RANK || m_eRank == RANK_NUM_RANKS)
	{
		m_eRank = RANK_NO_RANK;
	}
	else
	{
		int iRank = (int)m_eRank + iIncrement;
		if (iRank > (int) RANK_NUM_RANKS)
		{
			m_eRank = RANK_NO_RANK;
		}
		else
		{
			m_eRank = (PPokerObject::PRank::RANK)  iRank;
		}
	}
	return *this;
}

inline PPokerObject::PRank& PPokerObject::PRank::operator-=(int iDecrement)
{
	if (m_eRank == RANK_NO_RANK || m_eRank == RANK_NUM_RANKS)
	{
		m_eRank = RANK_NO_RANK;
	}
	else
	{
		int iRank = (int)m_eRank - iDecrement;
		if (iRank < (int) RANK_NO_RANK)
		{
			m_eRank = RANK_NO_RANK;																				}
		else
		{
			m_eRank = (PPokerObject::PRank::RANK)  iRank;
		}
	}
	return *this;
}

inline PPokerObject::PSuit PPokerObject::PSuit::charToSuit(unsigned char chSuit)
{
	switch (chSuit)
	{
	case 's':
	case 'S':
	case 170://'\xAA':
		return SPADES;
	case 'h':
	case 'H':
	case 169://'\xA9':
		return HEARTS;
	case 'd':
	case 'D':
	case 168://'\xA8':
		return DIAMONDS;
	case 'c':
	case 'C':
	case 167://'\xA7':
		return CLUBS; 
	default:
		ASSERT(FALSE);
		throw("INVALID SUIT");
	};
	if (chSuit == 170)
	{
		TRACE("hi there char = 170");
	}

}

inline PPokerObject::PSuit PPokerObject::PSuit::stringToSuit(const CString& strSuit)
{
	if (strSuit == "Spades")
		return SPADES;
	else if (strSuit ==  "Hearts")
		return HEARTS;
	else if (strSuit ==  "Diamonds")
		return DIAMONDS;
	else if (strSuit ==  "Clubs")
		return CLUBS; 
	else
	{
		//ASSERT(FALSE);
		throw("INVALID SUIT");
	}
}

inline bool PPokerObject::PSuit::operator!=(const PSuit& sSuit) const
{
	return m_eSuit != sSuit.m_eSuit;
}

inline bool PPokerObject::PSuit::operator==(const PSuit& sSuit) const
{
	return m_eSuit == sSuit.m_eSuit;
}

inline PPokerObject::PSuit& PPokerObject::PSuit::operator=(const PSuit& sSuit)
{
	m_eSuit = sSuit.m_eSuit;
	return *this;
}

inline bool PPokerObject::PSuit::operator<(const PSuit& sSuit) const	
{
	return m_eSuit < sSuit.m_eSuit;
}

inline bool PPokerObject::PSuit::operator<=(const PSuit& sSuit) const	
{
	return m_eSuit <= sSuit.m_eSuit;
}

inline bool PPokerObject::PSuit::operator>(const PSuit& sSuit) const  
{
	return m_eSuit > sSuit.m_eSuit;
}

inline bool PPokerObject::PSuit::operator>=(const PSuit& sSuit) const 
{
	return m_eSuit >= sSuit.m_eSuit;
}



inline int PPokerObject::PSuit::getHashValue() const
{
	return (int) m_eSuit;
}

inline PPokerObject::PSuit::PSuit(int iHashValue)
{
	m_eSuit = (SUIT) iHashValue;
}

inline CString PPokerObject::PSuit::asString() const
{
	switch (m_eSuit)
	{
	case SUIT_SPADES:
		return CString("s");
	case SUIT_HEARTS:
		return CString("h");
	case SUIT_DIAMONDS:
		return CString("d");
	case SUIT_CLUBS:
		return CString("c"); 
	default:
		ASSERT(FALSE);
		return CString("");
	};
}

inline void PPokerObject::PSuit::DUMP() const
{
	TRACE(asString());
}

#endif // !defined(AFX_PPOKEROBJECT_H__36E025F9_1F87_47B8_83BE_B7E11E19ACBE__INCLUDED_)
