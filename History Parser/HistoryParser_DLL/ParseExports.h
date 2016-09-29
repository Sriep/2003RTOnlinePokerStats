#if !defined(PARSEEXPORTS__INCLUDED_)
#define PARSEEXPORTS__INCLUDED_

#include "ParseFile.h"
									   
STDAPI ParseHandHistory(const CString& strFileName);

STDAPI ParseLogFile(HWND hwnd, int iSite, long* lFilePosition, const CString& strTableName);

#endif //PARSEEXPORTS__INCLUDED_
