// SharedMemory.h: interface for the CSharedMemory class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SHAREDMEMORY_H__B0B4426B_B4A0_45D5_B4E3_92F3771D6EAF__INCLUDED_)
#define AFX_SHAREDMEMORY_H__B0B4426B_B4A0_45D5_B4E3_92F3771D6EAF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define SHMEMSIZE (16*16*16*16-1) 

class CSharedMemory  
{
public:
	CSharedMemory();
	CSharedMemory(const CSharedMemory& cSM);
	virtual ~CSharedMemory();

	void OpenSharedMemory(const CString& strName, DWORD flProtect = FILE_MAP_ALL_ACCESS, long lSize = SHMEMSIZE);
	void CloseSharedMemory();
	void Set(const CString& strBuf) ;
	CString Get();
	bool CanFind(CString& strText);
	void Clear();
	void DUMP();
	CString GetName() const;
	void Append(const CString& strNewText);
	bool IsOwner() const;
	void Seek(long lPos);
	bool Eof();
	CString ReadLine();
	static Append(const CString& strNewText, const CString& strMemoryName);
	LPCSTR GerPtrNext() const;
	void ResetPosition();
	bool IsValid();
	long GetPositon();

private:
	CString m_strName;
	LPSTR m_lpvMem; // pointer to shared memory
	HANDLE m_hMapObject;
	bool m_bOwnerOfMemory;
	LPSTR m_pchNext;
	long m_lSize;
};

inline CSharedMemory::Append(const CString& strNewText, const CString& strMemoryName)
{
	CSharedMemory cSM;
	cSM.OpenSharedMemory(strMemoryName);
	cSM.Append(strNewText);
	cSM.CloseSharedMemory();
}

inline LPCSTR CSharedMemory::GerPtrNext() const
{
	return m_pchNext;
}

inline void CSharedMemory::ResetPosition()
{
	m_pchNext = m_lpvMem;
}

inline bool CSharedMemory::IsValid()
{
	return m_lpvMem != NULL;
}
	 
inline void CSharedMemory::Set(const CString& strBuf)
{ 
    if (!m_lpvMem)
		return;

	LPTSTR lpszTmp = (LPTSTR) m_lpvMem; 
	for (int iPos = 0 ; iPos < strBuf.GetLength() ; iPos++ )
	{
        *lpszTmp++ = strBuf[iPos]; 
	}
    *lpszTmp = '\0'; 
}

inline void CSharedMemory::Append(const CString& strNewText)
{
    if (!m_lpvMem)
		return;

	int iStart = strlen((const char*)m_lpvMem);
	if (m_lSize < iStart + strNewText.GetLength())
	{
		if (m_lSize < strNewText.GetLength())
		{
			return;
		}
		else
		{
			Clear();
			iStart = 0;
		}
	}

	LPTSTR lpszTmp = (LPTSTR) m_lpvMem; 
	for (int iPos = 0 ; iPos < strNewText.GetLength() ; iPos++ )
	{
        lpszTmp[iStart + iPos] = strNewText[iPos]; 
	}
    lpszTmp [iStart + strNewText.GetLength()]= '\0'; 
}
 
// GetSharedMem gets the contents of shared memory. 
inline CString CSharedMemory::Get()
{ 
	CString strData = "";
    
	if (m_lpvMem)
	{
		for (LPTSTR lpszTmp = (LPTSTR) m_lpvMem ; *lpszTmp != '\0' ; lpszTmp++ )
		{
			strData += *lpszTmp; 
		}
	}
	return strData;
}

inline bool CSharedMemory::CanFind(CString& strText)
{
    if (!m_lpvMem)
		return FALSE;
	return NULL != strstr((const char*) m_lpvMem, strText.GetBuffer(1));	
}

inline void CSharedMemory::Clear()
{
	memset(m_lpvMem, '\0', 4000);
	FlushViewOfFile(m_lpvMem, m_lSize);
}

inline void CSharedMemory::DUMP()
{
	TRACE1("Dump of shared memory\n-> %s\n", Get());
}

inline CString CSharedMemory::GetName() const
{
	return m_strName;
}

inline bool CSharedMemory::IsOwner() const
{
	return m_bOwnerOfMemory;
}

inline long CSharedMemory::GetPositon()
{
	return (m_pchNext - m_lpvMem) / sizeof(char);
}

inline void CSharedMemory::Seek(long lPos)
{
	m_pchNext  = (LPSTR) m_lpvMem + sizeof(char) * lPos;
}

inline bool CSharedMemory::Eof()
{
	return *m_pchNext == 0;
}

inline CString CSharedMemory::ReadLine()
{
	while (*m_pchNext == 10 || *m_pchNext == 13)
	{
		m_pchNext++;
	}
	
	CString strNewLine;
	while ( *m_pchNext != 10 && *m_pchNext != 13  && *m_pchNext != 0)
	{
		strNewLine += *m_pchNext++;		
	}

	return strNewLine;
}


#endif // !defined(AFX_SHAREDMEMORY_H__B0B4426B_B4A0_45D5_B4E3_92F3771D6EAF__INCLUDED_)
