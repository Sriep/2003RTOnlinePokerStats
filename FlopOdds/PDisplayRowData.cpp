// PDisplayRowData.cpp: implementation of the PDisplayRowData class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "flopodds.h"
#include "PDisplayRowData.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

PDisplayRowData::PDisplayRowData()
{

}

PDisplayRowData::~PDisplayRowData()
{

}

void PDisplayRowData::setDescription(CString strDiscription)
{
	m_strDiscription = strDiscription;
}

void PDisplayRowData::setHandsList(PHandsList listHands)
{
	m_HandsList =  listHands;
}

PDisplayRowData::PDisplayRowData(CString strDiscription, PHandsList listHands)
:	m_strDiscription(strDiscription),
	m_HandsList(listHands)
{

}

CString PDisplayRowData::getDescription()
{
	return 	m_strDiscription;
}

PHandsList PDisplayRowData::getHandsList()
{
	return 	m_HandsList;
}
