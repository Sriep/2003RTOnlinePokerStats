// PSParadiseLogSmallBlind.h: interface for the CPSParadiseLogSmallBlind class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PSParadiseLOGSMALLBLIND_H__FE0E4668_9521_4279_81B5_13BF3A882A81__INCLUDED_)
#define AFX_PSParadiseLOGSMALLBLIND_H__FE0E4668_9521_4279_81B5_13BF3A882A81__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "PSParadiseLog.h"

class CPSParadiseLogSmallBlind : public CPSParadiseLog  
{
public:
	CPSParadiseLogSmallBlind(CParseFile* pPF);
	virtual ~CPSParadiseLogSmallBlind();
	virtual CParseState* ParseI(const CString &strInLine, const CString &strFullLine);
};

#endif // !defined(AFX_PSParadiseLOGSMALLBLIND_H__FE0E4668_9521_4279_81B5_13BF3A882A81__INCLUDED_)
