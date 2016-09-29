// SPRSCountHands.cpp : implementation file
//

#include "stdafx.h"
#include "SPRSCountHands.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// SPRSCountHands

IMPLEMENT_DYNAMIC(SPRSCountHands, CRecordset)

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
	m_nParams = 2;
	m_strNickParam = _T("");
	m_iHostParam = 0;
	m_nDefaultType = snapshot;
	//m_strFilter = "[Host Id] = ? AND [Nick] = ?";
}


CString SPRSCountHands::GetDefaultConnect()
{
	return _T("ODBC;DSN=PokerData");
}

CString SPRSCountHands::GetDefaultSQL()
{
	return _T("");
}

void SPRSCountHands::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(SPRSCountHands)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX,_T("Number"), m_lNumber);
	//}}AFX_FIELD_MAP
   	pFX->SetFieldType(CFieldExchange::param);
	RFX_Text(pFX, _T("[Nick]"), m_strNickParam);
	RFX_Int(pFX, _T("[Host Id]"), m_iHostParam);
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


int SPRSCountHands::GetValue(CString strProcdeure, CString strNick, int iPokerSite)
{
	if (!strNick.IsEmpty())
	{
		SPRSCountHands rsHands;
		CString strSQL;
		strSQL.Format("{Call %s (?, ?)}", strProcdeure); 
		rsHands.m_iHostParam = iPokerSite;
		rsHands.m_strNickParam = strNick;
		TRACE1("About to call stored procedure %s\n", strProcdeure);
		if (!rsHands.Open(CRecordset::snapshot, strSQL))
		{
			throw("Failed to open recordset");
		}
		
		int iValue = rsHands.m_lNumber;
		rsHands.Close();
		return iValue;
	}
	else
	{
		return 0;
	}
}

