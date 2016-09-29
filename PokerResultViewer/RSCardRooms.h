#if !defined(AFX_RSCARDROOMS_H__A5F0F339_E53C_4BF2_BA14_21C5E3099E1B__INCLUDED_)
#define AFX_RSCARDROOMS_H__A5F0F339_E53C_4BF2_BA14_21C5E3099E1B__INCLUDED_
#include <afxdb.h>
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RSCardRooms.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// RSCardRooms recordset

class RSCardRooms : public CRecordset
{
public:
	RSCardRooms(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(RSCardRooms)

// Field/Param Data
	//{{AFX_FIELD(RSCardRooms, CRecordset)
	long	m_Card_Room_ID;
	CString	m_Card_Room;
	BOOL	m_Online;
	CString	m_Details;
	long	m_FK_Supported_Online;
	//}}AFX_FIELD
	long m_lStateParam;



// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(RSCardRooms)
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

#endif // !defined(AFX_RSCARDROOMS_H__A5F0F339_E53C_4BF2_BA14_21C5E3099E1B__INCLUDED_)
