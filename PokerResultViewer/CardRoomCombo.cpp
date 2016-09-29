// CardRoomCombo.cpp : implementation file
//

#include "stdafx.h"
#include "PokerResultViewer.h"
#include "CardRoomCombo.h"
#include "RSCardRooms.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCardRoomCombo

CCardRoomCombo::CCardRoomCombo()
{
}

CCardRoomCombo::~CCardRoomCombo()
{
}


BEGIN_MESSAGE_MAP(CCardRoomCombo, CComboBox)
	//{{AFX_MSG_MAP(CCardRoomCombo)
	ON_CONTROL_REFLECT(CBN_DROPDOWN, OnDropdown)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCardRoomCombo message handlers

void CCardRoomCombo::OnDropdown() 
{
	// TODO: Add your control notification handler code here
	if (GetCount() == 0)
	{
		Populate();
	}
}

long CCardRoomCombo::GetCardRoomId()
{
	return m_lCardRoomID[GetCurSel()];
}

void CCardRoomCombo::Populate()
{
	
	if (GetCount() == 0)
	{
		int iIndex = 0;
		ResetContent();
		RSCardRooms rs;
		rs.m_lStateParam = 1;
		if (!rs.Open(CRecordset::snapshot, NULL, CRecordset::readOnly))
		{
			return;
		}
		while (!rs.IsEOF())
		{
			InsertString(iIndex, rs.m_Card_Room);
			m_lCardRoomID[iIndex]  = rs.m_Card_Room_ID;
			iIndex++;
			rs.MoveNext();
		}
		rs.Close();
	}
}

CString CCardRoomCombo::GetText()
{
	CString strText;
	GetWindowText(strText);
	return strText;
}
