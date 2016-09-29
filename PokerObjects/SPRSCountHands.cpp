// SPRSCountHands.cpp : implementation file
//

#include "stdafx.h"
#include "SPRSCountHands.h"
#include "PPokerSite.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// SPRSCountHands

IMPLEMENT_DYNAMIC(SPRSCountHands, CRecordset)

SPCash SPRSCountHands::sm_cSP_ResultCash;

SPRSCountHands::SPRSCountHands(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(SPRSCountHands)
	//m_Player_Id = 0;
	//m_Host_Id = 0;
	//m_Nick = _T("");
	m_lNumber = 0;
	m_nFields = 1;
	//}}AFX_FIELD_INIT
	m_nParams = 1;
	m_strNickParam = _T("");
	m_nDefaultType = snapshot;
	m_bUseLogDatabse = true;
	//m_strFilter = "[Host Id] = ? AND [Nick] = ?";
	//UseLogDatabase(true); 
}


CString SPRSCountHands::GetDefaultConnect()
{
	return m_strConnectString;
}

CString SPRSCountHands::GetDefaultSQL()
{
	return _T("");
}

void SPRSCountHands::UseLogDatabase(bool bUseLogDatabase)
{
	m_bUseLogDatabse = bUseLogDatabase;
	if (bUseLogDatabase)
	{
		m_strConnectString  = _T(PPokerSite::GetLoggingSQLConnectString(m_iSiteId));
	}
	else
	{
		m_strConnectString  = _T(PPokerSite::GetCurrentSQLConnectString(m_iSiteId));
	}
}

void SPRSCountHands::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(SPRSCountHands)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX,_T("Number"), m_lNumber);
	//}}AFX_FIELD_MAP
   	pFX->SetFieldType(CFieldExchange::param);
	RFX_Text(pFX, _T("[Nick]"), m_strNickParam);
}

/////////////////////////////////////////////////////////////////////////////
// SPRSCountHands diagnostics

#ifdef _DEBUG
void SPRSCountHands::AssertValid() const
{
	CRecordset::AssertValid();
}

void SPRSCountHands::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

int SPRSCountHands::GetValue(const CString& strProcdeure, const CString& strNick, int iPokerSite)
{
	long iValue = GetValueArchiveDB(strProcdeure, strNick, iPokerSite);
	iValue += GetValueCurrentDB(strProcdeure, strNick, iPokerSite);

	return (int)iValue;
}


long SPRSCountHands::GetValueI(const CString& strProcdeure, const CString& strNick, int iPokerSite)
{
	if (!strNick.IsEmpty())
	{
		CString strSQL;
		if (m_bUseLogDatabse)
		{
			strSQL.Format("{Call %s..%s (?)}", PPokerSite::GetLoggingDataSource(m_iSiteId), strProcdeure); 
			//strSQL.Format("{Call %s (?)}", strProcdeure); 
		}
		else
		{
			strSQL.Format("{Call %s (?)}", strProcdeure); 
			//strSQL.Format("{Call %s..%s (?)}", PPokerSite::GetCurrentDataSource(m_iSiteId), strProcdeure); 
		}

		m_strNickParam = strNick;
#if defined(_DEBUG)
		TRACE2("About to call stored procedure %s Connect string %s\n", strProcdeure, m_strConnectString);   
		CTime tBefore = CTime::GetCurrentTime();
#endif
		if (!Open(CRecordset::snapshot, strSQL))
		{
			throw("Failed to open recordset");
		}
		int iValue = m_lNumber;
		Close();

#if defined(_DEBUG)
	CTime tAfter = CTime::GetCurrentTime();
	CString strTimeStart = tBefore.Format("%#c");
	CString strTimeFinish = tAfter.Format("%#c");
	CTimeSpan tsTimeTook = tAfter - tBefore;
	int iSecsTook = tsTimeTook.GetTotalMinutes()*60 + tsTimeTook.GetSeconds();
	
	CString strText;
	strText.Format("Retured %d,took %d seconds: Start %s, Finsihed %s\n",	iValue, iSecsTook, strTimeStart, strTimeFinish);
	TRACE(strText);
#endif
		return iValue;
	}
	else
	{
		return 0;
	}
}
/*
long SPRSCountHands::GetValueLogDB(const CString& strProcdeure, const CString& strNick, int iPokerSite)
{
	SPRSCountHands rsLogHands;
	rsLogHands.SetSiteId(iPokerSite);
	rsLogHands.UseLogDatabase(true); 
	return rsLogHands.GetValueI(strProcdeure, strNick, iPokerSite);
} */

long SPRSCountHands::GetValueArchiveDB(const CString& strProcdeure, const CString& strNick, int iPokerSite)
{
	if (AreHandsInArchiveDB(strNick, iPokerSite))
	{
		CSPDataKey key(strProcdeure, strNick, iPokerSite);
		ConstSPCashIterator iter = sm_cSP_ResultCash.find(key);
		if (iter == sm_cSP_ResultCash.end())
		{
			int iValue = ReadValuArchiveFromDB(strProcdeure, strNick, iPokerSite);
			sm_cSP_ResultCash.insert(SPCash::value_type(key,iValue));  
			return iValue;
		}
		else
		{
			return  (*iter).second;
		}
	}
	else
	{
		return 0;
	} 
	//else
	//{
	//	return ReadValuArchiveFromDB(strProcdeure, strNick, iPokerSite);
	//}
}

long SPRSCountHands::GetValueCurrentDB(const CString& strProcdeure, const CString& strNick, int iPokerSite)
{
	return ReadValuCurrentFromDB(strProcdeure, strNick, iPokerSite);
}
			
bool SPRSCountHands::AreHandsInArchiveDB(const CString& strNick, int iPokerSite)
{
	CSPDataKey key("sp_num_get_hands", strNick, iPokerSite);
	ConstSPCashIterator iter = sm_cSP_ResultCash.find(key);
	return (iter == sm_cSP_ResultCash.end()) || 0 < (*iter).second;
}

long SPRSCountHands::ReadValuArchiveFromDB(const CString &strProcdeure, const CString strNick, int iPokerSite)
{
	CDatabase dbArchive;
	dbArchive.Open(PPokerSite::GetArchiveDataSource(iPokerSite), false, false, PPokerSite::GetArchiveSQLConnectString(iPokerSite));
	SPRSCountHands rsArchiveHands(&dbArchive);
	rsArchiveHands.SetSiteId(iPokerSite);
	rsArchiveHands.UseLogDatabase(false); 
	int iValue = rsArchiveHands.GetValueI(strProcdeure, strNick, iPokerSite);
	dbArchive.Close();
	return iValue;
}

long SPRSCountHands::ReadValuCurrentFromDB(const CString &strProcdeure, const CString strNick, int iPokerSite)
{
	CDatabase dbCurrent;
	dbCurrent.Open(PPokerSite::GetCurrentDataSource(iPokerSite), false, false, PPokerSite::GetCurrentSQLConnectString(iPokerSite));
	SPRSCountHands rsCurrenteHands(&dbCurrent);
	rsCurrenteHands.SetSiteId(iPokerSite);
	rsCurrenteHands.UseLogDatabase(false); 
	int iValue = rsCurrenteHands.GetValueI(strProcdeure, strNick, iPokerSite);
	dbCurrent.Close();
	return iValue;
}
