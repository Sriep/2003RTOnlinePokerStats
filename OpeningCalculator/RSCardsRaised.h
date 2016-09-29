#if !defined(AFX_RSCARDSRAISED_H__09B963A4_9470_43D4_89DC_8843843BE3DF__INCLUDED_)
#define AFX_RSCARDSRAISED_H__09B963A4_9470_43D4_89DC_8843843BE3DF__INCLUDED_
#include <afxdb.h>

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RSCardsRaised.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// RSCardsRaised recordset

class RSCardsRaised : public CRecordset
{
public:
	RSCardsRaised(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(RSCardsRaised)

// Field/Param Data
	//{{AFX_FIELD(RSCardsRaised, CRecordset)
	int	m_First_Card_Rank;
	int	m_First_Card_Suit;
	int	m_Second_Card_Rank;
	int	m_Second_Card_Suit;
	int m_Position;

	int*	m_pFirst_Card_Rank;
	int*	m_pFirst_Card_Suit;
	int*	m_pSecond_Card_Rank;
	int*	m_pSecond_Card_Suit;
 	int*	m_pPosition;

	long*	m_pFirst_Card_RankLengths;
	long*	m_pFirst_Card_SuitLengths;
	long*	m_pSecond_Card_RankLengths;
	long*	m_pSecond_Card_SuitLengths;
	long*	m_pPositionLengths;
	//}}AFX_FIELD
	CString m_strNickParam;
	int		m_iHostParam;
	int		m_iVariant;
	CTime	m_tDate;




// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(RSCardsRaised)
	public:
	virtual CString GetDefaultConnect();    // Default connection string
	virtual CString GetDefaultSQL();    // Default SQL for Recordset
	virtual void DoFieldExchange(CFieldExchange* pFX);  // RFX support
	//}}AFX_VIRTUAL
	void DoBulkFieldExchange( CFieldExchange* pFX )	;


// Implementation
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RSCARDSRAISED_H__09B963A4_9470_43D4_89DC_8843843BE3DF__INCLUDED_)
