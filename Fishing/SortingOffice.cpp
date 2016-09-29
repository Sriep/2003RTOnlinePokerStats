// SortingOffice.cpp : implementation file
//

#include "stdafx.h"
#include "Fishing.h"
#include "SortingOffice.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSortingOffice
//HookWindowPairList CSortingOffice::sm_listSubscibers;

CSortingOffice::CSortingOffice()
{
	//m_nTimer = SetTimer(1, 60000, 0);
}

CSortingOffice::~CSortingOffice()
{
}


BEGIN_MESSAGE_MAP(CSortingOffice, CWnd)
	//{{AFX_MSG_MAP(CSortingOffice)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CSortingOffice message handlers

void CSortingOffice::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	SortMail();

	CWnd::OnTimer(nIDEvent);
}

void CSortingOffice::SortMail()
{
	//for ( HookWindowPairListIterator iter = sm_listSubscibers.begin() ; iter != sm_listSubscibers.end() ; iter++ )
	{
	//	CString GetDealerText(
		
	}
}


//void CSortingOffice::AddNewSubscriber(HookWindowPair sNewSubscriber)
//{
//	sm_listSubscibers.push_front(sNewSubscriber);
//}
