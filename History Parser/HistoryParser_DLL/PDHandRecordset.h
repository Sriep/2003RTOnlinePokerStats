#if !defined(AFX_PDHANDRECORDSET_H__D48FC77E_E3CF_407E_A73E_08A1587A091E__INCLUDED_)
#define AFX_PDHANDRECORDSET_H__D48FC77E_E3CF_407E_A73E_08A1587A091E__INCLUDED_
 
#include <afxdb.h>

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PDHandRecordset.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPDHandRecordset recordset

class CPDHandRecordset : public CRecordset
{
public:
	void AddJumbledGame(const CString& strGameNumber, int iSiteId);
	bool HasHandBeenRead(const CString& iHandReference, int iSite);
	void PrepareForEdit(bool bIncomplete = FALSE);
	CPDHandRecordset(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CPDHandRecordset)
	bool HandHistoryAlreadyInDatabase(bool bIncomplete);
	void DeleteHandFromdatabase();


// Field/Param Data
	//{{AFX_FIELD(CPDHandRecordset, CRecordset)
	long	m_Hand_Id;
	long	m_Small_bet;
	long	m_Big_bet;
	long	m_Ante;
	CString	m_Hand_reference;
	CTime	m_Date;
	int		m_Variant;
	int		m_Pot;
	BYTE	m_Rake;
	BYTE	m_Flop_card_1_rank;
	BYTE	m_Flop_card_1_suit;
	BYTE	m_Flop_card_2_rank;
	BYTE	m_Flop_card_2_suit;
	BYTE	m_Flop_card_3_rank;
	BYTE	m_Flop_card_3_suit;
	BYTE	m_Turn_rank;
	BYTE	m_Turn_suit;
	BYTE	m_River_rank;
	BYTE	m_River_suit;
	BYTE	m_Active_Players;  
	CString m_Table_name;
	BYTE	m_Incomplete;

	BYTE	m_Jumbled;
	//}}AFX_FIELD

	//Param Data
	CString m_strHandReferenceParam;
	bool m_bParadiseHand;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPDHandRecordset)
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

	private:
	void SetParadiseOn();
};


inline void  CPDHandRecordset::SetParadiseOn()
{
	m_bParadiseHand = true;
	m_nFields = 23;
}

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.





#endif // !defined(AFX_PDHANDRECORDSET_H__D48FC77E_E3CF_407E_A73E_08A1587A091E__INCLUDED_)
