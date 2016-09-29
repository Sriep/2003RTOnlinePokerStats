// HandsMap.cpp: implementation of the HandsMap class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "FlopOdds.h"
#include "HandsMap.h"
#include "PFPRainbowUnpaired.h"
#include "DAPokerStatistics.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

PHandsList::PHandsList()
{
}

PHandsList::~PHandsList()
{

}

void PHandsList::pushBackHands(const CString& strHand)
{
	ASSERT(2 == strHand.GetLength() || 3 == strHand.GetLength() );
	
	if (strHand.GetAt(0) == strHand.GetAt(1))
	{
		pushBackPairs(strHand.GetAt(0));
	}
	else if (2 == strHand.GetLength())
	{
		pushBackOffsuited(strHand.GetAt(0), strHand.GetAt(1));
	}
	else if ('s' == strHand.GetAt(2) || 'S' == strHand.GetAt(2))
	{
		pushBackSuited(strHand.GetAt(0), strHand.GetAt(1));
	}
	else
	{
		ASSERT(FALSE);
		throw ("INVALID HAND");
	}
}

void PHandsList::pushBackPairs(char chCard)
{
	push_back(PHoldemHand(chCard, SPADES, chCard, HEARTS)); 
	push_back(PHoldemHand(chCard, SPADES, chCard, DIAMONDS)); 
	push_back(PHoldemHand(chCard, SPADES, chCard, CLUBS)); 
	push_back(PHoldemHand(chCard, HEARTS, chCard, DIAMONDS)); 
	push_back(PHoldemHand(chCard, HEARTS, chCard, CLUBS)); 
	push_back(PHoldemHand(chCard, DIAMONDS, chCard, CLUBS)); 
}

void PHandsList::pushBackOffsuited(char chCard1, char chCard2)
{
	push_back(PHoldemHand(chCard1, SPADES, chCard2, HEARTS)); 
	push_back(PHoldemHand(chCard1, SPADES, chCard2, DIAMONDS)); 
	push_back(PHoldemHand(chCard1, SPADES, chCard2, CLUBS));
	
	push_back(PHoldemHand(chCard1, HEARTS, chCard2, SPADES)); 
	push_back(PHoldemHand(chCard1, HEARTS, chCard2, DIAMONDS)); 
	push_back(PHoldemHand(chCard1, HEARTS, chCard2, CLUBS)); 

	push_back(PHoldemHand(chCard1, DIAMONDS, chCard2, SPADES)); 
	push_back(PHoldemHand(chCard1, DIAMONDS, chCard2, HEARTS)); 
	push_back(PHoldemHand(chCard1, DIAMONDS, chCard2, CLUBS)); 

	push_back(PHoldemHand(chCard1, CLUBS, chCard2, SPADES)); 
	push_back(PHoldemHand(chCard1, CLUBS, chCard2, HEARTS)); 
	push_back(PHoldemHand(chCard1, CLUBS, chCard2, DIAMONDS)); 
}

void PHandsList::pushBackSuited(char chCard1, char chCard2)
{
	push_back(PHoldemHand(chCard1, SPADES, chCard2, SPADES)); 
	push_back(PHoldemHand(chCard1, HEARTS, chCard2, HEARTS)); 
	push_back(PHoldemHand(chCard1, DIAMONDS, chCard2, DIAMONDS)); 
	push_back(PHoldemHand(chCard1, CLUBS, chCard2, CLUBS)); 
}


PHandsList PHandsList::removeHands(bool fShouldRemove(PHoldemFlop, PHoldemHand), PHoldemFlop flop)
{
	PHandsList listMovedHands;

	PCardList listCardsToRemove;
	listCardsToRemove.push_back(flop.getFlop1());
	listCardsToRemove.push_back(flop.getFlop2());
	listCardsToRemove.push_back(flop.getFlop3());
	removeHandsWithCards(listCardsToRemove);

	HoldemHandIterator iIter;
	iIter = begin();
	int iNumberOfPops = 0;

	while (iIter != end())
	{
		if (fShouldRemove(flop, *iIter))
		{					
			HoldemHandIterator iToMove = iIter;
			iIter++;
			//listMovedHands.push_front(*iToMove);
listMovedHands.push_back(*iToMove);
			ASSERT(FALSE);
			erase(iToMove);
			iNumberOfPops++;
		}
		else
		{
			iIter++;
		}
	}
	return listMovedHands;
}

PHandsList PHandsList::removeHandsWithRank(bool fShouldRemove(PHoldemFlop, PHoldemHand, PPokerObject::PRank), PHoldemFlop flop, PRank rank)
{
	PHandsList listMovedHands;


	HoldemHandIterator iIter;
	iIter = begin();
	int iNumberOfPops = 0;

	while (iIter != end())
	{
		if (fShouldRemove(flop, *iIter, rank))
		{					
			HoldemHandIterator iToMove = iIter;
			iIter++;
			//listMovedHands.push_front(*iToMove);
listMovedHands.push_back(*iToMove);
			ASSERT(FALSE);
			erase(iToMove);
			iNumberOfPops++;
		}
		else
		{
			iIter++;
		}
	}
	return listMovedHands;
}

CString PHandsList::getTitle() const
{
	return m_strTitle;
}

void PHandsList::setTtitle(const CString &strTitle)
{
	m_strTitle = strTitle;
}

void PHandsList::DBWrite()
{
	DAPokerStatistics rsHandsLists;
	try
	{
		rsHandsLists.Open(CRecordset::dynaset, NULL, CRecordset::none);
		int maxKey = 0;
		while (!rsHandsLists.IsEOF())
		{
			maxKey =  __max(maxKey, rsHandsLists.m_ListId);
			if (rsHandsLists.m_Name == m_strTitle)
				rsHandsLists.Delete();
			rsHandsLists.MoveNext();
		}
		maxKey++;

		for ( HoldemHandIterator iIter = begin() ; iIter != end() ; iIter++ )
		{
			rsHandsLists.AddNew();
			rsHandsLists.m_ListId = maxKey;
			rsHandsLists.m_Name = m_strTitle;
			rsHandsLists.m_Card1 = (*iIter).getHighCard().getHashValue();
			rsHandsLists.m_Card2 = (*iIter).getLowCard().getHashValue();
			rsHandsLists.Update();
		}
		rsHandsLists.Close();
	}
	catch (CDBException* pDBExept)
	{
		if (rsHandsLists.IsOpen())
			rsHandsLists.Close();
		pDBExept->ReportError();
	}	
}

void PHandsList::DBRead()
{
	DAPokerStatistics rsHandsLists;
	try
	{
		rsHandsLists.Open(CRecordset::forwardOnly, NULL, CRecordset::readOnly);
		while (!rsHandsLists.IsEOF())
		{
			if (rsHandsLists.m_Name == m_strTitle)
			{
				//push_front( PHoldemHand(PCard(rsHandsLists.m_Card1), PCard(rsHandsLists.m_Card2)) );
				push_back( PHoldemHand(PCard(rsHandsLists.m_Card1), PCard(rsHandsLists.m_Card2)) );
			}
			rsHandsLists.MoveNext();
		}

		rsHandsLists.Close();
	}
	catch (CDBException* pDBExept)
	{
		if (rsHandsLists.IsOpen())
			rsHandsLists.Close();
		pDBExept->ReportError();
	}	
}

int PHandsList::getPercentage() const
{
	ASSERT(getNumHandsInList() == size());
	return (size() * 100) / NUM_HOLDEM_HANDS;
}

int PHandsList::getNumHandsInList() const
{
	int icount = 0;
	for ( ConstHoldemHandIterator iIter = begin() ; iIter != end() ; iIter++ )
	{
		icount++;
	}  
	return icount;
}

PHandsList::PHandsList(CString strTitle)
: m_strTitle(strTitle)
{

}

void PHandsList::FilterCardsInFlop(PHoldemFlop flop)
{
	PCardList listCardsToRemove;
	listCardsToRemove.push_back(flop.getFlop1());
	listCardsToRemove.push_back(flop.getFlop2());
	listCardsToRemove.push_back(flop.getFlop3());
	removeHandsWithCards(listCardsToRemove);
}

void PHandsList::removeHandsWithCards(PCardList listCardsToRemove)
{
	for ( ConstCardListIterator iterCardsToRemove = listCardsToRemove.begin() ;
			iterCardsToRemove != listCardsToRemove.end() ; 
			iterCardsToRemove++ )
	{
		HoldemHandIterator iterThis = begin();
		while (iterThis != end())
		{
			if ((*iterThis).getHighCard() == *iterCardsToRemove || (*iterThis).getLowCard() == *iterCardsToRemove)
			{
				HoldemHandIterator iterDoomed = iterThis;
				iterThis++;
				erase(iterDoomed);
			}
			else
			{
				if (iterThis != end())
					iterThis++;
			}
		}
		
	}
}

void PHandsList::DUMP()
{
	TRACE("HANDS LIST\n");
	for ( ConstHoldemHandIterator iIter = begin() ; iIter != end() ; iIter++ )
	{
		TRACE("   ");
		(*iIter).DUMP();
		TRACE("\n");
	}  
}

