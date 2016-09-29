// PPlayerAction.cpp: implementation of the PPlayerAction class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PPlayerAction.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

PPlayerAction::PPlayerAction()
{

}

PPlayerAction::~PPlayerAction()
{

}

PPlayerAction::PPlayerAction(const CString& strAction)
{
	m_eAction = GetActionFromString(strAction);
}

PPlayerAction::PPlayerAction(Action eAction)
:	m_eAction(eAction)
{

} 

void PPlayerAction::DUMP() const
{
	TRACE(GetStringFromAction(m_eAction));
}




