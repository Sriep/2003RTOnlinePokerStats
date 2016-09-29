// PSParadiseSumaryGereral.h: interface for the CPSParadiseSumaryGereral class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PSParadiseSUMARYGERERAL_H__8612676C_5844_4D9B_8598_16336120F822__INCLUDED_)
#define AFX_PSParadiseSUMARYGERERAL_H__8612676C_5844_4D9B_8598_16336120F822__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ParseState.h"

class CPSParadiseSumaryGereral : public CParseState  
{
public:
	CPSParadiseSumaryGereral(CParseFile* cPF);
	virtual ~CPSParadiseSumaryGereral();
	virtual CParseState* Parse(const CString &strInLine);
private:
	int GetLoss(CString& strUnreadLine, const CString& strNick);
	int GetProfit(CString& strUnreadLine, const CString& strNick);
};

#endif // !defined(AFX_PSParadiseSUMARYGERERAL_H__8612676C_5844_4D9B_8598_16336120F822__INCLUDED_)
