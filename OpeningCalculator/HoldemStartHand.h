// HoldemStartHand.h: interface for the HoldemStartHand class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_HOLDEMSTARTHAND_H__ADC9B77A_A403_403C_A490_C65C3008B28E__INCLUDED_)
#define AFX_HOLDEMSTARTHAND_H__ADC9B77A_A403_403C_A490_C65C3008B28E__INCLUDED_

#include "PPokerObject.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class PHoldemStartHand : public PPokerObject 
{
public:
	PHoldemStartHand();
	PHoldemStartHand(PRank rHighCard, PRank rLowCard, bool bSuited);

	virtual ~PHoldemStartHand();
	PRank GetHighRank() const;
	PRank GetLowRank() const;
	bool IsSuited() const;

	bool operator!=(const PHoldemStartHand& cHoldemStartHand) const;
	bool operator==(const PHoldemStartHand& cHoldemStartHand) const;
	bool operator<(const PHoldemStartHand& cHoldemStartHand) const;
	//bool operator<=(const PHoldemStartHand& cHoldemStartHand) const;
	bool operator>(const PHoldemStartHand& cHoldemStartHand) const;
	//bool operator>=(const PHoldemStartHand& cHoldemStartHand) const;
	PHoldemStartHand& operator=(const PHoldemStartHand& cHoldemStartHand);
	void DUMP() const;

	bool IsPair() const;
	bool IsUnsuitedManyGapper() const;
	bool IsUnsuitedThreeGapper() const;
	bool IsUnsuitedTwoGapper() const;
	bool IsUnsuitedOneGapper() const;
	bool IsUnsuitedZeroGapper() const;
	bool IsSuitedManyGapper() const;
	bool IsSuitedThreeGapper() const;
	bool IsSuitedTwoGapper() const;
	bool IsSuitedOneGapper() const;
	bool IsSuitedZeroGapper() const;

private:
	PRank m_rHighRank;
	PRank m_rLowRank;
	bool m_bSuited;
	int pctOpenRaised;
	int pctOpenCalled;
	int pctOpenCalledPos [10];
	int pctOpenRaisedPos [10];
};

#endif // !defined(AFX_HOLDEMSTARTHAND_H__ADC9B77A_A403_403C_A490_C65C3008B28E__INCLUDED_)
