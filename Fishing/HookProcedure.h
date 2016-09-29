#if !defined(HOOKPROCEDURE_H__INCLUDED_)
#define HOOKPROCEDURE_H__INCLUDED_

#include "stdafx.h"
#include <fstream.h>
#include "FishingAPI.h"
#include "FishingControl.h"
#include "Fishing.h"
#include "PPokerSite.h"
#include "SharedMemory.h"

#define PARADISE_NEW_TEXT_BLOCK_MARKER "End of Paradise poker text --- End of Paradise poker text"
#define POKER_ROOM_NEW_TEXT_BLOCK_MARKER "@@END_OF_POKER_ROOM_TEXT_BLOCK@@\n"

inline void HOOK_TRACE(CString strTrace)
{
	CString strFileName;
	strFileName.Format("C:\\Poker\\Live\\Trace.txt");
	ofstream fOutFile(strFileName, ios::app , filebuf::sh_read || filebuf::sh_write);
	fOutFile.write(strTrace.GetBuffer(1), strTrace.GetLength());
	fOutFile.flush();
	fOutFile.close();
}

inline void HandlePartyPokerMessage(CWPSTRUCT*  pmsg)
{
	CSharedMemory::Append((LPCSTR) pmsg->lParam, PPokerSite::GetDealerTextName(pmsg->hwnd, PPokerSite::POKER_SITE_PARTY));
#if defined(_DEBUG)
	CString strFileName;
	strFileName.Format("C:\\Poker\\Live\\Party_%X.txt", (long) pmsg->hwnd);
	ofstream fOutFile(strFileName, ios::app , filebuf::sh_read || filebuf::sh_write);
	fOutFile.write((LPCSTR) pmsg->lParam, strlen((LPCSTR) pmsg->lParam));
	fOutFile.flush();
	fOutFile.close();
#endif
}

inline void HandleHighStakesPokerMessage(CWPSTRUCT*  pmsg)
{
	CSharedMemory::Append((LPCSTR) pmsg->lParam, PPokerSite::GetDealerTextName(pmsg->hwnd, PPokerSite::POKER_SITE_HIGH_STAKES));
#if defined(_DEBUG)
	CString strFileName;
	strFileName.Format("C:\\Poker\\Live\\High_Stakes_%X.txt", (long) pmsg->hwnd);
	ofstream fOutFile(strFileName, ios::app , filebuf::sh_read || filebuf::sh_write);
	fOutFile.write((LPCSTR) pmsg->lParam, strlen((LPCSTR) pmsg->lParam));
	fOutFile.flush();
	fOutFile.close();
#endif
}

inline void HandleCryptologicMessage(CWPSTRUCT*  pmsg)
{
	CSharedMemory::Append((LPCSTR) pmsg->lParam, PPokerSite::GetDealerTextName(pmsg->hwnd, PPokerSite::POKER_SITE_CRYPTOLOGIC));
#if defined(_DEBUG)
	CString strFileName;
	strFileName.Format("C:\\Poker\\Live\\Crytpologic_%X.txt", (long) pmsg->hwnd);
	ofstream fOutFile(strFileName, ios::app , filebuf::sh_read || filebuf::sh_write);
	fOutFile.write((LPCSTR) pmsg->lParam, strlen((LPCSTR) pmsg->lParam));
	fOutFile.flush();
	fOutFile.close();
#endif
}

inline void HandleWSEXPokerMessage(CWPSTRUCT*  pmsg)
{
	CSharedMemory::Append((LPCSTR) pmsg->lParam, PPokerSite::GetDealerTextName(pmsg->hwnd, PPokerSite::POKER_SITE_WSEX));
#if defined(_DEBUG)
	CString strFileName;
	strFileName.Format("C:\\Poker\\Live\\WSEX_%X.txt", (long) pmsg->hwnd);
	ofstream fOutFile(strFileName, ios::app , filebuf::sh_read || filebuf::sh_write);
	fOutFile.write((LPCSTR) pmsg->lParam, strlen((LPCSTR) pmsg->lParam));
	fOutFile.flush();
	fOutFile.close();
#endif
}

inline void HandlePokerClubPokerMessage(CWPSTRUCT*  pmsg)
{
	CSharedMemory::Append((LPCSTR) pmsg->lParam, PPokerSite::GetDealerTextName(pmsg->hwnd, PPokerSite::POKER_SITE_POKER_CLUB));
#if defined(_DEBUG)
	CString strFileName;
	strFileName.Format("C:\\Poker\\Live\\PokerClub_%X.txt", (long) pmsg->hwnd);
	ofstream fOutFile(strFileName, ios::app , filebuf::sh_read || filebuf::sh_write);
	fOutFile.write((LPCSTR) pmsg->lParam, strlen((LPCSTR) pmsg->lParam));
	fOutFile.flush();
	fOutFile.close();
#endif
}

inline void HandleParadisePokerMessage(CWPSTRUCT*  pmsg) 
{
	CString strOutString;
	if (pmsg->message == LB_ADDSTRING)
	{
		strOutString.Format("%s\n", (LPCSTR) pmsg->lParam);
	}
	else if	(pmsg->message == LB_GETCOUNT)
	{
		strOutString = "End of Paradise poker text --- End of Paradise poker text\n";

	}
	CSharedMemory::Append(strOutString, PPokerSite::GetDealerTextName(pmsg->hwnd, PPokerSite::POKER_SITE_PARADISE));
#if defined(_DEBUG)
	CString strFileName;
	strFileName.Format("C:\\Poker\\Live\\Paradise_%X.txt", (long) pmsg->hwnd);
	ofstream fOutFile(strFileName, ios::app , filebuf::sh_read || filebuf::sh_write);
	fOutFile.write(strOutString.GetBuffer(1), strOutString.GetLength());
	fOutFile.flush();
	fOutFile.close();
#endif 	 
}

inline void HandleTruePokerMessage(CWPSTRUCT*  pmsg) 
{

}

inline void HandlePokerRoomPokerMessage(CWPSTRUCT*  pmsg) 
{
	LPCSTR strText = *((LPCSTR*) pmsg->wParam);
	CSharedMemory::Append(strText, PPokerSite::GetDealerTextName(pmsg->hwnd, PPokerSite::POKER_SITE_POKER_ROOM));
	//CSharedMemory::Append((LPCSTR) pmsg->wParam, PPokerSite::GetDealerTextName(pmsg->hwnd, PPokerSite::POKER_SITE_POKER_ROOM));
	CSharedMemory::Append(CString("\n@@END_OF_POKER_ROOM_TEXT_BLOCK@@\n"), PPokerSite::GetDealerTextName(pmsg->hwnd, PPokerSite::POKER_SITE_POKER_ROOM));
#if defined(_DEBUG)
	CString strFileName;
	strFileName.Format("C:\\Poker\\Live\\PokerRoom_%X.txt", (long) pmsg->hwnd);
	ofstream fOutFile(strFileName, ios::app , filebuf::sh_read || filebuf::sh_write);
	fOutFile.write((LPCSTR) pmsg->lParam, strlen((LPCSTR) pmsg->lParam));
	fOutFile.write("\n@@END_OF_POKER_ROOM_TEXT_BLOCK@@\n", strlen("@@END_OF_POKER_ROOM_TEXT_BLOCK@@\n"));
	fOutFile.flush();
	fOutFile.close();
#endif
}

inline void HandleUltimateBetrMessage(CWPSTRUCT*  pmsg) 
{
	CString strOutString;
	strOutString.Format("%s\n", (LPCSTR) pmsg->lParam);
	CSharedMemory::Append(strOutString, PPokerSite::GetDealerTextName(pmsg->hwnd, PPokerSite::POKER_SITE_ULTIMATE_BET));

#if defined(_DEBUG)
	CString strFileName;
	strFileName.Format("C:\\Poker\\Live\\Ultimate_Bet_%X.txt", (long) pmsg->hwnd);
	ofstream fOutFile(strFileName, ios::app , filebuf::sh_read || filebuf::sh_write);
	fOutFile.write(strOutString.GetBuffer(1), strOutString.GetLength());
	fOutFile.flush();
	fOutFile.close();
#endif
}

inline void HandleLabrokePokerMessage(CWPSTRUCT*  pmsg)
{
	LPCSTR strText = *((LPCSTR*) pmsg->lParam);
	CSharedMemory::Append(strText, PPokerSite::GetDealerTextName(pmsg->hwnd, PPokerSite::POKER_SITE_LABROKES));

#if defined(_DEBUG)
	CString strFileName;
	strFileName.Format("C:\\Poker\\Live\\%s_%X.txt", 
		PPokerSite::GetDealerTextName(pmsg->hwnd, PPokerSite::POKER_SITE_LABROKES), 
		(long) pmsg->hwnd);
	ofstream fOutFile(strFileName, ios::app , filebuf::sh_read || filebuf::sh_write);
	fOutFile.write(strText, strlen(strText));
	fOutFile.flush();
	fOutFile.close();
#endif
}

inline void HandleRoyalVegasPokerMessage(CWPSTRUCT*  pmsg)
{
	LPCSTR strText = *((LPCSTR*) pmsg->lParam);
	CSharedMemory::Append(strText, PPokerSite::GetDealerTextName(pmsg->hwnd, PPokerSite::POKER_SITE_ROYAL_VEGAS));

#if defined(_DEBUG)
	CString strFileName;
	strFileName.Format("C:\\Poker\\Live\\%s_%X.txt", 
		PPokerSite::GetDealerTextName(pmsg->hwnd, PPokerSite::POKER_SITE_ROYAL_VEGAS), 
		(long) pmsg->hwnd);
	ofstream fOutFile(strFileName, ios::app , filebuf::sh_read || filebuf::sh_write);
	fOutFile.write(strText, strlen(strText));
	fOutFile.flush();
	fOutFile.close();
#endif
}

#endif //HOOKPROCEDURE_H__INCLUDED_

