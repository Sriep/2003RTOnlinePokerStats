// PDeck.h: interface for the PDeck class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PDECK_H__5360921A_7D80_4ED7_93D3_387DA9367231__INCLUDED_)
#define AFX_PDECK_H__5360921A_7D80_4ED7_93D3_387DA9367231__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <vector>
#include <list>
#include "PHoldemHandData.h"
#include "PCard.h"

using std::vector;
typedef std::vector<PCard>::iterator CardIterator;
typedef std::vector<PCard>::const_iterator ConstCardIterator;

#define NUM_OF_CUTS 52

class PDeck : public  std::vector <PCard>, PPokerObject
{
public:
	PDeck();
	virtual ~PDeck();
	void DUMP();

	PCard DealCard();
	void ShuffelUp(const std::list <PCard>& excluded);
	void ShuffleUp1();
	void ShuffleUp2();

private:
	bool IsOverlap(PCard card, const std::list <PCard>& excluded);
	void populate();

	CardIterator m_NextCardToDeal;
};

inline PCard PDeck::DealCard()
{
	if (m_NextCardToDeal == end())
	{
		return PCard(1, 0);  
	}
    else
	{
		return *m_NextCardToDeal++;
	}

}
							 
inline void PDeck::ShuffleUp1()
{
	//TRACE("Before shuffle ");
	//DUMP();
	//unsigned int i = (unsigned)time(NULL);
	//TRACE1("Seed %d\n", i);
	//srand(i);

	for ( int iCutCard = 0 ; iCutCard < 52 ; iCutCard++ )
	{
		long iSwapCard = (long)(52 * rand())/((long)RAND_MAX+1);

		ASSERT(52 != iSwapCard);

		//TRACE2("About to Swap %d and %d\n", iCutCard, iSwapCard);
		PCard cCutCard = at(iCutCard);
		PCard cSwapCard = at(iSwapCard);
		//TRACE2("About to Swap %s and %s\n", cCutCard.asString(), cSwapCard.asString());
		at(iCutCard) = cSwapCard;
		at(iSwapCard) = cCutCard;		
		//DUMP();
	}
	//TRACE("After Shuffle ");
	//DUMP();

}

inline void PDeck::ShuffleUp2()
{
	std::list <PCard> startDeck;
	int iPosition = 0;
	for (int iSuit = 1 ; iSuit <= 4 ; iSuit++ )
	{
		for (int iRank = 1 ; iRank <= 13 ; iRank++ )
		{
			PCard cardToAssign = PCard((PRank)iRank, (PSuit)iSuit);
			startDeck.push_back(cardToAssign ); 
			iPosition++;
		}
	}
	clear();
	for ( int card = 51 ; card >= 0 ; card-- )
	{
			//TRACE("Start Deck is: \n");
			//std::list<PCard>::iterator iter2 = startDeck.begin();
			//for (iter2 = startDeck.begin() ; iter2 != startDeck.end() ; iter2++ )
			//{
			//	TRACE((*iter2).asString());
			//	TRACE("\n");
			//}
	
		long swapCard = (long)((card+1) * rand())/(RAND_MAX+1.0);
		//ASSERT(card != swapCard);
		std::list<PCard>::iterator iter = startDeck.begin();
		for ( int count = 0 ; count < swapCard ; count++ )
		{
			iter++;	
		}
		push_back(*iter);
		startDeck.erase(iter);
		//TRACE1("\nAdded card to main deck %d\n", swapCard);
		//DUMP();
	}
	m_NextCardToDeal = begin();
}

inline void PDeck::ShuffelUp(const std::list <PCard>& excluded)
{
	std::list <PCard> startDeck;
	int iDeckSize = 0;
	for (int iSuit = 1 ; iSuit <= 4 ; iSuit++ )
	{
		for (int iRank = 1 ; iRank <= 13 ; iRank++ )
		{
			PCard cardToAssign = PCard((PRank)iRank, (PSuit)iSuit);
			if (!IsOverlap(cardToAssign, excluded))
			{
				startDeck.push_back(cardToAssign ); 
				iDeckSize++;
			}
		}
	}

	clear();
	iDeckSize = startDeck.size();
	for ( int card = iDeckSize ; card > 0 ; card-- )
	{
			//TRACE("Start Deck is: \n");
			//std::list<PCard>::iterator iter2 = startDeck.begin();
			//for (iter2 = startDeck.begin() ; iter2 != startDeck.end() ; iter2++ )
			////{
			//	TRACE((*iter2).asString());
			//	TRACE("\n");
			//}

		//int range = highest_number - lowest_number + 1;
		//return lowest_number + int(range * rand()/(RAND_MAX + 1.0));
	
		long swapCard = (long)((card) * rand())/(RAND_MAX+1.0);
		ASSERT(card != swapCard);
		std::list<PCard>::iterator iter = startDeck.begin();
		for ( int count = 0 ; count < swapCard ; count++ )
		{
			iter++;	
		}
		push_back(*iter);
		startDeck.erase(iter);
		//TRACE1("\nAdded card to main deck %d\n", swapCard);
		//DUMP();
	}
	m_NextCardToDeal = begin();
	//DUMP();
}

inline bool PDeck::IsOverlap(PCard card, const std::list <PCard>& excluded)
{
	for ( std::list<PCard>::const_iterator iter = excluded.begin() ; iter != excluded.end() ; iter++ )
	{
		if (card == *iter)
			return true;
	}
	return false;
}

#endif // !defined(AFX_PDECK_H__5360921A_7D80_4ED7_93D3_387DA9367231__INCLUDED_)
