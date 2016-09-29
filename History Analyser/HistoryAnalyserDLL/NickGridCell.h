// NickGridCell.h: interface for the CNickGridCell class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_NICKGRIDCELL_H__89F1B0AF_AC9C_400E_9582_A5C9DA1D04D6__INCLUDED_)
#define AFX_NICKGRIDCELL_H__89F1B0AF_AC9C_400E_9582_A5C9DA1D04D6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "GridCell.h"

class CNickGridCell : public CGridCell  
{
public:
	DECLARE_DYNCREATE(CNickGridCell)
	CNickGridCell();
	virtual ~CNickGridCell();
    virtual void EndEdit();
};

#endif // !defined(AFX_NICKGRIDCELL_H__89F1B0AF_AC9C_400E_9582_A5C9DA1D04D6__INCLUDED_)
