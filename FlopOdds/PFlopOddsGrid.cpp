// PFlopOddsGrid.cpp: implementation of the PFlopOddsGrid class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PFlopOddsGrid.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
IMPLEMENT_DYNCREATE(PFlopOddsGrid, CGridCtrl)

PFlopOddsGrid::PFlopOddsGrid()
{

}

PFlopOddsGrid::~PFlopOddsGrid()
{

}

void PFlopOddsGrid::populate(PFlopPercentages* pFlopPercentages)
{
	SetColumnCount(4);
	SetFixedRowCount(1);
	SetRowCount(pFlopPercentages->size() + 1);
	SetItemText(0,0,"Hand");
	SetItemText(0,1,"Number");
	SetItemText(0,2,"%");
	SetItemText(0,3,"Total");
	int iRow = 1;

	for ( RowDataIterator iterRow = pFlopPercentages->begin() ; 
			iterRow != pFlopPercentages->end() ;
			iterRow++
		)
	{
		char buffer [34];
		char* pchBuffer = buffer;

		int iHits = (*iterRow).getHandsList().size();
		int iTotal = pFlopPercentages->getHandSpread().size();
		int iPercentage;
		iPercentage = (0 == iTotal) ? 0 : (iHits * 100) / iTotal;
		
		SetItemText(iRow,0,(*iterRow).getDescription());

		pchBuffer =  itoa(iHits, pchBuffer, 10);
		SetItemText(iRow,1, buffer);

		pchBuffer =  itoa(iPercentage, pchBuffer, 10);
		SetItemText(iRow,2, buffer);

		pchBuffer =  itoa(iTotal, pchBuffer, 10);
		SetItemText(iRow,3, buffer);

		iRow++;
	}
}

void PFlopOddsGrid::clear()
{

	SetRowCount(0);
    SetColumnCount(0);

}
