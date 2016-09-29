// ParsingException.h: interface for the CParsingException class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PARSINGEXCEPTION_H__AA6AC9E6_718B_4DA4_80A8_756551355A86__INCLUDED_)
#define AFX_PARSINGEXCEPTION_H__AA6AC9E6_718B_4DA4_80A8_756551355A86__INCLUDED_
 

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CParseState;

class CParsingException  
{
public:
	CParsingException(int iStringId, const CString& strText, CParseState* pCurrentState, CParseState* pNextState);
	CParseState* GetNextParseState();
	CParsingException(int iStringId, CParseState* pCurrentState, CParseState* pNextState);
	CParsingException(const CString& strText);
	CParsingException(int iMessageId);
	CParsingException();
	virtual ~CParsingException();
	CParseState* GetCurrentParseState() const;
	bool IsError(int iError) const;
	bool IsSkipLine() const;
	bool IsSkipHand() const;
	bool IsSkipFile() const;
	bool IsExitProgram() const;
	bool IsCloseGame() const;
private:
	void LogException();

	CParseState* m_pNextParseState;
	CParseState* m_pCurrentParseState;
	CString m_strMessage;
	int m_iMessageId;
};

#endif // !defined(AFX_PARSINGEXCEPTION_H__AA6AC9E6_718B_4DA4_80A8_756551355A86__INCLUDED_)
