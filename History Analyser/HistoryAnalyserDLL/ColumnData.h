// ColumnData.h: interface for the CColumnData class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_COLUMNDATA_H__2F1F43EB_4052_4A9A_AC0C_BC5DBD858522__INCLUDED_)
#define AFX_COLUMNDATA_H__2F1F43EB_4052_4A9A_AC0C_BC5DBD858522__INCLUDED_

#include <afxdb.h>
#include "RSColumData.h"
#include "ColumnData.h"
#include "ellData.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

enum ColumnType
{
	TYPE_SINGLE_VALUE = 0,
	TYPE_PERCENTAGE = 1,
	TYPE_PERCENTAGE_DOUBLE_SUM_DENOMINATOR = 2,
	TYPE_PERCENTAGE_TRIPLE_SUM_DENOMINATOR = 3,
	NUM_COLUMN_TYPES
};

enum Axis
{
	AXIS_NONE = 0,
	AXIS_TIGHT_LOOSE,
	AXIS_PASSIVE_AGGRESIVE,
	NUM_OF_AXIS
};

#define NO_VALUE -1


class CColumnData  
{
public:
	CColumnData();
	CColumnData(const CRSColumData& cData);
	virtual ~CColumnData();
	
	void Populate(const CRSColumData& cData);
	CColumnData& operator=(const CColumnData& cData);

	int	GetDataColumId() const;
	int	GetGridNumber() const;
	int	GetColumNumber() const;
	ColumnType GetType() const;
	CString	GetHeader() const;
	CString	GetTooltip() const;
	CString	GetHelp() const;
	CString	GetSP_Count_Numerator() const;
	CString	GetSP_Count_Denonator() const;
	CString	GetSP_Count_Denonator2() const;
	CString	GetSP_Count_Denonator3() const;
	CString	GetSP_Numerator_List() const;
	CString	GetSP_Denominator_List() const;
	int	GetDont_show() const;
	int	GetItalic() const;
	int	GetNormal() const;
	int	GetBold() const;
	int	GetUnderline() const;
	int	GetAvearageValue() const;
	int	GetVariance() const;
	int GetAxis() const;
	LOGFONT* CColumnData::SetFont(int iNumber, LOGFONT* pLogFont) const;
	CellData GetColumnData(CString strNick, int iPokerSite);
	int GetWeight() const;

private:

	int	m_Data_Colum_Id;
	int	m_Grid_Number;
	int	m_Colum_Number;
	ColumnType m_eType;
	CString	m_strHeader;
	CString	m_strTooltip;
	CString	m_strHelp;
	CString	m_strSP_Count_Numerator;
	CString	m_strSP_Count_Denonator;
	CString	m_strSP_Count_Denonator2;
	CString	m_strSP_Count_Denonator3;
	CString	m_strSP_Numerator_List;
	CString	m_strSP_Denominator_List;
	int	m_Dont_show;
	int	m_Italic;
	int	m_Normal;
	int	m_Bold;
	int	m_Underline;
	int	m_Avearage_Value;
	int	m_Variance;
	int m_iWeight;
	int m_Axis;

	CString m_strDisplayedTooltip;
	int m_iNumerator;
	int m_iDenomenator;
};

#endif // !defined(AFX_COLUMNDATA_H__2F1F43EB_4052_4A9A_AC0C_BC5DBD858522__INCLUDED_)
