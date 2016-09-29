// PDPlayersRecordset.cpp : implementation file
//

#include "stdafx.h"
#include "PDPlayersRecordset.h"
#include "PPokerSite.h"
#include "CRSCurrentPlayers.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPDPlayersRecordset

IMPLEMENT_DYNAMIC(CPDPlayersRecordset, CRecordset)

CPDPlayersRecordset::CPDPlayersRecordset(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CPDPlayersRecordset)
	m_Player_Id = 0;
	m_Nick = _T("");
	m_nFields = 2;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
	m_strNickParam = _T("");;
	m_nParams = 1;
	m_strFilter = "[Nick] = ?";
	m_iSiteId = PPokerSite::POKER_SITE_NONE;
	UseLogDatabse(true);
}


CString CPDPlayersRecordset::GetDefaultConnect()
{
	return m_strConnectString;
}

CString CPDPlayersRecordset::GetDefaultSQL()
{
	return _T("[dbo].[Players]");
}  	


void CPDPlayersRecordset::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CPDPlayersRecordset)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[Player Id]"), m_Player_Id);
	RFX_Text(pFX, _T("[Nick]"), m_Nick);
	//}}AFX_FIELD_MAP
   	pFX->SetFieldType(CFieldExchange::param); 
	RFX_Text(pFX, _T("[Nick]"), m_strNickParam);
}

/////////////////////////////////////////////////////////////////////////////
// CPDPlayersRecordset diagnostics

#ifdef _DEBUG
void CPDPlayersRecordset::AssertValid() const
{
	CRecordset::AssertValid();
}

void CPDPlayersRecordset::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

long CPDPlayersRecordset::GetPlayerIdA(const CString &strNick, int iSiteId)
{
	SetSite(iSiteId);
	long lPlayerId;
	
	if (GetFromLogDatabase(strNick, lPlayerId))
	{
		return lPlayerId;
	}
	else 
	{
		lPlayerId = StaticGetFromOrAddToCurrentDatabase(strNick, iSiteId);
		AddToLogDatabase(strNick, lPlayerId);
		return lPlayerId; 
	}
} 

bool CPDPlayersRecordset::GetFromLogDatabase(const CString &strNick, long& lPlayerId)
{
	m_strNickParam = strNick;
	UseLogDatabse(true);

	Open(CRecordset::snapshot);
	if (GetRecordCount() == 1)
	{
		lPlayerId = m_Player_Id;
		Close();
		return true;
	}
	else
	{
		ASSERT(GetRecordCount() == 0);

		lPlayerId = 0;
		Close();
		return false;
	}
}

long  CPDPlayersRecordset::StaticGetFromOrAddToCurrentDatabase(const CString &strNick, int iSiteId)
{
	 CPDPlayersRecordset rs;
	 rs.SetSite(iSiteId);
	 rs.UseLogDatabse(false);
	 return rs.GetFromOrAddToCurrentDatabase(strNick);
}
	
long CPDPlayersRecordset::GetFromOrAddToCurrentDatabase(const CString &strNick)
{	
	m_strNickParam = strNick;
	UseLogDatabse(false);
	long lPlayerId;

	Open(CRecordset::snapshot);
	if (GetRecordCount() == 1)
	{
		lPlayerId = m_Player_Id;
		Close();
		return lPlayerId;
	}
	else
	{
		ASSERT(GetRecordCount() == 0);
		Close();

		CRSCurrentPlayers rs;
		return rs.AddPlayer(strNick, m_iSiteId);
	}

}

void CPDPlayersRecordset::AddToLogDatabase(const CString &strNick, long lPlayerId)
{
	m_strNickParam = strNick;
	UseLogDatabse(true);
	Open(CRecordset::snapshot);
	ASSERT(GetRecordCount() == 0);
	if(GetRecordCount() == 0)
	{
		AddNew();
		m_Player_Id = lPlayerId;
		m_Nick = strNick;
		Update();
		//TRACE("Created in Log Table new Nick %s, with Id %d\n", strNick, m_Player_Id);
	}
	Close();
}	

long CPDPlayersRecordset::GetPlayerId(const CString&  strNick, int iSiteId)
{
	CPDPlayersRecordset rsPlayers;
	return rsPlayers.GetPlayerIdA(strNick, iSiteId);
}


