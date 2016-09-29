// PFPRainbowPaired.h: interface for the PFPRainbowPaired class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PFPRAINBOWPAIRED_H__37EE596A_03D7_4B75_B80C_85D9C1799BEF__INCLUDED_)
#define AFX_PFPRAINBOWPAIRED_H__37EE596A_03D7_4B75_B80C_85D9C1799BEF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "PFlopPercentages.h"

class PFPRainbowPaired : public PFlopPercentages  
{
public:
	PFPRainbowPaired(const PHandsList& cHandsList, const PHoldemFlop& cBoard);
	PFPRainbowPaired();
	virtual ~PFPRainbowPaired();

private:
	virtual void calculateFlopPercentages();
};

#endif // !defined(AFX_PFPRAINBOWPAIRED_H__37EE596A_03D7_4B75_B80C_85D9C1799BEF__INCLUDED_)
