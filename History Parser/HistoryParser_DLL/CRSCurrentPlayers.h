#if !defined(AFX_RSCURRENTPLAYERS1_H__B6226197_16CE_4B74_BE87_F44E9D96D4C9__INCLUDED_)
#define AFX_RSCURRENTPLAYERS1_H__B6226197_16CE_4B74_BE87_F44E9D96D4C9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RSCurrentPlayers1.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CRSCurrentPlayers recordset

class CRSCurrentPlayers : public CRecordset
{
public:
	CRSCurrentPlayers(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CRSCurrentPlayers)

// Field/Param Data
	//{{AFX_FIELD(CRSCurrentPlayers, CRecordset)
	long	m_Player_Id;
	CString	m_Nick;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRSCurrentPlayers)
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
	long AddPlayer(const CString& strNick, int iSite);
	void SetSite(int iSiteId);
private:
	int m_iSiteId;
	CString m_strConnectString;
};

inline void CRSCurrentPlayers::SetSite(int iSiteId)
{
	m_iSiteId = iSiteId;
}

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RSCURRENTPLAYERS1_H__B6226197_16CE_4B74_BE87_F44E9D96D4C9__INCLUDED_)
