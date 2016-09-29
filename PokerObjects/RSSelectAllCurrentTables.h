#if !defined(AFX_RSSELECTALLCURRENTTABLES_H__FABBCDBE_D9ED_419F_B66A_21033B219311__INCLUDED_)
#define AFX_RSSELECTALLCURRENTTABLES_H__FABBCDBE_D9ED_419F_B66A_21033B219311__INCLUDED_
#include <afxdb.h>
#include "TableGridRowData.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RSSelectAllCurrentTables.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// RSSelectAllCurrentTables recordset

class RSSelectAllCurrentTables : public CRecordset
{
public:
	TableGridRowDataList GetActiveTablesFromDB();
	RSSelectAllCurrentTables(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(RSSelectAllCurrentTables)

// Field/Param Data
	//{{AFX_FIELD(RSSelectAllCurrentTables, CRecordset)
	long	m_CurrentTableId;
	int		m_Site;
	long	m_DealerWindow;
	CString	m_TableName;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(RSSelectAllCurrentTables)
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
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RSSELECTALLCURRENTTABLES_H__FABBCDBE_D9ED_419F_B66A_21033B219311__INCLUDED_)
