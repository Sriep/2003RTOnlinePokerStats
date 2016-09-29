// PPokerSite.h: interface for the PPokerSite class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PPOKERSITE_H__AB0431A4_7026_4BBF_BA75_2E619A6B68FA__INCLUDED_)
#define AFX_PPOKERSITE_H__AB0431A4_7026_4BBF_BA75_2E619A6B68FA__INCLUDED_
#include "PPokerObject.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class PPokerSite : public PPokerObject  
{
public:
	PPokerSite(const PPokerSite& cSite);
	enum PokerSite
	{
		POKER_SITE_NONE = 0,
		POKER_SITE_PARTY = 1,
		POKER_SITE_PARADISE = 2,
		POKER_SITE_STARS = 3,
		POKER_SITE_TRUE = 4,
		POKER_SITE_ULTIMATE_BET = 5,
		POKER_SITE_LABROKES = 6,
		POKER_SITE_POKER_ROOM = 7,
		POKER_SITE_ROYAL_VEGAS = 8,
		POKER_SITE_HIGH_STAKES = 9,
		POKER_SITE_WSEX = 10,
		POKER_SITE_POKER_CLUB = 11,
		POKER_SITE_CRYPTOLOGIC = 12,
		NUM_OF_POKER_SITES
	};
	
	PPokerSite();
	PPokerSite(int iSiteId);
	virtual ~PPokerSite();
	bool operator==(const PPokerSite& sPPokerSite) const;
	PPokerSite& operator=(const PPokerSite& cPokerSite);
	CString Name() const;
	void DUMP() const;
	static CString GetName(int iSiteId);
	static CString GetDealerTextName(HWND hwnd, int iSiteId);
	static CString GetPlayerListName(HWND hwnd, int iSiteId);

	static CString GetLoggingSQLConnectString(int iSiteId);
	static CString GetCurrentSQLConnectString(int iSiteId);
	static CString GetArchiveSQLConnectString(int iSiteId);
	static CString GetLoggingDataSource(int iSiteId);
	static CString GetCurrentDataSource(int iSiteId);
	static CString GetArchiveDataSource(int iSiteId);
private:
	static CString GetCompactName(int iSiteId);
	PokerSite m_eSite;
};

inline PPokerSite::PPokerSite(int iSiteId)
{
	if (POKER_SITE_NONE <= iSiteId &&  NUM_OF_POKER_SITES> iSiteId)
	{
		m_eSite = (PokerSite) iSiteId;
	}
	else
	{
		m_eSite = POKER_SITE_NONE;
	}
}

inline PPokerSite::PPokerSite(const PPokerSite &cSite)
{
		m_eSite = cSite.m_eSite;
}

inline bool PPokerSite::operator==(const PPokerSite& cPokerSite) const
{
	return m_eSite == cPokerSite.m_eSite;
}

  
inline PPokerSite& PPokerSite::operator=(const PPokerSite& cPokerSite)
{
	m_eSite = cPokerSite.m_eSite;
	return *this;
}

inline CString PPokerSite::Name() const
{
	switch (m_eSite)
	{
	case POKER_SITE_NONE:
		return CString("No site");
	case POKER_SITE_PARTY:
		return CString("Party Poker");
	case POKER_SITE_PARADISE:
		return CString("Paradise Poker");
	case POKER_SITE_STARS:
		return CString("Poker Stars");
	case POKER_SITE_TRUE:
		return CString("True Poker");
	case POKER_SITE_ULTIMATE_BET:
		return CString("Ultimate Bet");
	case POKER_SITE_LABROKES:				   
		return CString("Labrokes Poker");
	case POKER_SITE_POKER_ROOM:				   
		return CString("Poker Room");	   
	case POKER_SITE_ROYAL_VEGAS:				   
		return CString("Royal Vegas");
	case POKER_SITE_HIGH_STAKES:				   
		return CString("High Stakes Bookstore");
	case NUM_OF_POKER_SITES:
		return CString("No site");
	case POKER_SITE_WSEX:
		return CString("World Poker Exchange");
	case POKER_SITE_POKER_CLUB:
		return CString("The Poker Club");
	case POKER_SITE_CRYPTOLOGIC:
		return CString("Cryptologic");
	default:
		ASSERT(false);
		return CString("Not Found");
	}

} 

inline CString PPokerSite::GetName(int iSiteId) 
{
	switch (iSiteId)
	{
	case POKER_SITE_NONE:
		return CString("No site");
	case POKER_SITE_PARTY:
		return CString("Party Poker");
	case POKER_SITE_PARADISE:
		return CString("Paradise Poker");
	case POKER_SITE_STARS:
		return CString("Poker Stars");
	case POKER_SITE_TRUE:
		return CString("True Poker");
	case POKER_SITE_ULTIMATE_BET:
		return CString("Ultimate Bet");
	case POKER_SITE_LABROKES:
		return CString("Labrokes Poker");
	case POKER_SITE_ROYAL_VEGAS:
		return CString("Royal Vegas");
	case POKER_SITE_POKER_ROOM:				   
		return CString("Poker Room");
	case POKER_SITE_HIGH_STAKES:				   
		return CString("High Stakes Bookstore");
	case POKER_SITE_WSEX:
		return CString("World Poker Exchange");
	case POKER_SITE_POKER_CLUB:
		return CString("The Poker Club");
	case POKER_SITE_CRYPTOLOGIC:
		return CString("Cryptologic");
	case NUM_OF_POKER_SITES:
		return CString("No site");
	default:
		ASSERT(false);
		return CString("Not Found");
	}
}
/*
inline CString PPokerSite::GetSQLConnectString(int iSiteId)
{
	switch (iSiteId)
	{
	case POKER_SITE_NONE:
		return CString("ODBC;DSN=PokerData;UID=sa;PWD=;");
	case POKER_SITE_PARTY:
		return CString("ODBC;DSN=LogParty;UID=sa;PWD=;");
	case POKER_SITE_PARADISE:
		return CString("ODBC;DSN=LogParadise;UID=sa;PWD=;");
	case POKER_SITE_STARS:
		return CString("ODBC;DSN=PokerData;UID=sa;PWD=;");
	case POKER_SITE_TRUE:
		return CString("ODBC;DSN=LogTrue;UID=sa;PWD=;");
	case POKER_SITE_ULTIMATE_BET:
		return CString("ODBC;DSN=LogUltimateBet;UID=sa;PWD=;");
	case POKER_SITE_LABROKES:
		return CString("ODBC;DSN=LogLabrokes;UID=sa;PWD=;");
	case POKER_SITE_ROYAL_VEGAS:
		return CString("ODBC;DSN=LogRoyalVegas;UID=sa;PWD=;");
	case POKER_SITE_POKER_ROOM:				   
		return CString("ODBC;DSN=PokerData;UID=sa;PWD=;");
	case POKER_SITE_HIGH_STAKES:				   
		return CString("ODBC;DSN=LogHighStakes;UID=sa;PWD=;");
	case POKER_SITE_WSEX:
		return CString("ODBC;DSN=LogWSEX;UID=sa;PWD=;");
	case POKER_SITE_POKER_CLUB:
		return CString("ODBC;DSN=LogThePokerClub;UID=sa;PWD=;");
	case NUM_OF_POKER_SITES:
		return CString("ODBC;DSN=PokerData;UID=sa;PWD=;");
	default:
		ASSERT(false);
		return CString("ODBC;DSN=PokerData;UID=sa;PWD=;");
	}
} */

inline CString PPokerSite::GetLoggingSQLConnectString(int iSiteId)
{
	CString strConnectString = "ODBC;DSN=Log";
	strConnectString += GetCompactName(iSiteId);
	strConnectString += ";UID=sa;PWD=;";
	return strConnectString;
}

inline CString PPokerSite::GetCurrentSQLConnectString(int iSiteId)
{
	CString strConnectString = "ODBC;DSN=Current";
	strConnectString += GetCompactName(iSiteId);
	strConnectString += ";UID=sa;PWD=;";
	return strConnectString;
}

inline CString PPokerSite::GetArchiveSQLConnectString(int iSiteId) 
{
	CString strConnectString = "ODBC;DSN=Archive";
	strConnectString += GetCompactName(iSiteId);
	strConnectString += ";UID=sa;PWD=;";
	return strConnectString;
}

inline CString PPokerSite::GetLoggingDataSource(int iSiteId)
{
	CString strDataSource = "Log";
	strDataSource += GetCompactName(iSiteId);
	return strDataSource;			
}

inline CString PPokerSite::GetCurrentDataSource(int iSiteId)
{
	CString strDataSource = "Current";
	strDataSource += GetCompactName(iSiteId);
	return strDataSource;
}

inline CString PPokerSite::GetArchiveDataSource(int iSiteId) 
{
	CString strDataSource = "Archive";
	strDataSource += GetCompactName(iSiteId);
	return strDataSource;
}


inline CString PPokerSite::GetCompactName(int iSiteId)
{
	switch (iSiteId)
	{
	case POKER_SITE_NONE:
		return CString("PokerData");
	case POKER_SITE_PARTY:
		return CString("Party");
	case POKER_SITE_PARADISE:
		return CString("Paradise");
	case POKER_SITE_STARS:
		return CString("PokerData");
	case POKER_SITE_TRUE:
		return CString("True");
	case POKER_SITE_ULTIMATE_BET:
		return CString("UltimateBet");
	case POKER_SITE_LABROKES:
		return CString("Labrokes");
	case POKER_SITE_ROYAL_VEGAS:
		return CString("RoyalVegas");
	case POKER_SITE_POKER_ROOM:				   
		return CString("PokerRoom");
	case POKER_SITE_HIGH_STAKES:				   
		return CString("HighStakes");
	case POKER_SITE_WSEX:
		return CString("WSEX");
	case POKER_SITE_POKER_CLUB:
		return CString("ThePokerClub");
	case NUM_OF_POKER_SITES:
		return CString("PokerData");
	case POKER_SITE_CRYPTOLOGIC:
		return CString("Cryptologic");
	default:
		ASSERT(false);
		return CString("PokerData");
	}
}

#endif // !defined(AFX_PPOKERSITE_H__AB0431A4_7026_4BBF_BA75_2E619A6B68FA__INCLUDED_)
