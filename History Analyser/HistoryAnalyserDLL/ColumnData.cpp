// ColumnData.cpp: implementation of the CColumnData class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ColumnData.h"
#include "SPRSCountHands.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CColumnData::CColumnData()
: 	m_iNumerator(0),
	m_iDenomenator(0),
	m_iWeight(0)
{
}

CColumnData::~CColumnData()
{

}

CColumnData::CColumnData(const CRSColumData& cData)
{
	Populate(cData);
}

void CColumnData::Populate(const CRSColumData& cData)
{
	m_Data_Colum_Id = cData.m_Data_Colum_Id;
	m_Grid_Number = cData.m_Grid_Number;
	m_Colum_Number = cData.m_Colum_Number;
	ASSERT(cData.m_Type < (int) NUM_COLUMN_TYPES);
	m_eType = (ColumnType)cData.m_Type;
	m_strHeader = cData.m_Header;
	m_strTooltip = cData.m_Tooltip;
	m_strDisplayedTooltip = m_strTooltip;
	m_strHelp = cData.m_Help;
	m_strSP_Count_Numerator = cData.m_SP_Count_Numerator;
	m_strSP_Count_Denonator = cData.m_SP_Count_Denonator;
	m_strSP_Numerator_List = cData.m_SP_Numerator_List;
	m_strSP_Denominator_List = cData.m_SP_Denominator_List;
	m_Dont_show = cData.m_Dont_show;
	m_Italic = cData.m_Italic;
	m_Normal = cData.m_Normal;
	m_Bold = cData.m_Bold;
	m_Underline = cData.m_Underline;
	m_Avearage_Value = cData.m_Avearage_Value;
	m_Variance = cData.m_Variance;
	m_iWeight = 0;
	m_Axis = cData.m_Axis;
	m_strSP_Count_Denonator2 = cData.m_SP_Count_Denonator2;
	m_strSP_Count_Denonator3 = cData.m_SP_Count_Denonator3;
	m_iNumerator = 0;
	m_iDenomenator = 0;
}

CColumnData& CColumnData::operator=(const CColumnData& cData)
{
	m_Data_Colum_Id = cData.m_Data_Colum_Id;
	m_Grid_Number = cData.m_Grid_Number;
	m_Colum_Number = cData.m_Colum_Number;
	m_eType = cData.m_eType;
	m_strHeader = cData.m_strHeader;
	m_strTooltip = cData.m_strTooltip;
	m_strDisplayedTooltip = cData.m_strDisplayedTooltip;
	m_strHelp = cData.m_strHelp;
	m_strSP_Count_Numerator = cData.m_strSP_Count_Numerator;
	m_strSP_Count_Denonator = cData.m_strSP_Count_Denonator;
	m_strSP_Count_Denonator2 = cData.m_strSP_Count_Denonator2;
	m_strSP_Count_Denonator3 = cData.m_strSP_Count_Denonator3;
	m_strSP_Numerator_List = cData.m_strSP_Numerator_List;
	m_strSP_Denominator_List = cData.m_strSP_Denominator_List;
	m_Dont_show = cData.m_Dont_show;
	m_Italic = cData.m_Italic;
	m_Normal = cData.m_Normal;
	m_Bold = cData.m_Bold;
	m_Underline = cData.m_Underline;
	m_Avearage_Value = cData.m_Avearage_Value;
	m_Variance = cData.m_Variance;
	m_iWeight = cData.m_iWeight;
	m_Axis = cData.m_Axis;
	m_iNumerator = cData.m_iNumerator;
	m_iDenomenator = cData.m_iDenomenator;
	return *this;
}

int	CColumnData::GetDataColumId() const
{ return m_Data_Colum_Id; }

int	CColumnData::GetGridNumber() const
{ return m_Grid_Number; }

int	CColumnData::GetColumNumber() const
{ return m_Colum_Number; }

CString	CColumnData::GetHeader() const
{ return m_strHeader; }

CString	CColumnData::GetTooltip() const
{ 
	return m_strDisplayedTooltip;;
}

CString	CColumnData::GetHelp() const
{ return m_strHelp; }

CString	CColumnData::GetSP_Count_Numerator() const
{ return m_strSP_Count_Numerator; }

CString	CColumnData::GetSP_Count_Denonator() const
{ 
	return m_strSP_Count_Denonator; 
}

CString	CColumnData::GetSP_Count_Denonator2() const
{ 
	return m_strSP_Count_Denonator2; 
}

CString	CColumnData::GetSP_Count_Denonator3() const
{ 
	return m_strSP_Count_Denonator3; 
}

CString	CColumnData::GetSP_Numerator_List() const
{ 
	return m_strSP_Numerator_List; 
}

CString	CColumnData::GetSP_Denominator_List() const			
{ 
	return m_strSP_Denominator_List; 
}

int	CColumnData::GetDont_show() const
{ 
	return m_Dont_show; 
}

int	CColumnData::GetItalic() const
{ 
	return m_Italic; 
}

int	CColumnData::GetNormal() const
{ 
	return m_Normal;
}

int	CColumnData::GetBold() const
{ 
	return m_Bold; 
}

int CColumnData::GetAxis() const
{
	return m_Axis;
}

LOGFONT* CColumnData::SetFont(int iNumber, LOGFONT* pLogFont) const
{
	ASSERT(m_Italic <=  m_Normal && m_Normal <= m_Bold);

	if (iNumber < m_Italic)
	{
		pLogFont->lfWeight = (FW_NORMAL * iNumber ) / m_Normal;
		pLogFont->lfItalic = true;
		pLogFont->lfUnderline = false;
	}
	else if (iNumber < m_Normal)
	{
		pLogFont->lfWeight = (FW_NORMAL * iNumber ) / m_Normal;
		pLogFont->lfItalic = false;
		pLogFont->lfUnderline = false;
	}
	else if (iNumber < m_Bold)
	{
		pLogFont->lfWeight = (FW_BOLD * iNumber ) / m_Bold;
		pLogFont->lfItalic = false;
		pLogFont->lfUnderline = false;
	}
	else if (iNumber >= m_Bold)
	{
		pLogFont->lfWeight = FW_BOLD;
		pLogFont->lfItalic = false;
		pLogFont->lfUnderline = true;
	}
	return pLogFont;
}


int	CColumnData::GetUnderline() const
{ return m_Underline; }

int	CColumnData::GetAvearageValue() const
{ return m_Avearage_Value; }

int	CColumnData::GetVariance() const
{ return m_Variance; }

ColumnType CColumnData::GetType() const
{
	return m_eType;
}

int CColumnData::GetWeight() const
{
	return m_iWeight;
}
CellData CColumnData::GetColumnData(CString strNick, int iPokerSite)
{
	m_iNumerator = SPRSCountHands::GetValue(GetSP_Count_Numerator(), strNick, iPokerSite);
	CellData cData;
	CString strToolTipTip;
	switch (m_eType)
	{
	case TYPE_SINGLE_VALUE:
		m_iWeight = m_iNumerator;
		strToolTipTip.Format(": %d", m_iNumerator);
		m_strDisplayedTooltip = m_strTooltip + strToolTipTip;
		return CellData(m_iNumerator,m_iNumerator);
	case TYPE_PERCENTAGE:
		{
			m_iDenomenator = SPRSCountHands::GetValue(GetSP_Count_Denonator(), strNick, iPokerSite);
			strToolTipTip.Format(" %d/%d",  m_iNumerator, m_iDenomenator);   
			m_strDisplayedTooltip = m_strTooltip + strToolTipTip;
			if (m_iDenomenator > 0)
			{
				m_iWeight = m_iDenomenator;
				return CellData((m_iNumerator * 100) / m_iDenomenator, m_iDenomenator);
			}
			else
			{
				m_iWeight = 0;
				return CellData(NO_VALUE, NO_VALUE);
			}
		}
	case TYPE_PERCENTAGE_DOUBLE_SUM_DENOMINATOR:
		{
			//int iDenomenator1 = GetValue(GetSP_Count_Denonator(), strNick, iPokerSite);
			int iDenomenator2 = SPRSCountHands::GetValue(GetSP_Count_Denonator2(), strNick, iPokerSite);
			m_iDenomenator = m_iNumerator + iDenomenator2;
			strToolTipTip.Format(" %d/%d",  m_iNumerator, m_iDenomenator);   
			m_strDisplayedTooltip = m_strTooltip + strToolTipTip;
			if (m_iDenomenator > 0)
			{
				m_iWeight = m_iDenomenator;
				return CellData((m_iNumerator * 100) / m_iDenomenator, m_iDenomenator);
			}
			else
			{
				m_iWeight = 0;
				return CellData(NO_VALUE, NO_VALUE);
			}
		}
	case TYPE_PERCENTAGE_TRIPLE_SUM_DENOMINATOR:
		{
			//int iDenomenator1 = GetValue(GetSP_Count_Denonator(), strNick, iPokerSite);
			int iDenomenator2 = SPRSCountHands::GetValue(GetSP_Count_Denonator2(), strNick, iPokerSite);
			int iDenomenator3 = SPRSCountHands::GetValue(GetSP_Count_Denonator3(), strNick, iPokerSite);
			m_iDenomenator = m_iNumerator + iDenomenator2 + iDenomenator3;
			strToolTipTip.Format(" %d/%d",  m_iNumerator, m_iDenomenator);   
			m_strDisplayedTooltip = m_strTooltip + strToolTipTip;
			if (m_iDenomenator > 0)
			{
				m_iWeight = m_iDenomenator;
				return CellData((m_iNumerator * 100) / m_iDenomenator, m_iDenomenator);
			}
			else
			{
				m_iWeight = 0;
				return CellData(NO_VALUE, NO_VALUE);
			}
		}
	default:
		ASSERT(FALSE);
		m_iWeight = 0;
		return CellData(NO_VALUE, NO_VALUE);;
	}
}
