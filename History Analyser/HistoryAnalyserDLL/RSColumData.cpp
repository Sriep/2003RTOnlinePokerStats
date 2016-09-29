// RSColumData.cpp : implementation file
//

#include "stdafx.h"
#include "RSColumData.h"
#include "PPokerSite.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRSColumData

IMPLEMENT_DYNAMIC(CRSColumData, CRecordset)

CRSColumData::CRSColumData(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CRSColumData)
	m_Data_Colum_Id = 0;
	m_Grid_Number = 0;
	m_Colum_Number = 0;
	m_Type = 0;
	m_Header = _T("");
	m_Tooltip = _T("");
	m_Help = _T("");
	m_SP_Count_Numerator = _T("");
	m_SP_Count_Denonator = _T("");
	m_SP_Numerator_List = _T("");
	m_SP_Denominator_List = _T("");
	m_Dont_show = 0;
	m_Italic = 0;
	m_Normal = 0;
	m_Bold = 0;
	m_Underline = 0;
	m_Avearage_Value = 0;
	m_Variance = 0;
	m_Axis = 0;
	m_SP_Count_Denonator2 = _T("");
	m_SP_Count_Denonator3 = _T("");
	m_nFields = 21;
	//}}AFX_FIELD_INIT
	m_nParams = 1;
	m_iGridNumberParam = 0;
	m_nDefaultType = snapshot;
	m_strFilter = "[Grid Number] = ?";
	m_strSort = "[Grid Number], [Colum Number]";
}


CString CRSColumData::GetDefaultConnect()
{
	return _T(LIVE_POKER_DATA_CONNECT_STRING);
}

CString CRSColumData::GetDefaultSQL()
{
	return _T("[dbo].[DataGrid]");
}

void CRSColumData::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CRSColumData)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Int(pFX, _T("[Data Colum Id]"), m_Data_Colum_Id);
	RFX_Byte(pFX, _T("[Grid Number]"), m_Grid_Number);
	RFX_Byte(pFX, _T("[Colum Number]"), m_Colum_Number);
	RFX_Byte(pFX, _T("[Type]"), m_Type);
	RFX_Text(pFX, _T("[Header]"), m_Header);
	RFX_Text(pFX, _T("[Tooltip]"), m_Tooltip);
	RFX_Text(pFX, _T("[Help]"), m_Help);
	RFX_Text(pFX, _T("[SP Count Numerator]"), m_SP_Count_Numerator);
	RFX_Text(pFX, _T("[SP Count Denonator]"), m_SP_Count_Denonator);
	RFX_Text(pFX, _T("[SP Numerator List]"), m_SP_Numerator_List);
	RFX_Text(pFX, _T("[SP Denominator List]"), m_SP_Denominator_List);
	RFX_Int(pFX, _T("[Dont show]"), m_Dont_show);
	RFX_Int(pFX, _T("[Italic]"), m_Italic);
	RFX_Int(pFX, _T("[Normal]"), m_Normal);
	RFX_Int(pFX, _T("[Bold]"), m_Bold);
	RFX_Int(pFX, _T("[Underline]"), m_Underline);
	RFX_Int(pFX, _T("[Avearage Value]"), m_Avearage_Value);
	RFX_Int(pFX, _T("[Variance]"), m_Variance);
	RFX_Byte(pFX, _T("[Axis]"), m_Axis);
	RFX_Text(pFX, _T("[SP Count Denonator2]"), m_SP_Count_Denonator2);
	RFX_Text(pFX, _T("[SP Count Denonator3]"), m_SP_Count_Denonator3);
   	pFX->SetFieldType(CFieldExchange::param); 
	RFX_Byte(pFX, _T("[Grid Number]"), m_iGridNumberParam);
	//}}AFX_FIELD_MAP
}			   

/////////////////////////////////////////////////////////////////////////////
// CRSColumData diagnostics

#ifdef _DEBUG
void CRSColumData::AssertValid() const
{
	CRecordset::AssertValid();
}

void CRSColumData::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
