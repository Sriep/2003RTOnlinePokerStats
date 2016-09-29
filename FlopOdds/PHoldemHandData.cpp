// PHoldemHandData.cpp: implementation of the PHoldemHandData class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "flopodds.h"
#include "PHoldemHandData.h"
#include "PPokerObject.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

PHoldemHandData::PHoldemHandData()
:  m_lWins(0),
   m_lTests(0),
   PHoldemHand()
{
   	for ( int i = 0 ; i < 9 ; i++ )
	{
  		m_lHandTypeWin[i] = 0;
  		m_lHandTypeLoss[i] = 0;
  		m_lHandTypeDraw[i] = 0;
  		m_lHandType[i] = 0;
	}
}

PHoldemHandData::PHoldemHandData(PCard cardHigh, PCard cardLow)
:  m_lWins(0),
   m_lTests(0),
   PHoldemHand(cardHigh, cardLow)
{
   	for ( int i = 0 ; i < 9 ; i++ )
	{
  		m_lHandTypeWin[i] = 0;
  		m_lHandTypeLoss[i] = 0;
  		m_lHandTypeDraw[i] = 0;
  		m_lHandType[i] = 0;
	}
}


PHoldemHandData::~PHoldemHandData()
{

}






