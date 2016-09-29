#if !defined(AFX_ACTIVETABLESCOMBO_H__35159D9E_BD71_459C_9F19_10DE82E6352C__INCLUDED_)
#define AFX_ACTIVETABLESCOMBO_H__35159D9E_BD71_459C_9F19_10DE82E6352C__INCLUDED_

#include "StatsGrid1.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ActiveTablesCombo.h : header file
//

#define MAX_NUMBER_OF_OPEN_TABLES 100

/////////////////////////////////////////////////////////////////////////////
// CActiveTablesCombo window

class CActiveTablesCombo : public CComboBox
{
// Construction
public:
	CActiveTablesCombo();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CActiveTablesCombo)
	//}}AFX_VIRTUAL

// Implementation
public:
	CString GetTableName();
	HWND GetDealerTextWindow() const;
	int GetSite() const;
	StringList GetListOfPlayers();
	virtual ~CActiveTablesCombo();

	// Generated message map functions
protected:
	//{{AFX_MSG(CActiveTablesCombo)
	afx_msg void OnDropdown();
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
private:
	HWND m_lDealerWindow [MAX_NUMBER_OF_OPEN_TABLES];
	int m_iSiteId [MAX_NUMBER_OF_OPEN_TABLES];
	CString m_strTableName[MAX_NUMBER_OF_OPEN_TABLES];
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ACTIVETABLESCOMBO_H__35159D9E_BD71_459C_9F19_10DE82E6352C__INCLUDED_)
