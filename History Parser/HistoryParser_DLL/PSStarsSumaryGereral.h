// PSStarsSumaryGereral.h: interface for the CPSStarsSumaryGereral class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PSStarsSUMARYGERERAL_H__8612676C_5844_4D9B_8598_16336120F822__INCLUDED_)
#define AFX_PSStarsSUMARYGERERAL_H__8612676C_5844_4D9B_8598_16336120F822__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ParseState.h"

class CPSStarsSumaryGereral : public CParseState  
{
public:
	CPSStarsSumaryGereral(CParseFile* cPF);
	virtual ~CPSStarsSumaryGereral();
	virtual CParseState* Parse(const CString &strInLine);
private:
	int GetLoss(CString& strUnreadLine, const CString& strNick);
	int GetProfit(CString& strUnreadLine, const CString& strNick);
	CString ReadLongNick(CString& strUnreadLine);
};

#endif // !defined(AFX_PSStarsSUMARYGERERAL_H__8612676C_5844_4D9B_8598_16336120F822__INCLUDED_)
