// EditRecentResults.cpp : implementation file
//

#include "stdafx.h"
#include "PokerResultViewer.h"
#include "EditRecentResults.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEditRecentResults dialog


CEditRecentResults::CEditRecentResults(CWnd* pParent /*=NULL*/)
	: CDialog(CEditRecentResults::IDD, pParent)
{
	//{{AFX_DATA_INIT(CEditRecentResults)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CEditRecentResults::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEditRecentResults)
	DDX_GridControl(pDX, IDC_RESULTS_GRID,m_gridEditResults);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CEditRecentResults, CDialog)
	//{{AFX_MSG_MAP(CEditRecentResults)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEditRecentResults message handlers
