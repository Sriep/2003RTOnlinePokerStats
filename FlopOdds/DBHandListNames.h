#if !defined(AFX_DBHANDLISTNAMES_H__FD614140_2D08_40EC_9A6B_00FF9170F434__INCLUDED_)
#define AFX_DBHANDLISTNAMES_H__FD614140_2D08_40EC_9A6B_00FF9170F434__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DBHandListNames.h : header file
//
#include <afxdb.h>
/////////////////////////////////////////////////////////////////////////////
// DBHandListNames recordset

class DBHandListNames : public CRecordset
{
public:
	DBHandListNames(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(DBHandListNames)

// Field/Param Data
	//{{AFX_FIELD(DBHandListNames, CRecordset)
	CString	m_Name;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DBHandListNames)
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

#endif // !defined(AFX_DBHANDLISTNAMES_H__FD614140_2D08_40EC_9A6B_00FF9170F434__INCLUDED_)
