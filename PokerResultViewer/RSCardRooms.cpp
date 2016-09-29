// RSCardRooms.cpp : implementation file
//

#include "stdafx.h"
#include "PokerResultViewer.h"
#include "RSCardRooms.h"
#include "PPokerObject.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// RSCardRooms

IMPLEMENT_DYNAMIC(RSCardRooms, CRecordset)

RSCardRooms::RSCardRooms(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(RSCardRooms)
	m_Card_Room_ID = 0;
	m_Card_Room = _T("");
	m_Online = FALSE;
	m_Details = _T("");
	m_FK_Supported_Online = 0;
	m_nFields = 5;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
	m_lStateParam = 0;
	m_nParams = 1;
	m_strFilter = "[State] = ?";
}


CString RSCardRooms::GetDefaultConnect()
{
	return _T(POKER_RESULTS_CONNECT_STRING);
}

CString RSCardRooms::GetDefaultSQL()
{
	return _T("[dbo].[CardRooms]");
}

void RSCardRooms::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(RSCardRooms)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[Card Room ID]"), m_Card_Room_ID);
	RFX_Text(pFX, _T("[Card Room]"), m_Card_Room);
	RFX_Bool(pFX, _T("[Online]"), m_Online);
	RFX_Text(pFX, _T("[Details]"), m_Details);
	RFX_Long(pFX, _T("[FK_Supported)Online]"), m_FK_Supported_Online);
	//}}AFX_FIELD_MAP
   	pFX->SetFieldType(CFieldExchange::param); 
	RFX_Long(pFX, _T("[State]"), m_lStateParam);
}

/////////////////////////////////////////////////////////////////////////////
// RSCardRooms diagnostics

#ifdef _DEBUG
void RSCardRooms::AssertValid() const
{
	CRecordset::AssertValid();
}

void RSCardRooms::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
