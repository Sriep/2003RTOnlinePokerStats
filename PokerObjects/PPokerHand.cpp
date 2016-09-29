// PPokerHand.cpp: implementation of the PPokerHand class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PPokerHand.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

PPokerHand::PPokerHand()
{
	resize(NUMM_CARDS_POKER_HAND);
   	Clear();
}

PPokerHand::~PPokerHand()
{

}

PPokerHand::PPokerHand(PCard card1, PCard card2, PCard card3, PCard card4, PCard card5)
{
	push_back(card1);
	push_back(card2);
	push_back(card3);
	push_back(card4);
	push_back(card5);
	std::sort(begin(), end());	//lowest = at(0) to hightest = at(4)
	CalculateHandType();
}


void PPokerHand::DUMP()	 const
{
	TRACE1(" %s ",PokerHandTypeAsString());
	at(0).DUMP();
	at(1).DUMP();
	at(2).DUMP();
	at(3).DUMP();
    at(4).DUMP();
}

void PPokerHand::CalculateHandType()
{
   	Clear();
	if (isOneSuited())
	{
	   if (isRun())
	   {
			m_eHandType	= HAND_TYPE_STRAIGHT_FLUSH;
			m_Rank[4] = at(4).getRank();
	   }
	   else
	   {
			m_eHandType	= HAND_TYPE_FLUSH;
			for ( int i = 0 ; i < 5 ; i++ )
			{
				m_Rank[i] = at(i).getRank();; 
			}
	   }
	}
	else if (isQuads())
	{
		m_eHandType	= HAND_TYPE_QUADS;
		m_Rank[4] = highTrips();
		m_Rank[3] = highestNonPair();
	}
	else if (isFullHouse())
	{
		m_eHandType	= HAND_TYPE_FULL_HOUSE;	
		m_Rank[4] = highTrips();
		m_Rank[3] = pairInFullHouse();
	}
	else if (isRun())
	{
		m_eHandType	= HAND_TYPE_STRAIGHT;
		m_Rank[4] = at(4).getRank();
	}
	else if (isTrips())
	{
		m_eHandType	= HAND_TYPE_TRIPS;	
		m_Rank[4] = highTrips();
		m_Rank[3] = highestNonPair();
		m_Rank[2] = secondNonPair();
	}
	else if (isTwoPair())
	{
		m_eHandType	= HAND_TYPE_TWO_PAIR;	
		m_Rank[4] = highPair();
		m_Rank[3] = lowPair();
		m_Rank[2] = highestNonPair();
	}
	else if (isOnePair())
	{
		m_eHandType	= HAND_TYPE_ONE_PAIR;	
		m_Rank[4] = highPair();
		m_Rank[3] = highestNonPair();
		m_Rank[2] = secondNonPair();
		m_Rank[1] = thirdNonPair();
	}
	else
	{
		m_eHandType	= HAND_TYPE_HIGH_CARD;	
		for ( int i = 0 ; i < 5 ; i++ )
		{
			m_Rank[i] = at(i).getRank();; 
		}
	}
}

