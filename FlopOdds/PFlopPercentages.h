// PFlopPercentages.h: interface for the PFlopPercentages class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PFLOPPERCENTAGES_H__68334BE2_527C_4CB9_9B46_54CACD2D5610__INCLUDED_)
#define AFX_PFLOPPERCENTAGES_H__68334BE2_527C_4CB9_9B46_54CACD2D5610__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#pragma warning( disable : 4786 )
#include <list>
#include "PPokerObject.h"
#include "PDisplayRowData.h"
#include "PHoldemFlop.h"	// Added by ClassView
#include "HandsMap.h"


using std::list;
typedef std::list<PDisplayRowData>::iterator RowDataIterator;


class PFlopPercentages : public std::list <PDisplayRowData>, public PPokerObject  
{
public:
	PFlopPercentages(const PFlopPercentages& cFlopPercentages);
	PFlopPercentages(const PHandsList& cHandsList, const PHoldemFlop& cBoard);
	static PFlopPercentages* calculateFlopPercentages(const PHandsList& cHandsList, const PHoldemFlop& cBoard);
	void setBoard(PHoldemFlop cBoard);
	PFlopPercentages();
	virtual ~PFlopPercentages();
	PHandsList getHandSpread() const;
	PHoldemFlop getFlop() const;

private:
	virtual void calculateFlopPercentages() = 0;
	PHandsList m_cHandSpread;
	PHoldemFlop m_cFlop;
};

#endif // !defined(AFX_PFLOPPERCENTAGES_H__68334BE2_527C_4CB9_9B46_54CACD2D5610__INCLUDED_)
