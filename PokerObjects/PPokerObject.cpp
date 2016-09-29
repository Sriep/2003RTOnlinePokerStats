// PPokerObject.cpp: implementation of the PPokerObject class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PPokerObject.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

const int PPokerObject::NUM_CARDS = 52;
const int PPokerObject::NUM_HOLDEM_HANDS = NUM_CARDS * (NUM_CARDS - 1) / 2;
const int PPokerObject::NUMM_CARDS_POKER_HAND = 5;

PPokerObject::PSuit PPokerObject::NO_SUIT = PSuit(PSuit::SUIT::SUIT_NO_SUIT);
PPokerObject::PSuit PPokerObject::SPADES = PSuit(PSuit::SUIT::SUIT_SPADES);
PPokerObject::PSuit PPokerObject::HEARTS = PSuit(PSuit::SUIT::SUIT_HEARTS);
PPokerObject::PSuit PPokerObject::DIAMONDS = PSuit(PSuit::SUIT::SUIT_DIAMONDS);
PPokerObject::PSuit PPokerObject::CLUBS = PSuit(PSuit::SUIT::SUIT_CLUBS);
PPokerObject::PRank PPokerObject::NO_RANK = PRank(PRank::RANK::RANK_NO_RANK);
PPokerObject::PRank PPokerObject::TWO = PRank(PRank::RANK::RANK_TWO);
PPokerObject::PRank PPokerObject::THREE = PRank(PRank::RANK::RANK_THREE);
PPokerObject::PRank PPokerObject::FOUR = PRank(PRank::RANK::RANK_FOUR);
PPokerObject::PRank PPokerObject::FIVE = PRank(PRank::RANK::RANK_FIVE);
PPokerObject::PRank PPokerObject::SIX = PRank(PRank::RANK::RANK_SIX);
PPokerObject::PRank PPokerObject::SEVEN = PRank(PRank::RANK::RANK_SEVEN);
PPokerObject::PRank PPokerObject::EIGHT = PRank(PRank::RANK::RANK_EIGHT);
PPokerObject::PRank PPokerObject::NINE = PRank(PRank::RANK::RANK_NINE);
PPokerObject::PRank PPokerObject::TEN = PRank(PRank::RANK::RANK_TEN);
PPokerObject::PRank PPokerObject::JACK = PRank(PRank::RANK::RANK_JACK);
PPokerObject::PRank PPokerObject::QUEEN = PRank(PRank::RANK::RANK_QUEEN);
PPokerObject::PRank PPokerObject::KING = PRank(PRank::RANK::RANK_KING);
PPokerObject::PRank PPokerObject::ACE = PRank(PRank::RANK::RANK_ACE);
PPokerObject::PRank PPokerObject::NUM_RANKS = PRank(PRank::RANK::RANK_NUM_RANKS);

PPlayerAction PPokerObject::ACTION_NONE = PPlayerAction(PPlayerAction::ACTION_NONE);
PPlayerAction PPokerObject::POST = PPlayerAction(PPlayerAction::ACTION_POST);
PPlayerAction PPokerObject::MUCK = PPlayerAction(PPlayerAction::ACTION_MUCK);
PPlayerAction PPokerObject::FOLD = PPlayerAction(PPlayerAction::ACTION_FOLD);
PPlayerAction PPokerObject::CHECK = PPlayerAction(PPlayerAction::ACTION_CHECK);
PPlayerAction PPokerObject::CALL = PPlayerAction(PPlayerAction::ACTION_CALL);
PPlayerAction PPokerObject::BET = PPlayerAction(PPlayerAction::ACTION_BET);
PPlayerAction PPokerObject::RAISE = PPlayerAction(PPlayerAction::ACTION_RAISE);
PPlayerAction PPokerObject::NUM_OF_ACTIONS = PPlayerAction(PPlayerAction::NUM_OF_ACTIONS);

PPokerObject::PPokerObject()
{

}

PPokerObject::~PPokerObject()
{

}




