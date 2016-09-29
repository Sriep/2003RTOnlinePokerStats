// PCard.h: interface for the PCard class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PCARD_H__E1F518B7_B650_4BFC_A656_4A7F763ACCD7__INCLUDED_)
#define AFX_PCARD_H__E1F518B7_B650_4BFC_A656_4A7F763ACCD7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "PPokerObject.h"

	class PCard : public PPokerObject  
{
public:
	virtual void DUMP() const;
	PCard(int iHashValue);
	virtual int getHashValue() const;
	PCard(PRank rRank, PSuit sSuit);
	PCard(unsigned char chRank, unsigned char chSuit);
	CString asString();

	PSuit getSuit() const; 
	PRank getRank() const;
	PCard();
	virtual ~PCard();
	bool operator!=(const PCard& card) const;
	bool operator==(const PCard& card) const;
	bool operator<(const PCard& card) const;
	bool operator<=(const PCard& card) const;
	bool operator>(const PCard& card) const;
	bool operator>=(const PCard& card) const;
	PCard& operator=(const PCard& card);
private:
	PRank m_rRank;
	PSuit m_sSuit;
};

inline 	CString PCard::asString()
{
   return m_rRank.asString() + m_sSuit.asString();
}


inline bool PCard::operator!=(const PCard& card) const
{
	return m_rRank != card.m_rRank || m_sSuit != card.m_sSuit;
}

inline bool PCard::operator==(const PCard& card) const
{
	return m_rRank == card.m_rRank && m_sSuit == card.m_sSuit;
}

inline PCard& PCard::operator=(const PCard& card)
{
	m_rRank = card.m_rRank;
	m_sSuit = card.m_sSuit;
	return *this;
}

inline bool PCard::operator<(const PCard& card) const	
{
	if (m_rRank == card.m_rRank)
		return m_sSuit < card.m_sSuit;

	return m_rRank < card.m_rRank;
}

inline bool PCard::operator<=(const PCard& card) const	
{
	if (m_rRank == card.m_rRank)
		return m_sSuit <= card.m_sSuit;

	return m_rRank <= card.m_rRank;
}

inline bool PCard::operator>(const PCard& card) const  
{
	if (m_rRank == card.m_rRank)
		return m_sSuit > card.m_sSuit;

	return m_rRank > card.m_rRank;
}

inline bool PCard::operator>=(const PCard& card) const 
{
	if (m_rRank == card.m_rRank)
		return m_sSuit >= card.m_sSuit;

	return m_rRank >= card.m_rRank;
}


#endif // !defined(AFX_PCARD_H__E1F518B7_B650_4BFC_A656_4A7F763ACCD7__INCLUDED_)
