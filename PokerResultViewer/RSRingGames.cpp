// RSRingGames.cpp : implementation file
//

#include "stdafx.h"
#include "PokerResultViewer.h"
#include "RSRingGames.h"
#include "PPokerObject.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// RSRingGames

IMPLEMENT_DYNAMIC(RSRingGames, CRecordset)

RSRingGames::RSRingGames(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(RSRingGames)
	m_RingGameId = 0;
	m_FK_CardRoom = 0;
	m_FK_Varient = 0;
	m_FK_BettingFormat = 0;
	m_FK_GameSize = 0;
	m_nFields = 5;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
	m_FK_CardRoomParm = 0;
	m_FK_VarientParm = 0;
	m_FK_BettingFormatParm = 0;
	m_FK_GameSizeParm = 0;
	m_nParams = 4;
	m_strFilter = "[FK_CardRoom] = ? AND [FK_Varient] = ? AND [FK_BettingFormat] = ? AND [FK_GameSize] = ?";
}


CString RSRingGames::GetDefaultConnect()
{
	return _T(POKER_RESULTS_CONNECT_STRING);
}

CString RSRingGames::GetDefaultSQL()
{
	return _T("[dbo].[RingGames]");
}

void RSRingGames::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(RSRingGames)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[RingGameId]"), m_RingGameId);
	RFX_Long(pFX, _T("[FK_CardRoom]"), m_FK_CardRoom);
	RFX_Long(pFX, _T("[FK_Varient]"), m_FK_Varient);
	RFX_Long(pFX, _T("[FK_BettingFormat]"), m_FK_BettingFormat);
	RFX_Long(pFX, _T("[FK_GameSize]"), m_FK_GameSize);
	//}}AFX_FIELD_MAP	
   	pFX->SetFieldType(CFieldExchange::param); 
	RFX_Long(pFX, _T("[FK_CardRoom"), m_FK_CardRoomParm);
	RFX_Long(pFX, _T("[FK_Varient]"), m_FK_VarientParm);
	RFX_Long(pFX, _T("[FK_BettingFormat]"), m_FK_BettingFormatParm);
	RFX_Long(pFX, _T("[FK_GameSize]"), m_FK_GameSizeParm);
}

/////////////////////////////////////////////////////////////////////////////
// RSRingGames diagnostics

#ifdef _DEBUG
void RSRingGames::AssertValid() const
{
	CRecordset::AssertValid();
}

void RSRingGames::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
