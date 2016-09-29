// PCalculateStartEVs.h: interface for the PCalculateStartEVs class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PCALCULATESTARTEVS_H__8C0CD0CC_3546_407E_9F86_C88595155D98__INCLUDED_)
#define AFX_PCALCULATESTARTEVS_H__8C0CD0CC_3546_407E_9F86_C88595155D98__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "HoldemHandList.h"
#include "PHandsListList.h"
#include "PGameBoard.h"
#include "HandEVDialog.h"

#define NUM_MONTE_CARLO_RUNS 100000
#define OUT_FILE_NAME "MC Enumeration out File.txt"
class PHandsList;

class PCalculateStartEVs  
{
public:
	PCalculateStartEVs();
	virtual ~PCalculateStartEVs();

	void calculateEVs(PHandsListArray pHandsListArray, CHandEVDialog& cViewWindow, int iNumTests);
	void WriteOutResults(const PHoldemHandList& results);
	bool consistant(const PGameBoard& cBooard, const PHoldemHand& cHand1, const PHoldemHand& cHand2) const;
};

inline bool PCalculateStartEVs::consistant(const PGameBoard& cBooard, const PHoldemHand& cHand1, const PHoldemHand& cHand2)	const
{
	bool bConsistant = true;
	bConsistant &= cBooard.BoardCard1() != cHand1.getHighCard();
	bConsistant &=  cBooard.BoardCard1() != cHand1.getLowCard();
	bConsistant &=  cBooard.BoardCard1() != cHand2.getHighCard();
	bConsistant &=  cBooard.BoardCard1() != cHand2.getLowCard();

	bConsistant &=  cBooard.BoardCard2() != cHand1.getHighCard();
	bConsistant &=  cBooard.BoardCard2() != cHand1.getLowCard();
	bConsistant &=  cBooard.BoardCard2() != cHand2.getHighCard();
	bConsistant &=  cBooard.BoardCard2() != cHand2.getLowCard();

	bConsistant &=  cBooard.BoardCard3() != cHand1.getHighCard();
	bConsistant &=  cBooard.BoardCard3() != cHand1.getLowCard();
	bConsistant &=  cBooard.BoardCard3() != cHand2.getHighCard();
	bConsistant &=  cBooard.BoardCard3() != cHand2.getLowCard();

	bConsistant &=  cBooard.BoardCard4() != cHand1.getHighCard();
	bConsistant &=  cBooard.BoardCard4() != cHand1.getLowCard();
	bConsistant &=  cBooard.BoardCard4() != cHand2.getHighCard();
	bConsistant &=  cBooard.BoardCard4() != cHand2.getLowCard();

	bConsistant &=  cBooard.BoardCard5() != cHand1.getHighCard();
	bConsistant &=  cBooard.BoardCard5() != cHand1.getLowCard();
	bConsistant &=  cBooard.BoardCard5() != cHand2.getHighCard();
	bConsistant &=  cBooard.BoardCard5() != cHand2.getLowCard();

	bConsistant &=  cHand1.getHighCard() != cHand2.getHighCard();
	bConsistant &=  cHand1.getHighCard() != cHand2.getLowCard();
	bConsistant &=  cHand1.getLowCard() != cHand2.getHighCard();
	bConsistant &=  cHand1.getLowCard() != cHand2.getLowCard();
	return bConsistant;
}

#endif // !defined(AFX_PCALCULATESTARTEVS_H__8C0CD0CC_3546_407E_9F86_C88595155D98__INCLUDED_)
									  
