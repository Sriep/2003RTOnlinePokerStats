// RSCurrentPlayers1.cpp : implementation file
//

#include "stdafx.h"
#include "historyparser_dll.h"
#include "CRSCurrentPlayers.h"
#include "PPokerSite.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRSCurrentPlayers

IMPLEMENT_DYNAMIC(CRSCurrentPlayers, CRecordset)

CRSCurrentPlayers::CRSCurrentPlayers(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CRSCurrentPlayers)
	m_Player_Id = 0;
	m_Nick = _T("");
	m_nFields = 2;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CRSCurrentPlayers::GetDefaultConnect()
{
	return PPokerSite::GetCurrentSQLConnectString(m_iSiteId);
}

CString CRSCurrentPlayers::GetDefaultSQL()
{
	return _T("[dbo].[Players]");
}

void CRSCurrentPlayers::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CRSCurrentPlayers)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[Player Id]"), m_Player_Id);
	RFX_Text(pFX, _T("[Nick]"), m_Nick);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CRSCurrentPlayers diagnostics

#ifdef _DEBUG
void CRSCurrentPlayers::AssertValid() const
{
	CRecordset::AssertValid();
}

void CRSCurrentPlayers::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

long CRSCurrentPlayers::AddPlayer(const CString& strNick, int iSite)
{
	SetSite(iSite);
	long lPlayerId;

	CString strCurrentDatasorce = PPokerSite::GetCurrentDataSource(iSite);
	CString strSelct;
	strSelct.Format("Select * from %s..Players where [Nick] = '%s'", strCurrentDatasorce, strNick);

	Open(CRecordset::snapshot, strSelct);
	if (GetRecordCount() == 1)
	{
		lPlayerId = m_Player_Id;
		Close();
		return lPlayerId;
	}
	else
	{
		ASSERT(GetRecordCount() == 0);
		AddNew();
		m_Nick = strNick;
		Update();
		Requery();
		lPlayerId = m_Player_Id;
		ASSERT(GetRecordCount() == 1);
		TRACE("Created in Current Table new Nick %s, with Id %d\n", strNick, m_Player_Id);
		Close();
		return lPlayerId;
	}
}

