// DlgProxy.cpp : implementation file
//

#include "stdafx.h"
#include "OpeningCalculator.h"
#include "DlgProxy.h"
#include "OpeningCalculatorDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COpeningCalculatorDlgAutoProxy

IMPLEMENT_DYNCREATE(COpeningCalculatorDlgAutoProxy, CCmdTarget)

COpeningCalculatorDlgAutoProxy::COpeningCalculatorDlgAutoProxy()
{
	EnableAutomation();
	
	// To keep the application running as long as an automation 
	//	object is active, the constructor calls AfxOleLockApp.
	AfxOleLockApp();

	// Get access to the dialog through the application's
	//  main window pointer.  Set the proxy's internal pointer
	//  to point to the dialog, and set the dialog's back pointer to
	//  this proxy.
	ASSERT (AfxGetApp()->m_pMainWnd != NULL);
	ASSERT_VALID (AfxGetApp()->m_pMainWnd);
	ASSERT_KINDOF(COpeningCalculatorDlg, AfxGetApp()->m_pMainWnd);
	m_pDialog = (COpeningCalculatorDlg*) AfxGetApp()->m_pMainWnd;
	m_pDialog->m_pAutoProxy = this;
}

COpeningCalculatorDlgAutoProxy::~COpeningCalculatorDlgAutoProxy()
{
	// To terminate the application when all objects created with
	// 	with automation, the destructor calls AfxOleUnlockApp.
	//  Among other things, this will destroy the main dialog
	if (m_pDialog != NULL)
		m_pDialog->m_pAutoProxy = NULL;
	AfxOleUnlockApp();
}

void COpeningCalculatorDlgAutoProxy::OnFinalRelease()
{
	// When the last reference for an automation object is released
	// OnFinalRelease is called.  The base class will automatically
	// deletes the object.  Add additional cleanup required for your
	// object before calling the base class.

	CCmdTarget::OnFinalRelease();
}

BEGIN_MESSAGE_MAP(COpeningCalculatorDlgAutoProxy, CCmdTarget)
	//{{AFX_MSG_MAP(COpeningCalculatorDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(COpeningCalculatorDlgAutoProxy, CCmdTarget)
	//{{AFX_DISPATCH_MAP(COpeningCalculatorDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

// Note: we add support for IID_IOpeningCalculator to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .ODL file.

// {C2131AA2-BEBF-4670-A88F-614D522D75ED}
static const IID IID_IOpeningCalculator =
{ 0xc2131aa2, 0xbebf, 0x4670, { 0xa8, 0x8f, 0x61, 0x4d, 0x52, 0x2d, 0x75, 0xed } };

BEGIN_INTERFACE_MAP(COpeningCalculatorDlgAutoProxy, CCmdTarget)
	INTERFACE_PART(COpeningCalculatorDlgAutoProxy, IID_IOpeningCalculator, Dispatch)
END_INTERFACE_MAP()

// The IMPLEMENT_OLECREATE2 macro is defined in StdAfx.h of this project
// {24999D88-D6BF-40CB-8592-134B45B2EA54}
IMPLEMENT_OLECREATE2(COpeningCalculatorDlgAutoProxy, "OpeningCalculator.Application", 0x24999d88, 0xd6bf, 0x40cb, 0x85, 0x92, 0x13, 0x4b, 0x45, 0xb2, 0xea, 0x54)

/////////////////////////////////////////////////////////////////////////////
// COpeningCalculatorDlgAutoProxy message handlers
