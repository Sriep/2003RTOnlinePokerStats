// PSHighStakesLogSummary.h: interface for the CPSHighStakesLogSummary class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PSHighStakesLOGSUMMARY_H__A06439F5_00C9_4935_AD5E_9D4EC9B54C1D__INCLUDED_)
#define AFX_PSHighStakesLOGSUMMARY_H__A06439F5_00C9_4935_AD5E_9D4EC9B54C1D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "PSHighStakesLog.h"

class CPSHighStakesLogSummary : public CPSHighStakesLog  
{
public:
	CPSHighStakesLogSummary(CParseFile* cPF);
	CPSHighStakesLogSummary(CParseFile* cPF, const CString& strNick, const CString& strAction, CString& strUnreadLine);
	virtual ~CPSHighStakesLogSummary();
	virtual CParseState* ParseI(const CString &strInLine, const CString &strFullLine);

	CString m_strNick;
	CString m_strAction;
	CString m_strUnreadLine;	
	bool m_bFirst;
};

#endif // !defined(AFX_PSHighStakesLOGSUMMARY_H__A06439F5_00C9_4935_AD5E_9D4EC9B54C1D__INCLUDED_)
