#if !defined(AFX_SPRSCOUNTHANDS_H__FC2D83B6_2204_4931_8B01_1F6990E975E6__INCLUDED_)
#define AFX_SPRSCOUNTHANDS_H__FC2D83B6_2204_4931_8B01_1F6990E975E6__INCLUDED_

#include <afxdb.h>

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SPRSCountHands.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// SPRSCountHands recordset

class SPRSCountHands : public CRecordset
{
public:
	SPRSCountHands(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(SPRSCountHands)

// Field/Param Data
	//{{AFX_FIELD(SPRSCountHands, CRecordset)
	long m_lNumber;
	CString m_strNickParam;
	int		m_iHostParam;
	//}}AFX_FIELD

	static int GetValue(CString strProcdeure, CString strNick, int iPokerSite);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(SPRSCountHands)
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

#endif // !defined(AFX_SPRSCOUNTHANDS_H__FC2D83B6_2204_4931_8B01_1F6990E975E6__INCLUDED_)
