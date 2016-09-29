// PSPartySummary.cpp: implementation of the CPSPartySummary class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PSPartySummary.h"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPSPartySummary::CPSPartySummary(CParseFile* pPF)
: CParseState(pPF)
{

}

CPSPartySummary::~CPSPartySummary()
{

}

CParseState* CPSPartySummary::Parse(const CString &strInLine)
{
	return this;
}

