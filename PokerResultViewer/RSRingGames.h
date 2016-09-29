#if !defined(AFX_RSRINGGAMES_H__BDD00D7B_6EDB_4BC2_A307_D2FF26785474__INCLUDED_)
#define AFX_RSRINGGAMES_H__BDD00D7B_6EDB_4BC2_A307_D2FF26785474__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RSRingGames.h : header file
//
#include <afxdb.h>
/////////////////////////////////////////////////////////////////////////////
// RSRingGames recordset

class RSRingGames : public CRecordset
{
public:
	RSRingGames(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(RSRingGames)

// Field/Param Data
	//{{AFX_FIELD(RSRingGames, CRecordset)
	long	m_RingGameId;
	long	m_FK_CardRoom;
	long	m_FK_Varient;
	long	m_FK_BettingFormat;
	long	m_FK_GameSize;
	//}}AFX_FIELD
	long	m_FK_CardRoomParm;
	long	m_FK_VarientParm;
	long	m_FK_BettingFormatParm;
	long	m_FK_GameSizeParm;


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(RSRingGames)
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

#endif // !defined(AFX_RSRINGGAMES_H__BDD00D7B_6EDB_4BC2_A307_D2FF26785474__INCLUDED_)
