// PFPOneSuited.h: interface for the PFPOneSuited class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PFPONESUITED_H__8FE3B389_659F_414B_BDD6_BC7AF76C6ED8__INCLUDED_)
#define AFX_PFPONESUITED_H__8FE3B389_659F_414B_BDD6_BC7AF76C6ED8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "PFlopPercentages.h"

class PFPSingleSuited : public PFlopPercentages  
{
public:
	PFPSingleSuited(const PHandsList& cHandsList, const PHoldemFlop& cBoard);
	PFPSingleSuited();
	virtual ~PFPSingleSuited();

private:
	virtual void calculateFlopPercentages();
};

#endif // !defined(AFX_PFPONESUITED_H__8FE3B389_659F_414B_BDD6_BC7AF76C6ED8__INCLUDED_)
