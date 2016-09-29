// PHoldemHand.cpp: implementation of the PHoldemHand class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PHoldemHand.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

PHoldemHand::PHoldemHand()
{

}

PHoldemHand::~PHoldemHand()
{

}

PHoldemHand::PHoldemHand(PRank rRank1, PSuit sSuit1, PRank rRank2, PSuit sSuit2)
{
	setHand(rRank1, sSuit1, rRank2, sSuit2);	
}

void PHoldemHand::setHand(PRank rRank1, PSuit sSuit1, PRank rRank2, PSuit sSuit2)
{
	if ( (rRank1 > rRank2) || ((rRank1 == rRank2) && (sSuit2 > sSuit2)) )
	{
		m_cHighCard = PCard(rRank1, sSuit1);
		m_cLowCard = PCard(rRank2, sSuit2);
	}
	else
	{
		m_cHighCard = PCard(rRank2, sSuit2);
		m_cLowCard = PCard(rRank1, sSuit1);
	}
}


PHoldemHand::PHoldemHand(char chRank1, PSuit sSuit1, char chRank2, PSuit sSuit2)
{
	setHand(PRank::charToRank(chRank1), sSuit1, PRank::charToRank(chRank2), sSuit2);	
}


PCard PHoldemHand::getHighCard() const
{
	return m_cHighCard;
}

PCard PHoldemHand::getLowCard()	const
{
	return m_cLowCard;
}

PHoldemHand::PHoldemHand(PCard cardHigh, PCard cardLow)
{
	if ( (cardHigh.getRank() > cardLow.getRank()) || ((cardHigh.getRank() == cardLow.getRank()) && (cardHigh.getSuit() > cardLow.getSuit())) )
	{
		m_cHighCard = cardHigh;
		m_cLowCard = cardLow;
	}
	else
	{
		m_cHighCard = cardHigh;
		m_cLowCard = cardLow;
	}
}

void PHoldemHand::orderCards()
{

}

CString PHoldemHand::asString() const
{
	CString strHandAsString;
	strHandAsString = m_cHighCard.getRank().asString() + m_cLowCard.getRank().asString();
	
	if (m_cHighCard.getSuit() == m_cLowCard.getSuit())
	{
		strHandAsString += "s";
	}
	return strHandAsString;

}

bool PHoldemHand::operator==(const PHoldemHand& cHoldemHand) const
{
	return m_cHighCard == cHoldemHand.m_cHighCard && m_cLowCard == cHoldemHand.m_cLowCard;
}

bool PHoldemHand::operator<(const PHoldemHand& cHoldemHand) const
{
	if (m_cHighCard == cHoldemHand.m_cHighCard)
		return m_cLowCard < cHoldemHand.m_cLowCard;

	return m_cHighCard < cHoldemHand.m_cHighCard;
}

void PHoldemHand::DUMP() const
{
	m_cHighCard.DUMP();
	TRACE(" ");
	m_cLowCard.DUMP();
}
