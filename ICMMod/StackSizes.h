// StackSizes.h: interface for the CStackSizes class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_STACKSIZES_H__44096435_6A19_417B_AF68_BC8C5825BD70__INCLUDED_)
#define AFX_STACKSIZES_H__44096435_6A19_417B_AF68_BC8C5825BD70__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#pragma warning( disable : 4786 )
#include <list>

using std::list;
typedef std::list<int>::iterator IterStackSizes;
typedef std::list<int>::const_iterator ConstIterStackSizes;

class CStackSizes : public std::list <int>  
{
public:
	IterStackSizes GetLargestInTail();
	IterStackSizes GetSmallistInTail();
	void DumpToFile(const CString& fileName) const;
	void DUMP() const;
	inline void SetTotalChips();
	inline int GetTotalChips();
	CStackSizes();
	virtual ~CStackSizes();
private:
	int m_totalChips;

};

int CStackSizes::GetTotalChips() 
{
//	ASSERT(m_totalChips > 0);
	SetTotalChips();
	return m_totalChips;
}

void CStackSizes::SetTotalChips()
{
	m_totalChips = 0;
	for ( IterStackSizes iIter = begin() ; iIter != end() ; iIter++ )
	{
		m_totalChips += *iIter;	
	}
}


#endif // !defined(AFX_STACKSIZES_H__44096435_6A19_417B_AF68_BC8C5825BD70__INCLUDED_)
