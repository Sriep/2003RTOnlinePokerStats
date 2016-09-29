#if !defined(AFX_RSCURRENTTABLES_H__EDF70A75_34D3_48BF_AC25_0620755D87DE__INCLUDED_)
#define AFX_RSCURRENTTABLES_H__EDF70A75_34D3_48BF_AC25_0620755D87DE__INCLUDED_

#include <afxdb.h>
#include "TableGridRowData.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RSCurrentTables.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// RSCurrentTables recordset

class RSCurrentTables : public CRecordset
{
public:
	void DeleteAll();
	long GetTableId(HWND hwnd, int iSite, const CString& strTableName);
	long GetTableId(HWND hwnd, int iSite);

	void RemoveTable(CString strTableName, HWND hwndWindow, int iSite);
	long AddTable(const CString& strTableName, HWND hwndDealerWindow, int iSite);
	RSCurrentTables(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(RSCurrentTables)

// Field/Param Data
	//{{AFX_FIELD(RSCurrentTables, CRecordset)
	long    m_CurrentTableId;
	int		m_Site;
	long	m_DealerWindow;
	CString	m_TableName;
	//}}AFX_FIELD

	//Param Data
	int m_iSiteParam;
	long m_iDealerWindowParam;
	CString m_strTableNameParam;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(RSCurrentTables)
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

#endif // !defined(AFX_RSCURRENTTABLES_H__EDF70A75_34D3_48BF_AC25_0620755D87DE__INCLUDED_)
