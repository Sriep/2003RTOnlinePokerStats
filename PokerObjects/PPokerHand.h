// PPokerHand.h: interface for the PPokerHand class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(PPokerHand_H__INCLUDED_)
#define PPokerHand_H__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <vector>
#include <algorithm>
#include "PPokerObject.h"
#include "PCard.h"	
#include "PRank.h"	
#include "PPokerHand.h"

enum HAND_TYPE
{
	HAND_TYPE_NONE = -1,
	HAND_TYPE_HIGH_CARD = 0,
	HAND_TYPE_ONE_PAIR,
	HAND_TYPE_TWO_PAIR,
	HAND_TYPE_TRIPS,
	HAND_TYPE_STRAIGHT,
	HAND_TYPE_FLUSH,
	HAND_TYPE_FULL_HOUSE,
	HAND_TYPE_QUADS,
	HAND_TYPE_STRAIGHT_FLUSH,
	HAND_TYPE_NUM_HAND_TYPES,
};


class PPokerHand : public  std::vector <PCard>, PPokerObject 

{
public:
	virtual bool isHighCard() const;
	virtual bool isOnePair() const;
	virtual bool isTwoPair() const;
	virtual bool isTrips() const;
	virtual bool isStraight() const;
	virtual bool isFlush() const;
	virtual bool isFullHouse() const;
	virtual bool isQuads() const;
	virtual bool isStraightFlush() const;
	virtual bool isHighCard(PRank rRank) const;
	virtual bool isHighCardOrWorse(PRank rRank) const;
	virtual bool isRun() const;
	virtual bool isOneSuited() const;
	PPokerHand(PCard card1, PCard card2, PCard card3, PCard card4, PCard card5);
	PPokerHand();					 
	virtual ~PPokerHand();
	bool operator!=(const PPokerHand& pokerHand) const;
	bool operator==(const PPokerHand& pokerHand) const;
	bool operator<(const PPokerHand& pokerHand) const;
	bool operator<=(const PPokerHand& pokerHand) const;
	bool operator>(const PPokerHand& pokerHand) const;
	bool operator>=(const PPokerHand& pokerHand) const;
	PPokerHand& operator=(const PPokerHand& pokerHand);
	static PPokerHand maxHand(const PPokerHand& pHand1, const PPokerHand& pHand2);
	HAND_TYPE handType() const;

	void DUMP() const;
private:
	void Clear();
	PRank thirdNonPair() const;
	PRank secondNonPair() const;				
	PRank lowPair() const;
	PRank highTrips() const;
	PRank pairInFullHouse() const;
	PRank highPair() const;			  
	PRank highestNonPair() const;
	//bool lessThanHighCardCheck(const PPokerHand& pokerHand) const;
	//bool lessThanOnePairCheck(const PPokerHand& pokerHand) const;
	//bool lessThanTwoPairCheck(const PPokerHand& pokerHand) const;
	//bool lessThanTripsCheck(const PPokerHand& pokerHand) const;
	//bool lessThanFullHouseCheck(const PPokerHand& pokerHand) const;
	//bool lessThanQuadsCheck(const PPokerHand& pokerHand) const;
	void CalculateHandType();
	CString PokerHandTypeAsString() const;


	HAND_TYPE m_eHandType;
	int m_Rank[5];
};

inline HAND_TYPE PPokerHand::handType() const
{
	return m_eHandType;
}


inline PPokerHand PPokerHand::maxHand(const PPokerHand& pHand1, const PPokerHand& pHand2)
{
	if (pHand1 > pHand2)
	{
		//pHand1.DUMP();
		return pHand1;
	} 
	else 
	{
		//pHand2.DUMP();
		return pHand2;
	}
}


inline bool PPokerHand::isFlush()  const
{
	ASSERT(size() ==  NUMM_CARDS_POKER_HAND);

	return isOneSuited() && !isRun();
}


inline bool PPokerHand::isStraight()  const
{
	ASSERT(size() ==  NUMM_CARDS_POKER_HAND);

	return isRun() && !isOneSuited();
}

inline bool PPokerHand::isRun() const
{
	ASSERT(size() ==  NUMM_CARDS_POKER_HAND);

	if (at(0).getRank() == PPokerObject::TWO
		&& at(1).getRank() == PPokerObject::THREE
		&& at(2).getRank() == PPokerObject::FOUR
		&& at(3).getRank() == PPokerObject::FIVE 
		&& at(4).getRank() == PPokerObject::ACE )
	{
		return true;
	}
	else
	{
		return (at(0).getRank() - at(1).getRank() == -1)
			&& (at(1).getRank() - at(2).getRank() == -1)
			&& (at(2).getRank() - at(3).getRank() == -1)
			&& (at(3).getRank() - at(4).getRank() == -1);
	}
}

inline bool PPokerHand::isOneSuited() const
{
	ASSERT(size() ==  NUMM_CARDS_POKER_HAND);

	return at(0).getSuit() == at(1).getSuit()
		&& at(1).getSuit() == at(2).getSuit() 
		&& at(2).getSuit() == at(3).getSuit()
		&& at(3).getSuit() == at(4).getSuit();
}

inline bool PPokerHand::isTrips()  const
{	/*
	if (at(0).getRank() == at(1).getRank())
	{
		return at(0).getRank() == at(2).getRank() && at(2).getRank() != at(3).getRank() && at(3).getRank() != at(4).getRank();
	}
	if (at(1).getRank() == at(2).getRank())
	{
		return at(2).getRank() == at(3).getRank() && at(3).getRank() != at(4).getRank();
	}
	if (at(2).getRank() == at(3).getRank())
	{
		return at(3).getRank() == at(4).getRank();
	}
	return false;*/
	if (at(0).getRank() == at(1).getRank())
	{
		return at(0).getRank() == at(2).getRank();
	}
	if (at(1).getRank() == at(2).getRank())
	{
		return at(2).getRank() == at(3).getRank() ;
	}
	if (at(2).getRank() == at(3).getRank())
	{
		return at(3).getRank() == at(4).getRank();
	}
	return false;

}

inline bool PPokerHand::isTwoPair() const
{
	if (at(0).getRank() == at(1).getRank())
	{
		if (at(1).getRank() == at(2).getRank())
			return false;
		if (at(2).getRank() == at(3).getRank())
			return at(3).getRank() != at(4).getRank();
		else
			return at(3).getRank() == at(4).getRank();
	}
	if (at(1).getRank() == at(2).getRank())
	{
		return at(2).getRank() != at(3).getRank() &&  at(3).getRank() == at(4).getRank();
	}
	return false;
}

inline bool PPokerHand::isOnePair() const
{
	if (at(0).getRank() == at(1).getRank())
	{
		return at(1).getRank() != at(2).getRank() && at(2).getRank() != at(3).getRank() && at(3).getRank() != at(4).getRank();
	}
	if (at(1).getRank() == at(2).getRank())
	{
		return at(2).getRank() != at(3).getRank() && at(3).getRank() != at(4).getRank();
	}
	if (at(2).getRank() == at(3).getRank())
	{
		return at(3).getRank() != at(4).getRank();
	}
	return at(3).getRank() == at(4).getRank();
}

inline bool PPokerHand::isHighCard() const
{
	return at(0).getRank() != at(1).getRank()
		&& at(1).getRank() != at(2).getRank() 
		&& at(2).getRank() != at(3).getRank() 
		&& at(3).getRank() != at(4).getRank()
		&& !isOneSuited() && !isRun();
}

inline bool PPokerHand::isHighCard(PRank rRank) const
{
	return isHighCard() && at(4).getRank() == rRank;
}

inline bool PPokerHand::isHighCardOrWorse(PRank rRank) const
{
	return isHighCard() && at(4).getRank() < rRank;
}

inline bool PPokerHand::isFullHouse() const
{
	if (at(0).getRank() == at(1).getRank())
	{
		if (at(0).getRank() == at(2).getRank())
			return at(2).getRank() != at(3).getRank() && at(3).getRank() == at(4).getRank();
		else 
			return at(2).getRank() == at(3).getRank() && at(3).getRank() == at(4).getRank();
	}
	return false;
}

inline bool PPokerHand::isQuads() const
{
	if (at(0).getRank() == at(1).getRank())
		return at(1).getRank() == at(2).getRank() && at(2).getRank() == at(3).getRank() && at(3).getRank() != at(4).getRank();
	else 
		return at(1).getRank() == at(2).getRank() && at(2).getRank() == at(3).getRank() && at(3).getRank() == at(4).getRank();
}

inline bool PPokerHand::isStraightFlush() const
{
	return isRun() && isOneSuited();
}
/*
inline bool PPokerHand::operator!=(const PPokerHand& pokerHand) const
{
	return !(*this == pokerHand);
}

inline bool PPokerHand::operator==(const PPokerHand& pokerHand) const
{
	if (at(0).getSuit()	== at(1).getSuit() 
		&& at(0).getSuit()	== at(2).getSuit() 
		&& at(0).getSuit()	== at(3).getSuit() 
		&& at(0).getSuit()	== at(4).getSuit())
	{
		if ( !(pokerHand.at(0).getSuit() == pokerHand.at(1).getSuit() 
				&& pokerHand.at(0).getSuit() == pokerHand.at(2).getSuit() 
				&& pokerHand.at(0).getSuit() == pokerHand.at(3).getSuit() 
				&& pokerHand.at(0).getSuit() == pokerHand.at(4).getSuit()) )
		{
			return false;
		}
	}

	return at(0).getRank() == pokerHand.at(0).getRank()
		&& at(1).getRank() == pokerHand.at(1).getRank() 
		&& at(2).getRank() == pokerHand.at(2).getRank() 
		&& at(3).getRank() == pokerHand.at(3).getRank()
		&& at(4).getRank() == pokerHand.at(4).getRank();
}

inline PPokerHand& PPokerHand::operator=(const PPokerHand& pokerHand)
{
	//TRACE("\n ME ");
	//DUMP();
	//TRACE(" being copied ino me ");
	//pokerHand.DUMP();
	//TRACE("\n");
   	Clear();
	at(0) = pokerHand.at(0);
	at(1) = pokerHand.at(1);
	at(2) = pokerHand.at(2); 
	at(3) = pokerHand.at(3);
	at(4) = pokerHand.at(4);
	std::sort(begin(), end());	//lowest = at(0) to hightest = at(4)
	//TRACE("I am now ");
	//DUMP();
	//TRACE("\n");
	return *this;
}


inline bool PPokerHand::operator<=(const PPokerHand& pokerHand) const	
{
	return !(pokerHand < *this);
}

inline bool PPokerHand::operator>(const PPokerHand& pokerHand) const  
{
	 //bool bHigher =  pokerHand < *this;
	 //TRACE(" Higher Hand : ");
	 //if	(bHigher)
	 //{
		 //DUMP();
	 //}
	 //else
	 //{
		//pokerHand.DUMP();
	 //}
	 //return bHigher;
	
	return pokerHand < *this;
}

inline bool PPokerHand::operator>=(const PPokerHand& pokerHand) const 
{
	return !(*this < pokerHand);;
}

inline bool PPokerHand::operator<(const PPokerHand& pokerHand) const	
{
	//TRACE("\n Comparing ");
	//DUMP();
	//TRACE(" and ");
	//pokerHand.DUMP();
	//TRACE("\n");

	if (isHighCard())
	{
		return lessThanHighCardCheck(pokerHand)	;
	}
	else if (pokerHand.isHighCard())
		return false;
		

	if (isOnePair())
	{
		return lessThanOnePairCheck(pokerHand);
	}
	else if (pokerHand.isOnePair())
		return false;

	if (isTwoPair())
	{
		return lessThanTwoPairCheck(pokerHand);
	}
	else if (pokerHand.isTwoPair())
		return false;

	if (isTrips())
	{
		return lessThanTripsCheck(pokerHand);
	}
	else if (pokerHand.isTrips())
		return false;

	if (isStraight())
	{
		if (pokerHand.isStraight())
			return at(4).getRank() < pokerHand.at(4).getRank();
		else
			return true;
	}
	else if (pokerHand.isStraight())
		return false;

	if (isFlush())
	{
		if (pokerHand.isFlush())
			return lessThanHighCardCheck(pokerHand)	;
		else
			return false;
	}
	else if (pokerHand.isFlush())
		return false;

	if (isFullHouse())
	{
		return lessThanFullHouseCheck(pokerHand);
	}
	else if (pokerHand.isFullHouse())
		return false;

	if (isQuads())
	{
		return lessThanQuadsCheck(pokerHand);
	}
	else if (pokerHand.isQuads())
		return false;

	ASSERT(isStraightFlush());
	ASSERT(pokerHand.isStraightFlush());
	return at(4).getRank() < pokerHand.at(4).getRank();
}

inline bool PPokerHand::lessThanHighCardCheck(const PPokerHand& pokerHand) const
{
	if (pokerHand.isHighCard())
	{
		if (at(4).getRank() !=	 pokerHand.at(4).getRank())
			return at(4).getRank() < pokerHand.at(4).getRank();
		else
		{
			if (at(3).getRank() != pokerHand.at(3).getRank())
				return at(3).getRank() < pokerHand.at(3).getRank();
			else
			{
				if (at(2).getRank() != pokerHand.at(2).getRank())
					return at(2).getRank() < pokerHand.at(2).getRank();
				else
				{
					if (at(1).getRank() != pokerHand.at(1).getRank())
						return at(1).getRank() < pokerHand.at(1).getRank();
					else
						return at(0).getRank() < pokerHand.at(0).getRank();
				}
			}
		}
	}
	return true;
}

inline bool PPokerHand::lessThanOnePairCheck(const PPokerHand& pokerHand) const
{
	if (pokerHand.isOnePair())
	{
		if (highPair() == pokerHand.highPair())
		{
			if (highestNonPair() == pokerHand.highestNonPair())
			{
				if (secondNonPair() == pokerHand.secondNonPair())
					return thirdNonPair() < pokerHand.thirdNonPair();
				else
					return secondNonPair() < pokerHand.secondNonPair();
			}
			else
				return highestNonPair() < pokerHand.highestNonPair();
		}			
		else
			return highPair() < pokerHand.highPair();

	}
	return true;
}

inline bool PPokerHand::lessThanTwoPairCheck(const PPokerHand& pokerHand) const
{
	if (pokerHand.isTwoPair())
	{
		if (highPair() == pokerHand.highPair())
		{
			if (lowPair() == pokerHand.lowPair())
				return highestNonPair() < pokerHand.highestNonPair();
			else
				return lowPair() < pokerHand.lowPair();
		}			
		else
			return highPair() < pokerHand.highPair();
	}
	return true;
}

inline bool PPokerHand::lessThanTripsCheck(const PPokerHand& pokerHand) const
{
	if (pokerHand.isTrips())
	{
		if (highTrips() == pokerHand.highTrips())
		{
			if (highestNonPair() == pokerHand.highestNonPair())
				return secondNonPair() < pokerHand.secondNonPair();
			else
				return highestNonPair() < pokerHand.highestNonPair();
		}			
		else
			return highTrips() < pokerHand.highTrips();
	}
	return true;
}

inline bool PPokerHand::lessThanFullHouseCheck(const PPokerHand& pokerHand) const
{
	if (pokerHand.isFullHouse())
	{
		if (highTrips() == pokerHand.highTrips())
		{
			return pairInFullHouse() < pokerHand.pairInFullHouse();
			//	return secondNonPair() < pokerHand.secondNonPair();
			//else
			//	return highestNonPair() < pokerHand.highestNonPair();
		}			
		else
			return highTrips() < pokerHand.highTrips();
	}
	return true;
}

inline bool PPokerHand::lessThanQuadsCheck(const PPokerHand& pokerHand) const
{
	if (pokerHand.isQuads())
	{
		if (highTrips() == pokerHand.highTrips())
		{
			return highestNonPair() < pokerHand.highestNonPair();
		}			
		else
			return highTrips() < pokerHand.highTrips();
	}
	return true;
}
*/
inline PPokerObject::PRank PPokerHand::highPair() const
{
	if (at(4).getRank() == at(3).getRank())
		return at(4).getRank();
	if (at(3).getRank() == at(2).getRank())
		return at(3).getRank();
	if (at(2).getRank() == at(1).getRank())
		return at(2).getRank();
	if (at(1).getRank() == at(0).getRank())
		return at(1).getRank();
	return PRank(NO_RANK);
} 

inline PPokerObject::PRank PPokerHand::pairInFullHouse() const
{
	PRank tripCard = highTrips();
	if (at(4).getRank() == tripCard)
		return at(0).getRank();
	else
		return at(4).getRank();
}

inline PPokerObject::PRank PPokerHand::highTrips() const
{
	if (at(2).getRank() == at(3).getRank() && at(3).getRank() == at(4).getRank())
		return at(2).getRank();
	if (at(1).getRank() == at(2).getRank() && at(2).getRank() == at(3).getRank())
		return at(1).getRank();
	if (at(0).getRank() == at(1).getRank() && at(1).getRank() == at(2).getRank())
		return at(0).getRank();
	return PRank(NO_RANK);
}

inline PPokerObject::PRank PPokerHand::lowPair() const
{
	if (at(4).getRank() == at(3).getRank())
	{
		ASSERT(at(3).getRank() != at(2).getRank());
		if (at(2).getRank() == at(1).getRank())
			return at(2).getRank();
	}
	else
	{
		ASSERT(at(2).getRank() == at(3).getRank());
	}
	ASSERT(at(0).getRank() == at(1).getRank());
	return at(0).getRank();
}

inline PPokerObject::PRank PPokerHand::highestNonPair() const
{
	if (at(4).getRank() != at(3).getRank())
	{
		return at(4).getRank();
	}
	if (at(3).getRank() == at(2).getRank()) 
	{
		if (at(1).getRank() == at(2).getRank())
		{
			ASSERT(at(0).getRank() != at(1).getRank());
			return at(0).getRank();   
		}
		else
		{
			//ASSERT(at(1).getRank() != at(0).getRank());
			return at(1).getRank();   
		}
	}
	if (at(2).getRank() != at(1).getRank())
	{
		return at(2).getRank();
	}
	//ASSERT(at(1).getRank() != at(0).getRank());
	return at(0).getRank(); 
}



inline PPokerObject::PRank PPokerHand::secondNonPair() const
{
	if (at(4).getRank() != at(3).getRank())
	{
		if (at(3).getRank() != at(2).getRank())
			return at(3).getRank();
		else
			return at(1).getRank(); // assume one pair
	}
	if (at(3).getRank() == at(2).getRank()) 
	{
		return at(0).getRank(); // assume trips
	}
	return at(1).getRank(); // assume one pair
}

inline PPokerObject::PRank PPokerHand::thirdNonPair() const
{
	if (at(4).getRank() != at(3).getRank())
	{
		if (at(3).getRank() == at(2).getRank())	// assume one pair
			return at(0).getRank();
		else
		{
			if (at(2).getRank() == at(1).getRank())	
				return at(0).getRank();
			else
				return at(2).getRank();
		}
	}
	ASSERT(at(0).getRank() != at(1).getRank());
	ASSERT(at(1).getRank() != at(2).getRank());
	ASSERT(at(2).getRank() != at(3).getRank());
	return at(0).getRank(); // assume one pair

}


inline void PPokerHand::Clear()
{
	for ( int i = 0 ; i < 5 ; i++ )
	{
		m_Rank[i] = 0;; 
	}
	m_eHandType = HAND_TYPE_NONE;
}

inline CString PPokerHand::PokerHandTypeAsString()	const
{  
	switch (m_eHandType)
	{	
		case HAND_TYPE_NONE  :
			return CString("None");
		case HAND_TYPE_HIGH_CARD :
			return CString("High Card");
		case HAND_TYPE_ONE_PAIR :
			return CString("One Pair");
		case HAND_TYPE_TWO_PAIR :
			return CString("Two Pair");
		case HAND_TYPE_TRIPS :
			return CString("Trips");
		case HAND_TYPE_STRAIGHT :
			return CString("Striaght");
		case HAND_TYPE_FLUSH :
			return CString("Flush");
		case HAND_TYPE_FULL_HOUSE :
			return CString("Full House");
		case HAND_TYPE_QUADS :
			return CString("Quads");
		case HAND_TYPE_STRAIGHT_FLUSH :
			return CString("Striaght Flush");
		case HAND_TYPE_NUM_HAND_TYPES :
			return CString("None");
		default :
			ASSERT(FALSE);
			return CString("Error");
	}
}

inline bool PPokerHand::operator!=(const PPokerHand& pokerHand) const
{
	return !(*this == pokerHand);
}

inline bool PPokerHand::operator==(const PPokerHand& pokerHand) const
{
	return 	m_eHandType == pokerHand.m_eHandType
			&& m_Rank[4] == pokerHand.m_Rank[4]
			&& m_Rank[3] == pokerHand.m_Rank[3]
			&& m_Rank[2] == pokerHand.m_Rank[2]
			&& m_Rank[1] == pokerHand.m_Rank[1]
			&& m_Rank[0] == pokerHand.m_Rank[0];
}

inline PPokerHand& PPokerHand::operator=(const PPokerHand& pokerHand)
{
	//TRACE("\n ME ");
	//DUMP();
	//TRACE(" being copied ino me ");
	//pokerHand.DUMP();
	//TRACE("\n");
	at(0) = pokerHand.at(0);
	at(1) = pokerHand.at(1);
	at(2) = pokerHand.at(2); 
	at(3) = pokerHand.at(3);
	at(4) = pokerHand.at(4);
	std::sort(begin(), end());	//lowest = at(0) to hightest = at(4)
	//TRACE("I am now ");
	//DUMP();
	//TRACE("\n");
	m_eHandType = pokerHand.m_eHandType;
	m_Rank[4] = pokerHand.m_Rank[4];
	m_Rank[3] = pokerHand.m_Rank[3];
	m_Rank[2] = pokerHand.m_Rank[2];
	m_Rank[1] = pokerHand.m_Rank[1];
	m_Rank[0] = pokerHand.m_Rank[0];

	return *this;
}


inline bool PPokerHand::operator<=(const PPokerHand& pokerHand) const	
{
	return !(pokerHand < *this);
}

inline bool PPokerHand::operator>(const PPokerHand& pokerHand) const  
{
	 //bool bHigher =  pokerHand < *this;
	 //TRACE(" Higher Hand : ");
	 //if	(bHigher)
	 //{
		 //DUMP();
	 //}
	 //else
	 //{
		//pokerHand.DUMP();
	 //}
	 //return bHigher;
	
	return pokerHand < *this;
}

inline bool PPokerHand::operator>=(const PPokerHand& pokerHand) const 
{
	return !(*this < pokerHand);;
}

inline bool PPokerHand::operator<(const PPokerHand& pokerHand) const	
{
	//if (HAND_TYPE_NONE  == m_eHandType)
	//{
	//	CalculateHandType();
	//}
	//TRACE("\n Comparing ");
	//DUMP();
	//TRACE(" and ");
	//pokerHand.DUMP();
	//TRACE("\n");
	if (m_eHandType < pokerHand.m_eHandType)
	{
		return true;
	}
	else if (m_eHandType == pokerHand.m_eHandType)
	{
		if (m_Rank[4] < pokerHand.m_Rank[4])
		{
			return true;
		}
		else if (m_Rank[4] == pokerHand.m_Rank[4])
		{
			if (m_Rank[3] < pokerHand.m_Rank[3])
			{
				return true;
			}
			else if (m_Rank[3] == pokerHand.m_Rank[3])
			{
				if (m_Rank[2] < pokerHand.m_Rank[2])
				{
					return true;
				}
				else if (m_Rank[2] == pokerHand.m_Rank[2])
				{
					if (m_Rank[1] < pokerHand.m_Rank[1])
					{
						return true;
					}
					else if (m_Rank[1] == pokerHand.m_Rank[1])
					{
						if (m_Rank[0] < pokerHand.m_Rank[0])
						{
							return true;
						}
					}
				}
			}
		}
	}
	return false;

}

#endif // !defined(PPokerHand_H__INCLUDED_)
