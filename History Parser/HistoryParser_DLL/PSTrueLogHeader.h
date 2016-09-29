// PSTrueLogSmallBlind.h: interface for the CPSTrueLogSmallBlind class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CPSTrueLogHeader__INCLUDED_)
#define AFX_CPSTrueLogHeader__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "PSTrueLog.h"

class CPSTrueLogHeader : public CPSTrueLog  
{
public:
	CPSTrueLogHeader(CParseFile* pPF);
	virtual ~CPSTrueLogHeader();
	virtual CParseState* ParseI(const CString &strInLine, const CString &strFullLine); 
	CString GetTableName(CString& strUnreadLine);
}; 

inline CString CPSTrueLogHeader::GetTableName(CString& strUnreadLine)
{
	int iIndexEndOfName = strUnreadLine.Find('-');
	if (iIndexEndOfName <= 0)
	{
		throw(new CParsingException(IDS_TABLE_NAME_NOT_FOUND, this, new CPSNone(m_cParseFile)));
	}

	CString strTableName = strUnreadLine.Left(iIndexEndOfName-1);
	strUnreadLine = strUnreadLine.Right(strUnreadLine.GetLength() - iIndexEndOfName);
	return strTableName;
}

#endif // !defined(AFX_CPSTrueLogHeader__INCLUDED_)
