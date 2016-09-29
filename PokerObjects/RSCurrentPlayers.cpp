// RSCurrentPlayers.cpp : implementation file
//

#include "stdafx.h"
#include "RSCurrentPlayers.h"
#include "RSCurrentTables.h"
#include "PPokerSite.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// RSCurrentPlayers

IMPLEMENT_DYNAMIC(RSCurrentPlayers, CRecordset)

RSCurrentPlayers::RSCurrentPlayers(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(RSCurrentPlayers)
	m_CurrentPlayerId = 0;
	m_FK_CurrentTable = 0;
	m_Name = _T("");
	m_nFields = 3;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
	m_lFK_TableIdParam = 0;
	m_nParams = 1;
	m_strFilter = "[FK_CurrentTable] = ?";
}


CString RSCurrentPlayers::GetDefaultConnect()
{
	return _T(LIVE_POKER_DATA_CONNECT_STRING);
}

CString RSCurrentPlayers::GetDefaultSQL()
{
	return _T("[dbo].[CurrentPlayers]");
}

void RSCurrentPlayers::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(RSCurrentPlayers)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[CurrentPlayerId]"), m_CurrentPlayerId);
	RFX_Long(pFX, _T("[FK_CurrentTable]"), m_FK_CurrentTable);
	RFX_Text(pFX, _T("[Name]"), m_Name);
	//}}AFX_FIELD_MAP
   	pFX->SetFieldType(CFieldExchange::param); 
	RFX_Long(pFX, _T("[FK_CurrentTable]"), m_lFK_TableIdParam);
}

/////////////////////////////////////////////////////////////////////////////
// RSCurrentPlayers diagnostics

#ifdef _DEBUG
void RSCurrentPlayers::AssertValid() const
{
	CRecordset::AssertValid();
}

void RSCurrentPlayers::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

void RSCurrentPlayers::RefreshPlayerList(HWND hwnd, int iSiteId, StringList listPlayers, const CString& strTableName)
{
	RSCurrentTables rsActiveTables;
	long lTableId =	rsActiveTables.GetTableId(hwnd, iSiteId, strTableName);
	m_lFK_TableIdParam = lTableId;
	TRACE3("Changing player list - Table Id = %d, SiteId = %d, Window = %d\n", lTableId, iSiteId, hwnd);
	if (lTableId >0 || lTableId <10000)
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
		for ( ConstStringListIterator iIter = listPlayers.begin() ; iIter != listPlayers.end() ; iIter++ )
		{
			CString strNick = *iIter;
			AddNew();
			m_FK_CurrentTable = lTableId;
			TRACE2("Adding player %s, to table with Id %d\n", strNick, lTableId);
			m_Name = strNick;
			Update();
		}
		Close();
	}
	else
	{
		ASSERT(FALSE);
	}

}

StringList RSCurrentPlayers::GetPlayerList(HWND hwnd, int iSiteId, const CString& strTableName)
{
	RSCurrentTables rsActiveTables;
	return GetPlayerList(rsActiveTables.GetTableId(hwnd, iSiteId, strTableName));
}

StringList RSCurrentPlayers::GetPlayerList(long lActiveTableId)
{
	m_lFK_TableIdParam = lActiveTableId;
	StringList strListPlayers;
	if (Open(CRecordset::snapshot))
	{
		while (!IsEOF())
		{
			if (!m_Name.IsEmpty())
			{
				strListPlayers.push_back(m_Name);
			}
			MoveNext();
		}
	}
	else
	{
		ASSERT(FALSE);
	}
	return strListPlayers;
}

void RSCurrentPlayers::DeletePlayers(HWND hwnd, int iSite)
{
	RSCurrentTables rsActiveTables;
	long lTableId =	rsActiveTables.GetTableId(hwnd, iSite);
	m_lFK_TableIdParam = lTableId;
	
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


void RSCurrentPlayers::DeleteAll()
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
