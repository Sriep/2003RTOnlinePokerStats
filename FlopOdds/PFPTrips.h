// PFPTrips.h: interface for the PFPTrips class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PFPTRIPS_H__F057D7DB_5B08_4154_9F34_641FC0205379__INCLUDED_)
#define AFX_PFPTRIPS_H__F057D7DB_5B08_4154_9F34_641FC0205379__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "PFlopPercentages.h"

class PFPTrips : public PFlopPercentages  
{
public:
	PFPTrips(const PHandsList& cHandsList, const PHoldemFlop& cBoard);
	PFPTrips();
	virtual ~PFPTrips();

private:
	virtual void calculateFlopPercentages();
};

#endif // !defined(AFX_PFPTRIPS_H__F057D7DB_5B08_4154_9F34_641FC0205379__INCLUDED_)
