// TableGridRowData.h: interface for the CTableGridRowData class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TABLEGRIDROWDATA_H__962AA803_DF9E_4F97_9C6E_BD7940B56736__INCLUDED_)
#define AFX_TABLEGRIDROWDATA_H__962AA803_DF9E_4F97_9C6E_BD7940B56736__INCLUDED_

#if !defined(LIST_DEFS)
#define	 LIST_DEFS
#include <list>
using std::list;
typedef std::list <CString>::iterator StringListIterator;
typedef std::list <CString>::const_iterator ConstStringListIterator;
typedef std::list <CString> StringList; 
typedef std::list <CString*> CNickPtrList;
typedef std::list <CString*>::iterator CNickPtrListIter;
#endif


#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CTableGridRowData  
{
public:
	void SetPlayerList(const StringList& listPlayers);
	void Calculate();
	CTableGridRowData();
	CTableGridRowData(const CTableGridRowData& cTGRD);
	CTableGridRowData(const CString& strTableName, HWND hwndTable, HWND hwndDealerText, int iSite);
	CTableGridRowData(const CString& strTableName, int iSite, int iVolPutMoneyInPot, int iSawRiver, int m_iRaisesNotFoldTo,int iVariance);
	virtual ~CTableGridRowData();
	CString GetTableName() const;
	HWND GetWindowHandle() const;
	HWND GetDealerTextWindow() const;
	int GetSite() const;
	int GetVolPutMoneyInPot() const;
	int GetSawRiver() const;
	int	GetRaisesNotFoldTo() const;
	int GetVariance() const;
	int GetNumberOfPlayers() const;
	void SetTableName(const CString&);
	void SetWindowHandle(HWND);
	void SetSite(int);
	void SetVolPutMoneyInPot(int);
	void SetSawRiver(int);
	void SetVariance(int);
	void DUMP() const;

	bool operator!=(const CTableGridRowData& cData) const;
	bool operator==(const CTableGridRowData& cData) const;	  
	CTableGridRowData& operator=(const CTableGridRowData& cTableGridRowData);
	
	StringList GetListOfPlayers() const;
private:
	StringList m_listPlayers;
	CString m_strTableName;
	HWND m_hwndWindowHandle;
	int m_iSite;
	int m_iVolPutMoneyInPot;
	int m_iSawRiver;
	int m_iRaisesNotFoldTo;
	float m_iVariance; 

protected:
	HWND m_hwndDealerTextWindow;
};

#if !defined(DEFINE_GRID_ROW_DATA)
#define DEFINE_GRID_ROW_DATA
typedef std::list<HWND> HWNDList;
typedef HWNDList::iterator HWNDListIterator;

typedef std::list<CTableGridRowData> TableGridRowDataList;
typedef TableGridRowDataList::iterator TableGridRowDataListIterator;
typedef TableGridRowDataList::const_iterator ConstTableGridRowDataListIterator;
#endif


#endif // !defined(AFX_TABLEGRIDROWDATA_H__962AA803_DF9E_4F97_9C6E_BD7940B56736__INCLUDED_)
