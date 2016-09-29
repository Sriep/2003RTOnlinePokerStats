// ellData.h: interface for the CellData class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ELLDATA_H__91055AF7_44FF_42D5_ABEE_C0EB89C846F5__INCLUDED_)
#define AFX_ELLDATA_H__91055AF7_44FF_42D5_ABEE_C0EB89C846F5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CellData  
{
public:
	CellData();
	virtual ~CellData();
	CellData(int iValue, int iWeight);

	int m_iValue;
	int m_iWeight;
};


#endif // !defined(AFX_ELLDATA_H__91055AF7_44FF_42D5_ABEE_C0EB89C846F5__INCLUDED_)
