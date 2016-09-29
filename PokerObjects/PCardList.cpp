// PCardList.cpp: implementation of the PCardList class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PCardList.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

PCardList::PCardList()
{

}

PCardList::~PCardList()
{

}

void PCardList::DUMP() const
{
	TRACE("CARDS LIST\n");
	for ( ConstCardListIterator iIter = begin() ; iIter != end() ; iIter++ )
	{
		TRACE("   ");
		(*iIter).DUMP();
	} 
	TRACE("\n");
}
