// PFPTrips.cpp: implementation of the PFPTrips class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "FlopOdds.h"
#include "PFPTrips.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

PFPTrips::PFPTrips()
{

}

PFPTrips::~PFPTrips()
{

}

PFPTrips::PFPTrips(const PHandsList& cHandsList, const PHoldemFlop& cBoard)
:	PFlopPercentages(cHandsList, cBoard)
{

}

void PFPTrips::calculateFlopPercentages()
{
	ASSERT(getFlop().isTripsFlop());

	PHandsList listQuads = getHandSpread(). removeHands(PHoldemFlop::isQuads, getFlop());
	push_front(PDisplayRowData("Quads", listQuads));

	PHandsList listFush = getHandSpread(). removeHands(PHoldemFlop::isFlush, getFlop());
	push_front(PDisplayRowData("Full Houses", listFush));
	
	PHandsList listTrips = getHandSpread(). removeHands(PHoldemFlop::isTrips, getFlop());
	push_front(PDisplayRowData("Trips", listTrips));
}
