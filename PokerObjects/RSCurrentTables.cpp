// RSCurrentTables.cpp : implementation file
//

#include "stdafx.h"
#include "spyconsul.h"
#include "RSCurrentTables.h"
#include "PPokerSite.h"
#include "TableGridRowData.h"
#include "RSCurrentPlayers.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// RSCurrentTables

IMPLEMENT_DYNAMIC(RSCurrentTables, CRecordset)

RSCurrentTables::RSCurrentTables(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(RSCurrentTables)
	m_CurrentTableId = 0;	
	m_Site = 0;
	m_DealerWindow = 0;
	m_TableName = _T("");
	m_nFields = 4;
	//}}AFX_FIELD_INIT
	m_iSiteParam = 0;
	m_iDealerWindowParam = 0;
	m_strTableNameParam = _T("");
	m_nDefaultType = snapshot;
	m_nParams = 3;
	m_strFilter = "[Site] = ? AND [DealerWindow] = ? AND [TableName] = ?";
}


CString RSCurrentTables::GetDefaultConnect()
{
	return _T(LIVE_POKER_DATA_CONNECT_STRING);
}

CString RSCurrentTables::GetDefaultSQL()
{
	return _T("[dbo].[CurrentTables]");
}

void RSCurrentTables::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(RSCurrentTables)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[CurrentTableId]"), m_CurrentTableId);
	RFX_Int(pFX, _T("[Site]"), m_Site);
	RFX_Long(pFX, _T("[DealerWindow]"), m_DealerWindow);
	RFX_Text(pFX, _T("[TableName]"), m_TableName);
	//}}AFX_FIELD_MAP
   	pFX->SetFieldType(CFieldExchange::param); 
	RFX_Int(pFX, _T("[Site]"), m_iSiteParam);
	RFX_Long(pFX, _T("[DealerWindow]"), m_iDealerWindowParam);
	RFX_Text(pFX, _T("[TableName]"), m_strTableNameParam);
}

/////////////////////////////////////////////////////////////////////////////
// RSCurrentTables diagnostics

#ifdef _DEBUG
void RSCurrentTables::AssertValid() const
{
	CRecordset::AssertValid();
}

void RSCurrentTables::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

long RSCurrentTables::AddTable(const CString &strTableName, HWND hwndDealerWindow, int iSite)
{
	if (strTableName.IsEmpty());
	{
		TRACE3("Adding Table %s at site %d with window %u\n", strTableName,	iSite , hwndDealerWindow);
		m_iSiteParam = iSite;
		m_iDealerWindowParam = (long) hwndDealerWindow;
		m_strTableNameParam = strTableName;
		if (!Open(CRecordset::snapshot))
		{
			ASSERT(FALSE);
		}
		if (GetRecordCount() == 0)
		{
			AddNew();
			m_Site = iSite;
			m_DealerWindow = (long)hwndDealerWindow;
			m_TableName = strTableName;
			Update();
			m_iSiteParam = iSite;
			m_iDealerWindowParam = (long) hwndDealerWindow;
			Requery();
			long lId = m_CurrentTableId;
			Close();
			return lId;
		}
		Close();
	}
	return -1;
}

void RSCurrentTables::RemoveTable(CString strTableName, HWND hwndWindow, int iSite)
{
	TRACE("Removing Table with window %d at site %d", (long) hwndWindow, iSite);
	RSCurrentPlayers rsActivePlayers;
	rsActivePlayers.DeletePlayers(hwndWindow,  iSite);
	
	m_iSiteParam = iSite;
	m_iDealerWindowParam = (long) hwndWindow;
	m_strTableNameParam = strTableName;
	if (!Open(CRecordset::snapshot))
	{
		ASSERT(FALSE);
		return;
	}
	if (GetRecordCount() != 0)
	{
		ASSERT(GetRecordCount() == 1);
		Delete();
		Close();
	}
	Close();
}

long RSCurrentTables::GetTableId(HWND hwnd, int iSite, const CString& strTableName)
{
	long lId;
	m_iSiteParam = iSite;
	m_iDealerWindowParam = (long) hwnd;
	m_strTableNameParam = strTableName;
	if (!Open(CRecordset::snapshot))
	{
		ASSERT(FALSE);
		return -1;
	}
	if (GetRecordCount() != 0)
	{
		lId = m_CurrentTableId;
		Close();
		return lId;
	}
	else
	{
		Close();
		return AddTable(strTableName, hwnd, iSite );
	}
}

long RSCurrentTables::GetTableId(HWND hwnd, int iSite)
{
	long lId;
	m_iSiteParam = iSite;
	m_iDealerWindowParam = (long) hwnd;
	if (!Open(CRecordset::snapshot))
	{
		ASSERT(FALSE);
		return 0;
	}
	if (GetRecordCount() != 0)
	{
		lId = m_CurrentTableId;
		Close();
		return lId;
	}
	else
	{
		return 0;
		Close();
	}
}

void RSCurrentTables::DeleteAll()
{
	if (!Open(CRecordset::snapshot))
	{
		ASSERT(FALSE);
		return;
	}
	while (!IsEOF())
	{
		Delete();
		MoveNext();
	}
	Close();
}

