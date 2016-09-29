#if !defined(AFX_PDACTIONSRECORDSET_H__DA7B55F5_34E5_4196_9C5D_5A7CE9143CE4__INCLUDED_)
#define AFX_PDACTIONSRECORDSET_H__DA7B55F5_34E5_4196_9C5D_5A7CE9143CE4__INCLUDED_

#include <afxdb.h>

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PDActionsRecordset.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPDActionsRecordset recordset

class CPDActionsRecordset : public CRecordset
{
public:
	CPDActionsRecordset(CDatabase* pDatabase = NULL);
	CPDActionsRecordset(int iSite, CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CPDActionsRecordset)
	void AddAction(long lResults, int iAction, long iAmount, int Round);

// Field/Param Data
	//{{AFX_FIELD(CPDActionsRecordset, CRecordset)
	long	m_Action_Id;
	long	m_Results_Id;
	int		m_Action;																				
	long	m_Amount;
	int		m_Round;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPDActionsRecordset)
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
	void SetSite(int iSiteId);
private:
	int m_iSiteId;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PDACTIONSRECORDSET_H__DA7B55F5_34E5_4196_9C5D_5A7CE9143CE4__INCLUDED_)
