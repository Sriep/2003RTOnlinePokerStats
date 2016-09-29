// InputHand.h: interface for the CInputHand class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_INPUTHAND_H__436FD097_38F4_4132_84C0_C9F966FCE593__INCLUDED_)
#define AFX_INPUTHAND_H__436FD097_38F4_4132_84C0_C9F966FCE593__INCLUDED_

#include "PDPlayersRecordset.h"	// Added by ClassView
#include "PCard.h"
#include "PPlayerAction.h"
#include "PDHandRecordset.h"	// Added by ClassView
#include "PDActionsRecordset.h"	// Added by ClassView
#include "PDResultsRecordset.h"	// Added by ClassView
#include "RS_DBQueue.h"
#include <fstream.h>

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define  PokerSites	int

enum PokerGames
{
	GAME_TEXUS_HOLDEM,
	NUM_OF_POKER_GAMES
};

enum PokerRound
{
	ROUND_PRE_FLOP = 1,
	ROUND_FLOP,
	ROUND_TURN,
	ROUND_RIVER
};


#define POSITION_SMALL_BLIND  1
#define POSITION_BIG_BLIND  2

class CInputHand  
{
public:								
	void AddJumbledHand(const CString& strhandReference);
	void SetRiver();
	void SetTurn();
	void SetFlop();
	void SetToNextRound();
	void CloseConnection();
	void OpenConnection();
	void NewHand();
	CInputHand();
	SetDataSource(int iSiteId);
	virtual ~CInputHand();

	void WriteToDataBase();
	void SetPlayerProfitLoss(const CString& strNick, int iProfitLoss);
	void SetRake(int iRake);
	void SetPot(int iPot);
	void SetRiver(PCard cRiverCard);
	void SetTurn(PCard cTurnCard);
	void SetFlopCard(PCard cFlop1);
	void SetFlop(PCard cFlop1, PCard cFlop2, PCard cFlop3);
	void SetBigBlind(const CString& strNick, int iAmount = 0);
	void SetSmallBlind(const CString& strNick, int iAmount = 0);
	void AddPlayer(int iSeatPos, const CString strNick, int iMoney);
	void SetGameNumber(long iGameNumber);
	void SetGameNumber(const CString& strGameNumber);
	void SetPokerSite(PokerSites ePokerSite);
	void Clear();
	void SetButtonPostion(int iButtonPostion);
	void SetNumberOfPlayers(int iNumOfPlayers);
	void SetTableName(const CString& strTableName);
	void SetDate(CTime tDate);
	void SetGame(PokerGames eGame);
	void SetBigBet(int iSmallBet);
	void SetSmallBet(int iSmallBet);
	void SetPlayersCards(const CString& strNick, PCard cFisrtCard, PCard cSecondCard);
	void AddPlayerAction(const CString& strNick, PPlayerAction eAction, int iAmount);
	void SetPlayerSatOut(const CString& strNick);
	void SetIncomplete();
	CString GetGameNumber();
	CDatabase* GetDatabase();
private:

	void StartNewTransaction();
	bool HandHistoryAlreadyInDatabase();
	long GetHandId();
	long GetIndividualResults(const CString& strNick);
	int GetHostId();
	bool m_bTransactionPending;

	CDatabase m_dbPokerData;
	CPDPlayersRecordset* m_prsPlayers;
	CPDResultsRecordset* m_prsResults;
	CPDActionsRecordset* m_prsActions;
	CPDHandRecordset* m_prsHands;
	PokerRound m_eRound;
	int m_iPostion;
	bool m_bIncomplete;
	int iNumberFlopCardsDelt;
	int m_iSiteId;
};

inline CDatabase* CInputHand::GetDatabase() 
{
	return &m_dbPokerData;
}

inline void CInputHand::SetSmallBet(int iSmallBet)
{
	TRACE1("Small bet = %d\n", iSmallBet);
	m_prsHands->m_Small_bet = iSmallBet;
}

inline void CInputHand::SetBigBet(int iBigBet) 
{
	TRACE1("Big bet = %d\n", iBigBet);
	m_prsHands->m_Big_bet = iBigBet;
}

inline void CInputHand::SetGame(PokerGames eGame)
{
	TRACE1("Game = %d\n", (int)eGame);
	m_prsHands->m_Variant = (int)eGame;
}

inline void CInputHand::SetDate(CTime tDate)
{
	CString strDate = tDate.Format( "%A, %B %d, %Y" );
	TRACE("Date = %s\b", strDate);
	m_prsHands->m_Date = tDate;
}

inline void CInputHand::SetTableName(const CString &strTableName)
{
	TRACE1("Table Name = %s\n", strTableName);
	m_prsHands->m_Table_name = strTableName;
	//Do not bother with table name
}

inline void CInputHand::SetNumberOfPlayers(int iNumOfPlayers)
{
	TRACE1("Number Of Players = %d\n", iNumOfPlayers);
}

inline void CInputHand::SetButtonPostion(int iButtonPostion)
{
	TRACE1("Button Postion = %d\n", iButtonPostion);
}

inline void CInputHand::Clear()
{
	TRACE("Clear Input hand\n");
}

inline void CInputHand::AddPlayer(int iSeatPos, const CString strNick, int iMoney)
{
	TRACE3("Add player %s at polsition number %d with $%d\n", strNick, iSeatPos, iMoney);
	ASSERT(m_prsPlayers && m_prsResults);
	long lPlayerId = CPDPlayersRecordset::GetPlayerId(strNick, m_iSiteId);
	m_prsResults->GetResultsFor(lPlayerId, GetHandId());
	m_prsResults->Edit();
	m_prsResults->m_Chips = iMoney;
	m_prsResults->Update();
}


inline void CInputHand::SetPlayersCards(const CString& strNick, PCard cFisrtCard, PCard cSecondCard)
{
	 TRACE1("Player %s's cards ", strNick);
	 cFisrtCard.DUMP();
	 TRACE(" and ");
	 cSecondCard.DUMP();
	 TRACE("\n");

	ASSERT(m_prsPlayers && m_prsResults);
	long lPlayerId = CPDPlayersRecordset::GetPlayerId(strNick, m_iSiteId);
	m_prsResults->GetResultsFor(lPlayerId, GetHandId());
	m_prsResults->Edit();
	m_prsResults->m_First_Card_Rank = cFisrtCard.getRank().getHashValue();
	m_prsResults->m_First_Card_Suit = cFisrtCard.getSuit().getHashValue();
	m_prsResults->m_Second_Card_Rank= cSecondCard.getRank().getHashValue();
	m_prsResults->m_Second_Card_Suit = cSecondCard.getSuit().getHashValue();
	m_prsResults->Update();
}

inline void CInputHand::AddPlayerAction(const CString& strNick, PPlayerAction eAction, int iAmount)
{
	TRACE3("Player %s's action was to %s an amount %d\n", strNick, eAction.ActionDescription(), iAmount);

	long lResultId = m_prsResults->GetResultsFor(CPDPlayersRecordset::GetPlayerId(strNick, m_iSiteId), GetHandId());
	if ((0 > m_prsResults->m_Position || m_prsResults->m_Position >10)
		&& (eAction != PPlayerAction::ACTION_POST))
	{
		m_prsResults->Edit();
		m_prsResults->m_Position = m_iPostion++;
		m_prsResults->Update();
		m_prsHands->m_Active_Players++;// = m_iPostion++;
		if (m_iPostion == 11)
			m_iPostion = 1;
	}											 
	ASSERT(m_prsActions);
	m_prsActions->AddAction(lResultId, eAction.GetAction(), iAmount, (int)m_eRound);
}

inline void CInputHand::SetFlopCard(PCard cFlopCard)
{
	m_eRound =	ROUND_FLOP;
	TRACE("Flop cards delt ");
	cFlopCard.DUMP();
	TRACE("\n");
	switch(iNumberFlopCardsDelt++)
	{
	case 0:
		m_prsHands->m_Flop_card_1_rank = cFlopCard.getRank().getHashValue();
		m_prsHands->m_Flop_card_1_suit = cFlopCard.getSuit().getHashValue();
		break;
	case 1:
		m_prsHands->m_Flop_card_2_rank = cFlopCard.getRank().getHashValue();
		m_prsHands->m_Flop_card_2_suit = cFlopCard.getSuit().getHashValue();
		break;
	case 2:
		m_prsHands->m_Flop_card_3_rank = cFlopCard.getRank().getHashValue();
		m_prsHands->m_Flop_card_3_suit = cFlopCard.getSuit().getHashValue();
		iNumberFlopCardsDelt = 0;
		break;
	default:
		ASSERT(FALSE);
	}
}

inline void CInputHand::SetFlop(PCard cFlop1, PCard cFlop2, PCard cFlop3)
{
	m_eRound =	ROUND_FLOP;
	TRACE("Flop cards delt ");
	cFlop1.DUMP();
	TRACE(" and ");
	cFlop2.DUMP();
	TRACE(" and ");
	cFlop3.DUMP();
	TRACE("\n");
	m_prsHands->m_Flop_card_1_rank = cFlop1.getRank().getHashValue();
	m_prsHands->m_Flop_card_1_suit = cFlop1.getSuit().getHashValue();
	m_prsHands->m_Flop_card_2_rank = cFlop2.getRank().getHashValue();
	m_prsHands->m_Flop_card_2_suit = cFlop2.getSuit().getHashValue();
	m_prsHands->m_Flop_card_3_rank = cFlop3.getRank().getHashValue();
	m_prsHands->m_Flop_card_3_suit = cFlop3.getSuit().getHashValue();
}

inline void CInputHand::SetTurn(PCard cTurnCard)
{
	m_eRound =	ROUND_TURN;
	TRACE("Turn cards delt ");
	cTurnCard.DUMP();
	TRACE("\n");
	m_prsHands->m_Turn_rank = cTurnCard.getRank().getHashValue();
	m_prsHands->m_Turn_suit = cTurnCard.getSuit().getHashValue();
}

inline void CInputHand::SetIncomplete()
{
	TRACE("Set imcomlete\n");
	m_bIncomplete = true;
}

inline void CInputHand::SetRiver(PCard cRiverCard)
{
	m_eRound =	ROUND_RIVER;
	TRACE("River cards delt ");
	cRiverCard.DUMP();
	TRACE("\n");
	m_prsHands->m_River_rank = cRiverCard.getRank().getHashValue();
	m_prsHands->m_River_suit = cRiverCard.getSuit().getHashValue();
}

inline void CInputHand::SetPot(int iPot)
{
	TRACE1("Pot was %d\n", iPot);
	m_prsHands->m_Pot = iPot;
}

inline void CInputHand::SetRake(int iRake)
{
	TRACE1("Rake was %d\n", iRake);
	m_prsHands->m_Rake = iRake;
}

inline void CInputHand::SetPlayerProfitLoss(const CString &strNick, int iProfitLoss)
{
	TRACE("Net profit/loss for %s was %d\n", strNick, iProfitLoss);
	ASSERT(m_prsPlayers && m_prsResults);
	long lPlayerId = CPDPlayersRecordset::GetPlayerId(strNick, m_iSiteId);
	m_prsResults->GetResultsFor(lPlayerId, GetHandId());
	m_prsResults->Edit();
	m_prsResults->m_Win_loss += iProfitLoss;
	m_prsResults->Update();
}

inline void CInputHand::WriteToDataBase()
{
	TRACE("Write to database called\n");
	m_prsHands->Update();

	CString strText;
	strText.Format("Read Hand Number %s\n", m_prsHands->m_Hand_reference);
	ofstream fOutFile(SPY_DEAMON_LOG_FILE, ios::app , filebuf::sh_read || filebuf::sh_write);
	fOutFile.write(strText, strlen(strText));
	fOutFile.flush();
	fOutFile.close();

	if (m_bTransactionPending)
	{
		m_dbPokerData.CommitTrans();
		m_bTransactionPending = FALSE;
	}
	else
	{
		ASSERT(FALSE);
	}
	if (m_prsHands)
	{
		m_prsHands->Close();
		delete(m_prsHands);
		m_prsHands = NULL;
	}
	if (m_prsPlayers)
	{
		//m_prsPlayers->Close();
		delete(m_prsPlayers);
		m_prsPlayers = NULL;
	}
	if (m_prsResults)
	{
		m_prsResults->Close();
		delete(m_prsResults);
		m_prsResults = NULL;
	}
	if (m_prsActions)
	{
		m_prsActions->Close();
		delete(m_prsActions);
		m_prsActions = NULL;
	}
	m_bIncomplete = false;
}

inline void CInputHand::OpenConnection()
{
}

inline void CInputHand::CloseConnection()
{
	if (m_bTransactionPending)
	{
		m_dbPokerData.Rollback();
		m_bTransactionPending = FALSE;
	}
	if (m_prsHands)
	{
		m_prsHands->Close();
		delete(m_prsHands);
		m_prsHands = NULL;
	}
	if (m_prsPlayers)
	{
		//m_prsPlayers->Close();
		delete(m_prsPlayers);
		m_prsPlayers = NULL;
	}
	if (m_prsResults)
	{
		m_prsResults->Close();
		delete(m_prsResults);
		m_prsResults = NULL;
	}
	if (m_prsActions)
	{
		m_prsActions->Close();
		delete(m_prsActions);
		m_prsActions = NULL;
	}

}

inline void CInputHand::NewHand()
{
	m_bIncomplete = false;
	if (m_bTransactionPending)
	{
		CloseConnection();
	}
	m_iPostion = POSITION_BIG_BLIND + 1;
	m_eRound = ROUND_PRE_FLOP;
}

inline void CInputHand::SetPlayerSatOut(const CString& strNick)
{
	TRACE1("Player %s sat out", strNick);
}

inline long CInputHand::GetHandId()
{
	ASSERT(m_prsHands);
	return m_prsHands->m_Hand_Id;
}

inline int CInputHand::GetHostId()
{
	return m_iSiteId;
}

inline CString CInputHand::GetGameNumber()
{
	ASSERT(m_prsHands);
	return m_prsHands->m_Hand_reference;
}

inline void CInputHand::SetFlop()
{
	TRACE("Set round to flop\n");
	m_eRound =	ROUND_FLOP;
}

inline void CInputHand::SetTurn()
{
	TRACE("Set round to turn\n");
	m_eRound =	ROUND_TURN;
}

inline void CInputHand::SetRiver()
{
	TRACE("Set round to river\n");
	m_eRound =	ROUND_RIVER;
}

inline void CInputHand::SetToNextRound()
{
	ASSERT(m_eRound != ROUND_RIVER);
	m_eRound = (PokerRound) (((int) m_eRound) + 1);
	TRACE("/nSet round to %i\n", m_eRound);
}



#endif // !defined(AFX_INPUTHAND_H__436FD097_38F4_4132_84C0_C9F966FCE593__INCLUDED_)
