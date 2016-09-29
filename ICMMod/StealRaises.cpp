// StealRaises.cpp: implementation of the CStealRaises class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include <stdlib.h> 
#include <fstream.h>

#include "ICMMod.h"
#include "StealRaises.h"
#include "TournamentEquity.h"
#include "StackSizeEVTAble.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CStealRaises::CStealRaises()
{

}

CStealRaises::~CStealRaises()
{

}

void CStealRaises::GenerateVrsLargest(CICMModDlg& cViewWindow)
{
 	CTournamentEquity caclulator;

	cViewWindow.m_ctrlProgressBar.SetRange(0, 100);
	cViewWindow.m_ctrlProgressBar.SetPos(0);

	CStackSizes looseStackSizes =  m_stackSizes;
	CStackSizes foldStackSizes =  m_stackSizes;
	CStackSizes winStackSizes =  m_stackSizes;

	CStackSizeEVTAble looseStackEVTable;
	CStackSizeEVTAble foldStackEVTable;
	CStackSizeEVTAble winStackEVTable;

	const int iLargestStack = *(m_stackSizes.GetLargestInTail());
	IterStackSizes largistStackLoose = (looseStackSizes.GetLargestInTail());
	IterStackSizes largistStackFold = (foldStackSizes.GetLargestInTail());
	IterStackSizes largistStackWin = (winStackSizes.GetLargestInTail());

	ASSERT(iLargestStack ==	 *largistStackLoose);
	ASSERT(iLargestStack ==	 *largistStackFold);
	ASSERT(iLargestStack ==	 *largistStackWin);		 
	
	for (int stack1 = m_stack1Min ; stack1 <= m_stack1Max  ; stack1 += m_stack1Step )
	{
		cViewWindow.m_ctrlProgressBar.SetPos((short)((long)(stack1*100)/(m_stack1Max - m_stack1Min)));
		cViewWindow.UpdateWindow();
		
		if (iLargestStack < stack1)
		{
			*looseStackSizes.begin() = stack1 - iLargestStack;
			*largistStackLoose = 2*iLargestStack;

			*foldStackSizes.begin() = stack1;
			*largistStackFold = iLargestStack;

			*winStackSizes.begin() = stack1 + iLargestStack;
			*largistStackWin = 0;
		}
		else
		{
			*looseStackSizes.begin() = 0;
			*largistStackLoose = stack1 + iLargestStack;

			*foldStackSizes.begin() = stack1;
			*largistStackFold = iLargestStack;

			*winStackSizes.begin() = 2*stack1;
			*largistStackWin = iLargestStack - stack1;
		}
		
		caclulator.CalculateEquity(looseStackSizes, m_prizes);
		looseStackEVTable.AddStackEVPair(*looseStackSizes.begin(), *(caclulator.begin()));
		looseStackEVTable.DUMP();

		caclulator.CalculateEquity(foldStackSizes, m_prizes);
		foldStackEVTable.AddStackEVPair(*foldStackSizes.begin(), *(caclulator.begin()));
		foldStackEVTable.DUMP();

		caclulator.CalculateEquity(winStackSizes, m_prizes);
		winStackEVTable.AddStackEVPair(*winStackSizes.begin(), *(caclulator.begin()));
		winStackEVTable.DUMP();
	}  
	WriteVrsLargestToFile(looseStackEVTable, foldStackEVTable, winStackEVTable, "C:\\Poker\\Software\\StackSizeVrsEVOut.txt");
	cViewWindow.m_ctrlProgressBar.SetPos(100);
	cViewWindow.UpdateWindow();
}

void CStealRaises::GenerateVrsSmallist()
{
 	CTournamentEquity caclulator;

	CStackSizes looseStackSizes =  m_stackSizes;
	CStackSizes foldStackSizes =  m_stackSizes;
	CStackSizes winStackSizes =  m_stackSizes;

	CStackSizeEVTAble looseStackEVTable;
	CStackSizeEVTAble foldStackEVTable;
	CStackSizeEVTAble winStackEVTable;

	const int iSmallistStack = *(m_stackSizes.GetSmallistInTail());
	IterStackSizes smallistStackLoose = (looseStackSizes.GetSmallistInTail());
	IterStackSizes smallistStackFold = (foldStackSizes.GetSmallistInTail());
	IterStackSizes smallistStackWin = (winStackSizes.GetSmallistInTail());

	ASSERT(iSmallistStack ==	 *smallistStackLoose);
	ASSERT(iSmallistStack ==	 *smallistStackFold);
	ASSERT(iSmallistStack ==	 *smallistStackWin);		 
	
	for (int stack1 = m_stack1Min ; stack1 <= m_stack1Max  ; stack1 += m_stack1Step )
	{
		if (iSmallistStack < stack1)
		{
			*looseStackSizes.begin() = stack1 - iSmallistStack;
			*smallistStackLoose = 2*iSmallistStack;

			*foldStackSizes.begin() = stack1;
			*smallistStackFold = iSmallistStack;

			*winStackSizes.begin() = stack1 + iSmallistStack;
			*smallistStackWin = 0;
		}
		else
		{
			*looseStackSizes.begin() = 0;
			*smallistStackLoose = stack1 + iSmallistStack;

			*foldStackSizes.begin() = stack1;
			*smallistStackFold = iSmallistStack;

			*winStackSizes.begin() = 2*stack1;
			*smallistStackWin = iSmallistStack - stack1;
		}
		
		caclulator.CalculateEquity(looseStackSizes, m_prizes);
		looseStackEVTable.AddStackEVPair(*looseStackSizes.begin(), *(caclulator.begin()));
		looseStackEVTable.DUMP();

		caclulator.CalculateEquity(foldStackSizes, m_prizes);
		foldStackEVTable.AddStackEVPair(*foldStackSizes.begin(), *(caclulator.begin()));
		foldStackEVTable.DUMP();

		caclulator.CalculateEquity(winStackSizes, m_prizes);
		winStackEVTable.AddStackEVPair(*winStackSizes.begin(), *(caclulator.begin()));
		winStackEVTable.DUMP();
	}  
	WriteVrsSmallistToFile(looseStackEVTable, foldStackEVTable, winStackEVTable, "C:\\Poker\\Software\\StackSizeVrsEVOut.txt");
}


void CStealRaises::GenerateVrsNoOne()
{
	CStackSizes stackSizes =  m_stackSizes;
 	CTournamentEquity caclulator;
	CStackSizeEVTAble stackSizeEVTable;
	
	for (int stack1 = m_stack1Min ; stack1 <= m_stack1Max  ; stack1 += m_stack1Step )
	{
		*(stackSizes.begin())  = stack1;
		//stackSizes.DUMP();

		caclulator.CalculateEquity(stackSizes, m_prizes);
		stackSizeEVTable.AddStackEVPair(stack1, *(caclulator.begin()));
		//stackSizeEVTable.DUMP();
	}  
	WriteVrsNoneToFile(stackSizeEVTable, "C:\\Poker\\Software\\StackSizeVrsEVOut.txt");
} 

void CStealRaises::SetBlindsAntes(int blindsAntes)
{
	 m_blindsAntes = blindsAntes;
}

void CStealRaises::SetPrizes(CPrizes prizes)
{
	 m_prizes = prizes;
}


void CStealRaises::SetStackSizes(CStackSizes stackSizes)
{
	 m_stackSizes = stackSizes;
}


void CStealRaises::SetStack1Max(int stack1Max)
{
	 m_stack1Max = stack1Max;
}


void CStealRaises::SetStack1Step(int stack1Step) 
{
	 m_stack1Step = stack1Step;
}


int CStealRaises::GetStack1Min() const
{
	 return m_stack1Min;
}

int CStealRaises::GetBlindsAntes()	const
{
	 return m_blindsAntes;
}

const CPrizes& CStealRaises::GetPrizes() const
{
	 return m_prizes;
}


const CStackSizes& CStealRaises::GetStackSizes() const
{
	 return m_stackSizes;
}


int CStealRaises::GetStack1Max()   const
{
	 return m_stack1Max;
}


int CStealRaises::GetStack1Step()  const
{
	 return m_stack1Step;
}

void CStealRaises::SetStack1Min(int stack1Min)  
{
	 m_stack1Min = stack1Min;
}


void CStealRaises::WriteVrsNoneToFile(CStackSizeEVTAble& stackSizeEv, CString fileName)
{
	ofstream fOutFile(fileName, ios::app , filebuf::sh_read || filebuf::sh_write);

	CString strOutString("\nTournament Final Table Ev to Stack Size Calculation\nVrs No One\n");
	fOutFile.write(strOutString.GetBuffer(1), strOutString.GetLength());

	strOutString.Format("Stack1 Min %d \nStack1 Max %d \nStep Stack 1 \n%d Blinds %d\n", m_stack1Min, m_stack1Max, m_stack1Step, m_blindsAntes);
	fOutFile.write(strOutString.GetBuffer(1), strOutString.GetLength());

	fOutFile.flush();
	fOutFile.close();
	
	m_stackSizes.DumpToFile(fileName);
	m_prizes.DumpToFile(fileName);
	stackSizeEv.DumpToFile(fileName);
}

void CStealRaises::WriteVrsLargestToFile(CStackSizeEVTAble& looseStackEVTable, CStackSizeEVTAble& foldStackEVTable, CStackSizeEVTAble& winStackEVTable, CString fileName)
{
	ofstream fOutFile(fileName, ios::app , filebuf::sh_read || filebuf::sh_write);

	CString strOutString("\nTournament Final Table Ev to Stack Size Calculation\nVrs Largest\n");
	fOutFile.write(strOutString.GetBuffer(1), strOutString.GetLength());

	strOutString.Format("Stack1 Min %d \nStack1 Max %d \nStep Stack 1 \n%d Blinds %d\n", m_stack1Min, m_stack1Max, m_stack1Step, m_blindsAntes);
	fOutFile.write(strOutString.GetBuffer(1), strOutString.GetLength());

	fOutFile.flush();
	fOutFile.close();
	
	m_stackSizes.DumpToFile(fileName);
	m_prizes.DumpToFile(fileName);

	strOutString = "EVs if loose to largets other stack";
	fOutFile.write(strOutString.GetBuffer(1), strOutString.GetLength());
	looseStackEVTable.DumpToFile(fileName);

	strOutString = "EVs if fold";
	fOutFile.write(strOutString.GetBuffer(1), strOutString.GetLength());
	foldStackEVTable.DumpToFile(fileName);

	strOutString = "EVs if win against largets other stack";
	fOutFile.write(strOutString.GetBuffer(1), strOutString.GetLength());
	winStackEVTable.DumpToFile(fileName);
}

void CStealRaises::WriteVrsSmallistToFile(CStackSizeEVTAble& looseStackEVTable, CStackSizeEVTAble& foldStackEVTable, CStackSizeEVTAble& winStackEVTable, CString fileName)
{
	ofstream fOutFile(fileName, ios::app , filebuf::sh_read || filebuf::sh_write);

	CString strOutString("\nTournament Final Table Ev to Stack Size Calculation\nVrs Smallist\n");
	fOutFile.write(strOutString.GetBuffer(1), strOutString.GetLength());

	strOutString.Format("Stack1 Min %d \nStack1 Max %d \nStep Stack 1 \n%d Blinds %d\n", m_stack1Min, m_stack1Max, m_stack1Step, m_blindsAntes);
	fOutFile.write(strOutString.GetBuffer(1), strOutString.GetLength());

	fOutFile.flush();
	fOutFile.close();
	
	m_stackSizes.DumpToFile(fileName);
	m_prizes.DumpToFile(fileName);

	strOutString = "EVs if loose to largets other stack";
	fOutFile.write(strOutString.GetBuffer(1), strOutString.GetLength());
	looseStackEVTable.DumpToFile(fileName);

	strOutString = "EVs if fold";
	fOutFile.write(strOutString.GetBuffer(1), strOutString.GetLength());
	foldStackEVTable.DumpToFile(fileName);

	strOutString = "EVs if win against largets other stack";
	fOutFile.write(strOutString.GetBuffer(1), strOutString.GetLength());
	winStackEVTable.DumpToFile(fileName);
}



