#if !defined(AFX_RSCURRENCY_H__9C94E603_787C_4B7E_84E2_E4AA7FF6FBB8__INCLUDED_)
#define AFX_RSCURRENCY_H__9C94E603_787C_4B7E_84E2_E4AA7FF6FBB8__INCLUDED_
#include <afxdb.h>
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RSCurrency.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// RSCurrency recordset

class RSCurrency : public CRecordset
{
public:
	RSCurrency(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(RSCurrency)

// Field/Param Data
	//{{AFX_FIELD(RSCurrency, CRecordset)
	long	m_Currency_Code;
	double	m_Exchange_Rate;
	CString	m_Symbol;
	CString m_CurrencyName;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(RSCurrency)
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

#endif // !defined(AFX_RSCURRENCY_H__9C94E603_787C_4B7E_84E2_E4AA7FF6FBB8__INCLUDED_)
