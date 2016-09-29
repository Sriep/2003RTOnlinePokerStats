// InputHand.cpp: implementation of the CInputHand class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "InputHand.h"
#include "ParsingException.h"
#include "PPlayerAction.h"
#include "PPokerSite.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif


//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CInputHand::CInputHand()
:	m_dbPokerData(),
	m_prsPlayers(NULL),
	m_prsResults(NULL),
	m_prsActions(NULL),
	m_prsHands(NULL),
	m_bTransactionPending(FALSE),
	m_bIncomplete(FALSE),
	m_iSiteId(PPokerSite::POKER_SITE_NONE),
	iNumberFlopCardsDelt(0)
{
	//if (!m_dbPokerData.Open("PokerData", false, false, "ODBC;DSN=PokerData;UID=sa;PWD=;"))//POKER_DATA_CONNECT_STRING))
	//{
	//	throw(new CParsingException("Error opening Poker Data database"));
	//}
}

CInputHand::SetDataSource(int iSiteId)
{
	m_iSiteId = iSiteId;
	if ( !m_dbPokerData.Open(PPokerSite::GetLoggingDataSource(iSiteId), false, false, PPokerSite::GetLoggingSQLConnectString(iSiteId)) )
	{
		throw(new CParsingException("Error opening Poker Data database"));
	}
	TRACE2("Opend datasource %s with connect string %s\n",PPokerSite::GetLoggingDataSource(iSiteId), PPokerSite::GetLoggingSQLConnectString(iSiteId)); 
}



CInputHand::~CInputHand()
{
	m_dbPokerData.Close();
}


void CInputHand::SetPokerSite(PokerSites ePokerSite)
{
	ASSERT(m_iSiteId = ePokerSite);
	TRACE1("Poker Site = %d\n", (int)ePokerSite);
	if (NULL == m_prsHands)
	{
		m_prsHands = new CPDHandRecordset(&m_dbPokerData);
		m_prsPlayers = new CPDPlayersRecordset();
		m_prsResults = new CPDResultsRecordset(&m_dbPokerData);
		m_prsActions = new CPDActionsRecordset(&m_dbPokerData);

	//	m_prsHands->m_iPokerSiteParam = (int)ePokerSite;
	}
	else
	{
		ASSERT(m_prsHands->m_strHandReferenceParam != "");
		StartNewTransaction();
		//m_prsHands->m_iPokerSiteParam = (int)ePokerSite;
		m_prsHands->PrepareForEdit(m_bIncomplete);
	}
}

void CInputHand::SetGameNumber(long lGameNumber)
{
	char strNumBuffer[34];
	SetGameNumber(ltoa(lGameNumber, strNumBuffer, 10));
}

void CInputHand::SetGameNumber(const CString& strGameNumber)
{
	TRACE1("Game number = %s\n", strGameNumber);
	if (NULL == m_prsHands)
	{
		m_prsHands = new CPDHandRecordset(&m_dbPokerData);
		m_prsPlayers = new CPDPlayersRecordset();
		m_prsResults = new CPDResultsRecordset(&m_dbPokerData);
		m_prsActions = new CPDActionsRecordset(&m_dbPokerData);

		m_prsHands->m_strHandReferenceParam = strGameNumber;
	}
	else
	{
		//ASSERT((int)PPokerSite::POKER_SITE_NONE != m_prsHands->m_iPokerSiteParam);
		StartNewTransaction();
		m_prsHands->m_strHandReferenceParam = strGameNumber;
		m_prsHands->PrepareForEdit(m_bIncomplete);
		m_prsHands->m_Incomplete = m_bIncomplete;
	}

	CString strText;
	strText.Format("Starting to read game number %s\n", strGameNumber);
	ofstream fOutFile(SPY_DEAMON_LOG_FILE, ios::app , filebuf::sh_read || filebuf::sh_write);
	fOutFile.write(strText, strlen(strText));
	fOutFile.flush();
	fOutFile.close();
}

void CInputHand::StartNewTransaction()
{
	if (m_bTransactionPending)
	{
		CloseConnection();
		m_prsHands = new CPDHandRecordset(&m_dbPokerData);
		m_prsPlayers = new CPDPlayersRecordset();
		m_prsResults = new CPDResultsRecordset(&m_dbPokerData);
		m_prsActions = new CPDActionsRecordset(&m_dbPokerData);
	}

	if (!m_dbPokerData.BeginTrans())
	{
		throw(new CParsingException("Error starting transaction"));
	}
	else
	{
		m_bTransactionPending = TRUE;
	}
}

void CInputHand::SetSmallBlind(const CString& strNick, int iAmount)
{
	TRACE2("Add small blind %s, who posted %d\n", strNick, iAmount);
	ASSERT(!strNick.IsEmpty());
	m_eRound = ROUND_PRE_FLOP;
	m_iPostion = POSITION_SMALL_BLIND;
			 
	ASSERT(m_prsPlayers && m_prsResults);
	long lPlayerId = CPDPlayersRecordset::GetPlayerId(strNick, m_iSiteId);
	m_prsResults->GetResultsFor(lPlayerId, GetHandId());
	m_prsResults->Edit();
	m_prsResults->m_Position = m_iPostion;
	m_prsResults->Update();
	//m_prsHands->m_Active_Players++;// = m_iPostion++;
}

void CInputHand::SetBigBlind(const CString &strNick, int iAmount)
{
	TRACE2("Add big blind %s, who posted %d\n", strNick, iAmount);

	m_eRound = ROUND_PRE_FLOP;
	m_iPostion = POSITION_BIG_BLIND;
			 
	ASSERT(m_prsPlayers && m_prsResults);
	long lPlayerId = CPDPlayersRecordset::GetPlayerId(strNick, m_iSiteId);
	m_prsResults->GetResultsFor(lPlayerId, GetHandId());
	m_prsResults->Edit();
	m_prsResults->m_Position = m_iPostion;
	m_prsResults->Update();
	//m_prsHands->m_Active_Players++;// = m_iPostion++;
}

   

void CInputHand::AddJumbledHand(const CString &strhandReference)
{
	ASSERT(NULL == m_prsHands);
	m_prsHands = new CPDHandRecordset(&m_dbPokerData);
	m_prsHands->AddJumbledGame(strhandReference, m_iSiteId);
	delete 	m_prsHands;
}
