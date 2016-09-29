// StackSizeEVTAble.cpp: implementation of the CStackSizeEVTAble class.
//
//////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include <stdlib.h> 
#include <fstream.h>

#include "ICMMod.h"
#include "StackSizeEVTAble.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CStackSizeEVTAble::CStackSizeEVTAble()
{

}

CStackSizeEVTAble::~CStackSizeEVTAble()
{

}

void CStackSizeEVTAble::AddStackEVPair(int stack, float ev)
{
	m_vectorStackSizes.push_back(stack);
	m_vectorStackEVs.push_back(ev);
					 
}

void CStackSizeEVTAble::DumpToFile(const CString& fileName)
{
	ofstream fOutFile(fileName, ios::app , filebuf::sh_read || filebuf::sh_write);

	IterInts stacksIter;
	IterFloat evsIter;
	stacksIter =  m_vectorStackSizes.begin();
	evsIter =  m_vectorStackEVs.begin();

	CString strOutString("\nFirst Stack Size vs Ev list\n");
	fOutFile.write(strOutString.GetBuffer(1), strOutString.GetLength());

	while (stacksIter != m_vectorStackSizes.end())
	{
		ASSERT(evsIter != m_vectorStackEVs.end());

		strOutString.Format("%d\t%f\n", (*stacksIter), (*evsIter));
		fOutFile.write(strOutString.GetBuffer(1), strOutString.GetLength());

		stacksIter++;
		evsIter++;
	}

	fOutFile.flush();
	fOutFile.close();
}


void CStackSizeEVTAble::DUMP() const
{
#if defined(_DEBUG)
	TRACE("\nStack size with Ev are: \n");
	CString strTemp;

	ConstIterInts stacksIter;
	ConstIterFloat evsIter;
	stacksIter =  m_vectorStackSizes.begin();
	evsIter =  m_vectorStackEVs.begin();
	while (stacksIter != m_vectorStackSizes.end())
	{
		ASSERT(evsIter != m_vectorStackEVs.end());

		strTemp.Format("%d has Ev %.4f", *stacksIter, *evsIter);
		TRACE(strTemp);
		TRACE("\n");

		stacksIter++;
		evsIter++;
	}
#endif
}
