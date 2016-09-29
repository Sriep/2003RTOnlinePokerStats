// OpeningCalculator1.cpp: implementation of the COpeningCalculator class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "OpeningCalculator.h"
#include "PHandSpread.h"
#include "OpeningCalculator1.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

COpeningCalculator::COpeningCalculator()
{

}

COpeningCalculator::~COpeningCalculator()
{

}

PHandSpread* COpeningCalculator::GetSpread(const CString& strNick)
{
	PHandSpread* pcNewSpread = new PHandSpread();

	return NULL;	
}; 
