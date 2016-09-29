// TournamentEquity.cpp: implementation of the CTournamentEquity class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ICMMod.h"
#include "TournamentEquity.h"

#include "Prizes.h"
#include "StackSizes.h"
#include "ICMModDlg.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CTournamentEquity::CTournamentEquity()
{
	resize(20);
}

CTournamentEquity::~CTournamentEquity()
{

}

void CTournamentEquity::CalculateEquity(CStackSizes stackSizes, const CPrizes& prizes)
{
	m_numPlayers = stackSizes.size();
	ASSERT(m_numPlayers<10);
	ASSERT(m_numPlayers>1);

	clear();

	CStackSizes	tempStackSizes = stackSizes;
	IterStackSizes iIter = tempStackSizes.begin();
	for ( int iPlayer = 0 ; iPlayer < m_numPlayers ; iPlayer++ )
	{
		ASSERT(iIter != tempStackSizes.end());
#if defined(_DEBUG)
		//DUMP();
		CString strTemp;
		strTemp.Format("Top level, iIter = %d\n", *iIter);
		TRACE(strTemp);
#endif
		int tempStack = *iIter;
		iIter = tempStackSizes.erase(iIter);
		tempStackSizes.push_front(tempStack);

		PAS_FLOAT fPlayerEquity = GetPlayerEquity(tempStackSizes, prizes,  0, m_numPlayers);

#if defined(_DEBUG)
		//tempStackSizes.DUMP();
		strTemp.Format("Player %d eqity = %f\n", iPlayer, fPlayerEquity);
		TRACE(strTemp);
#endif
		push_back(fPlayerEquity);
	}

}

PAS_FLOAT CTournamentEquity::GetPlayerEquity(CStackSizes stackSizes, const CPrizes& prizes, int iTopPlace, int numPlayersLeft)
{
   	const PAS_FLOAT stackSizePlayer = (PAS_FLOAT)(*(stackSizes.begin()));

	const PAS_FLOAT fTotalChips = (PAS_FLOAT)stackSizes.GetTotalChips();
	const PAS_FLOAT fProbOfWinning = stackSizePlayer / fTotalChips;
	ASSERT(iTopPlace < m_numPlayers+1);
	ASSERT(iTopPlace <= 8);
	//stackSizes.DUMP();
	
	CString strTemp;
	strTemp.Format("level %d stack = %f ProbOfWinning %f\n", iTopPlace, stackSizePlayer, fProbOfWinning);
	TRACE(strTemp);
	
	PAS_FLOAT fTEquity = prizes.at(iTopPlace) * fProbOfWinning;

	if ( 2 == numPlayersLeft)
	{
		fTEquity += prizes.at(iTopPlace+1)*(1-fProbOfWinning);
	}
	else 
	{
		CStackSizes	tempStackSizes = stackSizes;
		IterStackSizes iIter = tempStackSizes.begin();
		iIter++;
		for ( int iPlayer = 1 ; iPlayer < numPlayersLeft ; iPlayer++ )
		{
			ASSERT(iIter != tempStackSizes.end());
			//tempStackSizes.DUMP();

			int tempStack = *iIter;
			iIter = tempStackSizes.erase(iIter);
			//tempStackSizes.DUMP();

			PAS_FLOAT tempEquity = GetPlayerEquity(tempStackSizes, prizes,  iTopPlace+1, numPlayersLeft-1);
			tempEquity *= ((PAS_FLOAT) tempStack) / fTotalChips;
			fTEquity += tempEquity;
			tempStackSizes.push_back(tempStack);

			//tempStackSizes.DUMP();
		}
	}
	return fTEquity;
}

void CTournamentEquity::DUMP()
{
#if defined(_DEBUG)
	TRACE("\nTournamet Equities are: \n");
	CString strTemp;
	for ( IterTournametEquity iIter = begin() ; iIter != end() ; iIter++ )
	{
		strTemp.Format("%.4f", *iIter);
		TRACE(strTemp);
		TRACE("\n");
	}
#endif
}
