// ParsingException.cpp: implementation of the CParsingException class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ParsingException.h"
#include <fstream.h>
#include "PSNone.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CParsingException::CParsingException()
:   m_iMessageId(0)
{

}

CParsingException::~CParsingException()
{
	//delete m_pCurrentParseState;
}

CParsingException::CParsingException(int iStringId, CParseState* pCurrentState, CParseState* pNextState)
:   m_pNextParseState(pNextState),
	m_pCurrentParseState(pCurrentState),
    m_iMessageId(iStringId)
{
	m_strMessage.LoadString(iStringId);
	TRACE1("Parsing Exceptino thrown ** %s **\n", m_strMessage);
	//MessageBox(NULL, m_strMessage, "Parsing Excepton", MB_OK);
	LogException();
}

CParseState* CParsingException::GetNextParseState()
{
	return m_pNextParseState;
}

CParsingException::CParsingException(int iStringId, const CString &strText, CParseState* pCurrentState, CParseState* pNextState)
:   m_pNextParseState(pNextState),
	m_pCurrentParseState(pCurrentState),
    m_iMessageId(iStringId)
{
	m_strMessage.Format(iStringId, strText);
	TRACE1("Parsing Exceptino thrown ** %s **\n", m_strMessage);
	LogException();
}

CParsingException::CParsingException(int iMessageId)
:   m_pNextParseState(NULL),
	m_pCurrentParseState(NULL),
    m_iMessageId(iMessageId)
{
	m_strMessage.Format(m_iMessageId);
	TRACE1("Parsing Exceptino thrown ** %s **\n", m_strMessage);
	LogException();
}

CParsingException::CParsingException(const CString& strText)
:   m_strMessage(strText),
    m_iMessageId(0)
{
	TRACE1("Parsing Exceptino thrown ** %s **\n", m_strMessage);
	m_pCurrentParseState = NULL;//new CPSNone();
	LogException();
}

CParseState* CParsingException::GetCurrentParseState() const
{
	return m_pCurrentParseState;
}		  

bool CParsingException::IsError(int iError) const
{
	return iError == m_iMessageId;	 
}

bool CParsingException::IsSkipLine() const 
{
	return !IsSkipHand() && !IsSkipFile() && !IsExitProgram();
}

bool CParsingException::IsSkipHand() const
{
	return m_iMessageId == IDS_HAND_ALREADY_IN_DB 
			|| m_iMessageId == IDS_VARAINT_NOT_SUPPORTED
			|| m_iMessageId == IDS_PLAY_MONEY
			|| m_iMessageId == IDS_TABLE_NAME_NOT_FOUND
			|| m_iMessageId == IDS_HEADER_ERROR
			|| m_iMessageId == IDS_NOTHING_GAME
			|| m_iMessageId == IDS_NICK_NOT_FOUND
			|| m_iMessageId == IDS_NOT_ENOUGH_PLAYERS
			|| m_iMessageId == IDS_PARADISE_HAND_JUMBLED;
}

bool CParsingException::IsSkipFile() const
{
	return false;
}

bool CParsingException::IsExitProgram() const
{
	return false;
}

bool CParsingException::IsCloseGame() const
{
	return m_iMessageId == IDS_NOT_ENOUGH_PLAYERS
		|| m_iMessageId == IDS_PARADISE_HAND_JUMBLED;
}

void CParsingException::LogException()
{
	CString strText;
	strText.Format("Parsing exception thrown %s\n",m_strMessage);
	ofstream fOutFile(SPY_DEAMON_LOG_FILE, ios::app , filebuf::sh_read || filebuf::sh_write);
	fOutFile.write(strText, strlen(strText));
	fOutFile.flush();
	fOutFile.close();
}





