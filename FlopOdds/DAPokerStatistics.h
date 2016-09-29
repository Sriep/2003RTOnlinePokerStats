#if !defined(AFX_DAPOKERSTATISTICS_H__BECD72A3_170F_4C22_A214_3E7E3341FF32__INCLUDED_)
#define AFX_DAPOKERSTATISTICS_H__BECD72A3_170F_4C22_A214_3E7E3341FF32__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DAPokerStatistics.h : header file
//
#include <afxdb.h>
/////////////////////////////////////////////////////////////////////////////
// DAPokerStatistics recordset

class DAPokerStatistics : public CRecordset
{
public:
	DAPokerStatistics(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(DAPokerStatistics)

// Field/Param Data
	//{{AFX_FIELD(DAPokerStatistics, CRecordset)
	long	m_ListId;
	CString	m_Name;
	long	m_Card1;
	long	m_Card2;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DAPokerStatistics)
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

#endif // !defined(AFX_DAPOKERSTATISTICS_H__BECD72A3_170F_4C22_A214_3E7E3341FF32__INCLUDED_)
