// PHoldemFlop.cpp: implementation of the PHoldemFlop class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PHoldemFlop.h"

#include "PPokerHand.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

PHoldemFlop::PHoldemFlop()
{

}

PHoldemFlop::~PHoldemFlop()
{

}

PHoldemFlop::PHoldemFlop(PCard cFlop1, PCard cFlop2, PCard cFlop3)
:	m_cFlop3(cFlop3),
	m_cFlop2(cFlop2),
	m_cFlop1(cFlop1)
{

}

void PHoldemFlop::setBoard(PCard cFlop1, PCard cFlop2, PCard cFlop3)
{
	m_cFlop3 = cFlop3;
	m_cFlop2 = cFlop2;
	m_cFlop1 = cFlop1;
}

PHoldemFlop::PHoldemFlop(const PHoldemFlop& cBoard)
{
	m_cFlop3 = cBoard.m_cFlop3;
	m_cFlop2 = cBoard.m_cFlop2;
	m_cFlop1 = cBoard.m_cFlop1;
}


bool PHoldemFlop::isRainbowFlop()	const
{
	return m_cFlop1.getSuit() != m_cFlop2.getSuit() 
		&& m_cFlop2.getSuit() != m_cFlop3.getSuit() 
		&& m_cFlop1.getSuit() != m_cFlop3.getSuit();
}

bool PHoldemFlop::isTwoSuitedFlop() const
{
	return !isRainbowFlop() && !isSingleSuitedFlop();
}

bool PHoldemFlop::isSingleSuitedFlop() const
{
	return m_cFlop1.getSuit() == m_cFlop2.getSuit() 
		&& m_cFlop2.getSuit() == m_cFlop3.getSuit();
}


bool PHoldemFlop::isPairedFlop() const
{
	return !isUnPairedFlop() && !isTripsFlop();
}

bool PHoldemFlop::isTripsFlop() const
{
	return m_cFlop1.getRank() == m_cFlop2.getRank() 
		&& m_cFlop2.getRank() == m_cFlop3.getRank();
}

bool PHoldemFlop::isUnPairedFlop() const
{
	return m_cFlop1.getRank() != m_cFlop2.getRank() 
		&& m_cFlop2.getRank() != m_cFlop3.getRank() 
		&& m_cFlop1.getRank() != m_cFlop3.getRank();
}

bool PHoldemFlop::isStraightFlop() const
{
	if (!isUnPairedFlop())
		return FALSE;
	
	return PRank::distance(m_cFlop1.getRank(), m_cFlop2.getRank()) <= 5
				 &&	PRank::distance(m_cFlop2.getRank(), m_cFlop3.getRank()) <= 5
				 && PRank::distance(m_cFlop1.getRank(), m_cFlop3.getRank()) <= 5 ;
}

bool PHoldemFlop::isTwoWayStraightDrawFlop() const
{
	if (m_cFlop1.getRank() != ACE &&  m_cFlop2.getRank() != ACE && m_cFlop3.getRank() != ACE)
	{
		if (PRank::distance(m_cFlop1.getRank(), m_cFlop2.getRank()) <= 4 && m_cFlop1.getRank() != m_cFlop2.getRank())
			return true;
		if (PRank::distance(m_cFlop2.getRank(), m_cFlop3.getRank()) <= 4 && m_cFlop2.getRank() != m_cFlop3.getRank())
			return true;
		if (PRank::distance(m_cFlop1.getRank(), m_cFlop3.getRank()) <= 4 && m_cFlop1.getRank() != m_cFlop3.getRank())
			return true;
		return false;
	}

	if (m_cFlop1.getRank() == ACE)
	{
		if (m_cFlop2.getRank() != KING ||  m_cFlop2.getRank() != TWO || m_cFlop2.getRank() != ACE
			|| m_cFlop3.getRank() != KING  || m_cFlop3.getRank() != TWO || m_cFlop3.getRank() != ACE)
			return false;
		return 	(PRank::distance(m_cFlop2.getRank(), m_cFlop3.getRank()) <= 4 && m_cFlop2.getRank() != m_cFlop3.getRank());
	}

	if (m_cFlop2.getRank() == ACE)
	{
		if (m_cFlop1.getRank() != KING ||  m_cFlop1.getRank() != TWO || m_cFlop1.getRank() != ACE
			|| m_cFlop3.getRank() != KING  || m_cFlop3.getRank() != TWO || m_cFlop3.getRank() != ACE)
			return false;
		return 	(PRank::distance(m_cFlop1.getRank(), m_cFlop3.getRank()) <= 4 && m_cFlop1.getRank() != m_cFlop3.getRank());
	}

	if (m_cFlop3.getRank() == ACE)
	{
		if (m_cFlop1.getRank() != KING ||  m_cFlop1.getRank() != TWO || m_cFlop1.getRank() != ACE
			|| m_cFlop2.getRank() != KING  || m_cFlop2.getRank() != TWO || m_cFlop2.getRank() != ACE)
			return false;
		return 	(PRank::distance(m_cFlop1.getRank(), m_cFlop2.getRank()) <= 4 && m_cFlop1.getRank() != m_cFlop2.getRank());
	}

	ASSERT(FALSE); //all options covered
	return false;
}

bool PHoldemFlop::isGutShotFlop()  const
{
	if (PRank::distance(m_cFlop1.getRank(), m_cFlop2.getRank()) <= 5 && m_cFlop1.getRank() != m_cFlop2.getRank())
		return true;

	if (PRank::distance(m_cFlop2.getRank(), m_cFlop3.getRank()) <= 5 && m_cFlop2.getRank() != m_cFlop3.getRank())
		return true;

	return (PRank::distance(m_cFlop1.getRank(), m_cFlop3.getRank()) <= 5 && m_cFlop1.getRank() != m_cFlop3.getRank());
	
}

void PHoldemFlop::checkValid()
{

}

bool PHoldemFlop::isHighCard(PHoldemFlop flop, PHoldemHand cHand) 
{
	PPokerHand hand(flop.m_cFlop1, flop.m_cFlop2, flop.m_cFlop3, cHand.getHighCard(), cHand.getLowCard()); 

	return hand.isHighCard();
}

bool PHoldemFlop::isOnePair(PHoldemFlop flop, PHoldemHand cHand)  
{
	PPokerHand hand(flop.m_cFlop1, flop.m_cFlop2, flop.m_cFlop3, cHand.getHighCard(), cHand.getLowCard()); 

	return hand.isOnePair();
}

bool PHoldemFlop::isTwoPair(PHoldemFlop flop, PHoldemHand cHand) 
{
	PPokerHand hand(flop.m_cFlop1, flop.m_cFlop2, flop.m_cFlop3, cHand.getHighCard(), cHand.getLowCard()); 

	return hand.isTwoPair();
}

bool PHoldemFlop::isTrips(PHoldemFlop flop, PHoldemHand cHand)	
{
	PPokerHand hand(flop.m_cFlop1, flop.m_cFlop2, flop.m_cFlop3, cHand.getHighCard(), cHand.getLowCard()); 

	return hand.isTrips();
}

bool PHoldemFlop::isStraight(PHoldemFlop flop, PHoldemHand cHand) 
{
	PPokerHand hand(flop.m_cFlop1, flop.m_cFlop2, flop.m_cFlop3, cHand.getHighCard(), cHand.getLowCard()); 

	return hand.isStraight();
}

bool PHoldemFlop::isFlush(PHoldemFlop flop, PHoldemHand cHand)	
{
	PPokerHand hand(flop.m_cFlop1, flop.m_cFlop2, flop.m_cFlop3, cHand.getHighCard(), cHand.getLowCard()); 

	return hand.isFlush();
}

bool PHoldemFlop::isFullHouse(PHoldemFlop flop, PHoldemHand cHand) 
{
	PPokerHand hand(flop.m_cFlop1, flop.m_cFlop2, flop.m_cFlop3, cHand.getHighCard(), cHand.getLowCard()); 

	return hand.isFullHouse();
}

bool PHoldemFlop::isQuads(PHoldemFlop flop, PHoldemHand cHand)	
{
	PPokerHand hand(flop.m_cFlop1, flop.m_cFlop2, flop.m_cFlop3, cHand.getHighCard(), cHand.getLowCard()); 

	return hand.isQuads();
}

bool PHoldemFlop::isStraightFlush(PHoldemFlop flop, PHoldemHand cHand) 
{
	PPokerHand hand(flop.m_cFlop1, flop.m_cFlop2, flop.m_cFlop3, cHand.getHighCard(), cHand.getLowCard()); 

	return hand.isStraightFlush();
}

bool PHoldemFlop::isHighCard(PHoldemFlop flop, PHoldemHand cHand, PRank rRank)
{
	PPokerHand hand(flop.m_cFlop1, flop.m_cFlop2, flop.m_cFlop3, cHand.getHighCard(), cHand.getLowCard()); 
	if (!hand.isHighCard())
		return false;
	return cHand.getHighCard().getRank() == rRank || cHand.getLowCard().getRank() == rRank;
}

bool PHoldemFlop::isHighCardOrWorse(PHoldemFlop flop, PHoldemHand cHand, PRank rRank)
{
	PPokerHand hand(flop.m_cFlop1, flop.m_cFlop2, flop.m_cFlop3, cHand.getHighCard(), cHand.getLowCard()); 
	if (!hand.isHighCard())
		return false;
	return cHand.getHighCard().getRank() < rRank && cHand.getLowCard().getRank() < rRank;
}

bool PHoldemFlop::isFlushDraw(PHoldemFlop flop, PHoldemHand cHand)
{
	if (flop.m_cFlop1.getSuit() != flop.m_cFlop2.getSuit())
	{
		if (flop.m_cFlop1.getSuit() ==  flop.m_cFlop3.getSuit())
			return cHand.getHighCard().getSuit() ==  flop.m_cFlop1.getSuit() && flop.m_cFlop1 ==  cHand.getLowCard();
		else
			return cHand.getHighCard().getSuit() ==  flop.m_cFlop2.getSuit() && flop.m_cFlop2.getSuit() ==  cHand.getLowCard().getSuit();
	}

	if (flop.m_cFlop1.getSuit() != flop.m_cFlop3.getSuit())
		return cHand.getHighCard().getSuit() ==  flop.m_cFlop1.getSuit() && flop.m_cFlop1.getSuit() ==  cHand.getLowCard().getSuit();

	if (flop.m_cFlop1.getSuit() != cHand.getHighCard().getSuit())
		return flop.m_cFlop1.getSuit() ==  cHand.getLowCard().getSuit();
	
	return (flop.m_cFlop1.getSuit() != cHand.getLowCard().getSuit());
}

bool PHoldemFlop::isStraightDraw(PHoldemFlop flop, PHoldemHand cHand)
{
	return false;
}

bool PHoldemFlop::isGutShotDraw(PHoldemFlop flop, PHoldemHand cHand)
{
	return false;
}

PCard PHoldemFlop::getFlop1() const
{
	return m_cFlop1;
}

PCard PHoldemFlop::getFlop2() const
{
	return m_cFlop2;
}

PCard PHoldemFlop::getFlop3() const
{
	return m_cFlop3;
}

PPokerObject::PRank PHoldemFlop::getLowestMissingRank()
{
	if (m_cFlop1.getRank() == ACE || m_cFlop2.getRank() == ACE || m_cFlop3.getRank() == ACE)
	{
		if (m_cFlop1.getRank() == KING || m_cFlop2.getRank() == KING || m_cFlop3.getRank() == KING)
		{
			if (m_cFlop1.getRank() == QUEEN || m_cFlop2.getRank() == QUEEN || m_cFlop3.getRank() == QUEEN)
			{
				return JACK;
			}
			return QUEEN;
		}
		return KING;

	}
	return ACE;
}

void PHoldemFlop::DUMP() const
{
	TRACE("FLOP ");
	m_cFlop1.DUMP();
	TRACE(" ");
	m_cFlop2.DUMP();
	TRACE(" ");
	m_cFlop3.DUMP();
}
