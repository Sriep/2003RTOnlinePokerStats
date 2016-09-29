// StatsGrid1.cpp: implementation of the CStatsGrid class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "StatsGrid1.h"
#include "RSColumData.h"
#include "StatsGrid1.h"
#include "SPRSCountHands.h"
#include "StoredProcGridCell.h"
#include "NickGridCell.h"
#include "History AnalyserDlg.h"
#include "NickGridComboCell.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
IMPLEMENT_DYNCREATE(CStatsGrid, CGridCtrl)

const int CStatsGrid::NUM_ROWS_IN_GRID = 11;

CStatsGrid::CStatsGrid()
:	m_iPokerSite(1),
	m_iGridNumber(0),
	m_pdlgParent(NULL)
{
	SetCompareFunction(pfnCellStatsGridCompare);
}

CStatsGrid::~CStatsGrid()
{

}

void CStatsGrid::SetUp(int iGridNumber, CHistoryAnalyserDlg* pdlgParent)
{
	m_iGridNumber = iGridNumber;
	m_pdlgParent = pdlgParent;
	SetAutoSizeStyle(GVS_BOTH);
	SetHeaderSort(true);
	
	CNickGridCell nCell;
	CNickGridComboCell nComboCell;
	if (1 == iGridNumber)
	{
		SetDefaultCellType(nComboCell.GetRuntimeClass());
	}
	else
	{
		SetDefaultCellType(nCell.GetRuntimeClass());
	}
	
	SetColumnCount(1);
	SetFixedRowCount(1);
	SetRowCount(NUM_ROWS_IN_GRID);
	SetItemText(0,0,"Player");
	if (1 != iGridNumber)
	{ 
		for (int  iRow = 0 ; iRow < NUM_ROWS_IN_GRID ; iRow++ )
		{
			CNickGridCell* pCell = (CNickGridCell*) GetCell(iRow, 0);
			pCell->SetState(GVNI_READONLY);
		}
	}
	else
	{
		SetCellType(0,0, nCell.GetRuntimeClass());
	}

	CStoredProcGridCell spCell;
	SetDefaultCellType(spCell.GetRuntimeClass());
	CRSColumData rsColumData;
	rsColumData.m_iGridNumberParam = m_iGridNumber;
	if (!rsColumData.Open(CRecordset::snapshot, NULL, CRecordset::readOnly))
	{
		throw("Can not open recordset");
	}

	int iColumn	= 1;
	for (  ; !rsColumData.IsEOF() ; rsColumData.MoveNext() )
	{
		InsertColumn(rsColumData.m_Header,-1);
		for (int  iRow = 0 ; iRow < NUM_ROWS_IN_GRID ; iRow++ )
		{
			CStoredProcGridCell* pCell = (CStoredProcGridCell*) GetCell(iRow, iColumn);
			ASSERT(pCell->IsKindOf(RUNTIME_CLASS(CStoredProcGridCell)));
			pCell->Initilise(rsColumData);
			pCell->SetState(GVNI_READONLY);
		}
	 	iColumn++;
	} 
	rsColumData.Close();

}


void CStatsGrid::OnEndEditCell(int nRow, int nCol, CString str)
{
	ASSERT(nCol == 0);
	CNickGridComboCell* pCell = (CNickGridComboCell*) GetCell(nRow, nCol);
	CString strOldText = pCell->GetOldText();
	CGridCtrl::OnEndEditCell(nRow, nCol, str);
	pCell->SetText(str);
	
	RefreshRow(nRow);
	RedrawRow(nRow); 
	AutoSizeColumns();

	for (int iGrid = 1 ; iGrid < NUM_OF_GRIDS ; iGrid++ )
	{
		if (iGrid != m_iGridNumber)
		{
			m_pdlgParent->GetGrid(iGrid).ReplaceRow(strOldText, str);
		}
	}
	pCell->SetOldText(str);
	m_pdlgParent->UpdateStatusBar();
}

// reset a complete row
void CStatsGrid::RefreshRow(int row)
{
    if (0 != GetPokerSite())
	{
		for ( int col = 1 ; col < GetColumnCount() ; col++ )
		{
			CGridCellBase* pCell = GetCell(row, col);
			if (pCell)
			{
				pCell->Refresh(row);
			}
		}
	}
	Refresh();
}

int CStatsGrid::GetPokerSite()
{
	return m_pdlgParent->GetPokerSite() ;
}

void CStatsGrid::ReplaceRow(const CString& strOld, const CString& strNew)
{
	CString strTrimmedOld = strOld;
	strTrimmedOld.TrimRight(' ');
	strTrimmedOld.TrimLeft(' ');
	for ( int iRow = 1 ; iRow < NUM_ROWS_IN_GRID ; iRow++ )
	{
		CGridCellBase* pCell = GetCell(iRow, 0);
		ASSERT(pCell);
		if (pCell)
		{
			CString strName =  pCell->GetText();
			strName.TrimRight(' ');
			strName.TrimLeft(' ');
			if (strTrimmedOld == strName)
			{
				pCell->SetText(strNew);
				RefreshRow(iRow);
				RedrawRow(iRow);
				AutoSizeColumns();
			return;
			}
		}
	}
	ASSERT(FALSE);
}

void CStatsGrid::RefreshGrid()
{
 	for ( int iRow = 1 ; iRow < NUM_ROWS_IN_GRID ; iRow++ )
	{
		RefreshRow(iRow);
		m_pdlgParent->m_ctlProgressRefresh.SetPos(m_pdlgParent->m_ctlProgressRefresh.GetPos() + 1);
		m_pdlgParent->UpdateWindow();

	}
	CNickGridComboCell::GetPlayerListUpdates();	 
	AutoSizeColumns();
}

void CStatsGrid::ClearGrid()
{
	for ( int iRow = 1 ; iRow < NUM_ROWS_IN_GRID ; iRow++ )
	{
		if (1 != m_iGridNumber)
		{
			CGridCellBase* pCell = GetCell(iRow, 0);
			ASSERT(pCell);
			pCell->SetText("");
		}
		else
		{
			CNickGridComboCell* pCell = (CNickGridComboCell*) GetCell(iRow, 0);
			ASSERT(pCell);
			pCell->SetText("");
			pCell->SetOldText("");
		}
	} 
	RefreshGrid();
}

void CStatsGrid::RefreshPlayerCombos(int iSite)
{
	CNickGridComboCell::GetPlayerListUpdates();
	for (int  iRow = 1 ; iRow < CStatsGrid::NUM_ROWS_IN_GRID ; iRow++ )
	{
		CNickGridComboCell* pComboCell = (CNickGridComboCell*) GetCell(iRow, 0);
		ASSERT(pComboCell->IsKindOf(RUNTIME_CLASS(CNickGridComboCell)));
		pComboCell->SetSite(iSite);
	}

}

int CALLBACK CStatsGrid::pfnCellStatsGridCompare(LPARAM lParam1, LPARAM lParam2, LPARAM lParamSort)
{
	UNUSED_ALWAYS(lParamSort);

	CGridCellBase* pCell1 = (CGridCellBase*) lParam1;
	CGridCellBase* pCell2 = (CGridCellBase*) lParam2;
	if (!pCell1 || !pCell2) return 0;

	if ( pCell1->IsKindOf(RUNTIME_CLASS(CNickGridComboCell)) || pCell1->IsKindOf(RUNTIME_CLASS(CNickGridCell)) )
	{
		ASSERT( pCell2->IsKindOf(RUNTIME_CLASS(CNickGridComboCell)) || pCell2->IsKindOf(RUNTIME_CLASS(CNickGridCell)) );
		return pfnCellTextCompare(lParam1, lParam2, lParamSort);
	}
	else
	{
		return pfnCellNumericCompare(lParam1, lParam2, lParamSort);
	}

}

void CStatsGrid::UpdatePlayers(const StringList& listPlayers)
{
	RemovePlayersNotInList(listPlayers);

	for (ConstStringListIterator iter = listPlayers.begin() ; iter != listPlayers.end() ; iter++ )
	{
		if (!ExistingPlayer(*iter))
		{
			PlaceInFirstEmptyRow(*iter);
		}
	}	
}

void CStatsGrid::RemovePlayersNotInList(const StringList &listPlayers)
{
	for (int  iRow = 1 ; iRow < CStatsGrid::NUM_ROWS_IN_GRID ; iRow++ )
	{
		CGridCellBase* pComboCell = (CNickGridComboCell*) GetCell(iRow, 0);
		ASSERT(pComboCell->IsKindOf(RUNTIME_CLASS(CGridCellBase)));
		
		if (!(pComboCell->GetText() == ""))
		{
			bool bFound = false;
			ConstStringListIterator iter = listPlayers.begin();
			while (!bFound && iter != listPlayers.end())
			{
				if ((*iter) == pComboCell->GetText())
				{
					bFound = true;
				}
				iter++;
			}	
			if (!bFound)
			{
				pComboCell->SetText("");
			}
		}
	}
}

bool CStatsGrid::ExistingPlayer(const CString &strPlayer)
{
	for (int  iRow = 1 ; iRow < CStatsGrid::NUM_ROWS_IN_GRID ; iRow++ )
	{
		CGridCellBase* pComboCell = (CNickGridComboCell*) GetCell(iRow, 0);
		ASSERT(pComboCell->IsKindOf(RUNTIME_CLASS(CGridCellBase)));

		CString strName = pComboCell->GetText();
		if (strPlayer == strName)
		{
			return true;
		}
	}
	return false;
}

void CStatsGrid::PlaceInFirstEmptyRow(const CString &strPlayer)
{
	for (int  iRow = 1 ; iRow < CStatsGrid::NUM_ROWS_IN_GRID ; iRow++ )
	{
		CGridCellBase* pComboCell = (CNickGridComboCell*) GetCell(iRow, 0);
		ASSERT(pComboCell->IsKindOf(RUNTIME_CLASS(CGridCellBase)));

		CString strName = pComboCell->GetText();
		if (strName.IsEmpty())
		{
			pComboCell->SetText(strPlayer);
			return;
		}
	}
	//ASSERT(FALSE);
}
