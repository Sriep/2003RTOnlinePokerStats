// PGameBoard.h: interface for the PGameBoard class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PGAMEBOARD_H__3FD0A472_2167_4737_9A5C_1FE83BFC6B98__INCLUDED_)
#define AFX_PGAMEBOARD_H__3FD0A472_2167_4737_9A5C_1FE83BFC6B98__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
//#include "PHoldemHand.h"
#include "PDeck.h"
#include "PPokerHand.h"

class PGameBoard  
{
public:	   
	void setRandom();
	void setRandom(const std::list <PCard>& excluded);
	PGameBoard();
	virtual ~PGameBoard();
	void DUMP() const;
	//bool LhsBeatsRhs(const PHoldemHand& cHand1, const PHoldemHand& cHand2) const;
	//bool Equal(const PHoldemHand& cHand1, const PHoldemHand& cHand2) const;
	PPokerHand GetBestHand(const PHoldemHand& cHand1);
	bool consistant(const PHoldemHand& hand);

	PCard BoardCard1() const;
	PCard BoardCard2() const;
	PCard BoardCard3() const;
	PCard BoardCard4() const;
	PCard BoardCard5() const;

private:
	PCard m_cBoard1;
	PCard m_cBoard2;
	PCard m_cBoard3;
	PCard m_cBoard4;
	PCard m_cBoard5;
	PDeck m_cDeck;
};

inline PCard PGameBoard::BoardCard1() const
{
	return m_cBoard1;
}

inline PCard PGameBoard::BoardCard2() const
{
	return m_cBoard2;
}	

inline PCard PGameBoard::BoardCard3() const
{
	return m_cBoard3;
}	

inline PCard PGameBoard::BoardCard4() const
{
	return m_cBoard4;
} 

inline PCard PGameBoard::BoardCard5() const
{
	return m_cBoard5;
}

inline bool PGameBoard::consistant(const PHoldemHand& hand)
{
	bool bConsistant = true;
	bConsistant &=  m_cBoard1 != hand.getHighCard();
	bConsistant &=  m_cBoard1 != hand.getLowCard();

	bConsistant &=  m_cBoard2 != hand.getHighCard();
	bConsistant &=  m_cBoard2 != hand.getLowCard();

	bConsistant &=  m_cBoard3 != hand.getHighCard();
	bConsistant &=  m_cBoard3 != hand.getLowCard();

	bConsistant &=  m_cBoard4 != hand.getHighCard();
	bConsistant &=  m_cBoard4 != hand.getLowCard();

	bConsistant &=  m_cBoard5 != hand.getHighCard();
	bConsistant &=  m_cBoard5 != hand.getLowCard();

	return bConsistant;
}

inline PPokerHand PGameBoard::GetBestHand(const PHoldemHand& cHand1)
{
	//TRACE("\n");
	//TRACE("Board = ");
	//DUMP();
	//TRACE(" Holdem Hand ");
	//cHand1.DUMP();
	//TRACE("\n");
	PPokerHand pHighestHand(m_cBoard1, m_cBoard2, m_cBoard3, m_cBoard4, m_cBoard5);

	pHighestHand = PPokerHand::maxHand(pHighestHand, PPokerHand(cHand1.getHighCard(), m_cBoard2, m_cBoard3, m_cBoard4, m_cBoard5));
	pHighestHand = PPokerHand::maxHand(pHighestHand, PPokerHand(m_cBoard1, cHand1.getHighCard(), m_cBoard3, m_cBoard4, m_cBoard5));
	pHighestHand = PPokerHand::maxHand(pHighestHand, PPokerHand(m_cBoard1, m_cBoard2, cHand1.getHighCard(), m_cBoard4, m_cBoard5));
	pHighestHand = PPokerHand::maxHand(pHighestHand, PPokerHand(m_cBoard1, m_cBoard2, m_cBoard3, cHand1.getHighCard(),m_cBoard5));
	pHighestHand = PPokerHand::maxHand(pHighestHand, PPokerHand(m_cBoard1,m_cBoard2, m_cBoard3, m_cBoard4, cHand1.getHighCard()));

	pHighestHand = PPokerHand::maxHand(pHighestHand, PPokerHand(cHand1.getLowCard(), m_cBoard2, m_cBoard3, m_cBoard4, m_cBoard5));
	pHighestHand = PPokerHand::maxHand(pHighestHand, PPokerHand(m_cBoard1, cHand1.getLowCard(), m_cBoard3, m_cBoard4, m_cBoard5));
	pHighestHand = PPokerHand::maxHand(pHighestHand, PPokerHand(m_cBoard1, m_cBoard2, cHand1.getLowCard(), m_cBoard4, m_cBoard5));
	pHighestHand = PPokerHand::maxHand(pHighestHand, PPokerHand(m_cBoard1, m_cBoard2, m_cBoard3, cHand1.getLowCard(),m_cBoard5));
	pHighestHand = PPokerHand::maxHand(pHighestHand, PPokerHand(m_cBoard1,m_cBoard2, m_cBoard3, m_cBoard4, cHand1.getLowCard()));

	pHighestHand = PPokerHand::maxHand(pHighestHand, PPokerHand(cHand1.getHighCard(), cHand1.getLowCard(), m_cBoard3, m_cBoard4, m_cBoard5));
	pHighestHand = PPokerHand::maxHand(pHighestHand, PPokerHand(cHand1.getHighCard(), m_cBoard2, cHand1.getLowCard(), m_cBoard4, m_cBoard5));
	pHighestHand = PPokerHand::maxHand(pHighestHand, PPokerHand(cHand1.getHighCard(), m_cBoard2, m_cBoard3, cHand1.getLowCard(), m_cBoard5));
	pHighestHand = PPokerHand::maxHand(pHighestHand, PPokerHand(cHand1.getHighCard(), m_cBoard2, m_cBoard3, m_cBoard4, cHand1.getLowCard()));

	pHighestHand = PPokerHand::maxHand(pHighestHand, PPokerHand(m_cBoard1, cHand1.getHighCard(), cHand1.getLowCard(), m_cBoard4, m_cBoard5));
	pHighestHand = PPokerHand::maxHand(pHighestHand, PPokerHand(m_cBoard1, cHand1.getHighCard(), m_cBoard3, cHand1.getLowCard(), m_cBoard5));
	pHighestHand = PPokerHand::maxHand(pHighestHand, PPokerHand(m_cBoard1, cHand1.getHighCard(), m_cBoard3, m_cBoard4, cHand1.getLowCard()));

	pHighestHand = PPokerHand::maxHand(pHighestHand, PPokerHand(m_cBoard1, m_cBoard2,cHand1.getHighCard(), cHand1.getLowCard(), m_cBoard5));
	pHighestHand = PPokerHand::maxHand(pHighestHand, PPokerHand(m_cBoard1, m_cBoard2,cHand1.getHighCard(), m_cBoard4, cHand1.getLowCard()));

	pHighestHand = PPokerHand::maxHand(pHighestHand, PPokerHand(m_cBoard1, m_cBoard2, m_cBoard3, cHand1.getHighCard(), cHand1.getLowCard()));
				
	//TRACE("\n");
	//TRACE("Board = ");
	//DUMP();
	//TRACE(" Holdem Hand ");
	//cHand1.DUMP();
	//TRACE(" Highet Hand ");
	//pHighestHand.DUMP();
	//TRACE("\n");
	
	
	return pHighestHand;	
}
/*
inline bool PGameBoard::LhsBeatsRhs(const PHoldemHand& cHand1, const PHoldemHand& cHand2) const
{
	
	
	return true;
}

inline bool PGameBoard::Equal(const PHoldemHand& cHand1, const PHoldemHand& cHand2)  const
{
	return true;
} */

inline void PGameBoard::setRandom()
{
	m_cDeck.ShuffleUp2();  

	
/*	m_cDeck.ShuffleUp1();
	m_cDeck.ShuffleUp1();
	m_cDeck.ShuffleUp1();
	m_cDeck.ShuffleUp1();
	m_cDeck.ShuffleUp1();
	m_cDeck.ShuffleUp1();
	m_cDeck.ShuffleUp1();  	*/


	m_cBoard1 = m_cDeck.DealCard();
	m_cBoard2 = m_cDeck.DealCard();
	m_cBoard3 = m_cDeck.DealCard();
	m_cBoard4 = m_cDeck.DealCard();
	m_cBoard5 = m_cDeck.DealCard();

	/*ASSERT(	m_cBoard1 != m_cBoard2
			&& m_cBoard1 != m_cBoard3
			&& m_cBoard1 != m_cBoard4
			&& m_cBoard1 != m_cBoard5
			&& m_cBoard2 != m_cBoard3
			&& m_cBoard2 != m_cBoard4
			&& m_cBoard2 != m_cBoard5
			&& m_cBoard3 != m_cBoard4
			&& m_cBoard3 != m_cBoard5
			&& m_cBoard4 != m_cBoard5);
	  */
	//TRACE("Newly delt board \n");
	//DUMP();
}

inline void PGameBoard::setRandom(const std::list <PCard>& excluded)
{
	m_cDeck.ShuffelUp(excluded);  
	m_cBoard1 = m_cDeck.DealCard();
	m_cBoard2 = m_cDeck.DealCard();
	m_cBoard3 = m_cDeck.DealCard();
	m_cBoard4 = m_cDeck.DealCard();
	m_cBoard5 = m_cDeck.DealCard();
}

#endif // !defined(AFX_PGAMEBOARD_H__3FD0A472_2167_4737_9A5C_1FE83BFC6B98__INCLUDED_)
