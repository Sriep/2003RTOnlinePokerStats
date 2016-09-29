// PGameBoard.cpp: implementation of the PGameBoard class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "flopodds.h"
#include "PGameBoard.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

PGameBoard::PGameBoard()
{

}

PGameBoard::~PGameBoard()
{

}


void PGameBoard::DUMP() const
{
	m_cBoard1.DUMP();
	m_cBoard2.DUMP();
	m_cBoard3.DUMP();
	m_cBoard4.DUMP();
	m_cBoard5.DUMP();

}

