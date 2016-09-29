// PSWSEXLogSmallBlind.h: interface for the CPSWSEXLogSmallBlind class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PSWSEXLOGSMALLBLIND_H__FE0E4668_9521_4279_81B5_13BF3A882A81__INCLUDED_)
#define AFX_PSWSEXLOGSMALLBLIND_H__FE0E4668_9521_4279_81B5_13BF3A882A81__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "PSWSEXLog.h"

class CPSWSEXLogSmallBlind : public CPSWSEXLog  
{
public:
	CPSWSEXLogSmallBlind(CParseFile* pPF);
	virtual ~CPSWSEXLogSmallBlind();
	virtual CParseState* ParseI(const CString &strInLine, const CString &strFullLine);
};

#endif // !defined(AFX_PSWSEXLOGSMALLBLIND_H__FE0E4668_9521_4279_81B5_13BF3A882A81__INCLUDED_)
