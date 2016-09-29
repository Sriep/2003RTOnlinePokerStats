// NumericEdit.cpp : implementation file
//

#include "stdafx.h"
#include "PokerResultViewer.h"
#include "NumericEdit.h"
#pragma warning( disable : 4244 )  

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNumericEdit

CNumericEdit::CNumericEdit()
{
}

CNumericEdit::~CNumericEdit()
{
}


BEGIN_MESSAGE_MAP(CNumericEdit, CEdit)
	//{{AFX_MSG_MAP(CNumericEdit)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNumericEdit message handlers

long CNumericEdit::GetMoneyValue()
{
	CString strValue;
	GetWindowText(strValue);
	double dValue = atof(strValue);
	dValue *= 100;
	return (long) dValue;
}

void CNumericEdit::SetMoneyValue(long lNewValue)
{
	//int iRemainder = dNewValue % 100;
	//int iDecPlaces = 1;//iRemainder == 0 ? 0 : 2;	
	double dValue = lNewValue;
	dValue = dValue / 100;

	CString strValue;
	if (lNewValue %100 > 0)
	{
		strValue.Format("%.2f", dValue);
	}
	else
	{
		strValue.Format("%.0f", dValue);
	}

	if (strValue.IsEmpty())
		SetWindowText("0");
	else
		SetWindowText(strValue);
}

long CNumericEdit::GetValue()
{
	CString strValue;
	GetWindowText(strValue);
	double dValue = atof(strValue);
	return (long) dValue;
}

