// PFPTwoSuitedPaired.cpp: implementation of the PFPTwoSuitedPaired class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "FlopOdds.h"
#include "PFPTwoSuitedPaired.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

PFPTwoSuitedPaired::PFPTwoSuitedPaired()
{

}

PFPTwoSuitedPaired::~PFPTwoSuitedPaired()
{

}  

PFPTwoSuitedPaired::PFPTwoSuitedPaired(const PHandsList& cHandsList, const PHoldemFlop& cBoard)
:	PFlopPercentages(cHandsList, cBoard)
{

}


void PFPTwoSuitedPaired::calculateFlopPercentages()
{
	ASSERT(getFlop().isTwoSuitedFlop() && getFlop().isPairedFlop());

	PHandsList listGutShots = getHandSpread(). removeHands(PHoldemFlop::isGutShotDraw, getFlop());
	push_front(PDisplayRowData("Gut-shot draws", listGutShots));

	PHandsList listStraightDraws = getHandSpread(). removeHands(PHoldemFlop::isStraightDraw, getFlop());
	push_front(PDisplayRowData("Straight draws", listStraightDraws));
	
	PHandsList listFlushDraws = getHandSpread(). removeHands(PHoldemFlop::isFlushDraw, getFlop());
	push_front(PDisplayRowData("Flush draws", listFlushDraws));

	PHandsList listQuads = getHandSpread(). removeHands(PHoldemFlop::isQuads, getFlop());
	push_front(PDisplayRowData("Quads", listQuads));

	PHandsList listFullHouse = getHandSpread(). removeHands(PHoldemFlop::isFullHouse, getFlop());
	push_front(PDisplayRowData("Full Houses", listFullHouse));
	
	PHandsList listStraights = getHandSpread(). removeHands(PHoldemFlop::isStraight, getFlop());
	push_front(PDisplayRowData("Straights", listStraights));
	
	PHandsList listTrips = getHandSpread(). removeHands(PHoldemFlop::isTrips, getFlop());
	push_front(PDisplayRowData("Trips", listTrips));
	
	PHandsList listTowPairs = getHandSpread(). removeHands(PHoldemFlop::isTwoPair, getFlop());
	push_front(PDisplayRowData("Two Pair", listTowPairs));

	PHandsList listPairs = getHandSpread(). removeHands(PHoldemFlop::isOnePair, getFlop());
	push_front(PDisplayRowData("One Pair", listPairs));
}
