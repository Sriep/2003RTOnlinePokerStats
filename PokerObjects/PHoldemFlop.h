// PHoldemFlop.h: interface for the PHoldemFlop class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PHoldemFlop_H__0E657AB1_9632_4EC6_8B3A_99F76D1469C5__INCLUDED_)
#define AFX_PHoldemFlop_H__0E657AB1_9632_4EC6_8B3A_99F76D1469C5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "PPokerObject.h"
#include "PCard.h"	// Added by ClassView
#include "PHoldemHand.h"
#include "PRank.h"	// Added by ClassView

class PHoldemFlop : public PPokerObject  
{
public:
	virtual void DUMP() const;
	virtual PRank getLowestMissingRank();
	static bool isHighCard(PHoldemFlop flop, PHoldemHand cHand);
	static bool isOnePair(PHoldemFlop flop, PHoldemHand cHand);
	static bool isTwoPair(PHoldemFlop flop, PHoldemHand cHand);
	static bool isTrips(PHoldemFlop flop, PHoldemHand cHand);
	static bool isStraight(PHoldemFlop flop, PHoldemHand cHand);
	static bool isFlush(PHoldemFlop flop, PHoldemHand cHand);
	static bool isFullHouse(PHoldemFlop flop, PHoldemHand cHand) ;
	static bool isQuads(PHoldemFlop flop, PHoldemHand cHand);
	static bool isStraightFlush(PHoldemFlop flop, PHoldemHand cHand);

	static bool isFlushDraw(PHoldemFlop flop, PHoldemHand cHand);
	static bool isStraightDraw(PHoldemFlop flop, PHoldemHand cHand);
	static bool isGutShotDraw(PHoldemFlop flop, PHoldemHand cHand);
	static bool isHighCard(PHoldemFlop flop, PHoldemHand cHand, PRank rRank);
	static bool isHighCardOrWorse(PHoldemFlop flop, PHoldemHand cHand, PRank rRank);


	PHoldemFlop(const PHoldemFlop& cBoard);
	virtual void setBoard(PCard cFlop1, PCard cFlop2, PCard cFlop3);
	PHoldemFlop(PCard cFlop1, PCard cFlop2, PCard cFlop3);
	PHoldemFlop();
	virtual ~PHoldemFlop();
	PCard getFlop1() const;
	PCard getFlop2() const;
	PCard getFlop3() const;

	virtual bool isGutShotFlop() const;
	virtual bool isTwoWayStraightDrawFlop() const;
	virtual bool isStraightFlop() const;
	virtual bool isUnPairedFlop() const;
	virtual bool isTripsFlop() const;
	virtual bool isRainbowFlop() const;
	virtual bool isTwoSuitedFlop() const;
	virtual bool isSingleSuitedFlop() const;
	virtual bool isPairedFlop() const;
private:
	virtual void checkValid();
	
	PCard m_cFlop3;
	PCard m_cFlop2;
	PCard m_cFlop1;
};

#endif // !defined(AFX_PHoldemFlop_H__0E657AB1_9632_4EC6_8B3A_99F76D1469C5__INCLUDED_)
