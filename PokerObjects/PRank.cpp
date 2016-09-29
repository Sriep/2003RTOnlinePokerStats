// PRank.cpp: implementation of the PRank class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PPokerObject.h"
#include <algorithm>

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

using namespace std;

PPokerObject::PRank::PRank(RANK eRank)
: m_eRank(eRank)
{

}

PPokerObject::PRank::~PRank()
{

}



 /*
bool PPokerObject::PRank::operator<(const PRank& sRank1, const PRank& sRank2)
{
	return sRank1 < sRank2;	 
}

bool PPokerObject::PRank::operator<=(const PRank& sRank1, const PRank& sRank2) 
{
	return sRank1 < sRank2;	 
}

bool PPokerObject::PRank::operator>(const PRank& sRank1, const PRank& sRank2)
{
	return sRank1 < sRank2;	 
}

bool PPokerObject::PRank::operator>=(const PRank& sRank1, const PRank& sRank2)
{
	return sRank1 < sRank2;	 
}  */



/*
PPokerObject::PRank& PPokerObject::PRank::operator+(int iIncrement)
{
	PRank rResult = *this;
	rResult += iIncrement;
	return rResult;
}

PPokerObject::PRank& PPokerObject::PRank::operator-(int iDecrement)
{
	PRank rResult = *this;
	rResult -= iDecrement;
	return rResult;
} */




