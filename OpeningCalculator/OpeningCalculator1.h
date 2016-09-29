// OpeningCalculator1.h: interface for the COpeningCalculator class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_OPENINGCALCULATOR1_H__D857ADC1_C83C_406C_9AC7_857C9D413E48__INCLUDED_)
#define AFX_OPENINGCALCULATOR1_H__D857ADC1_C83C_406C_9AC7_857C9D413E48__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "PPokerObject.h"

class PHandSpread;

class COpeningCalculator : public PPokerObject  
{
public:
	COpeningCalculator();
	virtual ~COpeningCalculator();
	
	PHandSpread* GetSpread(const CString& strNick); 

};

#endif // !defined(AFX_OPENINGCALCULATOR1_H__D857ADC1_C83C_406C_9AC7_857C9D413E48__INCLUDED_)
