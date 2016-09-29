// ParseFile.cpp: implementation of the CParseFile class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "HistoryParser_DLL.h"
#include "ParseFile.h"
#include "PSNone.h"
#include "ParsingException.h"
#include <fstream.h>
#include "PartyLogNone.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CParseFile::CParseFile()
{
	 m_pCurrentState = new CPSNone(this);
}

CParseFile::~CParseFile()
{

}

void CParseFile::ParseHandHistory(istream &cInStream)
{
	char pchInputLine  [MAX_LINE_LENGTH]; 
	Setup();
	while (!cInStream.eof())
	{
		cInStream.getline(pchInputLine, MAX_LINE_LENGTH);
		ParseLine(pchInputLine);
	}
	CloseDown();
}

void CParseFile::ParseLine(const CString &strInputLine)
{
	try
	{
		m_pCurrentState = m_pCurrentState->Parse(strInputLine);
	}
	catch (CParsingException* pException)
	{							
		if (pException->IsCloseGame())
		{
			CloseDown();
			delete( m_pCurrentState);
			throw pException;
		}

		if (pException->IsSkipHand())
		{
			CloseDown();
			NewHand();
			if (pException->GetCurrentParseState())
			{
				delete(pException->GetCurrentParseState());
			}
			else
			{
				delete m_pCurrentState;
			}
			m_pCurrentState = GetStartState();
		}
		else
		{
			TRACE("Skip line");
		}
		delete pException;
	}
	catch (CDBException* pDBException)
	{
		pDBException->ReportError(MB_OK, IDS_DBERROR1); 
		ASSERT(FALSE);
		CloseDown();
		NewHand();
		delete m_pCurrentState;
		m_pCurrentState = GetStartState();
	}
	ASSERT(m_pCurrentState != NULL);
}


CParseState* CParseFile::GetStartState()
{
	return new CPSNone(this);
}

void CParseFile::Setup()
{
	m_cInputHand.OpenConnection();
}

void CParseFile::CloseDown()
{
	m_cInputHand.CloseConnection();
}

CInputHand& CParseFile::GetInputHand() 
{
	return m_cInputHand;  
}

StringList& CParseFile::GetListNicks() 
{
	return m_listNicks;

}

StringListIterator& CParseFile::GetItterLastNicks() 
{
	return m_itterLastNicks;

}

int CParseFile::GetSite()
{
	return PPokerSite::POKER_SITE_NONE;
}

CString CParseFile::GetTableName() const
{
	return m_strTableName;
}

bool CParseFile::IsLog()
{
	return false;
}

void CParseFile::SetDataSource()
{
	m_cInputHand.SetDataSource(GetSite());
}












