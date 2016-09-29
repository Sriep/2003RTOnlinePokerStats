#if !defined(AFX_RSGAMESIZE_H__92F6730F_E168_4090_8B03_90B7EE056B78__INCLUDED_)
#define AFX_RSGAMESIZE_H__92F6730F_E168_4090_8B03_90B7EE056B78__INCLUDED_
#include <afxdb.h>
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RSGameSize.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// RSGameSize recordset

class RSGameSize : public CRecordset
{
public:
	void ActivateFilter();
	RSGameSize(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(RSGameSize)

// Field/Param Data
	//{{AFX_FIELD(RSGameSize, CRecordset)
	long	m_Game_Size_Id;
	long	m_Small_Blind;
	long	m_Middle_Blind;
	long	m_Big_Blind;
	long	m_Ante;
	long	m_Small_Bet;
	long	m_Big_Bet;
	CString	m_Name;
	long	m_FK_Currency;
	//}}AFX_FIELD

	long	m_Small_BlindParm;
	long	m_Middle_BlindParm;
	long	m_Big_BlindParm;
	long	m_AnteParm;
	long	m_Small_BetParm;
	long	m_Big_BetParm;
	long	m_FK_CurrencyParm;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(RSGameSize)
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

#endif // !defined(AFX_RSGAMESIZE_H__92F6730F_E168_4090_8B03_90B7EE056B78__INCLUDED_)
