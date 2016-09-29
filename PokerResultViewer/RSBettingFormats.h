#if !defined(AFX_RSBETTINGFORMATS_H__D8170ED3_9D1D_4E65_9BEC_98693BAE3C5D__INCLUDED_)
#define AFX_RSBETTINGFORMATS_H__D8170ED3_9D1D_4E65_9BEC_98693BAE3C5D__INCLUDED_
#include <afxdb.h>
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RSBettingFormats.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// RSBettingFormats recordset

class RSBettingFormats : public CRecordset
{
public:
	RSBettingFormats(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(RSBettingFormats)

// Field/Param Data
	//{{AFX_FIELD(RSBettingFormats, CRecordset)
	long	m_BettingFormatID;
	CString	m_BettingFormat;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(RSBettingFormats)
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

#endif // !defined(AFX_RSBETTINGFORMATS_H__D8170ED3_9D1D_4E65_9BEC_98693BAE3C5D__INCLUDED_)
