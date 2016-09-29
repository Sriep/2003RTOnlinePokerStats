// SuitCombo.cpp : implementation file
//

#include "stdafx.h"
#include "FlopOdds.h"
#include "SuitCombo.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSuitCombo

CSuitCombo::CSuitCombo()
{
}

CSuitCombo::~CSuitCombo()
{
}


BEGIN_MESSAGE_MAP(CSuitCombo, CComboBox)
	//{{AFX_MSG_MAP(CSuitCombo)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSuitCombo message handlers

void CSuitCombo::populate()
{
	AddString("Spades");
	AddString("Hearts");
	AddString("Diamonds");
	AddString("Clubs");
}

PPokerObject::PSuit CSuitCombo::getSelectedSuit()
{
	if (GetCurSel() == CB_ERR)
	{
		return NO_SUIT;
	}  
	CString strSuit;
	GetWindowText(strSuit);

	return PSuit::stringToSuit(strSuit);
}

