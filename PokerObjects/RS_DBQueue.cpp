// RS_DBQueue.cpp : implementation file
//

#include "stdafx.h"
#include "spyconsul.h"
#include "RS_DBQueue.h"
#include "PPokerSite.h"
#include "RSLogDBLcoks.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// RS_DBQueue

const int RS_DBQueue::DB_QUEUE_LOWEST_PRIORITY = 4 ;
const int RS_DBQueue::DB_QUEUE_SPY_CONSUL_PRIORITY = 3 ;
const int RS_DBQueue::DB_QUEUE_HISTORY_ANALYSOR_PRIORITY = 2 ;
const int RS_DBQueue::DB_QUEUE_MOVE_DATA_PRIORITY = 1 ;



IMPLEMENT_DYNAMIC(RS_DBQueue, CRecordset)

RS_DBQueue::RS_DBQueue(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(RS_DBQueue)
	m_Queue_Id = 0;
	m_Priority = 0;
	m_Status = 0;
	m_nFields = 3;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString RS_DBQueue::GetDefaultConnect()
{
	return _T(LIVE_POKER_DATA_CONNECT_STRING);
}

CString RS_DBQueue::GetDefaultSQL()
{
	return _T("[dbo].[DB_Queue]");
}

void RS_DBQueue::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(RS_DBQueue)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[Queue Id]"), m_Queue_Id);
	RFX_Byte(pFX, _T("[Priority]"), m_Priority);
	RFX_Byte(pFX, _T("[Status]"), m_Status);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// RS_DBQueue diagnostics

#ifdef _DEBUG
void RS_DBQueue::AssertValid() const
{
	CRecordset::AssertValid();
}

void RS_DBQueue::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

bool RS_DBQueue::CanUseDB(int iPriority)
{
	return true;	
	/*
	if (iPriority == DB_QUEUE_MOVE_DATA_PRIORITY)
	{
		return !DatabaseInUse();
	}
	else
	{
		return HigherPriorityJobInQueue(iPriority);
	}
	*/
}

bool RS_DBQueue::HigherPriorityJobInQueue(int iPriority)
{
	m_strFilter.Format("Priority < %d", iPriority);
	if (IsOpen())
		Close();
	if (Open(CRecordset::snapshot))
	{
		int iRC = GetRecordCount();
		Close();
		return iRC == 0;
	}
	else
	{
		ASSERT(FALSE);
		throw( "Can not open DBQueue AddToQueue");
	}
}

RS_DBQueue::QueueID RS_DBQueue::AddToQueue(int iPriority)
{
	QueueID qID = 0;
	m_strSort = "[Queue Id]";
	if (Open(CRecordset::snapshot))
	{
		try
		{
			AddNew();
			m_Priority = iPriority;
			m_Status =  DB_QUEUE_WAITING;
			Update();
			Requery();
			MoveLast();
			TRACE2("Adding to DBQueue, Id = %d, Priority = %d\n", m_Queue_Id, iPriority);
			qID = m_Queue_Id;
			Close(); 
		}
		catch (...)
		{
			ASSERT(FALSE);
			Close(); 
			throw( "Problem adding queue entry");
		}
		return qID;
	}
	else
	{
		ASSERT(FALSE);
		throw( "Can not open DBQueue AddToQueue");
	}
}

void RS_DBQueue::FinishedUsingDB(QueueID qId)
{
	m_strFilter.Format("[Queue Id] = %d", qId);
	if (Open(CRecordset::snapshot))
	{
		try
		{
			//ASSERT(GetRecordCount() == 1);
			if (GetRecordCount() >= 1)
			{
				Delete();
			}
			Close();
		}
		catch (...)
		{
			ASSERT(FALSE);
			Close();
			throw( "Problem deleting queue entry");
		}
	}
	else
	{
		ASSERT(FALSE);
		throw( "Can not open DBQueue AddToQueue");
	}
	
	RSLogDBLcoks rsLogDBLocks;
	rsLogDBLocks.LogEndLock(qId);
}


RS_DBQueue::QueueID RS_DBQueue::WaitToUseDB(int iPriority, const CString& strDescription)
{
	TRACE("About to wait for DB with Priority %d\n", iPriority);
	QueueID qId = AddToQueue(iPriority);
	while( !CanUseDB(iPriority))
	{
		//Sleep(1000);
	}
	//SetToUsingDB(qId);
	

	RSLogDBLcoks rsLogDBLocks;
	rsLogDBLocks.LogStartLock(qId, strDescription);
	TRACE("Finished waiting for DB with Priority %d QueueId is %d\n", iPriority, qId);
	return qId;
}

void RS_DBQueue::SetToUsingDB(QueueID qId)
{
	m_strFilter.Format("[Queue Id] = %d", qId);
	if (IsOpen())
		Close();
	if (Open(CRecordset::snapshot))
	{
		try
		{
			Edit();
			m_Status =  DB_QUEUE_USING;
			Update();
			Close(); 
		}
		catch (...)
		{
			ASSERT(FALSE);
			Close(); 
			throw( "Problem edeting queue");
		}
	}
	else
	{
		ASSERT(FALSE);
		throw( "Can not open DBQueue AddToQueue");
	}
}

bool RS_DBQueue::DatabaseInUse()
{
	m_strFilter.Format("Status = %d", DB_QUEUE_USING);
	if (IsOpen())
		Close();
	if (Open(CRecordset::snapshot))
	{
		int iRC = GetRecordCount();
		Close();
		return iRC != 0;
	}
	else
	{
		ASSERT(FALSE);
		throw( "Can not open DBQueue AddToQueue");
	}
}
