// HoldemHandList.h: interface for the HoldemHandList class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_HOLDEMHANDLIST_H__8BB4C5C3_569C_42D4_BE91_E4D49398881F__INCLUDED_)
#define AFX_HOLDEMHANDLIST_H__8BB4C5C3_569C_42D4_BE91_E4D49398881F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <list>
#include "PHoldemHandData.h"

using std::list;
typedef std::list<PHoldemHandData>::iterator HoldemHandDataIterator;
typedef std::list<PHoldemHandData>::const_iterator ConstHoldemHandDataIterator;

class PHoldemHandList : public std::list <PHoldemHandData>, PPokerObject 
{
public:
	PHoldemHandList();
	virtual ~PHoldemHandList();

	void populate();
};

#endif // !defined(AFX_HOLDEMHANDLIST_H__8BB4C5C3_569C_42D4_BE91_E4D49398881F__INCLUDED_)
