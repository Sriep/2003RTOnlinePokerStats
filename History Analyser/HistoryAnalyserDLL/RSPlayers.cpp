// RSPlayers.cpp : implementation file
//

#include "stdafx.h"
#include "RSPlayers.h"
#include "PPokerSite.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// RSPlayers

IMPLEMENT_DYNAMIC(RSPlayers, CRecordset)

RSPlayers::RSPlayers(CDatabase* pdb)
: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(RSPlayers)
	m_Player_Id = 0;
	m_nFields = 1;
	//}}AFX_FIELD_INIT
	m_pPlayer = NULL;
	m_pPlayerLengths = NULL;
	m_nDefaultType = snapshot;

	m_iSiteId = 0;
}

RSPlayers::RSPlayers(int iSite)
: CRecordset(NULL)
{
	m_Player_Id = 0;
	m_nFields = 1;
	m_pPlayer = NULL;
	m_pPlayerLengths = NULL;
	m_nDefaultType = snapshot;
	SetSite(iSite);
}


CString RSPlayers::GetDefaultConnect()
{
	return _T(PPokerSite::GetCurrentSQLConnectString(m_iSiteId));
}

CString RSPlayers::GetDefaultSQL()
{
	return _T("[dbo].[Players]");
}

void RSPlayers::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(RSPlayers)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Int(pFX, _T("[Player Id]"), m_Player_Id);
	//}}AFX_FIELD_MAP
}

void RSPlayers::DoBulkFieldExchange( CFieldExchange* pFX )
{
	// call the Bulk RFX functions
	// for field data members
	pFX->SetFieldType( CFieldExchange::outputColumn );
	RFX_Text_Bulk(pFX, _T("[Nick]"), &m_pPlayer, &m_pPlayerLengths, PLAYER_NAME_MAX_LENGTH);

}

/////////////////////////////////////////////////////////////////////////////
// RSPlayers diagnostics

#ifdef _DEBUG
void RSPlayers::AssertValid() const
{
	CRecordset::AssertValid();
}

void RSPlayers::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

void RSPlayers::SetSite(int iSite)
{
	m_strSort = "[Nick]";
	m_iSiteId = iSite;
}
