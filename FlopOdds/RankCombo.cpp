// RankCombo.cpp : implementation file
//

#include "stdafx.h"
#include "FlopOdds.h"
#include "RankCombo.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRankCombo

CRankCombo::CRankCombo()
{
}

CRankCombo::~CRankCombo()
{
}


BEGIN_MESSAGE_MAP(CRankCombo, CComboBox)
	//{{AFX_MSG_MAP(CRankCombo)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRankCombo message handlers

void CRankCombo::populate()
{
	AddString("2");
	AddString("3");
	AddString("4");
	AddString("5");
	AddString("6");
	AddString("7");
	AddString("8");
	AddString("9");
	AddString("10");
	AddString("Jack");
	AddString("Queen");
	AddString("King");
	AddString("Ace");
}

PPokerObject::PRank CRankCombo::getSelectedRank()
{
	if (GetCurSel() == CB_ERR)
	{
		return NO_RANK;
	}  
	CString strRank;
	GetWindowText(strRank);

	return PPokerObject::PRank::stringToRank(strRank);
}



