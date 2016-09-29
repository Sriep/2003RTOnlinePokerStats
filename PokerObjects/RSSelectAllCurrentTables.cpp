// RSSelectAllCurrentTables.cpp : implementation file
//

#include "stdafx.h"
#include "historyanalyserdll.h"
#include "RSSelectAllCurrentTables.h"
#include "PPokerSite.h"
#include "RSCurrentPlayers.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// RSSelectAllCurrentTables

IMPLEMENT_DYNAMIC(RSSelectAllCurrentTables, CRecordset)

RSSelectAllCurrentTables::RSSelectAllCurrentTables(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(RSSelectAllCurrentTables)
	m_CurrentTableId = 0;
	m_Site = 0;
	m_DealerWindow = 0;
	m_TableName = _T("");
	m_nFields = 4;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString RSSelectAllCurrentTables::GetDefaultConnect()
{
	return _T(LIVE_POKER_DATA_CONNECT_STRING);
}

CString RSSelectAllCurrentTables::GetDefaultSQL()
{
	return _T("[dbo].[CurrentTables]");
}

void RSSelectAllCurrentTables::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(RSSelectAllCurrentTables)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[CurrentTableId]"), m_CurrentTableId);
	RFX_Int(pFX, _T("[Site]"), m_Site);
	RFX_Long(pFX, _T("[DealerWindow]"), m_DealerWindow);
	RFX_Text(pFX, _T("[TableName]"), m_TableName);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// RSSelectAllCurrentTables diagnostics

#ifdef _DEBUG
void RSSelectAllCurrentTables::AssertValid() const
{
	CRecordset::AssertValid();
}

void RSSelectAllCurrentTables::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

TableGridRowDataList RSSelectAllCurrentTables::GetActiveTablesFromDB()
{
	TRACE("Getting active tables\n");
	TableGridRowDataList listActiveTables;

	if (Open(CRecordset::snapshot))
	{
		while (!IsEOF())
		{
			CTableGridRowData cNewTable(m_TableName, NULL, (HWND)m_DealerWindow, m_Site);
			TRACE3("Got active Table %s at site %d with window %u\n", m_TableName,	m_Site , m_DealerWindow);
			RSCurrentPlayers rsCurrentPlayers;
			cNewTable.SetPlayerList(rsCurrentPlayers.GetPlayerList(m_CurrentTableId));

			listActiveTables.push_back(cNewTable);
			MoveNext();
		}
		Close();
	}
	else
	{
		ASSERT(FALSE);
	}

	return listActiveTables;
}
