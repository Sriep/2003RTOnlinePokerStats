// SPDataKey.h: interface for the CSPDataKey class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SPDATAKEY_H__F6E2DFBD_91A3_4B6C_B2B4_5813331C6EAF__INCLUDED_)
#define AFX_SPDATAKEY_H__F6E2DFBD_91A3_4B6C_B2B4_5813331C6EAF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CSPDataKey  
{
public:
	CSPDataKey();
	CSPDataKey(const CSPDataKey& key);
	CSPDataKey(const CString& strSPName, const CString& strNick, int iSite);
	virtual ~CSPDataKey();

	bool operator==(const CSPDataKey& key) const;
	CSPDataKey& operator=(const CSPDataKey& key);
	bool operator<(const CSPDataKey& card) const;
	bool operator<=(const CSPDataKey& card) const;
	bool operator>(const CSPDataKey& card) const;
	bool operator>=(const CSPDataKey& card) const;

private:
	CString m_strSPName;
	CString m_strNick;
	int m_iSite;
};


inline bool CSPDataKey::operator==(const CSPDataKey& key) const
{
	return m_strSPName == key.m_strSPName && m_strNick == key.m_strNick && m_iSite == key.m_iSite;
}

inline CSPDataKey& CSPDataKey::operator=(const CSPDataKey& key)
{
	m_strSPName = key.m_strSPName;
	m_strNick = key.m_strNick;
	m_iSite = key.m_iSite;
	return *this;
}

inline bool CSPDataKey::operator<(const CSPDataKey& key) const	
{
	if (m_iSite == key.m_iSite)
	{
		if (m_strNick == key.m_strNick)
		{
			return	m_strSPName < key.m_strSPName;
		}
		else
		{
			return m_strNick < key.m_strNick;
		}
	}
	else
	{
		return m_iSite < key.m_iSite;
	}
}

inline bool CSPDataKey::operator<=(const CSPDataKey& key) const	
{
	if (m_iSite == key.m_iSite)
	{
		if (m_strNick == key.m_strNick)
		{
			return	m_strSPName <= key.m_strSPName;
		}
		else
		{
			return m_strNick <= key.m_strNick;
		}
	}
	else
	{
		return m_iSite <= key.m_iSite;
	}
}

inline bool CSPDataKey::operator>(const CSPDataKey& key) const  
{
	if (m_iSite == key.m_iSite)
	{
		if (m_strNick == key.m_strNick)
		{
			return	m_strSPName > key.m_strSPName;
		}
		else
		{
			return m_strNick > key.m_strNick;
		}
	}
	else
	{
		return m_iSite > key.m_iSite;
	}
}

inline bool CSPDataKey::operator>=(const CSPDataKey& key) const 
{
	if (m_iSite == key.m_iSite)
	{
		if (m_strNick == key.m_strNick)
		{
			return	m_strSPName >= key.m_strSPName;
		}
		else
		{
			return m_strNick >= key.m_strNick;
		}
	}
	else
	{
		return m_iSite >= key.m_iSite;
	}
}



#endif // !defined(AFX_SPDATAKEY_H__F6E2DFBD_91A3_4B6C_B2B4_5813331C6EAF__INCLUDED_)
																																	  

