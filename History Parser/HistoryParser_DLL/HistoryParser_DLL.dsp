# Microsoft Developer Studio Project File - Name="HistoryParser_DLL" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=HistoryParser_DLL - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "HistoryParser_DLL.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "HistoryParser_DLL.mak" CFG="HistoryParser_DLL - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "HistoryParser_DLL - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "HistoryParser_DLL - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""$/History Parser/HistoryParser_DLL", BBBAAAAA"
# PROP Scc_LocalPath "."
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "HistoryParser_DLL - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /D "_USRDLL" /FR /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /dll /machine:I386
# ADD LINK32 ../../Output/Release/PokerObjects.lib /nologo /subsystem:windows /dll /machine:I386 /out:"../../Output/Release/HistoryParser_DLL.dll"

!ELSEIF  "$(CFG)" == "HistoryParser_DLL - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /D "_USRDLL" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 ../../Output/Debug/PokerObjectsd.lib /nologo /subsystem:windows /dll /debug /machine:I386 /out:"../../Output/Debug/HistoryParser_DLLd.dll" /pdbtype:sept

!ENDIF 

# Begin Target

# Name "HistoryParser_DLL - Win32 Release"
# Name "HistoryParser_DLL - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\CRSCurrentPlayers.cpp
# End Source File
# Begin Source File

SOURCE=.\CryptologicLogNone.cpp
# End Source File
# Begin Source File

SOURCE=.\HighStakesLogNone.cpp
# End Source File
# Begin Source File

SOURCE=.\HistoryParser_DLL.cpp
# End Source File
# Begin Source File

SOURCE=.\HistoryParser_DLL.def
# End Source File
# Begin Source File

SOURCE=.\HistoryParser_DLL.rc
# End Source File
# Begin Source File

SOURCE=.\InputHand.cpp
# End Source File
# Begin Source File

SOURCE=.\ParseCryptologicLogFile.cpp
# End Source File
# Begin Source File

SOURCE=.\ParseExports.cpp
# End Source File
# Begin Source File

SOURCE=.\ParseFile.cpp
# End Source File
# Begin Source File

SOURCE=.\ParseHighStakesLogFile.cpp
# End Source File
# Begin Source File

SOURCE=.\ParseLabrokesLogFile.cpp
# End Source File
# Begin Source File

SOURCE=.\ParseLogFile.cpp
# End Source File
# Begin Source File

SOURCE=.\ParsePartyLogFile.cpp
# End Source File
# Begin Source File

SOURCE=.\ParsePokerClubLogFile.cpp
# End Source File
# Begin Source File

SOURCE=.\ParseRoyalVegasLogFile.cpp
# End Source File
# Begin Source File

SOURCE=.\ParserParadiseLogFile.cpp
# End Source File
# Begin Source File

SOURCE=.\ParserPokerRoomLogFile.cpp
# End Source File
# Begin Source File

SOURCE=.\ParseState.cpp
# End Source File
# Begin Source File

SOURCE=.\ParseTruePokeLogFile.cpp
# End Source File
# Begin Source File

SOURCE=.\ParseUltimateBetFile.cpp
# End Source File
# Begin Source File

SOURCE=.\ParseWSEXLogFile.cpp
# End Source File
# Begin Source File

SOURCE=.\ParsingException.cpp
# End Source File
# Begin Source File

SOURCE=.\PartyLogNone.cpp
# End Source File
# Begin Source File

SOURCE=.\PDActionsRecordset.cpp
# End Source File
# Begin Source File

SOURCE=.\PDHandRecordset.cpp
# End Source File
# Begin Source File

SOURCE=.\PDPlayersRecordset.cpp
# End Source File
# Begin Source File

SOURCE=.\PDResultsRecordset.cpp
# End Source File
# Begin Source File

SOURCE=.\PSCryptologicLog.cpp
# End Source File
# Begin Source File

SOURCE=.\PSCryptologicLogAllFold.cpp
# End Source File
# Begin Source File

SOURCE=.\PSCryptologicLogBlind.cpp
# End Source File
# Begin Source File

SOURCE=.\PSCryptologicLogPlayerAction.cpp
# End Source File
# Begin Source File

SOURCE=.\PSCryptologicLogPlayerFirxtAction.cpp
# End Source File
# Begin Source File

SOURCE=.\PSCryptologicLogSummary.cpp
# End Source File
# Begin Source File

SOURCE=.\PSHighStakesLog.cpp
# End Source File
# Begin Source File

SOURCE=.\PSHighStakesLogDealing.cpp
# End Source File
# Begin Source File

SOURCE=.\PSHighStakesLogPlayerAction.cpp
# End Source File
# Begin Source File

SOURCE=.\PSHighStakesLogPlayerFirxtAction.cpp
# End Source File
# Begin Source File

SOURCE=.\PSHighStakesLogSummary.cpp
# End Source File
# Begin Source File

SOURCE=.\PSNone.cpp
# End Source File
# Begin Source File

SOURCE=.\PSParadiseDealing.cpp
# End Source File
# Begin Source File

SOURCE=.\PSParadiseDealToPlayer.cpp
# End Source File
# Begin Source File

SOURCE=.\PSParadiseGetBigBlind.cpp
# End Source File
# Begin Source File

SOURCE=.\PSParadiseGetSmallBlind.cpp
# End Source File
# Begin Source File

SOURCE=.\PSParadiseHeader1.cpp
# End Source File
# Begin Source File

SOURCE=.\PSParadiseHeader2.cpp
# End Source File
# Begin Source File

SOURCE=.\PSParadiseLog.cpp
# End Source File
# Begin Source File

SOURCE=.\PSParadiseLogPlayerAction.cpp
# End Source File
# Begin Source File

SOURCE=.\PSParadiseLogPlayerFirxtAction.cpp
# End Source File
# Begin Source File

SOURCE=.\PSParadiseLogResult.cpp
# End Source File
# Begin Source File

SOURCE=.\PSParadiseLogSmallBlind.cpp
# End Source File
# Begin Source File

SOURCE=.\PSParadisePlayerAction.cpp
# End Source File
# Begin Source File

SOURCE=.\PSParadisePlayerList.cpp
# End Source File
# Begin Source File

SOURCE=.\PSParadiseSumary1.cpp
# End Source File
# Begin Source File

SOURCE=.\PSParadiseSumary2.cpp
# End Source File
# Begin Source File

SOURCE=.\PSParadiseSumaryGereral.cpp
# End Source File
# Begin Source File

SOURCE=.\PSPartyDealing.cpp
# End Source File
# Begin Source File

SOURCE=.\PSPartyDealToPlayer.cpp
# End Source File
# Begin Source File

SOURCE=.\PSPartyGetBigBlind.cpp
# End Source File
# Begin Source File

SOURCE=.\PSPartyGetSmallBlind.cpp
# End Source File
# Begin Source File

SOURCE=.\PSPartyHeader1.cpp
# End Source File
# Begin Source File

SOURCE=.\PSPartyHeader2.cpp
# End Source File
# Begin Source File

SOURCE=.\PSPartyHeader3.cpp
# End Source File
# Begin Source File

SOURCE=.\PSPartyLog.cpp
# End Source File
# Begin Source File

SOURCE=.\PSPartyLogBigBlind.cpp
# End Source File
# Begin Source File

SOURCE=.\PSPartyLogDealing.cpp
# End Source File
# Begin Source File

SOURCE=.\PSPartyLogPlayerAction.cpp
# End Source File
# Begin Source File

SOURCE=.\PSPartyLogPlayerFirxtAction.cpp
# End Source File
# Begin Source File

SOURCE=.\PSPartyLogSmallBlind.cpp
# End Source File
# Begin Source File

SOURCE=.\PSPartyPlayerAction.cpp
# End Source File
# Begin Source File

SOURCE=.\PSPartyPlayerList.cpp
# End Source File
# Begin Source File

SOURCE=.\PSPartySumary1.cpp
# End Source File
# Begin Source File

SOURCE=.\PSPartySumary2.cpp
# End Source File
# Begin Source File

SOURCE=.\PSPartySumaryGereral.cpp
# End Source File
# Begin Source File

SOURCE=.\PSPartySummary.cpp
# End Source File
# Begin Source File

SOURCE=.\PSPokerRoomLog.cpp
# End Source File
# Begin Source File

SOURCE=.\PSPokerRoomLogDealing.cpp
# End Source File
# Begin Source File

SOURCE=.\PSPokerRoomLogPlayerFirxtAction.cpp
# End Source File
# Begin Source File

SOURCE=.\PSPokerRoomLogResult.cpp
# End Source File
# Begin Source File

SOURCE=.\PSPokerRoomLogSmallBlind.cpp
# End Source File
# Begin Source File

SOURCE=.\PSPokerRoomPlayerAction.cpp
# End Source File
# Begin Source File

SOURCE=.\PSRoyalVegasLog.cpp
# End Source File
# Begin Source File

SOURCE=.\PSRoyalVegasLogDealing.cpp
# End Source File
# Begin Source File

SOURCE=.\PSRoyalVegasLogPlayerAction.cpp
# End Source File
# Begin Source File

SOURCE=.\PSRoyalVegasLogPlayerFirxtAction.cpp
# End Source File
# Begin Source File

SOURCE=.\PSRoyalVegasLogSummary.cpp
# End Source File
# Begin Source File

SOURCE=.\PSStarsDealing.cpp
# End Source File
# Begin Source File

SOURCE=.\PSStarsDealToPlayer.cpp
# End Source File
# Begin Source File

SOURCE=.\PSStarsGetBigBlind.cpp
# End Source File
# Begin Source File

SOURCE=.\PSStarsGetSmallBlind.cpp
# End Source File
# Begin Source File

SOURCE=.\PSStarsHeader1.cpp
# End Source File
# Begin Source File

SOURCE=.\PSStarsHeader2.cpp
# End Source File
# Begin Source File

SOURCE=.\PSStarsPlayerAction.cpp
# End Source File
# Begin Source File

SOURCE=.\PSStarsPlayerList.cpp
# End Source File
# Begin Source File

SOURCE=.\PSStarsShowDown.cpp
# End Source File
# Begin Source File

SOURCE=.\PSStarsSumary1.cpp
# End Source File
# Begin Source File

SOURCE=.\PSStarsSumary2.cpp
# End Source File
# Begin Source File

SOURCE=.\PSStarsSumaryGereral.cpp
# End Source File
# Begin Source File

SOURCE=.\PSTrueLog.cpp
# End Source File
# Begin Source File

SOURCE=.\PSTrueLogBigBlind.cpp
# End Source File
# Begin Source File

SOURCE=.\PSTrueLogDealing.cpp
# End Source File
# Begin Source File

SOURCE=.\PSTrueLogHeader.cpp
# End Source File
# Begin Source File

SOURCE=.\PSTrueLogPlayerAction.cpp
# End Source File
# Begin Source File

SOURCE=.\PSTrueLogPlayerCards.cpp
# End Source File
# Begin Source File

SOURCE=.\PSTrueLogPlayerFirxtAction.cpp
# End Source File
# Begin Source File

SOURCE=.\PSTrueLogSmallBlind.cpp
# End Source File
# Begin Source File

SOURCE=.\PSTrueLogSumary.cpp
# End Source File
# Begin Source File

SOURCE=.\PSUltimateBetLog.cpp
# End Source File
# Begin Source File

SOURCE=.\PSUltimateBetLogBigBlind.cpp
# End Source File
# Begin Source File

SOURCE=.\PSUltimateBetLogDealing.cpp
# End Source File
# Begin Source File

SOURCE=.\PSUltimateBetLogPlayerAction.cpp
# End Source File
# Begin Source File

SOURCE=.\PSUltimateBetLogPlayerFirxtAction.cpp
# End Source File
# Begin Source File

SOURCE=.\PSUltimateBetLogShowdown.cpp
# End Source File
# Begin Source File

SOURCE=.\PSUltimateBetLogSmallBlind.cpp
# End Source File
# Begin Source File

SOURCE=.\PSWSEXLog.cpp
# End Source File
# Begin Source File

SOURCE=.\PSWSEXLogBigBlind.cpp
# End Source File
# Begin Source File

SOURCE=.\PSWSEXLogDealing.cpp
# End Source File
# Begin Source File

SOURCE=.\PSWSEXLogPlayerAction.cpp
# End Source File
# Begin Source File

SOURCE=.\PSWSEXLogPlayerFirxtAction.cpp
# End Source File
# Begin Source File

SOURCE=.\PSWSEXLogSmallBlind.cpp
# End Source File
# Begin Source File

SOURCE=.\PSWSEXLogSummary.cpp
# End Source File
# Begin Source File

SOURCE=.\RoyalVegasLogNone.cpp
# End Source File
# Begin Source File

SOURCE=.\SPDeleteHand.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\TrueLogNone.cpp
# End Source File
# Begin Source File

SOURCE=.\UltimateBetLogNone.cpp
# End Source File
# Begin Source File

SOURCE=.\WSEXLogNone.cpp
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\HistoryParser_DLL.rc2
# End Source File
# Begin Source File

SOURCE=.\ParseUltimateBetLogFile.h
# End Source File
# Begin Source File

SOURCE=.\RSCurrentTables.h
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\CRSCurrentPlayers.h
# End Source File
# Begin Source File

SOURCE=.\CryptologicLogNone.h
# End Source File
# Begin Source File

SOURCE=.\HighStakesLogNone.h
# End Source File
# Begin Source File

SOURCE=.\HistoryParser_DLL.h
# End Source File
# Begin Source File

SOURCE=.\InputHand.h
# End Source File
# Begin Source File

SOURCE=.\ParseCryptologicLogFile.h
# End Source File
# Begin Source File

SOURCE=.\ParseExports.h
# End Source File
# Begin Source File

SOURCE=.\ParseFile.h
# End Source File
# Begin Source File

SOURCE=.\ParseHighStakesLogFile.h
# End Source File
# Begin Source File

SOURCE=.\ParseLabrokesLogFile.h
# End Source File
# Begin Source File

SOURCE=.\ParseLogFile.h
# End Source File
# Begin Source File

SOURCE=.\ParsePartyLogFile.h
# End Source File
# Begin Source File

SOURCE=.\ParsePokerClubLogFile.h
# End Source File
# Begin Source File

SOURCE=.\ParseRoyalVegasLogFile.h
# End Source File
# Begin Source File

SOURCE=.\ParserParadiseLogFile.h
# End Source File
# Begin Source File

SOURCE=.\ParserPokerRoomLogFile.h
# End Source File
# Begin Source File

SOURCE=.\ParseState.h
# End Source File
# Begin Source File

SOURCE=.\ParseState.inl
# End Source File
# Begin Source File

SOURCE=.\ParseTruePokerLogFile.h
# End Source File
# Begin Source File

SOURCE=.\ParseWSEXLogFile.h
# End Source File
# Begin Source File

SOURCE=.\ParsingException.h
# End Source File
# Begin Source File

SOURCE=.\PartyLogNone.h
# End Source File
# Begin Source File

SOURCE=.\PDActionsRecordset.h
# End Source File
# Begin Source File

SOURCE=.\PDHandRecordset.h
# End Source File
# Begin Source File

SOURCE=.\PDPlayersRecordset.h
# End Source File
# Begin Source File

SOURCE=.\PDResultsRecordset.h
# End Source File
# Begin Source File

SOURCE=.\PSCryptologicLog.h
# End Source File
# Begin Source File

SOURCE=.\PSCryptologicLogAllFold.h
# End Source File
# Begin Source File

SOURCE=.\PSCryptologicLogBlind.h
# End Source File
# Begin Source File

SOURCE=.\PSCryptologicLogPlayerAction.h
# End Source File
# Begin Source File

SOURCE=.\PSCryptologicLogPlayerFirxtAction.h
# End Source File
# Begin Source File

SOURCE=.\PSCryptologicLogSummary.h
# End Source File
# Begin Source File

SOURCE=.\PSHighStakesLog.h
# End Source File
# Begin Source File

SOURCE=.\PSHighStakesLogDealing.h
# End Source File
# Begin Source File

SOURCE=.\PSHighStakesLogPlayerAction.h
# End Source File
# Begin Source File

SOURCE=.\PSHighStakesLogPlayerFirxtAction.h
# End Source File
# Begin Source File

SOURCE=.\PSHighStakesLogSummary.h
# End Source File
# Begin Source File

SOURCE=.\PSNone.h
# End Source File
# Begin Source File

SOURCE=.\PSParadiseDealing.h
# End Source File
# Begin Source File

SOURCE=.\PSParadiseDealToPlayer.h
# End Source File
# Begin Source File

SOURCE=.\PSParadiseGetBigBlind.h
# End Source File
# Begin Source File

SOURCE=.\PSParadiseGetSmallBlind.h
# End Source File
# Begin Source File

SOURCE=.\PSParadiseHeader1.h
# End Source File
# Begin Source File

SOURCE=.\PSParadiseHeader2.h
# End Source File
# Begin Source File

SOURCE=.\PSParadiseLog.h
# End Source File
# Begin Source File

SOURCE=.\PSParadiseLogPlayerAction.h
# End Source File
# Begin Source File

SOURCE=.\PSParadiseLogPlayerFirxtAction.h
# End Source File
# Begin Source File

SOURCE=.\PSParadiseLogResult.h
# End Source File
# Begin Source File

SOURCE=.\PSParadiseLogSmallBlind.h
# End Source File
# Begin Source File

SOURCE=.\PSParadisePlayerAction.h
# End Source File
# Begin Source File

SOURCE=.\PSParadisePlayerList.h
# End Source File
# Begin Source File

SOURCE=.\PSParadiseSumary1.h
# End Source File
# Begin Source File

SOURCE=.\PSParadiseSumary2.h
# End Source File
# Begin Source File

SOURCE=.\PSParadiseSumaryGereral.h
# End Source File
# Begin Source File

SOURCE=.\PSPartyDealing.h
# End Source File
# Begin Source File

SOURCE=.\PSPartyDealToPlayer.h
# End Source File
# Begin Source File

SOURCE=.\PSPartyGetBigBlind.h
# End Source File
# Begin Source File

SOURCE=.\PSPartyGetSmallBlind.h
# End Source File
# Begin Source File

SOURCE=.\PSPartyHeader1.h
# End Source File
# Begin Source File

SOURCE=.\PSPartyHeader2.h
# End Source File
# Begin Source File

SOURCE=.\PSPartyHeader3.h
# End Source File
# Begin Source File

SOURCE=.\PSPartyLog.h
# End Source File
# Begin Source File

SOURCE=.\PSPartyLogBigBlind.h
# End Source File
# Begin Source File

SOURCE=.\PSPartyLogDealing.h
# End Source File
# Begin Source File

SOURCE=.\PSPartyLogPlayerAction.h
# End Source File
# Begin Source File

SOURCE=.\PSPartyLogPlayerFirxtAction.h
# End Source File
# Begin Source File

SOURCE=.\PSPartyLogSmallBlind.h
# End Source File
# Begin Source File

SOURCE=.\PSPartyPlayerAction.h
# End Source File
# Begin Source File

SOURCE=.\PSPartyPlayerList.h
# End Source File
# Begin Source File

SOURCE=.\PSPartySumary1.h
# End Source File
# Begin Source File

SOURCE=.\PSPartySumary2.h
# End Source File
# Begin Source File

SOURCE=.\PSPartySumaryGereral.h
# End Source File
# Begin Source File

SOURCE=.\PSPartySummary.h
# End Source File
# Begin Source File

SOURCE=.\PSPokerRoomLog.h
# End Source File
# Begin Source File

SOURCE=.\PSPokerRoomLogDealing.h
# End Source File
# Begin Source File

SOURCE=.\PSPokerRoomLogPlayerAction.h
# End Source File
# Begin Source File

SOURCE=.\PSPokerRoomLogPlayerFirxtAction.h
# End Source File
# Begin Source File

SOURCE=.\PSPokerRoomLogResult.h
# End Source File
# Begin Source File

SOURCE=.\PSPokerRoomLogSmallBlind.h
# End Source File
# Begin Source File

SOURCE=.\PSRoyalVegasLog.h
# End Source File
# Begin Source File

SOURCE=.\PSRoyalVegasLogDealing.h
# End Source File
# Begin Source File

SOURCE=.\PSRoyalVegasLogPlayerAction.h
# End Source File
# Begin Source File

SOURCE=.\PSRoyalVegasLogPlayerFirxtAction.h
# End Source File
# Begin Source File

SOURCE=.\PSRoyalVegasLogSummary.h
# End Source File
# Begin Source File

SOURCE=.\PSStarsDealing.h
# End Source File
# Begin Source File

SOURCE=.\PSStarsDealToPlayer.h
# End Source File
# Begin Source File

SOURCE=.\PSStarsGetBigBlind.h
# End Source File
# Begin Source File

SOURCE=.\PSStarsGetSmallBlind.h
# End Source File
# Begin Source File

SOURCE=.\PSStarsHeader1.h
# End Source File
# Begin Source File

SOURCE=.\PSStarsHeader2.h
# End Source File
# Begin Source File

SOURCE=.\PSStarsPlayerAction.h
# End Source File
# Begin Source File

SOURCE=.\PSStarsPlayerList.h
# End Source File
# Begin Source File

SOURCE=.\PSStarsShowDown.h
# End Source File
# Begin Source File

SOURCE=.\PSStarsSumary1.h
# End Source File
# Begin Source File

SOURCE=.\PSStarsSumary2.h
# End Source File
# Begin Source File

SOURCE=.\PSStarsSumaryGereral.h
# End Source File
# Begin Source File

SOURCE=.\PSTrueLog.h
# End Source File
# Begin Source File

SOURCE=.\PSTrueLogBigBlind.h
# End Source File
# Begin Source File

SOURCE=.\PSTrueLogDealing.h
# End Source File
# Begin Source File

SOURCE=.\PSTrueLogHeader.h
# End Source File
# Begin Source File

SOURCE=.\PSTrueLogPlayerAction.h
# End Source File
# Begin Source File

SOURCE=.\PSTrueLogPlayerCards.h
# End Source File
# Begin Source File

SOURCE=.\PSTrueLogPlayerFirxtAction.h
# End Source File
# Begin Source File

SOURCE=.\PSTrueLogSmallBlind.h
# End Source File
# Begin Source File

SOURCE=.\PSTrueLogSummary.h
# End Source File
# Begin Source File

SOURCE=.\PSUltimateBetLog.h
# End Source File
# Begin Source File

SOURCE=.\PSUltimateBetLogBigBlind.h
# End Source File
# Begin Source File

SOURCE=.\PSUltimateBetLogDealing.h
# End Source File
# Begin Source File

SOURCE=.\PSUltimateBetLogPlayerAction.h
# End Source File
# Begin Source File

SOURCE=.\PSUltimateBetLogPlayerFirxtAction.h
# End Source File
# Begin Source File

SOURCE=.\PSUltimateBetLogShowdown.h
# End Source File
# Begin Source File

SOURCE=.\PSUltimateBetLogSmallBlind.h
# End Source File
# Begin Source File

SOURCE=.\PSWSEXLog.h
# End Source File
# Begin Source File

SOURCE=.\PSWSEXLogBigBlind.h
# End Source File
# Begin Source File

SOURCE=.\PSWSEXLogDealing.h
# End Source File
# Begin Source File

SOURCE=.\PSWSEXLogPlayerAction.h
# End Source File
# Begin Source File

SOURCE=.\PSWSEXLogPlayerFirxtAction.h
# End Source File
# Begin Source File

SOURCE=.\PSWSEXLogSmallBlind.h
# End Source File
# Begin Source File

SOURCE=.\PSWSEXLogSummary.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\RoyalVegasLogNone.h
# End Source File
# Begin Source File

SOURCE=.\SPDeleteHand.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\TrueLogNone.h
# End Source File
# Begin Source File

SOURCE=.\UltimateBetLogNone.h
# End Source File
# Begin Source File

SOURCE=.\WSEXLogNone.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
