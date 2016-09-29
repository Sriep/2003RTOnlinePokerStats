// HandsMap.h: interface for the HandsMap class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_HANDSMAP_H__BE689DD6_8EFD_488C_A0D4_9DCD12034278__INCLUDED_)
#define AFX_HANDSMAP_H__BE689DD6_8EFD_488C_A0D4_9DCD12034278__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#pragma warning( disable : 4786 )
//#include <list>
#include <vector>
#include <list>
#include <algorithm>
#include "PHoldemHand.h"
#include "PHoldemFlop.h"
#include "PCardList.h"


//using std::list;
//typedef std::list<PHoldemHand>::iterator HoldemHandIterator;
//typedef std::list<PHoldemHand>::const_iterator ConstHoldemHandIterator;

//class PHandsList : public std::list <PHoldemHand>, PPokerObject 
using std::vector;
typedef std::vector<PHoldemHand>::iterator HoldemHandIterator;
typedef std::vector<PHoldemHand>::const_iterator ConstHoldemHandIterator;

class PHandsList : public std::vector <PHoldemHand>, PPokerObject 
{
public:
	virtual void DUMP();
	virtual void FilterCardsInFlop(PHoldemFlop flop);
	PHandsList(CString strTitle);
	virtual int getNumHandsInList() const;
	virtual int getPercentage() const;
	virtual void DBRead();
	virtual void DBWrite();
	virtual void setTtitle(const CString& strTitle);
	virtual CString getTitle() const;
	virtual void pushBackHands(const CString& strHand);
	virtual void removeHandsWithCards(PCardList listCardsToRemove);
	PHandsList();
	virtual ~PHandsList();
	PHandsList removeHands(bool fShouldRemove(PHoldemFlop, PHoldemHand), PHoldemFlop flop);
	PHandsList removeHandsWithRank(bool fShouldRemove(PHoldemFlop, PHoldemHand, PPokerObject::PRank), PHoldemFlop flop, PRank rank);
	PHoldemHand GetRandomHand();
	PHoldemHand GetRandomHand(const std::list <PCard>& excluded);
private:
	bool IsOverlap(PHoldemHand hand, const std::list <PCard>& excluded);


	CString m_strTitle;
	void pushBackSuited(char chCard1, char chCard2);
	void pushBackOffsuited(char chCard1, char chCard2);																 
	void pushBackPairs(char chCard);
};

inline PHoldemHand PHandsList::GetRandomHand()
{
	if (0 == size())
	{
		return PHoldemHand();
	}

	long RandNum = rand();
	long iPosRandomCard =  (long)(size() * RandNum)/(long)(RAND_MAX+1);
	ASSERT(iPosRandomCard != size());
	return at(iPosRandomCard);
}

inline PHoldemHand PHandsList::GetRandomHand(const std::list <PCard>& excluded)
{
	PHoldemHand hand = GetRandomHand();
	while (IsOverlap(hand, excluded))
	{
		hand = GetRandomHand();
	}
	return hand;
}

inline bool PHandsList::IsOverlap(PHoldemHand hand, const std::list <PCard>& excluded)
{
	
	for ( std::list<PCard>::const_iterator iter = excluded.begin() ; iter != excluded.end() ; iter++ )
	{
		if (hand.getHighCard() == *iter)
			return true;
		if (hand.getLowCard() == *iter)
			return true;
	}
	return false;
}

#endif // !defined(AFX_HANDSMAP_H__BE689DD6_8EFD_488C_A0D4_9DCD12034278__INCLUDED_)

