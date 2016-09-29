// StoredProcGridCell.h: interface for the CStoredProcGridCell class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_STOREDPROCGRIDCELL_H__54236A48_B754_4A55_B425_46E6D6A0EB82__INCLUDED_)
#define AFX_STOREDPROCGRIDCELL_H__54236A48_B754_4A55_B425_46E6D6A0EB82__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "GridCell.h"
#include "ColumnData.h"

class CStoredProcGridCell : public CGridCell  
{
public:
	DECLARE_DYNCREATE(CStoredProcGridCell)

	CStoredProcGridCell(const CColumnData& cDataInfo);
	CStoredProcGridCell();
	virtual ~CStoredProcGridCell();
	void Initilise(const CColumnData& cDataInfo);
	virtual void Refresh(int iRow);
	virtual LPCTSTR GetTipText() const; 
private:
	void SetColour(int iValue);
	CColumnData m_cDataInfo;
};

#endif // !defined(AFX_STOREDPROCGRIDCELL_H__54236A48_B754_4A55_B425_46E6D6A0EB82__INCLUDED_)
