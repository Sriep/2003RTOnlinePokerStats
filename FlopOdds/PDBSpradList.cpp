// PDBSpradList.cpp: implementation of the PDBSpradList class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "flopodds.h"
#include "PDBSpradList.h"
#include "DBHandListNames.h"
#include "PSpreadListGridCell.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

IMPLEMENT_DYNCREATE(PDBSpradListGrid, CGridCtrl)

PDBSpradListGrid::PDBSpradListGrid()
{

}

PDBSpradListGrid::~PDBSpradListGrid()
{

}

void PDBSpradListGrid::setup(PHandsList* pHandsList)
{
	m_pDlgHandsList =  pHandsList;
	PSpreadListGridCell cell;
	SetDefaultCellType(cell.GetRuntimeClass());
	SetListMode(true);
	populate();
}

void PDBSpradListGrid::DBRead()
{
	m_listHandSpreads.clear();
	DBHandListNames rsHandsListsNames;
	try
	{
		rsHandsListsNames.Open(CRecordset::forwardOnly, NULL, CRecordset::readOnly);
		while (!rsHandsListsNames.IsEOF())
		{
			PHandsList pHandsList(rsHandsListsNames.m_Name);
			pHandsList.DBRead();
			m_listHandSpreads.push_back(pHandsList);
			rsHandsListsNames.MoveNext();
		}

		rsHandsListsNames.Close();
	}
	catch (CDBException* pDBExept)
	{
		if (rsHandsListsNames.IsOpen())
			rsHandsListsNames.Close();
		pDBExept->ReportError();
	}	
}

void PDBSpradListGrid::populate()
{
	DBRead();
	
	SetColumnCount(2);
	SetFixedRowCount(1);
	SetRowCount(m_listHandSpreads.size() + 1);
	SetItemText(0,0,"Title");
	SetItemText(0,1,"%");
	int iRow = 1;

	for ( HoldemHandsListIterator iterRow = m_listHandSpreads.begin() ; 
			iterRow != m_listHandSpreads.end() ;
			iterRow++
		)
	{
		SetItemText(iRow,0,(*iterRow).getTitle());
				
		char buffer [34];
		char* pchBuffer = buffer;
		int iPercentage = (*iterRow).getPercentage();
		pchBuffer =  itoa(iPercentage, pchBuffer, 10);
		SetItemText(iRow,1, buffer);
		((PSpreadListGridCell*) GetCell(iRow,0))->setHandsList(&(*iterRow), m_pDlgHandsList);
		((PSpreadListGridCell*) GetCell(iRow,1))->setHandsList(&(*iterRow), m_pDlgHandsList);
		iRow++;
	} 
}
