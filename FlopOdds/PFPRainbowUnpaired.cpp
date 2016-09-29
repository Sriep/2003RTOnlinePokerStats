// PFPRainbowUnpaired.cpp: implementation of the PFPRainbowUnpaired class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PFPRainbowUnpaired.h"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

PFPRainbowUnpaired::PFPRainbowUnpaired()
{

}

PFPRainbowUnpaired::~PFPRainbowUnpaired()
{

}

PFPRainbowUnpaired::PFPRainbowUnpaired(const PHandsList& cHandsList, const PHoldemFlop& cBoard)
:	PFlopPercentages(cHandsList, cBoard)
{

}


void PFPRainbowUnpaired::calculateFlopPercentages()
{
	ASSERT(getFlop().isRainbowFlop() && getFlop().isUnPairedFlop());

	PHandsList listGutShots = getHandSpread(). removeHands(PHoldemFlop::isGutShotDraw, getFlop());
	push_front(PDisplayRowData("Gut-shot draws", listGutShots));

	PHandsList listStraightDraws = getHandSpread(). removeHands(PHoldemFlop::isStraightDraw, getFlop());
	push_front(PDisplayRowData("Straight draws", listStraightDraws));
	
	PHandsList listStraights = getHandSpread(). removeHands(PHoldemFlop::isStraight, getFlop());
	push_front(PDisplayRowData("Straights", listStraights));
	
	PHandsList listTrips = getHandSpread(). removeHands(PHoldemFlop::isTrips, getFlop());
	push_front(PDisplayRowData("Trips", listTrips));
	
	PHandsList listTowPairs = getHandSpread(). removeHands(PHoldemFlop::isTwoPair, getFlop());
	push_front(PDisplayRowData("Two Pair", listTowPairs));

	PHandsList listPairs = getHandSpread(). removeHands(PHoldemFlop::isOnePair, getFlop());
	push_front(PDisplayRowData("One Pair", listPairs));

	PHandsList listHighCards = getHandSpread(). removeHands(PHoldemFlop::isHighCard, getFlop());
	push_front(PDisplayRowData("High Card", listHighCards));
   
	PHandsList listHighCardsBest = getHandSpread().removeHandsWithRank(PHoldemFlop::isHighCard, getFlop(), getFlop().getLowestMissingRank());
	CString strHighCard;
	strHighCard.Format("%s High", getFlop().getLowestMissingRank().asString());
	push_back(PDisplayRowData(strHighCard, listHighCardsBest));
	
	PHandsList listHighCardsNotBest = getHandSpread().removeHandsWithRank(PHoldemFlop::isHighCardOrWorse, getFlop(), getFlop().getLowestMissingRank());
	CString strHighCardWorseThan;
	strHighCardWorseThan.Format("< %s High", getFlop().getLowestMissingRank().asString());
	push_back(PDisplayRowData(strHighCardWorseThan, listHighCardsNotBest));
}




