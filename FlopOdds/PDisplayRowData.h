// PDisplayRowData.h: interface for the PDisplayRowData class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PDISPLAYROWDATA_H__7AB887F9_4702_4030_BC36_07AF50A54198__INCLUDED_)
#define AFX_PDISPLAYROWDATA_H__7AB887F9_4702_4030_BC36_07AF50A54198__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "PPokerObject.h"
#include "HandsMap.h"	// Added by ClassView

class PDisplayRowData : public PPokerObject  
{
public:
	virtual PHandsList getHandsList();
	virtual CString getDescription();
	PDisplayRowData(CString, PHandsList);
	virtual void setHandsList(PHandsList listHands);
	virtual void setDescription(CString strDiscription);
	PDisplayRowData();
	virtual ~PDisplayRowData();

private:
	CString m_strDiscription;
	PHandsList m_HandsList;
};

#endif // !defined(AFX_PDISPLAYROWDATA_H__7AB887F9_4702_4030_BC36_07AF50A54198__INCLUDED_)
