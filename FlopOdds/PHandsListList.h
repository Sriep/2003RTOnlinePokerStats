// PHandsListList.h: interface for the PHandsListList class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PHANDSLISTLIST_H__90875117_4D5F_401D_8197_254ACB965633__INCLUDED_)
#define AFX_PHANDSLISTLIST_H__90875117_4D5F_401D_8197_254ACB965633__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#pragma warning( disable : 4786 )
#include <list>
#include <algorithm>
#include "HandsMap.h"


using std::list;
typedef std::list<PHandsList>::iterator HoldemHandsListIterator;
typedef std::list<PHandsList>::const_iterator ConstHoldemHandsListIIterator;

class PHandsListList : public std::list <PHandsList>, PPokerObject   
{
public:
	PHandsListList();
	virtual ~PHandsListList();

};

#endif // !defined(AFX_PHANDSLISTLIST_H__90875117_4D5F_401D_8197_254ACB965633__INCLUDED_)
