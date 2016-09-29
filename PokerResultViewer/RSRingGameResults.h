#if !defined(AFX_RSRINGGAMERESULTS_H__CBFB366B_0619_48D3_88A7_324C228E426E__INCLUDED_)
#define AFX_RSRINGGAMERESULTS_H__CBFB366B_0619_48D3_88A7_324C228E426E__INCLUDED_
#include <afxdb.h>
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RSRingGameResults.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// RSRingGameResults recordset

class RSRingGameResults : public CRecordset
{
public:
	RSRingGameResults(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(RSRingGameResults)

// Field/Param Data
	//{{AFX_FIELD(RSRingGameResults, CRecordset)
	long	m_ResultID;
	long	m_FK_RingGames;
	CTime	m_Date;
	long	m_Duration;
	long	m_WinLoss;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(RSRingGameResults)
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

#endif // !defined(AFX_RSRINGGAMERESULTS_H__CBFB366B_0619_48D3_88A7_324C228E426E__INCLUDED_)
