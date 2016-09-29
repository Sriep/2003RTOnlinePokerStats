// PSUltimateBetLogSmallBlind.h: interface for the CPSUltimateBetLogSmallBlind class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PSUltimateBetLOGSMALLBLIND_H__FE0E4668_9521_4279_81B5_13BF3A882A81__INCLUDED_)
#define AFX_PSUltimateBetLOGSMALLBLIND_H__FE0E4668_9521_4279_81B5_13BF3A882A81__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "PSUltimateBetLog.h"

class CPSUltimateBetLogSmallBlind : public CPSUltimateBetLog  
{
public:
	CPSUltimateBetLogSmallBlind(CParseFile* pPF);
	virtual ~CPSUltimateBetLogSmallBlind();
	virtual CParseState* ParseI(const CString &strInLine, const CString &strFullLine);
};

#endif // !defined(AFX_PSUltimateBetLOGSMALLBLIND_H__FE0E4668_9521_4279_81B5_13BF3A882A81__INCLUDED_)
