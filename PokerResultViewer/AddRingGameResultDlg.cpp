// AddRingGameResultDlg.cpp : implementation file
//

#include "stdafx.h"
#include "PokerResultViewer.h"
#include "AddRingGameResultDlg.h"
#include "RSGameSize.h"	
#include "RSRingGames.h"
#include "RSRingGameResults.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAddRingGameResultDlg dialog


CAddRingGameResultDlg::CAddRingGameResultDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAddRingGameResultDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAddRingGameResultDlg)
	//}}AFX_DATA_INIT
	m_comboVariant.SetDependantCombo(&m_comboGameSize);
	m_comboBettingFormat.SetDependantCombo(&m_comboGameSize);
}


void CAddRingGameResultDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAddRingGameResultDlg)
	DDX_Control(pDX, IDC_RGRESULT_DATETIME, m_ctlDateTime);
	DDX_Control(pDX, IDC_RGRESULT_GAME_SIZE_NAME, m_ctlGameSizeName);
	DDX_Control(pDX, IDC_RGRESULT_SMALL_BET, m_ctlSmallBet);
	DDX_Control(pDX, IDC_RGRESULT_MIDDLE_BLIND, m_ctlMiddleBlind);
	DDX_Control(pDX, IDC_RGRESULT_BIG_BLIND, m_ctlBigBlind);
	DDX_Control(pDX, IDC_RGRESULT_BIG_BET, m_ctlBigBet);
	DDX_Control(pDX, IDC_RGRESULT_ANTE, m_ctlAnte);
	DDX_Control(pDX, IDC_RGRESULT_SMALL_BLIND, m_ctlSmallBlind);
	DDX_Control(pDX, IDC_RGRESULT_CURRENCY, m_comboCurrency);
	DDX_Control(pDX, IDC_RGRESULT_CASINO, m_comboCardRoom);
	DDX_Control(pDX, IDC_RGRESULT_VARIANT, m_comboVariant);
	DDX_Control(pDX, IDC_RGRESULT_GAME_SIZE, m_comboGameSize);
	DDX_Control(pDX, IDC_RGRESULT_BETTING_FORMAT, m_comboBettingFormat);
	DDX_Control(pDX, IDC_RGRESULT_WIN_LOSS_CURRENCY, m_ctlCurrencySymbol);
	DDX_Control(pDX, IDC_RGRESULT_WIN_LOSS, m_ctlWinLoss);
	DDX_Control(pDX, IDC_RGRESULT_DURATION, m_ctlDuration);
	DDX_Control(pDX, IDC_RGRESULT_DATE, m_calctlDate);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAddRingGameResultDlg, CDialog)
	//{{AFX_MSG_MAP(CAddRingGameResultDlg)
	ON_CBN_SELCHANGE(IDC_RGRESULT_CURRENCY, OnSelchangeCurrency)
	ON_CBN_SELCHANGE(IDC_RGRESULT_GAME_SIZE, OnSelchangeRgresultGameSize)
	ON_BN_CLICKED(IDC_B_ADDRESULTS, OnAddResults)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAddRingGameResultDlg message handlers

BOOL CAddRingGameResultDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	m_comboCurrency.Populate();
	m_comboCurrency.SetCurSel(1); //Will get from registry eventualy --- 'onestly	

	m_comboCardRoom.Populate();

	m_comboVariant.Populate();
	m_comboVariant.SetCurSel(0);

	m_comboGameSize.Populate();

	m_comboBettingFormat.Populate();
	m_comboBettingFormat.SetCurSel(2);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CAddRingGameResultDlg::OnSelchangeCurrency() 
{
	// TODO: Add your control notification handler code here
	m_ctlCurrencySymbol.SetWindowText(m_comboCurrency.GetCurrencySymbol());
}

void CAddRingGameResultDlg::OnBAddnewgamesize() 
{
	// TODO: Add your control notification handler code here
	RSGameSize rsGameSize;
	rsGameSize.ActivateFilter();
	rsGameSize.m_AnteParm =  m_ctlAnte.GetMoneyValue();
	rsGameSize.m_Small_BetParm =  m_ctlSmallBet.GetMoneyValue();
	rsGameSize.m_Big_BetParm =  m_ctlBigBet.GetMoneyValue();
	rsGameSize.m_Small_BlindParm =  m_ctlSmallBlind.GetMoneyValue();
	rsGameSize.m_Middle_BlindParm =  m_ctlMiddleBlind.GetMoneyValue();
	rsGameSize.m_Big_BlindParm =  m_ctlBigBlind.GetMoneyValue();
	rsGameSize.m_Big_BlindParm =  m_ctlBigBlind.GetMoneyValue();
	rsGameSize.m_FK_CurrencyParm = 	m_comboCurrency.GetCurrencyCode();

	rsGameSize.Open();
	if (rsGameSize.GetRecordCount() == 0)
	{
		rsGameSize.AddNew();
		rsGameSize.m_Ante =  m_ctlAnte.GetMoneyValue();
		rsGameSize.m_Small_Bet =  m_ctlSmallBet.GetMoneyValue();
		rsGameSize.m_Big_Bet =  m_ctlBigBet.GetMoneyValue();
		rsGameSize.m_Small_Blind =  m_ctlSmallBlind.GetMoneyValue();
		rsGameSize.m_Middle_Blind =  m_ctlMiddleBlind.GetMoneyValue();
		rsGameSize.m_Big_Blind =  m_ctlBigBlind.GetMoneyValue();
		rsGameSize.m_FK_Currency = 	m_comboCurrency.GetCurrencyCode();
		CString strName;
		m_ctlGameSizeName.GetWindowText(strName);
		rsGameSize.m_Name = strName;
		rsGameSize.Update();
		rsGameSize.Requery();
	}
	m_comboGameSize.Populate();
	m_comboGameSize.SetSelToGameSizeId(rsGameSize.m_Game_Size_Id);
	rsGameSize.Close();
}


void CAddRingGameResultDlg::OnSelchangeRgresultGameSize() 
{
	// TODO: Add your control notification handler code here
	
	m_ctlAnte.SetMoneyValue(m_comboGameSize.GetAnte());
	m_ctlSmallBet.SetMoneyValue(m_comboGameSize.GetSmallBet());
	m_ctlBigBet.SetMoneyValue(m_comboGameSize.GetBigBet());			 
	m_ctlSmallBlind.SetMoneyValue(m_comboGameSize.GetSmallBlind());
	m_ctlMiddleBlind.SetMoneyValue(m_comboGameSize.GetMiddleBlind());
	m_ctlBigBlind.SetMoneyValue(m_comboGameSize.GetBigBlind());
	m_ctlGameSizeName.SetWindowText(m_comboGameSize.GetName());
	m_comboCurrency.SetFromCurrencyCode(m_comboGameSize.GetFKCurrency());
}

void CAddRingGameResultDlg::OnAddResults() 
{
	// TODO: Add your control notification handler code here
	OnBAddnewgamesize();
	RSRingGameResults rsResults; 
	rsResults.Open();
	rsResults.AddNew();

	rsResults.m_FK_RingGames = GetOrMakeRingGameId();	   
	
	CTime tTime;
	m_ctlDateTime.GetTime(tTime);
	CString strDate = tTime.Format( "%c" );
	TRACE("Time = %s\n", strDate);
										
	CTime tDate;
	m_calctlDate.GetCurSel(tDate);
	//m_calctlDate.GetToday(tDate);
	strDate = tDate.Format("%A, %B %d, %Y");
	TRACE("Date = %s\n", strDate);

	tDate -= CTimeSpan(12,0,0,0);	//Dont understand there appears to be some bug that causes wrong date to be given.
	m_calctlDate.SetCurSel(tDate);

	CTime tDateTime(tDate.GetYear(), tDate.GetMonth(), tDate.GetDay(), tTime.GetHour(), tTime.GetMinute(), tTime.GetSecond());
	strDate = tDateTime.Format( "%#c" );
	TRACE("Date Time = %s\n", strDate);
	rsResults.m_Date = tDateTime;

	CString strMessage;
	strMessage.Format("%s %s %s\n%s\n%s\nWin =%s%d Duration = %d minuets",
		m_comboCardRoom.GetText(),
		m_comboBettingFormat.GetText(),
		m_comboVariant.GetText(),
		m_comboGameSize.GetText(),
		strDate,
		m_comboCurrency.GetCurrencyChar(),
		m_ctlWinLoss.GetValue(),
		m_ctlDuration.GetValue());
	if (IDOK == MessageBox(strMessage, "Confirm you want to add results",MB_OKCANCEL))
	{
		rsResults.m_Duration = m_ctlDuration.GetValue();
		rsResults.m_WinLoss = m_ctlWinLoss.GetMoneyValue();
		rsResults.Update();
	}

	rsResults.Close();
}

long CAddRingGameResultDlg::GetOrMakeRingGameId()
{
	RSRingGames rsRingGames;
	rsRingGames.m_FK_CardRoomParm =  m_comboCardRoom.GetCardRoomId();
	rsRingGames.m_FK_VarientParm =  m_comboVariant.GetVairiantId();
	rsRingGames.m_FK_BettingFormatParm =  m_comboBettingFormat.GetBettingFormatId();
	rsRingGames.m_FK_GameSizeParm =  m_comboGameSize.GetGameSizeId();

	rsRingGames.Open();
	if (rsRingGames.GetRecordCount() == 0)
	{
		rsRingGames.AddNew();
		rsRingGames.m_FK_CardRoom =  m_comboCardRoom.GetCardRoomId();
		rsRingGames.m_FK_Varient =  m_comboVariant.GetVairiantId();
		rsRingGames.m_FK_BettingFormat =  m_comboBettingFormat.GetBettingFormatId();
		rsRingGames.m_FK_GameSize = m_comboGameSize.GetGameSizeId();
		rsRingGames.Update();
		rsRingGames.Requery();
	}
	long lRingGameId = rsRingGames.m_RingGameId;
	rsRingGames.Close();
	return lRingGameId;
}

