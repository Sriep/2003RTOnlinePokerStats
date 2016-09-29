// StackSizes.cpp: implementation of the CStackSizes class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include <stdlib.h> 
#include <fstream.h>
#include "ICMMod.h"
#include "StackSizes.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CStackSizes::CStackSizes()
{
	SetTotalChips();
}

CStackSizes::~CStackSizes()
{

}


void CStackSizes::DUMP() const
{
#if defined(_DEBUG)
	TRACE("\nStacks are: \n");
	CString strTemp;
	int num = 1;
	for ( ConstIterStackSizes iIter = begin() ; iIter != end() ; iIter++ )
	{
		strTemp.Format("Player %d = %d", num, *iIter);
		TRACE(strTemp);
		TRACE("\n");
		num++;
	}
	strTemp.Format("Total Chips are %d\n", m_totalChips);
	TRACE(strTemp);
#endif
}


void CStackSizes::DumpToFile(const CString &fileName) const
{
	ofstream fOutFile(fileName, ios::app , filebuf::sh_read || filebuf::sh_write);

	CString strOutString("\nStack Sizes\n");
	fOutFile.write(strOutString.GetBuffer(1), strOutString.GetLength());
	int num = 1;
	for ( ConstIterStackSizes iIter = begin() ; iIter != end() ; iIter++ )
	{
		strOutString.Format("Player %d = %d\n", num, *iIter);
		fOutFile.write(strOutString.GetBuffer(1), strOutString.GetLength());
	}

	fOutFile.flush();
	fOutFile.close();
}

IterStackSizes CStackSizes::GetLargestInTail()
{
	ASSERT(begin() != end());

	IterStackSizes iterLargestSoFar = (++begin());
	for ( IterStackSizes iter = iterLargestSoFar ; iter != end() ; iter++ )
	{
		if (*iter > *iterLargestSoFar)
			iterLargestSoFar =iter;
	}
	return iterLargestSoFar;
}

IterStackSizes CStackSizes::GetSmallistInTail()
{
	ASSERT(begin() != end());

	IterStackSizes iterSmallistSoFar = (++begin());
	for ( IterStackSizes iter = iterSmallistSoFar ; iter != end() ; iter++ )
	{
		if (*iter < *iterSmallistSoFar)
			iterSmallistSoFar = iter;
	}
	ASSERT(0 != *iterSmallistSoFar);
	return iterSmallistSoFar;
}
							