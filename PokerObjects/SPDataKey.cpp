// SPDataKey.cpp: implementation of the CSPDataKey class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SPDataKey.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CSPDataKey::CSPDataKey()
{

}

CSPDataKey::CSPDataKey(const CSPDataKey& key)
:	m_strSPName(key.m_strSPName),
	m_strNick(key.m_strNick),
	m_iSite(key.m_iSite)
{
}

CSPDataKey::CSPDataKey(const CString& strSPName, const CString& strNick, int iSite)
:	m_strSPName(strSPName),
	m_strNick(strNick),
	m_iSite(iSite)
{
}

CSPDataKey::~CSPDataKey()
{

}
