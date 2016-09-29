// PHoldemHandActions.cpp: implementation of the PHoldemHandActions class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "OpeningCalculator.h"
#include "PHoldemHandActions.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

PHoldemHandActions::PHoldemHandActions()
:   m_iRaisePerms(-1),
	m_iCallPerms(-1),
	m_iFoldPerms(-1),
	m_iNumRaises(-1),
	m_iNumCalls(-1),
	m_iTotalPermutations(-1)
{

}

PHoldemHandActions::~PHoldemHandActions()
{

}

PHoldemHandActions::PHoldemHandActions(int iTotalPermutations)
:   m_iRaisePerms(0),
	m_iCallPerms(0),
	m_iFoldPerms(iTotalPermutations),
	m_iNumRaises(0),
	m_iNumCalls(0),
	m_iTotalPermutations(iTotalPermutations)
{
}

/*
bool PHoldemHandActions::operator!=(const PHoldemHandActions& cHoldemStartHand) const
{
	return m_cOpeningHand != cHoldemStartHand.m_cOpeningHand;
}

bool PHoldemHandActions::operator==(const PHoldemHandActions& cHoldemStartHand) const
{
	return m_cOpeningHand == cHoldemStartHand.m_cOpeningHand;
}

bool PHoldemHandActions::operator<(const PHoldemHandActions& cHoldemStartHand) const
{
	return m_cOpeningHand < cHoldemStartHand.m_cOpeningHand;
}

//bool PHoldemHandActions::operator<=(const PHoldemHandActions& cHoldemStartHand) const;

bool PHoldemHandActions::operator>(const PHoldemHandActions& cHoldemStartHand) const
{
	return m_cOpeningHand > cHoldemStartHand.m_cOpeningHand;
}

//bool PHoldemHandActions::operator>=(const PHoldemHandActions& cHoldemStartHand) const;
  */
PHoldemHandActions& PHoldemHandActions::operator=(const PHoldemHandActions& cHoldemStartHand)
{
	m_iRaisePerms = cHoldemStartHand.m_iRaisePerms; 
	m_iCallPerms = cHoldemStartHand.m_iCallPerms; 
	m_iFoldPerms = cHoldemStartHand.m_iFoldPerms; 
	m_iNumRaises = cHoldemStartHand.m_iNumRaises; 
	m_iNumCalls = cHoldemStartHand.m_iNumCalls;
	m_iTotalPermutations = cHoldemStartHand.m_iTotalPermutations;
	return *this;
}

void PHoldemHandActions::DUMP() const
{
	TRACE3("Raise Permm %d, CallPers %d, Fold Perm %d ", m_iRaisePerms, m_iCallPerms, m_iFoldPerms);
	TRACE1("Total Perms %d ", m_iTotalPermutations);
	TRACE2("Num Raises %d  Num Calls %s\n", m_iNumRaises, m_iNumCalls);
}
	
void PHoldemHandActions::AddAction(const PPlayerAction& cAction)
{
	switch(cAction.GetAction())
	{
	case PPlayerAction::ACTION_RAISE:
		m_iNumRaises++;
		break;
	case PPlayerAction::ACTION_CALL:
		m_iNumCalls++;
		break;
	default:
		ASSERT(FALSE);
	}
}	 


int PHoldemHandActions::GetRaisePerms() const
{
	return m_iRaisePerms;
}


int PHoldemHandActions::GetCallPerms() const
{
	return m_iCallPerms;
}


int PHoldemHandActions::GetFoldPerms() const
{
	return m_iFoldPerms;
}


int PHoldemHandActions::GetTotalPerms() const
{
	return m_iTotalPermutations;
}

int PHoldemHandActions::GetNumRaises() const
{
	return m_iNumRaises;
}


int PHoldemHandActions::GetNumCalls() const
{
	return m_iNumCalls;
}

void PHoldemHandActions::SetZeroFoldPerms()
{
	m_iFoldPerms = 0;
}




