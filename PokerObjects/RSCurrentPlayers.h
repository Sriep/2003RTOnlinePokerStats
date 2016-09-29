#if !defined(AFX_RSCURRENTPLAYERS_H__8A3CFA4C_C014_4DC7_9B4A_FBC7EB0A29E1__INCLUDED_)
#define AFX_RSCURRENTPLAYERS_H__8A3CFA4C_C014_4DC7_9B4A_FBC7EB0A29E1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RSCurrentPlayers.h : header file
//
#include <afxdb.h>
#include "TableGridRowData.h"
#include "PlayerList.h"	// Added by ClassView
/////////////////////////////////////////////////////////////////////////////
// RSCurrentPlayers recordset

class RSCurrentPlayers : public CRecordset
{
public:
	void DeleteAll();
	StringList GetPlayerList(HWND hwnd, int iSiteId, const CString& strTableName);
	StringList GetPlayerList(long lActiveTableId);
	void DeletePlayers(HWND hwnd, int iSite);
	void RefreshPlayerList(HWND hwnd, int iSiteId, StringList listPlayers, const CString& strTableName);
	RSCurrentPlayers(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(RSCurrentPlayers)

// Field/Param Data
	//{{AFX_FIELD(RSCurrentPlayers, CRecordset)
	long	m_CurrentPlayerId;
	long	m_FK_CurrentTable;
	CString	m_Name;
	//}}AFX_FIELD
	long m_lFK_TableIdParam;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(RSCurrentPlayers)
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

#endif // !defined(AFX_RSCURRENTPLAYERS_H__8A3CFA4C_C014_4DC7_9B4A_FBC7EB0A29E1__INCLUDED_)
