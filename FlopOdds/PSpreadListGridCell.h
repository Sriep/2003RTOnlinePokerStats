// PSpreadListGridCell.h: interface for the PSpreadListGridCell class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PSPREADLISTGRIDCELL_H__26320A29_82F9_4DB2_97D3_4BECDADAE7D5__INCLUDED_)
#define AFX_PSPREADLISTGRIDCELL_H__26320A29_82F9_4DB2_97D3_4BECDADAE7D5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "GridCtrl.h"
#include "HandsMap.h"	// Added by ClassView

class PSpreadListGridCell : public CGridCell   
{
	DECLARE_DYNCREATE(PSpreadListGridCell)
public:
	virtual void setHandsList(PHandsList* plistHands, PHandsList* plistDlgHands);
	PSpreadListGridCell();
	virtual ~PSpreadListGridCell();

protected:
	virtual void OnClick( CPoint PointCellRelative);
	virtual void OnDblClick(CPoint PointCellRelative);
private:
	PHandsList* m_plistCellHands;
	PHandsList* m_plistDlgHands;
};

#endif // !defined(AFX_PSPREADLISTGRIDCELL_H__26320A29_82F9_4DB2_97D3_4BECDADAE7D5__INCLUDED_)
