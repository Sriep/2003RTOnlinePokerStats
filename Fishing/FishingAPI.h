#if !defined(_HOOKPROCEDURE_)
#define _HOOKPROCEDURE_

#define SHARED_DATA_FILE "b:\\SHARED_DATA_FILE.txt"

LRESULT CALLBACK PokerSpyHook(int nCode, WPARAM wParam, LPARAM lParam);

STDAPI CastPokerSpyHook(HWND hwndSourceWindow, int iSite, HWND& hHandle);

STDAPI UnCastPokerSpyHook(HWND hwnd);

#endif //_HOOKPROCEDURE_ 
