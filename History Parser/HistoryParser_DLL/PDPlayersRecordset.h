#if !defined(AFX_PDPLAYERSRECORDSET_H__176B27C9_9E5F_4D88_8017_F158AC002276__INCLUDED_)
#define AFX_PDPLAYERSRECORDSET_H__176B27C9_9E5F_4D88_8017_F158AC002276__INCLUDED_

#include <afxdb.h>
#include "PPokerSite.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PDPlayersRecordset.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPDPlayersRecordset recordset

class CPDPlayersRecordset : public CRecordset
{
public:
	static long GetPlayerId(const CString& strNick, int iSiteId);
	CPDPlayersRecordset(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CPDPlayersRecordset)

// Field/Param Data
	//{{AFX_FIELD(CPDPlayersRecordset, CRecordset)
	long	m_Player_Id;
	CString	m_Nick;
	//}}AFX_FIELD
	//Param Data

	CString m_strNickParam;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPDPlayersRecordset)
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
	//static long GetPlayerId(CString strNick, int iSiteId);
	void SetSite(int iSiteId);
	void UseLogDatabse(bool bUseLogDatanase);
private:
	bool GetFromLogDatabase(const CString &strNick, long& lPlayerId);
	long GetFromOrAddToCurrentDatabase(const CString &strNick);
	static long StaticGetFromOrAddToCurrentDatabase(const CString &strNick, int iSiteId);
	void AddToLogDatabase(const CString &strNick, long lPlayerId);
	long GetPlayerIdA(const CString& strNick, int iSiteId);

	int m_iSiteId;
	CString m_strConnectString;
	bool m_bUseLogDatabase;
};

inline void CPDPlayersRecordset::SetSite(int iSiteId)
{
	m_iSiteId = iSiteId;
}

inline void  CPDPlayersRecordset::UseLogDatabse(bool bUseLogDatanase)
{
	m_bUseLogDatabase = bUseLogDatanase;
	if (bUseLogDatanase)
	{
		m_strConnectString = PPokerSite::GetLoggingSQLConnectString(m_iSiteId);
		//m_nFields = 2;
	}
	else
	{
		m_strConnectString = PPokerSite::GetCurrentSQLConnectString(m_iSiteId);
		//m_nFields = 1;
	}
}


//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PDPLAYERSRECORDSET_H__176B27C9_9E5F_4D88_8017_F158AC002276__INCLUDED_)
