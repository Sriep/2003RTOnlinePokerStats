// PSPartySumaryGereral.h: interface for the CPSPartySumaryGereral class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PSPARTYSUMARYGERERAL_H__8612676C_5844_4D9B_8598_16336120F822__INCLUDED_)
#define AFX_PSPARTYSUMARYGERERAL_H__8612676C_5844_4D9B_8598_16336120F822__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ParseState.h"

class CPSPartySumaryGereral : public CParseState  
{
public:
	CPSPartySumaryGereral(CParseFile* cPF);
	virtual ~CPSPartySumaryGereral();
	virtual CParseState* Parse(const CString &strInLine);
private:
	int GetLoss(CString& strUnreadLine, const CString& strNick);
	int GetProfit(CString& strUnreadLine, const CString& strNick);
	//CString ReadNick(CString& strUnreadLine);
};

#endif // !defined(AFX_PSPARTYSUMARYGERERAL_H__8612676C_5844_4D9B_8598_16336120F822__INCLUDED_)
