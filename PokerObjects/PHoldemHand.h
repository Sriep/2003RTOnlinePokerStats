// PHoldemHand.h: interface for the PHoldemHand class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PHOLDEMHAND_H__E8D06597_6335_4DBB_A512_BDB846D2731F__INCLUDED_)
#define AFX_PHOLDEMHAND_H__E8D06597_6335_4DBB_A512_BDB846D2731F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "PPokerObject.h"
#include "PCard.h"

class PHoldemHand : public PPokerObject  
{
public:
	virtual void DUMP() const;
	virtual CString asString() const;
	PHoldemHand(PCard cardHigh, PCard cardLow);
	virtual PCard getLowCard() const;
	virtual PCard getHighCard() const;
	PHoldemHand(char chRank1, PSuit sSuit1, char chRank2, PSuit sSuit2);
	virtual void setHand(PRank rRank1, PSuit sSuit1, PRank rRank2, PSuit sSuit2);
	PHoldemHand(PRank rRank1, PSuit sSuit1, PRank rRank2, PSuit sSuit2);
	PHoldemHand();
	virtual ~PHoldemHand();
	bool operator==(const PHoldemHand& sRank) const;
	bool operator<(const PHoldemHand& sRank) const;
private:
	void orderCards();
	PCard m_cHighCard;
	PCard m_cLowCard;
};


#endif // !defined(AFX_PHOLDEMHAND_H__E8D06597_6335_4DBB_A512_BDB846D2731F__INCLUDED_)
