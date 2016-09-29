#if !defined(AFX_PDRESULTSRECORDSET_H__41C155B1_C0C3_4E00_A6CB_3B69F1BCEAEB__INCLUDED_)
#define AFX_PDRESULTSRECORDSET_H__41C155B1_C0C3_4E00_A6CB_3B69F1BCEAEB__INCLUDED_

#include <afxdb.h>

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PDResultsRecordset.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPDResultsRecordset recordset

class CPDResultsRecordset : public CRecordset
{
public:
	long GetResultsFor(long lPlayerId, long lHandId);
	CPDResultsRecordset(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CPDResultsRecordset)

// Field/Param Data
	//{{AFX_FIELD(CPDResultsRecordset, CRecordset)
	long	m_Individual_Results_Id;
	long	m_Hand_Id;
	long	m_Player_Id;
	BYTE	m_Position;
	int		m_Win_loss;
	BYTE	m_First_Card_Rank;
	BYTE	m_First_Card_Suit;
	BYTE	m_Second_Card_Rank;
	BYTE	m_Second_Card_Suit;
	long	m_Chips;
	//}}AFX_FIELD
   	long m_iHandIdParam;
	long m_iPlayerIdParam;


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPDResultsRecordset)
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

#endif // !defined(AFX_PDRESULTSRECORDSET_H__41C155B1_C0C3_4E00_A6CB_3B69F1BCEAEB__INCLUDED_)
