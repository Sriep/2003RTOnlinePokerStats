// ParseLogFile.h: interface for the CParseLogFile class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PARSELOGFILE_H__61C72E8F_F84E_4C91_AECF_B27F71BA93AF__INCLUDED_)
#define AFX_PARSELOGFILE_H__61C72E8F_F84E_4C91_AECF_B27F71BA93AF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ParseFile.h"

class CParseLogFile : public CParseFile  
{
public:
	CParseLogFile();
	virtual ~CParseLogFile();
	static CParseLogFile* New(int iSite);
	virtual bool HasFoundAllPlayersInHand() const;
	virtual void SetAllPlayersInHandFound(bool bVal);
	virtual void RefreshPlayers();
	virtual void NewHand();
	virtual void SavePlayersList();
	virtual void ParseLogFile(HWND hwnd, long& lFilePositionconst, const CString& strTableName);
	virtual bool IsLog();
	virtual int GetNumberOfHiddenCharactersPerLogLine() const;
	int GetHandsRead() const;
	static CString GetGameNumber(LPSTR pchInputLine, char chEndOfGameNumber);

protected:
	bool m_bFoundAllPlayers;
	bool m_bNewHand;
	HWND m_hwndDealerText;
	StringList m_listNicksLastHand;
	int m_iHandsRead;
};

inline int CParseLogFile::GetHandsRead() const
{
	return m_iHandsRead;
}

inline CString CParseLogFile::GetGameNumber(LPSTR pchInputLine, char chEndOfGameNumber)
{
	char* pchEndOfHandNumber = 	strchr(pchInputLine, chEndOfGameNumber);
	if (pchEndOfHandNumber != NULL)
	{
		CString strHandNumber ="";
		for (char* pch = pchInputLine ; pch != pchEndOfHandNumber ; pch++ )
		{
			if (*pch != ',')
			{
				strHandNumber += *pch;	
			}
		}
		return strHandNumber;
	}
	return CString("0");
}

#endif // !defined(AFX_PARSELOGFILE_H__61C72E8F_F84E_4C91_AECF_B27F71BA93AF__INCLUDED_)
