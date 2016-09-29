// ellData.cpp: implementation of the CellData class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ellData.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CellData::CellData()
{

}

CellData::~CellData()
{

}


CellData::CellData(int iValue, int iWeight)
: m_iValue(iValue),
  m_iWeight(iWeight)
{
}

