// RoyalVegasLogNone.h: interface for the CRoyalVegasLogNone class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_RoyalVegasLOGNONE_H__B7AD3784_4E05_40E4_B3DE_4B88D45E56D0__INCLUDED_)
#define AFX_RoyalVegasLOGNONE_H__B7AD3784_4E05_40E4_B3DE_4B88D45E56D0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ParseState.h"
#include "PPokerSite.h"
#include "PPlayerAction.h"

class CRoyalVegasLogNone : public CParseState  
{
public:
	CRoyalVegasLogNone(CParseFile* cPF);
	virtual ~CRoyalVegasLogNone();
	virtual CParseState* Parse(const CString &strInLine);
	void ReadPost(CString& strUnreadLine);
	void ReadSmallBlind(CString& strUnreadLine);
	void ReadBigBlind(CString& strUnreadLine);
	void SetUpForNewHand(CString& strUnreadLine);
	void SetBlinds();
private	:
	CString m_strSmallBlind;
	int m_iAmountSmallBlind;	
	CString m_strPoster[10];
	int m_iAmountPoster[10];
	int m_iNumberOfPosters;
};

inline void CRoyalVegasLogNone::ReadPost(CString& strUnreadLine)
{
	ReverseReadText(')', strUnreadLine);
	int iPost = ReverseGetNextNumber(strUnreadLine);

	ReverseReadIfNextWord("posted to play ($", strUnreadLine);
	strUnreadLine.TrimLeft(' ');
	strUnreadLine.TrimRight(' ');
	ASSERT(strUnreadLine != "");
	m_strPoster[m_iNumberOfPosters] = strUnreadLine;
	m_iAmountPoster[m_iNumberOfPosters++] = iPost;
	TRACE1("%s posted", m_strPoster);
}

inline void CRoyalVegasLogNone::ReadSmallBlind(CString& strUnreadLine)
{
	ReverseReadText(')', strUnreadLine);
	int iPost = ReverseGetNextNumber(strUnreadLine);
	ReverseReadText("posted small blind ($", strUnreadLine);
	strUnreadLine.TrimLeft(' ');
	strUnreadLine.TrimRight(' ');
	ASSERT(strUnreadLine != "");
	m_strSmallBlind = strUnreadLine;
	m_iAmountSmallBlind = iPost;
	TRACE1("%s posted the small blind\n", m_strSmallBlind);
}

inline void CRoyalVegasLogNone::ReadBigBlind(CString& strUnreadLine)
{
	ReverseReadText(')', strUnreadLine);
	int iPost = ReverseGetNextNumber(strUnreadLine);
	ReverseReadText("posted big blind ($", strUnreadLine);
	strUnreadLine.TrimLeft(' ');
	strUnreadLine.TrimRight(' ');
	m_strPoster[0] = strUnreadLine;
	ASSERT(0 == m_iNumberOfPosters);
	m_iAmountPoster[m_iNumberOfPosters++] = iPost;
	TRACE1("%s posted the big blind\n", strUnreadLine);
}


inline void CRoyalVegasLogNone::SetUpForNewHand(CString& strUnreadLine)
{
	sm_cInputHand.NewHand();
	sm_cInputHand.SetPokerSite(m_cParseFile->GetSite());
	//sm_cInputHand.SetPokerSite(PPokerSite::POKER_SITE_ROYAL_VEGAS);
	sm_cInputHand.SetIncomplete();
	sm_listNicks.clear();
	sm_cInputHand.SetGameNumber(GetNextNumber(strUnreadLine));
	sm_cInputHand.SetGame(GAME_TEXUS_HOLDEM);
	sm_cInputHand.SetTableName(m_cParseFile->GetTableName());
}


inline void CRoyalVegasLogNone::SetBlinds()
{
	sm_cInputHand.SetSmallBlind(m_strSmallBlind, m_iAmountSmallBlind);
	sm_listNicks.push_back(m_strSmallBlind);
	sm_cInputHand.SetBigBlind(m_strPoster[0], m_iAmountPoster[0]);
	sm_listNicks.push_back(m_strPoster[0]);

	for ( int iPoster = 1 ; iPoster < m_iNumberOfPosters ; iPoster++ )
	{
		sm_cInputHand.AddPlayer(0, m_strPoster[iPoster], 0);
		PPlayerAction cAction(PPlayerAction::ACTION_POST);
		sm_cInputHand.AddPlayerAction(m_strPoster[iPoster], cAction, m_iAmountPoster[iPoster]);
	}
}

#endif // !defined(AFX_RoyalVegasLOGNONE_H__B7AD3784_4E05_40E4_B3DE_4B88D45E56D0__INCLUDED_)
