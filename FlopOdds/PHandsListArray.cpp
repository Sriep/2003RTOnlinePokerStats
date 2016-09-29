// PHandsListArray.cpp: implementation of the PHandsListArray class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PHandsListArray.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

PHandsListArray::PHandsListArray()
: m_iNumberOfLists(0)
{
}

PHandsListArray::~PHandsListArray()
{

}

void PHandsListArray::Set(PHandsList* array)
{
    for (int i=0 ; i < 9 ; i++)
	{
		m_HandLists[i] = array[i];
	}
}

