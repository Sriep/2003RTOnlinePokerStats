// PHandSpread.h: interface for the PHandSpread class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PHANDSPREAD_H__157FA8C4_C370_4953_9D1B_9FE7C659F93D__INCLUDED_)
#define AFX_PHANDSPREAD_H__157FA8C4_C370_4953_9D1B_9FE7C659F93D__INCLUDED_

#include "PHoldemHandActions.h"
#include "PPokerObject.h"
#include "PHandSpread.h"
#include "HoldemStartHand.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define NUM_PAIRS 13
#define NUM_ZERO_GAPPERS 12
#define NUM_ONE_GAPPERS 11
#define NUM_TWO_GAPPERS 10
#define NUM_THREE_GAPPERS 9
#define NUM_ACE_MANY_GAPPERS 8
#define NUM_KING_MANY_GAPPERS 7
#define NUM_QUEEN_MANY_GAPPERS 6
#define NUM_JACK_MANY_GAPPERS 5
#define NUM_TEN_MANY_GAPPERS 4
#define NUM_NINE_MANY_GAPPERS 3
#define NUM_EIGHT_MANY_GAPPERS 2
#define NUM_SEVEN_MANY_GAPPERS 1
#define NUM_POSITIONS 10


class PHandSpread : public PPokerObject  
{
public:
	PHandSpread();
	PHandSpread(const CString& strNick, int iPokerSite, int Variant, CTime tDate);
	virtual ~PHandSpread();
	void InitiliseArrays();

	void PopulateSpread();
private:
	void GetHandsFromDatabase();
	void GetHandsFromDatabase(PPlayerAction cAction, const CString& strProcdure);
	void SplitCallAndRaises();
	void AddHand(int iFirstRank,  int iFirstSuit,int iSecondRank, int iSecondSuit, int iPosition, PPlayerAction cAction );
	
	void DoFolds();
	void AddNonFoldsFrom(const PHoldemStartHand& cHand, int iPosition);
	void AddNonFoldAt(const PHoldemStartHand& cHand, int iPosition);
	bool DoFolds(const PHoldemStartHand& cHand, int iPosition);
	bool DoFoldsPairs(const PHoldemStartHand& cHand, int iPosition);
	bool DoFoldsUnsuitedManyGapper(const PHoldemStartHand& cHand, int iPosition);
	bool DoFoldsUnsuitedThreeGapper(const PHoldemStartHand& cHand, int iPosition);
	bool DoFoldsUnsuitedTwoGapper(const PHoldemStartHand& cHand, int iPosition);
	bool DoFoldsUnsuitedOneGapper(const PHoldemStartHand& cHand, int iPosition);
	bool DoFoldsUnsuitedZeroGapper(const PHoldemStartHand& cHand, int iPosition);
	bool DoFoldsSuitedManyGapper(const PHoldemStartHand& cHand, int iPosition);
	bool DoFoldsSuitedThreeGapper(const PHoldemStartHand& cHand, int iPosition);
	bool DoFoldsSuitedTwoGapper(const PHoldemStartHand& cHand, int iPosition);
	bool DoFoldsSuitedOneGapper(const PHoldemStartHand& cHand, int iPosition);
	bool DoFoldsSuitedZeroGapper(const PHoldemStartHand& cHand, int iPosition);

	bool SetToZeroFolds(PPokerObject::PRank rLow, PPokerObject::PRank RHigh, bool bSuited, int iPos);

	void DUMP() const;	  
	void DUMP_POS(int iPosition) const;
	static const int TOTAL_PERMUTATIONS;

private:
	PHoldemHandActions	m_aHands [PPokerObject::PRank::RANK_NUM_RANKS] [PPokerObject::PRank::RANK_NUM_RANKS] [2] [NUM_POSITIONS + 1];
	CString m_strNick;
	int m_iPokerSite;
	int m_Variant;
	CTime m_tDate;
	int m_iTotalFolds;
	int m_iTotalCalls;
	int m_iTotalRaises;
	int m_iNumFolds [NUM_POSITIONS + 1];
	int m_iNumCalls [NUM_POSITIONS + 1];
	int m_iNumRaises [NUM_POSITIONS + 1];

	int m_iNumHandsSeen [NUM_POSITIONS + 1];
};

#endif // !defined(AFX_PHANDSPREAD_H__157FA8C4_C370_4953_9D1B_9FE7C659F93D__INCLUDED_)
