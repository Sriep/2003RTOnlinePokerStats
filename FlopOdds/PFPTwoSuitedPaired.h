// PFPTwoSuitedPaired.h: interface for the PFPTwoSuitedPaired class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PFPTWOSUITEDPAIRED_H__5B140608_EDE0_48A7_B4CB_4248B5C94CD7__INCLUDED_)
#define AFX_PFPTWOSUITEDPAIRED_H__5B140608_EDE0_48A7_B4CB_4248B5C94CD7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "PFlopPercentages.h"

class PFPTwoSuitedPaired : public PFlopPercentages  
{
public:
	PFPTwoSuitedPaired(const PHandsList& cHandsList, const PHoldemFlop& cBoard);
	PFPTwoSuitedPaired();
	virtual ~PFPTwoSuitedPaired();

private:
	virtual void calculateFlopPercentages();
};

#endif // !defined(AFX_PFPTWOSUITEDPAIRED_H__5B140608_EDE0_48A7_B4CB_4248B5C94CD7__INCLUDED_)
