#if !defined(AFX_SPDELETEHAND_H__5CB370E7_3894_4851_862C_23A96858D46A__INCLUDED_)
#define AFX_SPDELETEHAND_H__5CB370E7_3894_4851_862C_23A96858D46A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SPDeleteHand.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// SPDeleteHand recordset

class SPDeleteHand : public CRecordset
{
public:
	SPDeleteHand(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(SPDeleteHand)

// Field/Param Data
	//{{AFX_FIELD(SPDeleteHand, CRecordset)
	//}}AFX_FIELD
	CString m_strHandReferenceParm;



// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(SPDeleteHand)
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

#endif // !defined(AFX_SPDELETEHAND_H__5CB370E7_3894_4851_862C_23A96858D46A__INCLUDED_)
