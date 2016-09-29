// RSGameSize.cpp : implementation file
//

#include "stdafx.h"
#include "PPokerObject.h"
#include "PokerResultViewer.h"
#include "RSGameSize.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// RSGameSize

IMPLEMENT_DYNAMIC(RSGameSize, CRecordset)

RSGameSize::RSGameSize(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(RSGameSize)
	m_Game_Size_Id = 0;
	m_Small_Blind = 0;
	m_Middle_Blind = 0;
	m_Big_Blind = 0;
	m_Ante = 0;
	m_Small_Bet = 0;
	m_Big_Bet = 0;
	m_Name = _T("");
	m_FK_Currency = 0;

	m_nFields = 9;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
	m_Small_BlindParm = 0;
	m_Middle_BlindParm = 0;
	m_Big_BlindParm = 0;
	m_AnteParm = 0;
	m_Small_BetParm = 0;
	m_Big_BetParm = 0;
	m_FK_CurrencyParm = 0;
	m_nParams = 7;

	m_strSort = "[FK_Currency], [Small Blind],[Small Bet], [Ante]" ;
}


CString RSGameSize::GetDefaultConnect()
{
	return _T(POKER_RESULTS_CONNECT_STRING);
}

CString RSGameSize::GetDefaultSQL()
{
	return _T("[dbo].[Game Size]");
}

void RSGameSize::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(RSGameSize)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[Game Size Id]"), m_Game_Size_Id);
	RFX_Long(pFX, _T("[Small Blind]"), m_Small_Blind);
	RFX_Long(pFX, _T("[Middle Blind]"), m_Middle_Blind);
	RFX_Long(pFX, _T("[Big Blind]"), m_Big_Blind);
	RFX_Long(pFX, _T("[Ante]"), m_Ante);
	RFX_Long(pFX, _T("[Small Bet]"), m_Small_Bet);
	RFX_Long(pFX, _T("[Big Bet]"), m_Big_Bet);
	RFX_Text(pFX, _T("[Name]"), m_Name);
	RFX_Long(pFX, _T("[FK_Currency]"), m_FK_Currency);

	//}}AFX_FIELD_MAP
   	pFX->SetFieldType(CFieldExchange::param); 
	RFX_Long(pFX, _T("[Small Blind]"), m_Small_BlindParm);
	RFX_Long(pFX, _T("[Middle Blind]"), m_Middle_BlindParm);
	RFX_Long(pFX, _T("[Big Blind]"), m_Big_BlindParm);
	RFX_Long(pFX, _T("[Ante]"), m_AnteParm);
	RFX_Long(pFX, _T("[Small Bet]"), m_Small_BetParm);
	RFX_Long(pFX, _T("[Big Bet]"), m_Big_BetParm);
	RFX_Long(pFX, _T("[FK_Currency]"), m_FK_CurrencyParm);

}

/////////////////////////////////////////////////////////////////////////////
// RSGameSize diagnostics

#ifdef _DEBUG
void RSGameSize::AssertValid() const
{
	CRecordset::AssertValid();
}

void RSGameSize::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


void RSGameSize::ActivateFilter()
{
	m_strFilter = "[Small Blind] = ? AND [Middle Blind] = ? AND [Big Blind] = ? AND [Ante] = ? AND [Small Bet] = ? AND [Big Bet] = ? AND [FK_Currency] = ?";
}
