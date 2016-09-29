// RSLogDBLcoks.cpp : implementation file
//

#include "stdafx.h"
#include "RSLogDBLcoks.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// RSLogDBLcoks

IMPLEMENT_DYNAMIC(RSLogDBLcoks, CRecordset)

RSLogDBLcoks::RSLogDBLcoks(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(RSLogDBLcoks)
	m_DBLock_Id = 0;
	m_Queue_Id = 0;
	m_Total_seconds = 0;
	m_Description = _T("");
	m_Start_time = CTime::GetCurrentTime();
	m_end_time = CTime::GetCurrentTime();
	m_nFields = 6;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
	m_iQueueIdParam = 0;
	m_nParams = 1;
//	m_strFilter = "[Site] = ? AND [DealerWindow] = ?";
}


CString RSLogDBLcoks::GetDefaultConnect()
{
	return _T(LIVE_POKER_DATA_CONNECT_STRING);
}

CString RSLogDBLcoks::GetDefaultSQL()
{
	return _T("[dbo].[LogOfDBLocks]");
}

void RSLogDBLcoks::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(RSLogDBLcoks)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[DBLock Id]"), m_DBLock_Id);
	RFX_Long(pFX, _T("[Queue Id]"), m_Queue_Id);
	RFX_Date(pFX, _T("[Start time]"), m_Start_time);
	RFX_Date(pFX, _T("[end time]"), m_end_time);
	RFX_Long(pFX, _T("[Total seconds]"), m_Total_seconds);
	RFX_Text(pFX, _T("[Description]"), m_Description);
	//}}AFX_FIELD_MAP
   	pFX->SetFieldType(CFieldExchange::param); 
	RFX_Long(pFX, _T("[Queue Id]"), m_iQueueIdParam);
}

void RSLogDBLcoks::LogStartLock(long lQueueId, CString strDescription)
{
	if (!Open(CRecordset::snapshot))
	{
		ASSERT(FALSE);
	}
	AddNew();
	m_Queue_Id = lQueueId;
	m_Description = strDescription;
	m_Start_time = CTime::GetCurrentTime();
	Update();
	Close();
}

void RSLogDBLcoks::LogEndLock(long lQueueId)
{
	m_strFilter = "[Queue Id] = ?";
	m_iQueueIdParam = lQueueId;
	if (!Open(CRecordset::snapshot))
	{
		ASSERT(FALSE);
	}
	ASSERT(GetRecordCount() == 1);
	if (GetRecordCount() == 1)
	{
		Edit();
		m_end_time = CTime::GetCurrentTime();
		CTimeSpan cTS = m_end_time -  m_Start_time;
		m_Total_seconds = cTS.GetTotalSeconds();
		Update();
		Close();
	}
}

/////////////////////////////////////////////////////////////////////////////
// RSLogDBLcoks diagnostics

#ifdef _DEBUG
void RSLogDBLcoks::AssertValid() const
{
	CRecordset::AssertValid();
}

void RSLogDBLcoks::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
