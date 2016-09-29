// PCard.cpp: implementation of the PCard class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PCard.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

PCard::PCard()
:	m_rRank(NO_RANK),
	m_sSuit(NO_SUIT)
{

}

PCard::~PCard()
{

}

PCard::PCard(PRank rRank, PSuit sSuit)
:	m_rRank(rRank),
	m_sSuit(sSuit)
{
}

PCard::PCard(unsigned char chRank,unsigned char chSuit)
:	m_rRank(PPokerObject::PRank::charToRank(chRank)), 
	m_sSuit(PPokerObject::PSuit::charToSuit(chSuit))
{
}






int PCard::getHashValue()  const
{
	return m_sSuit.getHashValue() * PPokerObject::PRank::RANK::RANK_NUM_RANKS	+  m_rRank.getHashValue();
}

PCard::PCard(int iHashValue)
:	m_rRank(iHashValue % PPokerObject::PRank::RANK::RANK_NUM_RANKS),
	m_sSuit(iHashValue / PPokerObject::PRank::RANK::RANK_NUM_RANKS)
{
}

PPokerObject::PSuit PCard::getSuit() const 
{
	return m_sSuit;
}

PPokerObject::PRank PCard::getRank() const 
{
	return m_rRank;
}

void PCard::DUMP() const
{
	m_rRank.DUMP();
	m_sSuit.DUMP();
}
