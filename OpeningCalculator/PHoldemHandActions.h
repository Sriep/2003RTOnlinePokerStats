// POpeningHandRequirment.h: interface for the POpeningHandRequirment class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_POPENINGHANDREQUIRMENT_H__A5B5705B_255C_4FF3_9FDD_EFBE7DDACB2B__INCLUDED_)
#define AFX_POPENINGHANDREQUIRMENT_H__A5B5705B_255C_4FF3_9FDD_EFBE7DDACB2B__INCLUDED_

#include "PPokerObject.h"


#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class PHoldemHandActions : public PPokerObject  
{
public:
	PHoldemHandActions();
	PHoldemHandActions(int iTotalPermutations);
	virtual ~PHoldemHandActions();

	//bool operator!=(const PHoldemHandActions& cOpeningHand) const;
	//bool operator==(const PHoldemHandActions& cOpeningHand) const;
	//bool operator<(const PHoldemHandActions& cOpeningHand) const;
	//bool operator<=(const POpeningHandRequirment& cOpeningHand) const;
	//bool operator>(const PHoldemHandActions& cOpeningHand) const;
	//bool operator>=(const POpeningHandRequirment& cOpeningHand) const;
	PHoldemHandActions& operator=(const PHoldemHandActions& cOpeningHand);
	//void AddCall();
	//void AddRaise();
	void AddAction(const PPlayerAction& cAction);
	int GetRaisePerms() const;
	int GetCallPerms() const;
	int GetFoldPerms() const;
	int GetTotalPerms() const;
	int GetNumRaises() const;
	int GetNumCalls() const;

	void SetZeroFoldPerms();

	void DUMP() const;
private:
	int m_iRaisePerms;
	int m_iCallPerms;
	int m_iFoldPerms;
	int m_iNumRaises;
	int m_iNumCalls;
	int m_iTotalPermutations;
};

#endif // !defined(AFX_POPENINGHANDREQUIRMENT_H__A5B5705B_255C_4FF3_9FDD_EFBE7DDACB2B__INCLUDED_)
