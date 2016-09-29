#if !defined(AFX_RSPokerBase_H__EDF70A75_34D3_48BF_AC25_0620755D87DE__INCLUDED_)
#define AFX_RSPokerBase_H__EDF70A75_34D3_48BF_AC25_0620755D87DE__INCLUDED_

#include <afxdb.h>

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RSPokerBase.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// RSPokerBase recordset

class RSPokerBase : public CRecordset
{
public:
	RSPokerBase(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(RSPokerBase)

// Field/Param Data
	//{{AFX_FIELD(RSPokerBase, CRecordset)
	//}}AFX_FIELD

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(RSPokerBase)
	public:
	//}}AFX_VIRTUAL

// Implementation
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RSPokerBase_H__EDF70A75_34D3_48BF_AC25_0620755D87DE__INCLUDED_)
