// PCardList.h: interface for the PCardList class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PCARDLIST_H__D969F09B_0F33_466F_A5C8_9C1F6BC34CA2__INCLUDED_)
#define AFX_PCARDLIST_H__D969F09B_0F33_466F_A5C8_9C1F6BC34CA2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#pragma warning( disable : 4786 )
#include <list>
#include "PPokerHAnd.h"

typedef std::list<PCard>::iterator CardListIterator;
typedef std::list<PCard>::const_iterator ConstCardListIterator;

class PCardList : public std::list<PCard>, PPokerObject  
{
public:
	virtual void DUMP() const;
	PCardList();
	virtual ~PCardList();

};

#endif // !defined(AFX_PCARDLIST_H__D969F09B_0F33_466F_A5C8_9C1F6BC34CA2__INCLUDED_)
