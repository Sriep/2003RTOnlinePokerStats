// SharedMemory.cpp: implementation of the CSharedMemory class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SharedMemory.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////


CSharedMemory::CSharedMemory(const CSharedMemory& cSM)
:	m_strName(cSM.m_strName),
	m_lpvMem(cSM.m_lpvMem),
	m_bOwnerOfMemory(cSM.m_bOwnerOfMemory),
	m_hMapObject(cSM.m_hMapObject),
	m_pchNext(cSM.m_pchNext)
{

}

CSharedMemory::~CSharedMemory()
{
}

CSharedMemory::CSharedMemory()
:	m_strName(""),
	m_lpvMem(NULL),
	m_bOwnerOfMemory(FALSE),
	m_pchNext(NULL)
{

}

void CSharedMemory::OpenSharedMemory(const CString& strName, DWORD flProtect, long lSize)
{ 
	BOOL fInit;
	ASSERT(!m_bOwnerOfMemory);
	m_strName = strName;
	m_lSize = lSize;

	// Create a named file mapping object.
	m_hMapObject = CreateFileMapping( 
		INVALID_HANDLE_VALUE, // use paging file
		NULL,                 // default security attributes
		PAGE_READWRITE,       // read/write access
		0,                    // size: high 32-bits
		m_lSize,            // size: low 32-bits
		m_strName);     // name of map object

	if (m_hMapObject == NULL) 
		return; 					  

	// The first process to attach initializes memory.

	fInit = (GetLastError() != ERROR_ALREADY_EXISTS);
	m_bOwnerOfMemory = (GetLastError() != ERROR_ALREADY_EXISTS);

	// Get a pointer to the file-mapped shared memory.

	m_lpvMem = (LPSTR) MapViewOfFile( 
		m_hMapObject,     // object to map view of
		flProtect, // read/write access
		0,              // high offset:  map from
		0,           // low offset:   beginning
		0);             // default: map entire file

	if (m_lpvMem == NULL) 
		return; 

	// Initialize memory if this is the first process.

	if (fInit)
	{
		memset(m_lpvMem, '\0', m_lSize); 
	}
	m_pchNext = (LPSTR) m_lpvMem;
} 



void CSharedMemory::CloseSharedMemory()
{
	UnmapViewOfFile(m_lpvMem);
	if (m_bOwnerOfMemory)
	{
		CloseHandle(m_hMapObject);
	}
}











