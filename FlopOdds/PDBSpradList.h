// PDBSpradList.h: interface for the PDBSpradList class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PDBSPRADLIST_H__34AE05DD_11A1_46BB_9AE4_5B0249C0998E__INCLUDED_)
#define AFX_PDBSPRADLIST_H__34AE05DD_11A1_46BB_9AE4_5B0249C0998E__INCLUDED_

#include "PHandsListList.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "gridctrl.h"


class PDBSpradListGrid : public CGridCtrl  
{
	DECLARE_DYNCREATE(PDBSpradListGrid)
public:
	virtual void setup(PHandsList* m_cHandsList);	 
	virtual void DBRead();
	PDBSpradListGrid();
	virtual ~PDBSpradListGrid();

private:
	virtual void populate();
	PHandsListList m_listHandSpreads;
	PHandsList* m_pDlgHandsList;
};

#endif // !defined(AFX_PDBSPRADLIST_H__34AE05DD_11A1_46BB_9AE4_5B0249C0998E__INCLUDED_)
