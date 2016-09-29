#if !defined(AFX_RSCARDSCALLED_H__66B46E69_5629_4507_8449_82B6DED4B72C__INCLUDED_)
#define AFX_RSCARDSCALLED_H__66B46E69_5629_4507_8449_82B6DED4B72C__INCLUDED_
#include <afxdb.h>

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RSCardsCalled.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// RSCardsCalled recordset

class RSCardsCalled : public CRecordset
{
public:
	RSCardsCalled(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(RSCardsCalled)

// Field/Param Data
	//{{AFX_FIELD(RSCardsCalled, CRecordset)
	BYTE	m_First_Card_Rank;
	BYTE	m_First_Card_Suit;
	BYTE	m_Second_Card_Rank;
	BYTE	m_Second_Card_Suit;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(RSCardsCalled)
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

#endif // !defined(AFX_RSCARDSCALLED_H__66B46E69_5629_4507_8449_82B6DED4B72C__INCLUDED_)
