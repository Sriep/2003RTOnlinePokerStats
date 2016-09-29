// PCalculateStartEVs.cpp: implementation of the PCalculateStartEVs class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "flopodds.h"
#include "PCalculateStartEVs.h"
#include "HandsMap.h"
#include <stdlib.h> 
#include <fstream.h>

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

PCalculateStartEVs::PCalculateStartEVs()
{

}

PCalculateStartEVs::~PCalculateStartEVs()
{

}

void PCalculateStartEVs::calculateEVs(PHandsListArray pHandsListArray, CHandEVDialog& cViewWindow, int iNumTests)
{
	pHandsListArray.Get(0).DUMP();
	PHoldemHandList holdemHands;
	holdemHands.populate();	
	unsigned int seed = (unsigned)time(NULL);
	TRACE1("Seed %d\n", seed);
	srand(seed);

	cViewWindow.m_ProgressCtrl.SetRange(0, 100);
	cViewWindow.m_ProgressCtrl.SetPos(0);

	for (long iSimsDone = 0 ; iSimsDone < iNumTests ; iSimsDone++ )
	{
		
		cViewWindow.m_ProgressCtrl.SetPos((short)((long)(iSimsDone*100)/iNumTests));
		cViewWindow.UpdateWindow();
		//TRACE1("Sims done %d\n", iSimsDone);


		//PHoldemHand pRandomSample = pHandsListArray.Get(0).GetRandomHand();
		pHandsListArray.SetRandomSample();
		PGameBoard cBoard;
		cBoard.setRandom(pHandsListArray.GetCardsInSample());
		//TRACE("Comparing board ");
		//cBoard.DUMP();
		//TRACE("\n");
		PPokerHand phBestFromRanSample = pHandsListArray.FindBestHand(cBoard);
		
		HoldemHandDataIterator iDataIter;
		for ( iDataIter = holdemHands.begin() ; iDataIter != holdemHands.end() ; iDataIter++ )
		{
			//TRACE(" Compair hand : ");
			//(*iDataIter).DUMP();
			//TRACE("\n");
			if (cBoard.consistant(*iDataIter))
			{
				//TRACE(" Comparing board ");
				//cBoard.DUMP();
				//TRACE("\n");
				PPokerHand phLeftBest = cBoard.GetBestHand(*iDataIter);
				//TRACE(" Comparing best hands ");
				//phLeftBest.DUMP();
				//TRACE("   Random sample-> ");
				//phRanSample.DUMP();
				//TRACE("\n");
				if (phLeftBest == phBestFromRanSample)
				{
					(*iDataIter).draw();
					//(*iDataIter).addHandTypeDraw(phLeftBest.handType());
					//TRACE(" tie\n");
				}
				else if  (phLeftBest > phBestFromRanSample)
				{
					(*iDataIter).won();
					//(*iDataIter).addHandTypeWin(phLeftBest.handType());
					//TRACE(" won\n");
				}
				else
				{
					(*iDataIter).loss();
					//(*iDataIter).addHandTypeLoss(phLeftBest.handType());
					//TRACE(" Random sample won\n");
				}
				//TRACE("\n");
				//(*iDataIter).addHandType(phLeftBest.handType());
			}
			else
			{
				int i=5	;
			}
		}
	}
	WriteOutResults(holdemHands);
	cViewWindow.m_ProgressCtrl.SetPos(iNumTests);
	cViewWindow.UpdateWindow();
} 

/*
void PCalculateStartEVs::calculateEVs(PHandsList* pHandsList, CHandEVDialog& cViewWindow)
{
	pHandsList[0].DUMP();
	PHoldemHandList holdemHands;
	holdemHands.populate();	
	unsigned int seed = (unsigned)time(NULL);
	TRACE1("Seed %d\n", seed);
	srand(seed);

	cViewWindow.m_ProgressCtrl.SetRange(0, 100);
	cViewWindow.m_ProgressCtrl.SetPos(0);

	for (long iSimsDone = 0 ; iSimsDone < NUM_MONTE_CARLO_RUNS ; iSimsDone++ )
	{
		
		cViewWindow.m_ProgressCtrl.SetPos((short)((long)(iSimsDone*100)/NUM_MONTE_CARLO_RUNS));
		cViewWindow.UpdateWindow();
		//TRACE1("Sims done %d\n", iSimsDone);

		PGameBoard cBoard;
		cBoard.setRandom();
		//TRACE("Comparing board ");
		//cBoard.DUMP();
		//TRACE("\n");

		PHoldemHand pRandomSample = pHandsList[0].GetRandomHand();
		//TRACE(" RAndom card selected ");
		//pRandomSample.DUMP();
		//TRACE("\n"); 
		PPokerHand phRanSample = cBoard.GetBestHand(pRandomSample);
		
		HoldemHandDataIterator iDataIter;
		for ( iDataIter = holdemHands.begin() ; iDataIter != holdemHands.end() ; iDataIter++ )
		{
			//TRACE(" Compair hand : ");
			//(*iDataIter).DUMP();
			//TRACE("\n");
			if (consistant(cBoard, *iDataIter, pRandomSample))
			{
				//TRACE(" Comparing board ");
				//cBoard.DUMP();
				//TRACE("\n");
				PPokerHand phLeftBest = cBoard.GetBestHand(*iDataIter);
				//TRACE(" Comparing best hands ");
				//phLeftBest.DUMP();
				//TRACE("   Random sample-> ");
				//phRanSample.DUMP();
				//TRACE("\n");
				if (phLeftBest == phRanSample)
				{
					(*iDataIter).draw();
					//(*iDataIter).addHandTypeDraw(phLeftBest.handType());
					//TRACE(" tie\n");
				}
				else if  (phLeftBest > phRanSample)
				{
					(*iDataIter).won();
					//(*iDataIter).addHandTypeWin(phLeftBest.handType());
					//TRACE(" won\n");
				}
				else
				{
					(*iDataIter).loss();
					//(*iDataIter).addHandTypeLoss(phLeftBest.handType());
					//TRACE(" Random sample won\n");
				}
				//TRACE("\n");
				//(*iDataIter).addHandType(phLeftBest.handType());
			}
			else
			{
				int i=5	;
			}
		}
	}
	WriteOutResults(holdemHands);
	cViewWindow.m_ProgressCtrl.SetPos(NUM_MONTE_CARLO_RUNS);
	cViewWindow.UpdateWindow();
} */

void  PCalculateStartEVs::WriteOutResults(const PHoldemHandList& results)
{
	CString strFileName;
	strFileName.Format("C:\\Poker\\Software\\EVOut.txt");
	ofstream fOutFile(strFileName, ios::app , filebuf::sh_read || filebuf::sh_write);

	ConstHoldemHandDataIterator iDataIter;
	iDataIter =  results.begin();
	for ( iDataIter = results.begin() ; iDataIter != results.end() ; iDataIter++ )
	{
		CString strOutString;
		strOutString.Format("%s\t%f\n", (*iDataIter).asString(), (*iDataIter).EV());
		fOutFile.write(strOutString.GetBuffer(1), strOutString.GetLength());
		/*
		strOutString.Format("Total\t%f", (*iDataIter).getPercetage(HAND_TYPE_HIGH_CARD));
		fOutFile.write(strOutString.GetBuffer(1), strOutString.GetLength());
		strOutString.Format("\t%f", (*iDataIter).getPercetage(HAND_TYPE_ONE_PAIR));
		fOutFile.write(strOutString.GetBuffer(1), strOutString.GetLength());
		strOutString.Format("\t%f", (*iDataIter).getPercetage(HAND_TYPE_TWO_PAIR));
		fOutFile.write(strOutString.GetBuffer(1), strOutString.GetLength());
		strOutString.Format("\t%f", (*iDataIter).getPercetage(HAND_TYPE_TRIPS));
		fOutFile.write(strOutString.GetBuffer(1), strOutString.GetLength());
		strOutString.Format("\t%f", (*iDataIter).getPercetage(HAND_TYPE_STRAIGHT));
		fOutFile.write(strOutString.GetBuffer(1), strOutString.GetLength());
		strOutString.Format("\t%f", (*iDataIter).getPercetage(HAND_TYPE_FLUSH));
		fOutFile.write(strOutString.GetBuffer(1), strOutString.GetLength());
		strOutString.Format("\t%f", (*iDataIter).getPercetage(HAND_TYPE_FULL_HOUSE));
		fOutFile.write(strOutString.GetBuffer(1), strOutString.GetLength());
		strOutString.Format("\t%f", (*iDataIter).getPercetage(HAND_TYPE_QUADS));
		fOutFile.write(strOutString.GetBuffer(1), strOutString.GetLength());
		strOutString.Format("\t%f\n", (*iDataIter).getPercetage(HAND_TYPE_STRAIGHT_FLUSH));
		fOutFile.write(strOutString.GetBuffer(1), strOutString.GetLength());

		strOutString.Format("Wins\t%f", (*iDataIter).getPercetageWin(HAND_TYPE_HIGH_CARD));
		fOutFile.write(strOutString.GetBuffer(1), strOutString.GetLength());
		strOutString.Format("\t%f", (*iDataIter).getPercetageWin(HAND_TYPE_ONE_PAIR));
		fOutFile.write(strOutString.GetBuffer(1), strOutString.GetLength());
		strOutString.Format("\t%f", (*iDataIter).getPercetageWin(HAND_TYPE_TWO_PAIR));
		fOutFile.write(strOutString.GetBuffer(1), strOutString.GetLength());
		strOutString.Format("\t%f", (*iDataIter).getPercetageWin(HAND_TYPE_TRIPS));
		fOutFile.write(strOutString.GetBuffer(1), strOutString.GetLength());
		strOutString.Format("\t%f", (*iDataIter).getPercetageWin(HAND_TYPE_STRAIGHT));
		fOutFile.write(strOutString.GetBuffer(1), strOutString.GetLength());
		strOutString.Format("\t%f", (*iDataIter).getPercetageWin(HAND_TYPE_FLUSH));
		fOutFile.write(strOutString.GetBuffer(1), strOutString.GetLength());
		strOutString.Format("\t%f", (*iDataIter).getPercetageWin(HAND_TYPE_FULL_HOUSE));
		fOutFile.write(strOutString.GetBuffer(1), strOutString.GetLength());
		strOutString.Format("\t%f", (*iDataIter).getPercetageWin(HAND_TYPE_QUADS));
		fOutFile.write(strOutString.GetBuffer(1), strOutString.GetLength());
		strOutString.Format("\t%f\n", (*iDataIter).getPercetageWin(HAND_TYPE_STRAIGHT_FLUSH));

		fOutFile.write(strOutString.GetBuffer(1), strOutString.GetLength());
		strOutString.Format("Losses\t%f", (*iDataIter).getPercetageLoss(HAND_TYPE_HIGH_CARD));
		fOutFile.write(strOutString.GetBuffer(1), strOutString.GetLength());
		strOutString.Format("\t%f", (*iDataIter).getPercetageLoss(HAND_TYPE_ONE_PAIR));
		fOutFile.write(strOutString.GetBuffer(1), strOutString.GetLength());
		strOutString.Format("\t%f", (*iDataIter).getPercetageLoss(HAND_TYPE_TWO_PAIR));
		fOutFile.write(strOutString.GetBuffer(1), strOutString.GetLength());
		strOutString.Format("\t%f", (*iDataIter).getPercetageLoss(HAND_TYPE_TRIPS));
		fOutFile.write(strOutString.GetBuffer(1), strOutString.GetLength());
		strOutString.Format("\t%f", (*iDataIter).getPercetageLoss(HAND_TYPE_STRAIGHT));
		fOutFile.write(strOutString.GetBuffer(1), strOutString.GetLength());
		strOutString.Format("\t%f", (*iDataIter).getPercetageLoss(HAND_TYPE_FLUSH));
		fOutFile.write(strOutString.GetBuffer(1), strOutString.GetLength());
		strOutString.Format("\t%f", (*iDataIter).getPercetageLoss(HAND_TYPE_FULL_HOUSE));
		fOutFile.write(strOutString.GetBuffer(1), strOutString.GetLength());
		strOutString.Format("\t%f", (*iDataIter).getPercetageLoss(HAND_TYPE_QUADS));
		fOutFile.write(strOutString.GetBuffer(1), strOutString.GetLength());
		strOutString.Format("\t%f\n", (*iDataIter).getPercetageLoss(HAND_TYPE_STRAIGHT_FLUSH));

		fOutFile.write(strOutString.GetBuffer(1), strOutString.GetLength());
		strOutString.Format("Draws\t%f", (*iDataIter).getPercetageDraw(HAND_TYPE_HIGH_CARD));
		fOutFile.write(strOutString.GetBuffer(1), strOutString.GetLength());
		strOutString.Format("\t%f", (*iDataIter).getPercetageDraw(HAND_TYPE_ONE_PAIR));
		fOutFile.write(strOutString.GetBuffer(1), strOutString.GetLength());
		strOutString.Format("\t%f", (*iDataIter).getPercetageDraw(HAND_TYPE_TWO_PAIR));
		fOutFile.write(strOutString.GetBuffer(1), strOutString.GetLength());
		strOutString.Format("\t%f", (*iDataIter).getPercetageDraw(HAND_TYPE_TRIPS));
		fOutFile.write(strOutString.GetBuffer(1), strOutString.GetLength());
		strOutString.Format("\t%f", (*iDataIter).getPercetageDraw(HAND_TYPE_STRAIGHT));
		fOutFile.write(strOutString.GetBuffer(1), strOutString.GetLength());
		strOutString.Format("\t%f", (*iDataIter).getPercetageDraw(HAND_TYPE_FLUSH));
		fOutFile.write(strOutString.GetBuffer(1), strOutString.GetLength());
		strOutString.Format("\t%f", (*iDataIter).getPercetageDraw(HAND_TYPE_FULL_HOUSE));
		fOutFile.write(strOutString.GetBuffer(1), strOutString.GetLength());
		strOutString.Format("\t%f", (*iDataIter).getPercetageDraw(HAND_TYPE_QUADS));
		fOutFile.write(strOutString.GetBuffer(1), strOutString.GetLength());
		strOutString.Format("\t%f\n", (*iDataIter).getPercetageDraw(HAND_TYPE_STRAIGHT_FLUSH));
		fOutFile.write(strOutString.GetBuffer(1), strOutString.GetLength());*/
	}

	fOutFile.flush();
	fOutFile.close();
}



