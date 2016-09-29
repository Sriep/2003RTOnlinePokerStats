#if !defined(AFX_RSVARIANTS_H__1B628631_3874_4C86_9F3B_EBC076011F3A__INCLUDED_)
#define AFX_RSVARIANTS_H__1B628631_3874_4C86_9F3B_EBC076011F3A__INCLUDED_
#include <afxdb.h>
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RSVariants.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// RSVariants recordset

class RSVariants : public CRecordset
{
public:
	RSVariants(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(RSVariants)

// Field/Param Data
	//{{AFX_FIELD(RSVariants, CRecordset)
	long	m_Varients_Id;
	CString	m_Name;
	CString	m_Description;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(RSVariants)
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

#endif // !defined(AFX_RSVARIANTS_H__1B628631_3874_4C86_9F3B_EBC076011F3A__INCLUDED_)
