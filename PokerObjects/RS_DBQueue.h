#if !defined(AFX_RS_DBQUEUE_H__5D884B58_3F6A_4D77_9AB1_7BB0E63EF658__INCLUDED_)
#define AFX_RS_DBQUEUE_H__5D884B58_3F6A_4D77_9AB1_7BB0E63EF658__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RS_DBQueue.h : header file
//
#include <afxdb.h>
/////////////////////////////////////////////////////////////////////////////
// RS_DBQueue recordset

class RS_DBQueue : public CRecordset
{
public:
	enum QueueAction
	{
		DB_QUEUE_WAITING = 0,
		DB_QUEUE_USING = 1,
		DB_QUEUE_FINISHED = 2,
		NUM_DB_QUEUE_ACTIONS
	};

	typedef int QueueID;
	static const int DB_QUEUE_LOWEST_PRIORITY;
	static const int DB_QUEUE_HISTORY_ANALYSOR_PRIORITY;
	static const int DB_QUEUE_SPY_CONSUL_PRIORITY;
	static const int DB_QUEUE_MOVE_DATA_PRIORITY;

	RS_DBQueue::QueueID WaitToUseDB(int iPriority, const CString& strDescription);
	void FinishedUsingDB(QueueID qid);

	RS_DBQueue(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(RS_DBQueue)

// Field/Param Data
	//{{AFX_FIELD(RS_DBQueue, CRecordset)
	long	m_Queue_Id;
	BYTE	m_Priority;
	BYTE	m_Status;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(RS_DBQueue)
	public:
	virtual CString GetDefaultConnect();    // Default connection string
	virtual CString GetDefaultSQL();    // Default SQL for Recordset
	virtual void DoFieldExchange(CFieldExchange* pFX);  // RFX support
	//}}AFX_VIRTUAL

// Implementation
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
private:
	void SetToUsingDB(QueueID qId);
	QueueID AddToQueue(int iPriority);
	bool CanUseDB(int iPriority);
	bool HigherPriorityJobInQueue(int iPriority);
	bool DatabaseInUse();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RS_DBQUEUE_H__5D884B58_3F6A_4D77_9AB1_7BB0E63EF658__INCLUDED_)
