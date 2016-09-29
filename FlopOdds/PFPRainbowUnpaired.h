// PFPRainbowUnpaired.h: interface for the PFPRainbowUnpaired class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PFPRAINBOWUNPAIRED_H__03DEA63E_1F8E_44CB_A0B3_29A19B466B6D__INCLUDED_)
#define AFX_PFPRAINBOWUNPAIRED_H__03DEA63E_1F8E_44CB_A0B3_29A19B466B6D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "PFlopPercentages.h"

class PFPRainbowUnpaired : public PFlopPercentages  
{
public:
	virtual void calculateFlopPercentages();
	PFPRainbowUnpaired(const PHandsList& cHandsList, const PHoldemFlop& cBoard);
	PFPRainbowUnpaired();
	virtual ~PFPRainbowUnpaired();

private:			  

};

#endif // !defined(AFX_PFPRAINBOWUNPAIRED_H__03DEA63E_1F8E_44CB_A0B3_29A19B466B6D__INCLUDED_)
