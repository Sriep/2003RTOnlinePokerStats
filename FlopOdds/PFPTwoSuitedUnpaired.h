// PFPTwoSuitedUnpaired.h: interface for the PFPTwoSuitedUnpaired class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PFPTWOSUITEDUNPAIRED_H__91C658D5_69C4_4E33_B808_5130179836CC__INCLUDED_)
#define AFX_PFPTWOSUITEDUNPAIRED_H__91C658D5_69C4_4E33_B808_5130179836CC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "PFlopPercentages.h"

class PFPTwoSuitedUnpaired : public PFlopPercentages  
{
public:
	PFPTwoSuitedUnpaired(const PHandsList& cHandsList, const PHoldemFlop& cBoard);
	PFPTwoSuitedUnpaired();
	virtual ~PFPTwoSuitedUnpaired();

private:
	virtual void calculateFlopPercentages();
};

#endif // !defined(AFX_PFPTWOSUITEDUNPAIRED_H__91C658D5_69C4_4E33_B808_5130179836CC__INCLUDED_)
