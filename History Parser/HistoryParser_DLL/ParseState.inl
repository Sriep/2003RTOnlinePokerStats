// ParseState.inl: implementation of the CParseState class.
//
//////////////////////////////////////////////////////////////////////
#if !defined(AFX_PARSESTATE_INL____INCLUDED_)
#define AFX_PARSESTATE_INL____INCLUDED_

#include "PSNone.h"
#include "ParsingException.h"
  
inline CString CParseState::GetNextWord(CString& strUnreadLine)
{
	strUnreadLine.TrimLeft(' '); 
	int iIndexNextSpace = strUnreadLine.Find(' ');
	if (iIndexNextSpace == -1)
	{
		iIndexNextSpace = strUnreadLine.GetLength();
	}


	CString strNextWord = strUnreadLine.Left(iIndexNextSpace);
	if (!strNextWord.IsEmpty())
	{
		strUnreadLine = strUnreadLine.Right(strUnreadLine.GetLength() - strNextWord.GetLength());
		return strNextWord;
	}
	else
	{
		throw(new CParsingException(IDS_NEXT_WORD_NOTFOUND, this, new CPSNone(m_cParseFile)));
	}
}  

inline long CParseState::GetNextNumber(CString& strUnreadLine)
{
	strUnreadLine.TrimLeft(' ');
	
	CString strNextNumberWithCommas = strUnreadLine.SpanIncluding(NUMBERS);
	if (!strNextNumberWithCommas.IsEmpty())
	{
		strUnreadLine = strUnreadLine.Right(strUnreadLine.GetLength() - strNextNumberWithCommas.GetLength());
		CString strNextNumber ="";
		for (int iPos = 0 ; iPos < strNextNumberWithCommas.GetLength() ; iPos++ )
		{
			if (strNextNumberWithCommas[iPos] != ',')
			{
				strNextNumber += strNextNumberWithCommas[iPos];	
			}
		}
		return atol(strNextNumber);
	}
	else
	{
		throw(new CParsingException(IDS_NEXT_NUMBER_NOTFOUND, strUnreadLine, this, new CPSNone(m_cParseFile)));
	}
}
  
inline void CParseState::ReadText(const CString& strText, CString& strUnreadLine)
{
	strUnreadLine.TrimLeft(' ');   

	CString strNextWord = strUnreadLine.Left(strText.GetLength());
	if (strNextWord == strText)
	{
		strUnreadLine = strUnreadLine.Right(strUnreadLine.GetLength() - strText.GetLength());
		TRACE1("Read %s\n", strText);
	}
	else
	{
		throw(new CParsingException(IDS_TEXT_NOT_FOUND, strText, this, new CPSNone(m_cParseFile)));
	}
}				   

inline void CParseState::ReverseReadText(const CString &strText, CString& strUnreadLine) const
{
	strUnreadLine.TrimRight(' ');   

	CString strNextWord = strUnreadLine.Right(strText.GetLength());
	if (strNextWord == strText)
	{
		strUnreadLine = strUnreadLine.Left(strUnreadLine.GetLength() - strText.GetLength());
		TRACE1("Read %s\n", strText);
	}
	else
	{
		throw(new CParsingException(IDS_TEXT_NOT_FOUND));
	}
}

inline CString CParseState::ReverseGetNextWord(CString& strUnreadLine)
{ 
	strUnreadLine.TrimRight(' ');   

	int iIndexNextSpace = strUnreadLine.ReverseFind(' ');
	if (iIndexNextSpace == -1)
	{
		iIndexNextSpace = strUnreadLine.GetLength();
	}


	CString strNextWord = strUnreadLine.Right(strUnreadLine.GetLength() - iIndexNextSpace - 1);
	if (!strNextWord.IsEmpty())
	{
		strUnreadLine = strUnreadLine.Left(strUnreadLine.GetLength() - strNextWord.GetLength());
		return strNextWord;
	}
	else
	{
		throw(new CParsingException(IDS_NEXT_WORD_NOTFOUND, this, new CPSNone(m_cParseFile)));
	}
}

inline int CParseState::ReverseGetNextNumber(CString& strUnreadLine)
{
	strUnreadLine.TrimRight(' ');   

	CString strNextNumber = ReverseSpanIncluding(strUnreadLine, NUMBERS);
	if (!strNextNumber.IsEmpty())
	{
		strUnreadLine = strUnreadLine.Left(strUnreadLine.GetLength() - strNextNumber.GetLength() );
		int iIndexComma = strNextNumber.Find(",");
		if (iIndexComma != -1)
		{
			strNextNumber = strNextNumber.Left(iIndexComma) 
				+ strNextNumber.Right(strNextNumber.GetLength() -  iIndexComma - 1);
		}
		return atoi(strNextNumber);
	}
	else
	{
		throw(new CParsingException(IDS_NEXT_NUMBER_NOTFOUND, strNextNumber, this, new CPSNone(m_cParseFile)));
	}
}  

inline CString CParseState::ReverseSpanIncluding(const CString& strTheString, const CString& strToLookFor)
{
	int iIndex = strTheString.GetLength() -  1;

	for ( ; -1 != strToLookFor.Find(strTheString.GetAt(iIndex)) ; iIndex-- )
	{
	}

	return strTheString.Right(strTheString.GetLength() - iIndex - 1);
}


inline bool CParseState::IsNextWord(const CString &strToLookFor, CString strSource) const
{
	strSource.TrimLeft(' '); 
	
	return strToLookFor == strSource.Left(strToLookFor.GetLength());
}

inline bool CParseState::ReadIfNextWord(const CString& strToLookFor, CString& strUnreadLine) const
{
	strUnreadLine.TrimLeft(' '); 
	
	if ( strToLookFor == strUnreadLine.Left(strToLookFor.GetLength()) )
	{
		strUnreadLine =	strUnreadLine.Right(strUnreadLine.GetLength() - strToLookFor.GetLength());
		return true;
	}
	else
	{
		return false;
	}
}

inline bool CParseState::ReverseReadIfNextWord(const CString& strToLookFor, CString& strSource) const
{
	if (IsLastWord(strToLookFor, strSource))
	{
		ReverseReadText(strToLookFor, strSource);
		return true;
	}
	else
	{
		return false;
	}

}

inline bool CParseState::IsLastWord(const CString &strToLookFor, CString strSource) const
{
	strSource.TrimRight(' '); 
	
	return strToLookFor == strSource.Right(strToLookFor.GetLength());
}

inline bool CParseState::FindText(const CString& strToFind, CString&  strUnreadLine) const
{
	int iIndex = strUnreadLine.Find(strToFind);
	if ( -1 == iIndex)
	{
		return false;
	}
	else
	{
		strUnreadLine = strUnreadLine.Right(strUnreadLine.GetLength() - iIndex - strToFind.GetLength());
		return true;
	}
}

inline PCard CParseState::ReadCard(CString& strUnreadLine)
{
	strUnreadLine.TrimLeft(' '); 

	unsigned char chRank = strUnreadLine.GetAt(0);
	unsigned char chSuit = strUnreadLine.GetAt(1);
	if ('1' == chRank)
	{
		ASSERT('0' == chSuit);
		chSuit = strUnreadLine.GetAt(2);
		strUnreadLine = strUnreadLine.Right(strUnreadLine.GetLength() - 3);
	}
	else
	{
		strUnreadLine = strUnreadLine.Right(strUnreadLine.GetLength() - 2);
	}
	return PCard(chRank, chSuit);
}

inline PCard CParseState::ReverseReadCard(CString& strUnreadLine)
{
	strUnreadLine.TrimRight(' '); 

	char chSuit = strUnreadLine.GetAt(strUnreadLine.GetLength() - 1);
	char chRank = strUnreadLine.GetAt(strUnreadLine.GetLength() - 2);
	strUnreadLine = strUnreadLine.Left(strUnreadLine.GetLength() - 2);
	return PCard(chRank, chSuit);
}

inline PPlayerAction CParseState::ReverseReadAction(CString& strUnreadLine)
{
	strUnreadLine.TrimRight(' '); 

	CString strAction = ReverseSpanIncluding(strUnreadLine, LETTERS);
	strUnreadLine = strUnreadLine.Left(strUnreadLine.GetLength() - strAction.GetLength() );

	return PPlayerAction(strAction);
}


inline bool CParseState::IsNumber(char ichar) 
{
	return '0' <= ichar  	&& ichar <= '9'; 
}

inline StringListIterator CParseState::Find(const CString& strNick)
{
	StringListIterator itterNicks = sm_listNicks.begin();
	while (itterNicks != sm_listNicks.end())
	{
		if (strNick == *itterNicks)
			return itterNicks;
		itterNicks++;
	}
	return itterNicks;
}

inline CString CParseState::ReadLongNick(CString& strUnreadLine)
{
	strUnreadLine.TrimLeft(' '); 
	if (strUnreadLine.IsEmpty())
	{
		throw( new CParsingException("Empty string when expecting nick"));
	}

	StringListIterator itterBestMatchSoFar;
	bool bFound = false;
	for ( StringListIterator iIter = sm_listNicks.begin() ; iIter != sm_listNicks.end() ; iIter++ )
	{
		if (!bFound || (*iIter).GetLength() > (*itterBestMatchSoFar).GetLength())
		{
			//TRACE(*iIter);
			if ( (*iIter) == strUnreadLine.Left((*iIter).GetLength()) )
			{
				itterBestMatchSoFar = iIter;
				bFound = true;
			}
		}
	}

	if (bFound)
	{
		strUnreadLine = strUnreadLine.Right( strUnreadLine.GetLength() - (*itterBestMatchSoFar).GetLength() );
		return *itterBestMatchSoFar;
	}
	else
	{
		return CString("");
	}
}	

inline CString CParseState::ReadNick(CString& strUnreadLine)
{	
//#if defined(_DEBUG)
//	CString strStartLine = strUnreadLine;
//	CString strNick = GetNextWord(strUnreadLine);
//	if (strNick.IsEmpty())
//	{
//		throw( new CParsingException("Empty string when expecting nick"));
//	}
//	ASSERT(strNick == ReadLongNick(strStartLine));
//	return strNick;
//#else 
	return GetNextWord(strUnreadLine);
//#endif
}

inline bool CParseState::StarsIgnoreLine(const CString& strInLine)
{							   	  			
	if (-1 != strInLine.Find("joins the table at seat #"))
	{
		return true;
	}

	return IsLastWord(" out", strInLine)
		|| IsLastWord("returned", strInLine)
		|| IsLastWord("connected", strInLine)
		|| IsLastWord("disconnected", strInLine)
		|| IsLastWord("failing to post", strInLine)
		|| IsLastWord("the button", strInLine)
		|| IsLastWord("table", strInLine)
		|| IsLastWord("capped", strInLine);

}

inline bool CParseState::PartyIgnoreLine(const CString& strInLine)
{							   	  			
	return IsLastWord(" out.", strInLine);

}

inline bool CParseState::ParadiseIgnoreLine(const CString& strInLine)
{							   	  			
	if(IsNextWord("Dealt to ", strInLine) && IsLastWord(']', strInLine))
	{
		return true;
	}

	return IsLastWord("out", strInLine)
		|| IsLastWord("out", strInLine);

}


inline bool CParseState::IsNickInNickList(const CString &strNick)
{
	for ( ConstStringListIterator iIter = sm_listNicks.begin() ; iIter != sm_listNicks.end() ; iIter++ )
	{
		if ( (*iIter) == strNick )
		{
			return true;
		}
	}
	return false;
} 

inline int CParseState::GetMounthAsInt(const CString& strMounth) 
{
	if (strMounth == "Jan")
	{
		return 1;
	}
	else if (strMounth == "Feb")
	{
		return 2;
	}
	else if (strMounth == "Mar")
	{
		return 3;
	}
	else if (strMounth == "Apr")
	{
		return 4;
	}
	else if (strMounth == "May")
	{
		return 5;
	}
	else if (strMounth == "Jun")
	{
		return 6;
	}
	else if (strMounth == "Jul")
	{
		return 7;
	}
	else if (strMounth == "Aug")
	{
		return 8;
	}
	else if (strMounth == "Sep")
	{
		return 9;
	}
	else if (strMounth == "Oct")
	{
		return 10;
	}
	else if (strMounth == "Nov")
	{
		return 11;
	}
	else if (strMounth == "Dec")
	{
		return 12;
	}
	ASSERT(FALSE);
	return 1;
}

 
#endif //AFX_PARSESTATE_INL____INCLUDED_