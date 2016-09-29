// PDeck.cpp: implementation of the PDeck class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "flopodds.h"
#include "PDeck.h"
#include <stdlib.h> 

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

PDeck::PDeck()
{
   //populate();
}

PDeck::~PDeck()
{

}

void PDeck::populate()
{
	int iPosition = 0;
	for (int iSuit = 1 ; iSuit <= 4 ; iSuit++ )
	{
		for (int iRank = 1 ; iRank <= 13 ; iRank++ )
		{
			PCard cardToAssign = PCard((PRank)iRank, (PSuit)iSuit);
			push_back(cardToAssign ); 
			iPosition++;
		}
	}
	ASSERT(iPosition == 52);
	//TRACE("After Stacking deck ");
	//DUMP();
	m_NextCardToDeal = begin();
}

void PDeck::DUMP()
{
#if defined(_DEBUG)
	TRACE("Deck is: \n");
	for (int iCard = 0 ; iCard < size() ; iCard++ )
	{
		TRACE(at(iCard).asString());
		TRACE("\n");
	}
#endif
}


