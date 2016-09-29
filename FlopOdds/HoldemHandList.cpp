// HoldemHandList.cpp: implementation of the HoldemHandList class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "flopodds.h"
#include "HoldemHandList.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

PHoldemHandList::PHoldemHandList()
{

}

PHoldemHandList::~PHoldemHandList()
{

}

void PHoldemHandList::populate()
{
	for (int iRank1 = 1 ; iRank1 <= 13 ; iRank1++ )
	{
		for (int iRank2 = 1 ; iRank2 <= iRank1 ; iRank2++ )
		{
			push_back(PHoldemHandData( PCard((PRank)iRank1, SPADES), PCard((PRank)iRank2, CLUBS) )); 
			if (iRank1 != iRank2)
			{
				push_back(PHoldemHandData( PCard((PRank)iRank1, SPADES), PCard((PRank)iRank2, SPADES) )); 
			}

		}
	}
}
