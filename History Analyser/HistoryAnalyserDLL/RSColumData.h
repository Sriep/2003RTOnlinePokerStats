#if !defined(AFX_RSCOLUMDATA_H__49571AE9_4935_42C9_A73E_7A510A7EFAB8__INCLUDED_)
#define AFX_RSCOLUMDATA_H__49571AE9_4935_42C9_A73E_7A510A7EFAB8__INCLUDED_

#include <afxdb.h>

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RSColumData.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CRSColumData recordset

class CRSColumData : public CRecordset
{
public:
	CRSColumData(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CRSColumData)

// Field/Param Data
	//{{AFX_FIELD(CRSColumData, CRecordset)
	int		m_Data_Colum_Id;
	BYTE	m_Grid_Number;
	BYTE	m_Colum_Number;
	BYTE	m_Type;
	CString	m_Header;
	CString	m_Tooltip;
	CString	m_Help;
	CString	m_SP_Count_Numerator;
	CString	m_SP_Count_Denonator;
	CString	m_SP_Numerator_List;
	CString	m_SP_Denominator_List;
	int	m_Dont_show;
	int	m_Italic;
	int	m_Normal;
	int	m_Bold;
	int	m_Underline;
	int	m_Avearage_Value;
	int	m_Variance;
	BYTE m_Axis;
	CString	m_SP_Count_Denonator2;
	CString	m_SP_Count_Denonator3;
	//}}AFX_FIELD
	BYTE m_iGridNumberParam;


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRSColumData)
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

#endif // !defined(AFX_RSCOLUMDATA_H__49571AE9_4935_42C9_A73E_7A510A7EFAB8__INCLUDED_)
