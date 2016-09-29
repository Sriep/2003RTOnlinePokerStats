// HoldemStartHand.cpp: implementation of the HoldemStartHand class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "OpeningCalculator.h"
#include "HoldemStartHand.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

PHoldemStartHand::PHoldemStartHand()
:	 m_rHighRank(PPokerObject::NO_RANK),
	 m_rLowRank(PPokerObject::NO_RANK),
	 m_bSuited(false)
{

}

PHoldemStartHand::~PHoldemStartHand()
{

}

PHoldemStartHand::PHoldemStartHand(PRank rHighCard, PRank rLowCard, bool bSuited)
:	 m_rHighRank(rHighCard),
	 m_rLowRank(rLowCard),
	 m_bSuited(bSuited)
{
	if (rHighCard < rLowCard)
	{
		 m_rHighRank = rLowCard;
		 m_rLowRank = rHighCard;
	}
}

PPokerObject::PRank PHoldemStartHand::GetHighRank() const
{
	return m_rHighRank;
}

PPokerObject::PRank PHoldemStartHand::GetLowRank() const
{
	return m_rLowRank;
}

bool PHoldemStartHand::IsSuited() const
{
	return m_bSuited;
}

bool PHoldemStartHand::operator!=(const PHoldemStartHand& cHoldemStartHand) const
{
	return	 m_rHighRank != cHoldemStartHand.m_rHighRank
			 || m_rLowRank != cHoldemStartHand.m_rLowRank
			 || m_bSuited != cHoldemStartHand.m_bSuited;
}

bool PHoldemStartHand::operator==(const PHoldemStartHand& cHoldemStartHand) const
{
	return	 m_rHighRank == cHoldemStartHand.m_rHighRank
			 || m_rLowRank == cHoldemStartHand.m_rLowRank
			 || m_bSuited == cHoldemStartHand.m_bSuited;
}

bool PHoldemStartHand::operator<(const PHoldemStartHand& cHoldemStartHand) const
{
	int iDifference = m_rHighRank - cHoldemStartHand.m_rHighRank ;
	
	if ( (0 == iDifference || 3 < iDifference || -3 > iDifference)  
		 && m_bSuited == cHoldemStartHand.m_bSuited)
	{
		if (m_rHighRank != cHoldemStartHand.m_rHighRank)
		{
			return 	m_rHighRank < cHoldemStartHand.m_rHighRank;
		}
		else
		{
			return m_rLowRank < cHoldemStartHand.m_rLowRank;
		}
	}
	else
	{
		return false;
	}
}

bool PHoldemStartHand::operator>(const PHoldemStartHand& cHoldemStartHand) const
{
	int iDifference = m_rHighRank - cHoldemStartHand.m_rHighRank; 
	
	if ( (0 == iDifference || 3 < iDifference || -3 > iDifference)  
		 && m_bSuited == cHoldemStartHand.m_bSuited)
	{
		if (m_rHighRank != cHoldemStartHand.m_rHighRank)
		{
			return 	m_rHighRank > cHoldemStartHand.m_rHighRank;
		}
		else
		{
			return m_rLowRank > cHoldemStartHand.m_rLowRank;
		}
	}
	else
	{
		return false;
	}
}

//bool PHoldemStartHand::operator<=(const PHoldemStartHand& cHoldemStartHand) const
//{
//}

//bool PHoldemStartHand::operator>=(const PHoldemStartHand& cHoldemStartHand) const
//{
//}

PHoldemStartHand& PHoldemStartHand::operator=(const PHoldemStartHand& cHoldemStartHand)
{
	m_rHighRank = cHoldemStartHand.m_rHighRank;
	m_rLowRank = cHoldemStartHand.m_rLowRank;
	m_bSuited = cHoldemStartHand.m_bSuited;
	return *this;
}

void PHoldemStartHand::DUMP() const
{
	m_rHighRank.DUMP();
	m_rLowRank.DUMP();
	if (m_bSuited && m_rHighRank != m_rLowRank)
	{
		TRACE(" suited");
	}
	else if (!m_bSuited && m_rHighRank != m_rLowRank)
	{
		TRACE(" Off suited");
	}
}

bool PHoldemStartHand::IsPair() const
{
	return m_rHighRank == m_rLowRank;
}

bool PHoldemStartHand::IsUnsuitedManyGapper() const
{
	return (m_rHighRank.operator>(m_rLowRank + 4)) && !m_bSuited;
}

bool PHoldemStartHand::IsUnsuitedThreeGapper() const
{
	return m_rHighRank.operator==(m_rLowRank + 4) && !m_bSuited;
}

bool PHoldemStartHand::IsUnsuitedTwoGapper() const
{
	return m_rHighRank.operator==( m_rLowRank + 3) && !m_bSuited;
}

bool PHoldemStartHand::IsUnsuitedOneGapper() const
{
	return m_rHighRank.operator==( m_rLowRank + 2) && !m_bSuited;
}

bool PHoldemStartHand::IsUnsuitedZeroGapper() const
{
	return m_rHighRank.operator==( m_rLowRank + 1) && !m_bSuited;
}

bool PHoldemStartHand::IsSuitedManyGapper() const
{
	return m_rHighRank.operator>( m_rLowRank + 4) && m_bSuited;
}

bool PHoldemStartHand::IsSuitedThreeGapper() const
{
	return m_rHighRank.operator==( m_rLowRank + 4) && m_bSuited;
}

bool PHoldemStartHand::IsSuitedTwoGapper() const
{
	return m_rHighRank.operator==( m_rLowRank + 3) && m_bSuited;
}

bool PHoldemStartHand::IsSuitedOneGapper() const
{
	return m_rHighRank.operator==( m_rLowRank + 2) && m_bSuited;
}

bool PHoldemStartHand::IsSuitedZeroGapper() const
{
	return m_rHighRank.operator==( m_rLowRank + 1) && m_bSuited;
}


