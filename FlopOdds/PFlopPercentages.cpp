// PFlopPercentages.cpp: implementation of the PFlopPercentages class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PFlopPercentages.h"

#include "FlopOdds.h"
#include "PFPOneSuited.h"
#include "PFPRainbowPaired.h"
#include "PFPRainbowUnpaired.h"
#include "PFPTrips.h"
#include "PFPTwoSuitedPaired.h"
#include "PFPTwoSuitedUnpaired.h"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

PFlopPercentages::PFlopPercentages()
{

}


PFlopPercentages::PFlopPercentages(const PHandsList& cHandsList, const PHoldemFlop& cFlop)
:	m_cHandSpread(cHandsList),
	m_cFlop(cFlop)
{
	m_cHandSpread.FilterCardsInFlop(m_cFlop);
}

PFlopPercentages::~PFlopPercentages()
{

}	 

PFlopPercentages::PFlopPercentages(const PFlopPercentages& cFlopPercentages)
{
	m_cFlop = cFlopPercentages.m_cFlop;
	m_cHandSpread = cFlopPercentages.m_cHandSpread;
	m_cHandSpread.FilterCardsInFlop(m_cFlop);
}	

void PFlopPercentages::setBoard(PHoldemFlop cFlop)
{
	m_cFlop = cFlop;
	m_cHandSpread.FilterCardsInFlop(m_cFlop);
}

PFlopPercentages* PFlopPercentages::calculateFlopPercentages(const PHandsList& cHandsList, const PHoldemFlop& cBoard)
{
	PFlopPercentages* pFlopPercentages;
	if (cBoard.isRainbowFlop() && cBoard.isUnPairedFlop())
	{
		pFlopPercentages = new PFPRainbowUnpaired(cHandsList, cBoard);
	}
	else if (cBoard.isRainbowFlop() && cBoard.isPairedFlop())
	{
		pFlopPercentages = new PFPRainbowPaired(cHandsList, cBoard);
	}
	else if (cBoard.isTripsFlop())
	{
		pFlopPercentages = new PFPTrips(cHandsList, cBoard);
	}
	else if (cBoard.isTwoSuitedFlop() && cBoard.isUnPairedFlop())
	{
		pFlopPercentages = new PFPTwoSuitedUnpaired(cHandsList, cBoard);
	}
	else if (cBoard.isTwoSuitedFlop() && cBoard.isPairedFlop()) 
	{
		pFlopPercentages = new PFPTwoSuitedPaired(cHandsList, cBoard);
	}
	else if (cBoard.isSingleSuitedFlop())
	{
		pFlopPercentages = new PFPSingleSuited(cHandsList, cBoard);
	}
	else
	{
		ASSERT(FALSE);
		return NULL;
	}	
	pFlopPercentages->calculateFlopPercentages();
	return pFlopPercentages;
}

PHandsList PFlopPercentages::getHandSpread() const
{
	return 	m_cHandSpread;
}

PHoldemFlop PFlopPercentages::getFlop() const
{
	return m_cFlop;
}

