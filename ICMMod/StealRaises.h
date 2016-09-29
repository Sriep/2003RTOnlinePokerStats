// StealRaises.h: interface for the CStealRaises class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_STEALRAISES_H__4A2EA3FF_1487_4CF0_BB41_0271CD6D658F__INCLUDED_)
#define AFX_STEALRAISES_H__4A2EA3FF_1487_4CF0_BB41_0271CD6D658F__INCLUDED_

#include "StackSizes.h"	// Added by ClassView
#include "Prizes.h"	// Added by ClassView
#include "StackSizeEVTAble.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CStealRaises  
{
public:
	CStealRaises();
	virtual ~CStealRaises();

	void GenerateVrsLargest(CICMModDlg& cViewWindow);
	void GenerateVrsSmallist();
	void GenerateVrsNoOne();

	void SetStack1Min(int stack1Min);
	void SetBlindsAntes(int blindsAntes);
	void SetPrizes(CPrizes prizes);
	void SetStackSizes(CStackSizes);
	void SetStack1Max(int stack1Max);
	void SetStack1Step(int stack1Min);

	int GetStack1Min() const;
	int GetBlindsAntes() const;
	const CPrizes& GetPrizes() const;
	const CStackSizes& GetStackSizes() const;
	int GetStack1Max() const;
	int GetStack1Step() const;
private:
	void WriteVrsNoneToFile(CStackSizeEVTAble& stackSizeEv, CString fileNameconst);
	void WriteVrsLargestToFile(CStackSizeEVTAble&, CStackSizeEVTAble&, CStackSizeEVTAble&, CString fileName);
	void WriteVrsSmallistToFile(CStackSizeEVTAble&, CStackSizeEVTAble&, CStackSizeEVTAble&, CString fileName);

	int m_blindsAntes;
	CPrizes m_prizes;
	CStackSizes m_stackSizes;
	int m_stack1Min;
	int m_stack1Max;
	int m_stack1Step;
};

#endif // !defined(AFX_STEALRAISES_H__4A2EA3FF_1487_4CF0_BB41_0271CD6D658F__INCLUDED_)
