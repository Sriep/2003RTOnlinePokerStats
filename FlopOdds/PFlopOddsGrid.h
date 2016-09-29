// PFlopOddsGrid.h: interface for the PFlopOddsGrid class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PFLOPODDSGRID_H__B8C00EC9_3F9E_4788_9AE3_CF267401840F__INCLUDED_)
#define AFX_PFLOPODDSGRID_H__B8C00EC9_3F9E_4788_9AE3_CF267401840F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "gridctrl.h"

#include "PFlopPercentages.h"

class PFlopOddsGrid : public CGridCtrl  
{
	DECLARE_DYNCREATE(PFlopOddsGrid)
public:
	virtual void clear();
	virtual void populate(PFlopPercentages* pFlopPercentages);
	PFlopOddsGrid();
	virtual ~PFlopOddsGrid();

};

#endif // !defined(AFX_PFLOPODDSGRID_H__B8C00EC9_3F9E_4788_9AE3_CF267401840F__INCLUDED_)
