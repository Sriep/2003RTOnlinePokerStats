#if !defined(AFX_RSPLAYERS_H__53DAD451_0636_44F8_88F4_329A96026CCC__INCLUDED_)
#define AFX_RSPLAYERS_H__53DAD451_0636_44F8_88F4_329A96026CCC__INCLUDED_

#include <afxdb.h>

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RSPlayers.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// RSPlayers recordset

#define PLAYER_NAME_MAX_LENGTH 50

class RSPlayers : public CRecordset
{
public:
	RSPlayers(CDatabase* pDatabase = NULL);
	RSPlayers(int iSite);
	DECLARE_DYNAMIC(RSPlayers)

// Field/Param Data
	//{{AFX_FIELD(RSPlayers, CRecordset)
	int	m_Player_Id;
	//}}AFX_FIELD

	LPSTR	m_pPlayer;
	long*	m_pPlayerLengths;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(RSPlayers)
	public:
	virtual CString GetDefaultConnect();    // Default connection string
	virtual CString GetDefaultSQL();    // Default SQL for Recordset
	virtual void DoFieldExchange(CFieldExchange* pFX);  // RFX support
	//}}AFX_VIRTUAL
	void DoBulkFieldExchange( CFieldExchange* pFX )	;
	void SetSite(int iSite);

// Implementation
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif	 

private:
	int m_iSiteId;	

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RSPLAYERS_H__53DAD451_0636_44F8_88F4_329A96026CCC__INCLUDED_)
