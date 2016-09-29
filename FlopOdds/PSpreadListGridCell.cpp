// PSpreadListGridCell.cpp: implementation of the PSpreadListGridCell class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "flopodds.h"
#include "PSpreadListGridCell.h"
#include "PDlgHandsSelection.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

IMPLEMENT_DYNCREATE(PSpreadListGridCell, CGridCell)

PSpreadListGridCell::PSpreadListGridCell()
{

}

PSpreadListGridCell::~PSpreadListGridCell()
{

}

void PSpreadListGridCell::OnDblClick(CPoint PointCellRelative)
{
	PDlgHandsSelection dlgHandSelector(*m_plistCellHands);
	if (IDOK == dlgHandSelector.DoModal())
	{
		*m_plistDlgHands = *m_plistCellHands; 
	}
}

void PSpreadListGridCell::setHandsList(PHandsList* plistHands, PHandsList* pDlgHandsList)
{
	m_plistCellHands = plistHands;
	m_plistDlgHands = pDlgHandsList;
}

void PSpreadListGridCell::OnClick(CPoint PointCellRelative)
{
		*m_plistDlgHands = *m_plistCellHands; 
}
