// StoredProcGridCell.cpp: implementation of the CStoredProcGridCell class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "StoredProcGridCell.h"
#include "SPRSCountHands.h"
#include "StatsGrid1.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

IMPLEMENT_DYNCREATE(CStoredProcGridCell, CGridCell)

CStoredProcGridCell::CStoredProcGridCell(const CColumnData& cDataInfo)
:	m_cDataInfo(cDataInfo)
{
}

CStoredProcGridCell::CStoredProcGridCell()
{

}

CStoredProcGridCell::~CStoredProcGridCell()
{

}

void CStoredProcGridCell::Initilise(const CColumnData& cDataInfo)
{
	m_cDataInfo = cDataInfo;
}  

void CStoredProcGridCell::Refresh(int iRow)
{
	CGridCellBase* pCell = GetGrid()->GetCell(iRow, 0);
	ASSERT(pCell);

	if (pCell->GetText() == "")
	{
		CGridCellBase* pDefaultCell = GetDefaultCell();
		SetBackClr(pDefaultCell->GetBackClr());
		SetText("");
		return;
	}

	CellData cData =  m_cDataInfo.GetColumnData(pCell->GetText(),((CStatsGrid*)GetGrid())->GetPokerSite());
	
	LOGFONT* pLogFont = m_cDataInfo.SetFont(cData.m_iWeight, GetFont());
	SetFont(pLogFont);

	if (cData.m_iWeight > m_cDataInfo.GetDont_show())
	{
		if (m_cDataInfo.GetType() == TYPE_SINGLE_VALUE)
		{
			CGridCellBase* pDefaultCell = GetDefaultCell();
			SetBackClr(pDefaultCell->GetBackClr());
		}
		else
		{
			SetColour(cData.m_iValue);
		}

		char buffer [34];
		char* pchBuffer = buffer;
		pchBuffer = itoa(cData.m_iValue, pchBuffer, 10);
		SetText(pchBuffer);
	}
	else
	{
		CGridCellBase* pDefaultCell = GetDefaultCell();
		SetBackClr(pDefaultCell->GetBackClr());
		SetText("");
	}

}

LPCTSTR CStoredProcGridCell::GetTipText() const
{
	return m_cDataInfo.GetTooltip();
} 

void CStoredProcGridCell::SetColour(int iValue)
{
	if (0 == m_cDataInfo.GetVariance())
	{
		CGridCellBase* pDefaultCell = GetDefaultCell();
		SetBackClr(RGB(255,255,255));
	}
	else
	{
		int iDiff = (iValue - m_cDataInfo.GetAvearageValue())/ m_cDataInfo.GetVariance();
		
		iDiff *= 10;
		if (iDiff < -255)
			iDiff = -255;
		if (255 < iDiff)
			iDiff = 255;

		switch (m_cDataInfo.GetAxis())
		{
		case AXIS_NONE:
			SetBackClr(RGB(255,255,255)) ;
			break; 
		case AXIS_TIGHT_LOOSE:
			if (0<iDiff)
			{	 
				SetBackClr(RGB(255 - iDiff,255,255 - iDiff));

			}
			else
			{
				SetBackClr(RGB(255,255 + iDiff,255 + iDiff));
			}
			break;

		case AXIS_PASSIVE_AGGRESIVE:
			if (0<iDiff)
			{
				SetBackClr(RGB(255 - iDiff,255 - iDiff,255));
			}
			else
			{
				SetBackClr(RGB(255 + iDiff, 255,255 + iDiff));
			}
			break;
		default:
			CGridCellBase* pDefaultCell = GetDefaultCell();
			SetBackClr(pDefaultCell->GetBackClr()) ;
			ASSERT(FALSE);
		}
	}
}




