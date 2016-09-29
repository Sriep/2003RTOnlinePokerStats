// Prizes.cpp: implementation of the CPrizes class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include <stdlib.h> 
#include <fstream.h>

#include "ICMMod.h"
#include "Prizes.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPrizes::CPrizes()
{

}

CPrizes::~CPrizes()
{

}

void CPrizes::DUMP()  const
{
#if defined(_DEBUG)
	TRACE("\nPrzes are: \n");
	CString strTemp;
	int num = 1;
	for ( ConstIterPrizes iIter = begin() ; iIter != end() ; iIter++ )
	{
		strTemp.Format("Prize %d = %d", num, *iIter);
		TRACE(strTemp);
		TRACE("\n");
		num++;
	}
#endif
}

void CPrizes::DumpToFile(const CString &fileName) const
{
	ofstream fOutFile(fileName, ios::app , filebuf::sh_read || filebuf::sh_write);

	CString strOutString("\nPrize amonuts\n");
	fOutFile.write(strOutString.GetBuffer(1), strOutString.GetLength());
	int num = 1;
	for ( ConstIterPrizes iIter = begin() ; iIter != end() ; iIter++ )
	{
		strOutString.Format("Prize %d = %d\n", num, *iIter);
		fOutFile.write(strOutString.GetBuffer(1), strOutString.GetLength());
	}

	fOutFile.flush();
	fOutFile.close();
}
