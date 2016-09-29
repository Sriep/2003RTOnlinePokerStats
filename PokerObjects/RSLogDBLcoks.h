#if !defined(AFX_RSLOGDBLCOKS_H__5D218FE6_ABCD_4A71_88B6_71D48475193F__INCLUDED_)
#define AFX_RSLOGDBLCOKS_H__5D218FE6_ABCD_4A71_88B6_71D48475193F__INCLUDED_
#include <afxdb.h>

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RSLogDBLcoks.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// RSLogDBLcoks recordset

class RSLogDBLcoks : public CRecordset
{
public:
	RSLogDBLcoks(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(RSLogDBLcoks)

// Field/Param Data
	//{{AFX_FIELD(RSLogDBLcoks, CRecordset)
	long	m_DBLock_Id;
	long	m_Queue_Id;
	CTime	m_Start_time;
	CTime	m_end_time;
	long	m_Total_seconds;
	CString	m_Description;
	//}}AFX_FIELD

	//Param Data
	long m_iQueueIdParam;


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(RSLogDBLcoks)
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

	void LogStartLock(long lQueueId, CString strDescription);
	void LogEndLock(long lQueueId);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RSLOGDBLCOKS_H__5D218FE6_ABCD_4A71_88B6_71D48475193F__INCLUDED_)
