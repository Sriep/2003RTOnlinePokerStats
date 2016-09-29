// Prizes.h: interface for the CPrizes class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PRIZES_H__39F25492_A037_464A_A409_2CB6878F99B7__INCLUDED_)
#define AFX_PRIZES_H__39F25492_A037_464A_A409_2CB6878F99B7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#pragma warning( disable : 4786 )
#include <vector>

using std::vector;
typedef std::vector<int>::iterator IterPrizes;
typedef std::vector<int>::const_iterator ConstIterPrizes;

class CPrizes : public std::vector <int>  
{
public:
	void DumpToFile(const CString &fileName) const;
	void DUMP() const;
	CPrizes();
	virtual ~CPrizes();

};

#endif // !defined(AFX_PRIZES_H__39F25492_A037_464A_A409_2CB6878F99B7__INCLUDED_)
