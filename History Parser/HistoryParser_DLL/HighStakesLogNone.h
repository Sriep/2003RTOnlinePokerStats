// HighStakesLogNone.h: interface for the CHighStakesLogNone class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_HighStakesLOGNONE_H__B7AD3784_4E05_40E4_B3DE_4B88D45E56D0__INCLUDED_)
#define AFX_HighStakesLOGNONE_H__B7AD3784_4E05_40E4_B3DE_4B88D45E56D0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ParseState.h"
#include "PPokerSite.h"
#include "PPlayerAction.h"

class CHighStakesLogNone : public CParseState  
{
public:
	CHighStakesLogNone(CParseFile* cPF);
	virtual ~CHighStakesLogNone();
	virtual CParseState* Parse(const CString &strInLine);
	void ReadPost(CString& strUnreadLine);
	void ReadSmallBlind(CString& strUnreadLine);
	//void ReadBigBlind(CString& strUnreadLine);
	void SetUpForNewHand(CString& strUnreadLine);
	void SetBlinds();
private	:
	CString m_strSmallBlind;
	//int m_iAmountSmallBlind;	
	CString m_strPoster[10];
	//int m_iAmountPoster[10];
	int m_iNumberOfPosters;
};

inline void CHighStakesLogNone::ReadPost(CString& strUnreadLine)
{
	if (ReverseReadIfNextWord("posted big blind.", strUnreadLine) 
		|| ReverseReadIfNextWord("posted big blind and dead small blind.", strUnreadLine))
	{
		strUnreadLine.TrimLeft(' ');
		strUnreadLine.TrimRight(' ');
		ASSERT(strUnreadLine != "");
		m_strPoster[m_iNumberOfPosters] = strUnreadLine;
		TRACE1("%s posted\n", m_strPoster[m_iNumberOfPosters]);
		m_iNumberOfPosters++;
	}
	else
	{
		ASSERT(FALSE);
	}
}

inline void CHighStakesLogNone::ReadSmallBlind(CString& strUnreadLine)
{
	ReverseReadText("posted small blind.", strUnreadLine);
	strUnreadLine.TrimLeft(' ');
	strUnreadLine.TrimRight(' ');
	ASSERT(strUnreadLine != "");
	m_strSmallBlind = strUnreadLine;
	TRACE1("%s posted the small blind\n", m_strSmallBlind);
}
 /*
inline void CHighStakesLogNone::ReadBigBlind(CString& strUnreadLine)
{
	ReverseReadText("posted big blind.", strUnreadLine);
	strUnreadLine.TrimLeft(' ');
	strUnreadLine.TrimRight(' ');
	m_strPoster[0] = strUnreadLine;
	ASSERT(0 == m_iNumberOfPosters);
	TRACE1("%s postedd\n", strUnreadLine);
}  */


inline void CHighStakesLogNone::SetUpForNewHand(CString& strUnreadLine)
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


inline void CHighStakesLogNone::SetBlinds()
{
	sm_cInputHand.SetSmallBlind(m_strSmallBlind, 0);
	sm_listNicks.push_back(m_strSmallBlind);
	sm_cInputHand.SetBigBlind(m_strPoster[0], 0);
	sm_listNicks.push_back(m_strPoster[0]);

	for ( int iPoster = 1 ; iPoster < m_iNumberOfPosters ; iPoster++ )
	{
		sm_cInputHand.AddPlayer(0, m_strPoster[iPoster], 0);
		PPlayerAction cAction(PPlayerAction::ACTION_POST);
		sm_cInputHand.AddPlayerAction(m_strPoster[iPoster], cAction, 0);
	}
}

#endif // !defined(AFX_HighStakesLOGNONE_H__B7AD3784_4E05_40E4_B3DE_4B88D45E56D0__INCLUDED_)
