// StackSizeEVTAble.h: interface for the CStackSizeEVTAble class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_STACKSIZEEVTABLE_H__DD4551E5_59FE_4E8B_9EB4_5FB263D3CA3A__INCLUDED_)
#define AFX_STACKSIZEEVTABLE_H__DD4551E5_59FE_4E8B_9EB4_5FB263D3CA3A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#pragma warning( disable : 4786 )
#include <vector>
#include "ICMModDlg.h"

using std::vector;
typedef std::vector<int> STD_IntVector; 
typedef std::vector<PAS_FLOAT> STD_FloatVector; 

typedef std::vector<int>::iterator IterInts;
typedef std::vector<int>::const_iterator ConstIterInts;

typedef std::vector<PAS_FLOAT>::iterator IterFloat;
typedef std::vector<PAS_FLOAT>::const_iterator ConstIterFloat;

class CStackSizeEVTAble  
{
public:
	void DUMP() const;
	void DumpToFile(const CString& fileName);
	void AddStackEVPair(int stack, float ev);
	CStackSizeEVTAble();
	virtual ~CStackSizeEVTAble();

private:
	STD_IntVector m_vectorStackSizes;
	STD_FloatVector m_vectorStackEVs;

};

#endif // !defined(AFX_STACKSIZEEVTABLE_H__DD4551E5_59FE_4E8B_9EB4_5FB263D3CA3A__INCLUDED_)
