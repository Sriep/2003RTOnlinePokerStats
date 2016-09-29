// PHandSpread.cpp: implementation of the PHandSpread class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "OpeningCalculator.h"
#include "PHandSpread.h"
#include "RSCardsRaised.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

// Data



//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

const int PHandSpread::TOTAL_PERMUTATIONS = 52*51;


PHandSpread::PHandSpread()
:	m_strNick(""), 
	m_iPokerSite(0), 
	m_Variant(0), 
	m_tDate(CTime::GetCurrentTime()),
	m_iTotalFolds(TOTAL_PERMUTATIONS*10),
	m_iTotalCalls(0),
	m_iTotalRaises(0)
{	
	for (int iPos = 0 ; iPos <= NUM_POSITIONS ; iPos++ )
	{
		m_iNumFolds [iPos] = TOTAL_PERMUTATIONS;
		m_iNumCalls [iPos] = 0;
		m_iNumRaises [iPos] = 0;
		m_iNumHandsSeen [iPos] = 0;
	}
}

PHandSpread::~PHandSpread()
{

} 

PHandSpread::PHandSpread(const CString& strNick, int iPokerSite, int iVariant, CTime tDate)
:	m_strNick(strNick), 
	m_iPokerSite(iPokerSite), 
	m_Variant(iVariant), 
	m_tDate(tDate),
	m_iTotalFolds(TOTAL_PERMUTATIONS*10),
	m_iTotalCalls(0),
	m_iTotalRaises(0)
{
	InitiliseArrays();
}

void PHandSpread::InitiliseArrays()
{
	for ( int iPosition = 1 ; iPosition <= NUM_POSITIONS ; iPosition++ )
	{
		for( PRank rRank = TWO 	;  rRank < NUM_RANKS ; ++rRank )
		{
			m_aHands[rRank][rRank][false][iPosition] =	PHoldemHandActions(6);
		}

		for( PRank rHighRank = THREE ; rHighRank < NUM_RANKS ; ++rHighRank )
		{
			for ( PRank rLowRank = TWO ; rLowRank < rHighRank ; ++rLowRank )
			{	
				m_aHands[rHighRank][rLowRank][true][iPosition] = PHoldemHandActions(4);	
				m_aHands[rHighRank][rLowRank][false][iPosition] = PHoldemHandActions(12);	
			}
		}

		m_iNumFolds [iPosition] = TOTAL_PERMUTATIONS;
		m_iNumCalls [iPosition] = 0;
		m_iNumRaises [iPosition] = 0;
		m_iNumHandsSeen [iPosition] = 0;
	}
}

void PHandSpread::PopulateSpread()
{
	GetHandsFromDatabase();
	DoFolds();
	DUMP();
}

void PHandSpread::GetHandsFromDatabase()
{
	GetHandsFromDatabase(RAISE, "sp_preflop_cards_open_raised");
	GetHandsFromDatabase(CALL, "sp_preflop_cards_open_called");
}

void PHandSpread::GetHandsFromDatabase(PPlayerAction cAction, const CString& strProcdure)
{
	RSCardsRaised rsHands;
	CString strSQL;
	strSQL.Format("{Call %s (?, ?)}", strProcdure);

	rsHands.m_iHostParam = m_iPokerSite;
	rsHands.m_strNickParam = m_strNick;
	//rsHands.SetRowsetSize(25);
	TRACE1("About to call stored procedure %s\n", strProcdure);
	if (!rsHands.Open(CRecordset::forwardOnly, strSQL, CRecordset::useMultiRowFetch ))
	{
		throw("Failed to open recordset");
	}
	int i = rsHands.GetRowsFetched();
	while (!rsHands.IsEOF())
	{
		for ( unsigned int iPos = 0 ; iPos < rsHands.GetRowsFetched() ; iPos++ )
		{
			AddHand(*(rsHands.m_pFirst_Card_Rank + iPos),
					*(rsHands.m_pFirst_Card_Suit + iPos),
					*(rsHands.m_pSecond_Card_Rank + iPos), 
					*(rsHands.m_pSecond_Card_Suit + iPos),
					*(rsHands.m_pPosition + iPos),
					cAction);
			m_iNumHandsSeen[*(rsHands.m_pPosition + iPos)] += 1;
		};
		rsHands.MoveNext();
	}
	rsHands.Close();

}

void PHandSpread::SplitCallAndRaises()
{

}

void PHandSpread::AddHand(int iFirstRank,  int iFirstSuit,int iSecondRank, int iSecondSuit, int iPosition, PPlayerAction cAction)
{
	BOOL bSuited = iFirstSuit == iSecondSuit;
	if (iFirstRank > iSecondRank)
	{
		m_aHands[iFirstRank][iSecondRank][bSuited][iPosition].AddAction(cAction);
	}
	else
	{
		m_aHands[iSecondRank][iFirstRank][bSuited][iPosition].AddAction(cAction);
	}

	AddNonFoldsFrom(PHoldemStartHand(iFirstRank, iSecondRank, iFirstSuit == iSecondSuit), iPosition);

	if (iFirstRank == iSecondRank)
	{
		TRACE1("Added a piar of %d ", iFirstRank+1);
	}
	else
	{
		TRACE2("Added hand %d %d ", iFirstRank+1, iSecondRank+1);
		if (bSuited)
		{
			TRACE("suited ");
		}
		else
		{
			TRACE("unsuited ");
		}
	}
	TRACE1(" At position %d\n", iPosition);
}

void PHandSpread::DUMP() const
{
	TRACE("*********************************************************\n");
	TRACE1("Dump of %s \n", m_strNick);
	TRACE1("****** Number of Folds %d *********\n", m_iTotalFolds);
	for ( int iPosition = 1 ; iPosition < NUM_POSITIONS ; iPosition++ )
	{						
		TRACE1("****** Cards seen %d *********\n", m_iNumHandsSeen[iPosition]);
		TRACE2("****** Number of Folds at postion %d now = %d *********\n", iPosition, m_iNumFolds[iPosition]);
		DUMP_POS(iPosition);
		TRACE("\n\n");
	}
	TRACE("*********************************************************\n");
}

void PHandSpread::DUMP_POS(int iPosition) const
{
	TRACE1("Position %d\n", iPosition);
	TRACE("Suited\n");
	TRACE("\t\t\t");
	for( PRank rHighRank = KING	;  rHighRank > NO_RANK ; --rHighRank )
	{
		TRACE1("%s\t\t\t",rHighRank.asString());
	}
	TRACE("\n");

	for(  rHighRank = ACE ; rHighRank > NO_RANK ; --rHighRank )
	{
		TRACE1("%s\t\t\t",rHighRank.asString());
		for( PRank rLowRank = KING	;  rLowRank > NO_RANK ; --rLowRank )
		{
			int iRaises = m_aHands[rHighRank][rLowRank][true][iPosition].GetRaisePerms();
			int iCalls = m_aHands[rHighRank][rLowRank][true][iPosition].GetCallPerms();
			int iFolds = m_aHands[rHighRank][rLowRank][true][iPosition].GetFoldPerms();
			CString strTrace;
			strTrace.Format("r%ds%df%d\t",iRaises, iCalls, iFolds);
			TRACE(strTrace);
			if (strTrace.GetLength() < 9)
			{
				TRACE("\t");
			}
		}
		TRACE("\n");
	}

	TRACE("Unsuited and Pairs\n");
	TRACE("\t\t\t");
	for(  rHighRank = ACE	;  rHighRank > NO_RANK ; --rHighRank )
	{
		TRACE1("%s\t\t\t",rHighRank.asString());
	}
	TRACE("\n");
	for( rHighRank = ACE 	;  rHighRank > NO_RANK ; --rHighRank )
	{
		TRACE1("%s\t\t\t",rHighRank.asString());
		for( PRank rLowRank = ACE ;  rLowRank > NO_RANK ; --rLowRank )
		{
			int iRaises = m_aHands[rHighRank][rLowRank][false][iPosition].GetRaisePerms();
			int iCalls = m_aHands[rHighRank][rLowRank][false][iPosition].GetCallPerms();
			int iFolds = m_aHands[rHighRank][rLowRank][false][iPosition].GetFoldPerms();
			CString strTrace;
			strTrace.Format("r%ds%df%d\t",iRaises, iCalls, iFolds);
			TRACE(strTrace);
			if (strTrace.GetLength() < 9)
			{
				TRACE("\t");
			}
		}
		TRACE("\n");
	}
}


void PHandSpread::DoFolds()
{


}

void PHandSpread::AddNonFoldsFrom(const PHoldemStartHand& cHand, int iPosition)
{
	TRACE("Adding the hand ");
	cHand.DUMP();
	TRACE("\n");
	//TRACE1("****** Number of Folds %d *********\n", m_iTotalFolds);
	if (iPosition > 2)
	{
		for (int iPos = iPosition ; iPos <= NUM_POSITIONS ; iPos++ )
		{
			//DUMP_POS(iPosition);
			//TRACE2("****** Number of Folds at postion %d now = %d *********\n", iPos, m_iNumFolds[iPos]);
			AddNonFoldAt(cHand, iPos);
			//DUMP_POS(iPosition);
			//TRACE("\n");
			//TRACE2("****** Number of Folds at postion %d now = %d *********\n", iPos, m_iNumFolds[iPos]);
		}
	}
	if (iPosition != 2)
	{
		AddNonFoldAt(cHand, 1);
	}
	//TRACE1("****** Number of Folds %d *********\n", m_iTotalFolds);
	//AddNonFoldAt(cHand, 2);

}


void PHandSpread::AddNonFoldAt(const PHoldemStartHand& cHand, int iPosition)
{
	if (cHand.IsPair())
	{
		DoFoldsPairs(cHand, iPosition);
	}
	else if (cHand.IsSuitedZeroGapper())
	{
		DoFoldsSuitedZeroGapper(cHand, iPosition);
	}
	else if (cHand.IsSuitedOneGapper())
	{
		DoFoldsSuitedOneGapper(cHand, iPosition);
	}
	else if (cHand.IsSuitedTwoGapper())
	{
		DoFoldsSuitedTwoGapper(cHand, iPosition);
	}
	else if (cHand.IsSuitedThreeGapper())
	{
		DoFoldsSuitedThreeGapper(cHand, iPosition);
	}
	else if (cHand.IsSuitedManyGapper())
	{
		DoFoldsSuitedManyGapper(cHand, iPosition);
	}
	else if (cHand.IsUnsuitedZeroGapper())
	{
		DoFoldsUnsuitedZeroGapper(cHand, iPosition);
	}
	else if (cHand.IsUnsuitedOneGapper())
	{
		DoFoldsUnsuitedOneGapper(cHand, iPosition);
	}
	else if (cHand.IsUnsuitedTwoGapper())
	{
		DoFoldsUnsuitedTwoGapper(cHand, iPosition);
	}
	else if (cHand.IsUnsuitedThreeGapper())
	{
		DoFoldsUnsuitedThreeGapper(cHand, iPosition);
	}
	else if (cHand.IsUnsuitedManyGapper())
	{
		DoFoldsUnsuitedManyGapper(cHand, iPosition);
	}
	else
	{
		ASSERT(FALSE);
	}
}

bool PHandSpread::DoFoldsPairs(const PHoldemStartHand& cHand, int iPosition)
{
	ASSERT(cHand.IsPair());
	for( PRank rRank = cHand.GetHighRank() 	;  rRank < NUM_RANKS ; ++rRank )
	{
		if (!SetToZeroFolds(rRank,rRank,false,iPosition))
		{
			return true;
		}
	}
	return false;
}
	   
bool PHandSpread::DoFoldsUnsuitedManyGapper(const PHoldemStartHand& cHand, int iPosition)
{
	ASSERT(cHand.IsUnsuitedManyGapper());

	for( PRank rHighRank = cHand.GetHighRank() ; rHighRank < NUM_RANKS ; ++rHighRank )
	{
		for( PRank rLowRank = cHand.GetLowRank() ; rLowRank < NUM_RANKS ; ++rLowRank )
		{
			if (!SetToZeroFolds(rHighRank,rLowRank,true,iPosition))
			{
				return true;
			}
		}
	}

	PHoldemStartHand cSuitedManyGapper(cHand.GetHighRank(), cHand.GetLowRank(), true);
	return DoFoldsSuitedManyGapper(cSuitedManyGapper, iPosition);
}

bool PHandSpread::DoFoldsUnsuitedThreeGapper(const PHoldemStartHand& cHand, int iPosition)
{
	ASSERT(cHand.IsUnsuitedThreeGapper());

	for( PRank rRank = cHand.GetHighRank() ; rRank < NUM_RANKS ; ++rRank )
	{
		PRank rLow(rRank);
		rLow -= 4;
		if (!SetToZeroFolds(rRank,rLow,true,iPosition))
		{
			return true;
		}
	}

	for( rRank = cHand.GetHighRank() ; rRank < NUM_RANKS ; ++rRank )
	{
		PRank rLow(rRank);
		rLow -= 4;
		if (!SetToZeroFolds(rRank,rLow,true,iPosition))
		{
			return true;
		}
	}

	PHoldemStartHand cUnsuitedTwoGapper(cHand.GetHighRank(), cHand.GetHighRank() + 3, false);
	return DoFoldsUnsuitedTwoGapper(cUnsuitedTwoGapper, iPosition);
}


bool PHandSpread::DoFoldsUnsuitedTwoGapper(const PHoldemStartHand& cHand, int iPosition)
{
	ASSERT(cHand.IsUnsuitedTwoGapper());

	for( PRank rRank = cHand.GetHighRank() ; rRank < NUM_RANKS ; ++rRank )
	{
		PRank rLow(rRank);
		rLow -= 3;
		if (!SetToZeroFolds(rRank,rLow,true,iPosition))
		{
			return true;
		}
	}

	for( rRank = cHand.GetHighRank() ; rRank < NUM_RANKS ; ++rRank )
	{
		PRank rLow(rRank);
		rLow -= 3;
		if (!SetToZeroFolds(rRank,rLow,true,iPosition))
		{
			return true;
		}
	}

	PHoldemStartHand cUnsuitedOneGapper(cHand.GetHighRank(), cHand.GetHighRank() + 2, false);
	return DoFoldsUnsuitedOneGapper(cUnsuitedOneGapper, iPosition);
}

bool PHandSpread::DoFoldsUnsuitedOneGapper(const PHoldemStartHand& cHand, int iPosition)
{
	ASSERT(cHand.IsUnsuitedOneGapper());

	for( PRank rRank = cHand.GetHighRank() ; rRank < NUM_RANKS ; ++rRank )
	{
		PRank rLow(rRank);
		rLow -= 2;
		if (!SetToZeroFolds(rRank,rLow,true,iPosition))
		{
			return true;
		}
	}

	for( rRank = cHand.GetHighRank() ; rRank < NUM_RANKS ; ++rRank )
	{
		PRank rLow(rRank);
		rLow -= 2;
		if (!SetToZeroFolds(rRank,rLow,true,iPosition))
		{
			return true;
		}
	}

	PHoldemStartHand cUnsuitedZeroGapper(cHand.GetHighRank(), cHand.GetHighRank() + 1, false);
	return DoFoldsUnsuitedZeroGapper(cUnsuitedZeroGapper, iPosition);
}

bool PHandSpread::DoFoldsUnsuitedZeroGapper(const PHoldemStartHand& cHand, int iPosition)
{
	ASSERT(cHand.IsUnsuitedZeroGapper());

	for( PRank rRank = cHand.GetHighRank() ; rRank < NUM_RANKS ; ++rRank )
	{
		PRank rLow(rRank);
		rLow -= 1;
		if (!SetToZeroFolds(rRank,rLow,true,iPosition))
		{
			return true;
		}
	}
	PHoldemStartHand cSuitedZeroGapper(cHand.GetHighRank(), cHand.GetLowRank(), true);
	return DoFoldsSuitedZeroGapper(cSuitedZeroGapper, iPosition);
}

bool PHandSpread::DoFoldsSuitedManyGapper(const PHoldemStartHand& cHand, int iPosition)
{
	ASSERT(cHand.IsSuitedManyGapper());

	for( PRank rHighRank = cHand.GetHighRank() ; rHighRank < NUM_RANKS ; ++rHighRank )
	{
		for( PRank rLowRank = cHand.GetLowRank() ; rLowRank < NUM_RANKS ; ++rLowRank )
		{
			if (!SetToZeroFolds(rHighRank,rLowRank,true,iPosition))
			{
				return true;
			}
		}
	}
	return false;
}

bool PHandSpread::DoFoldsSuitedThreeGapper(const PHoldemStartHand& cHand, int iPosition)
{
	ASSERT(cHand.IsSuitedThreeGapper());

	for( PRank rRank = cHand.GetHighRank() ; rRank < NUM_RANKS ; ++rRank )
	{
		PRank rLow(rRank);
		rLow -= 4;
		if (!SetToZeroFolds(rRank,rLow,true,iPosition))
		{
			return true;
		}
	}
	PHoldemStartHand cSuitedTwoGapper(cHand.GetHighRank(), cHand.GetHighRank() + 3, true);
	return DoFoldsSuitedTwoGapper(cSuitedTwoGapper, iPosition);
}

bool PHandSpread::DoFoldsSuitedTwoGapper(const PHoldemStartHand& cHand, int iPosition)
{
	ASSERT(cHand.IsSuitedTwoGapper());

	for( PRank rRank = cHand.GetHighRank() ; rRank < NUM_RANKS ; ++rRank )
	{
		PRank rLow(rRank);
		rLow -= 3;
		if (!SetToZeroFolds(rRank,rLow,true,iPosition))
		{
			return true;
		}
	}
	PHoldemStartHand cSuitedOneGapper(cHand.GetHighRank(), cHand.GetHighRank() + 2, true);
	return DoFoldsSuitedOneGapper(cSuitedOneGapper, iPosition);
}

bool PHandSpread::DoFoldsSuitedOneGapper(const PHoldemStartHand& cHand, int iPosition)
{
	ASSERT(cHand.IsSuitedOneGapper());

	for( PRank rRank = cHand.GetHighRank() ; rRank < NUM_RANKS ; ++rRank )
	{
		PRank rLow(rRank);
		rLow -= 2;
		if (!SetToZeroFolds(rRank,rLow,true,iPosition))
		{
			return true;
		}
	}
	PHoldemStartHand cSuitedZeroGapper(cHand.GetHighRank(), cHand.GetHighRank() + 1, true);
	return DoFoldsSuitedZeroGapper(cSuitedZeroGapper, iPosition);
}

bool PHandSpread::DoFoldsSuitedZeroGapper(const PHoldemStartHand& cHand, int iPosition)
{
	ASSERT(cHand.IsSuitedZeroGapper());

	for( PRank rRank = cHand.GetHighRank() ; rRank < NUM_RANKS ; ++rRank )
	{
		PRank rLow(rRank);
		rLow -= 1;
		if (!SetToZeroFolds(rRank,rLow,true,iPosition))
		{
			return true;
		}
	}
	PHoldemStartHand cPair(cHand.GetLowRank(), cHand.GetLowRank(), false);
	return DoFoldsPairs(cPair, iPosition);
}

bool PHandSpread::SetToZeroFolds(PPokerObject::PRank rHigh, PPokerObject::PRank rLow, bool bSuited, int iPosition)
{
	ASSERT(rHigh >= rLow);
	ASSERT(m_aHands[rHigh][rLow][bSuited][iPosition].GetFoldPerms() >= 0);
	if (m_aHands[rHigh][rLow][bSuited][iPosition].GetFoldPerms() <= 0)
	{
		return false;
	}
	else
	{
		m_iTotalFolds -= m_aHands[rHigh][rLow][bSuited][iPosition].GetFoldPerms();
		m_iNumFolds[iPosition] -= m_aHands[rHigh][rLow][bSuited][iPosition].GetFoldPerms();
		m_aHands[rHigh][rLow][bSuited][iPosition].SetZeroFoldPerms();
		return true;
	}
}




