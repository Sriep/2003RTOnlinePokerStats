#if !defined(AFX_SPRSCOUNTHANDS_H__FC2D83B6_2204_4931_8B01_1F6990E975E6__INCLUDED_)
#define AFX_SPRSCOUNTHANDS_H__FC2D83B6_2204_4931_8B01_1F6990E975E6__INCLUDED_

#pragma warning( disable : 4786 )  
#include <afxdb.h>
#include <map>
#include "SPDataKey.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SPRSCountHands.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// SPRSCountHands recordset

#define SPRESULT_CASH_START_SIZE 256
//typedef  CMap<CSPDataKey, CSPDataKey&, long, long&> SPCash;

using std::map;
typedef std::map<CSPDataKey, long> SPCash; 
typedef std::map <CSPDataKey, long>::iterator SPCashIterator;
typedef std::map <CSPDataKey, long>::const_iterator ConstSPCashIterator;

class SPRSCountHands : public CRecordset
{
public:
	static long ReadValuArchiveFromDB(const CString& strProc, const CString strNick, int iPokerSite);
	static long ReadValuCurrentFromDB(const CString& strProc, const CString strNick, int iPokerSite);
	SPRSCountHands(CDatabase* pDatabase = NULL);
	SetSiteId(int iSiteId);
	DECLARE_DYNAMIC(SPRSCountHands)

// Field/Param Data
	//{{AFX_FIELD(SPRSCountHands, CRecordset)
	long m_lNumber;
	CString m_strNickParam;
	//}}AFX_FIELD

	static int GetValue(const CString& strProcdeure, const CString& strNick, int iPokerSite);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(SPRSCountHands)
	public:
	virtual CString GetDefaultConnect();    // Default connection string
	virtual CString GetDefaultSQL();    // Default SQL for Recordset
	virtual void DoFieldExchange(CFieldExchange* pFX);  // RFX support
	//}}AFX_VIRTUAL

// Implementation
	void UseLogDatabase(bool bUseLogDatabase);

#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
private:
	static long GetValueCurrentDB(const CString& strProcdeure, const CString& strNick, int iPokerSite);
	//static long GetValueLogDB(const CString& strProcdeure, const CString& strNick, int iPokerSite);
	static long GetValueArchiveDB(const CString& strProcdeure, const CString& strNick, int iPokerSite);
	long GetValueI(const CString& strProcdeure, const CString& strNick, int iPokerSite);
	static bool AreHandsInArchiveDB(const CString& strNick, int iPokerSite);
	
	int m_iSiteId;
	CString m_strConnectString;	
	bool m_bUseLogDatabse;
	static SPCash sm_cSP_ResultCash;
};

inline 	SPRSCountHands::SetSiteId(int iSiteId)
{
	 m_iSiteId = iSiteId;
}


//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SPRSCOUNTHANDS_H__FC2D83B6_2204_4931_8B01_1F6990E975E6__INCLUDED_)
