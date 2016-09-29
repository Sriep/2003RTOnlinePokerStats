# Microsoft Developer Studio Project File - Name="PokerObjects" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=PokerObjects - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "PokerObjects.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "PokerObjects.mak" CFG="PokerObjects - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "PokerObjects - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "PokerObjects - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""$/PokerObjects", AIBAAAAA"
# PROP Scc_LocalPath "."
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "PokerObjects - Win32 Release"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /Zi /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR /Yu"stdafx.h" /FD /c
# SUBTRACT CPP /O<none>
# ADD BASE RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo /out:"../Output/Release\PokerObjects.lib"

!ELSEIF  "$(CFG)" == "PokerObjects - Win32 Debug"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo /out:"../Output/Debug/PokerObjectsd.lib"

!ENDIF 

# Begin Target

# Name "PokerObjects - Win32 Release"
# Name "PokerObjects - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\ComboCompletion.cpp
# End Source File
# Begin Source File

SOURCE=.\PCard.cpp
# End Source File
# Begin Source File

SOURCE=.\PCardList.cpp
# End Source File
# Begin Source File

SOURCE=.\PHoldemFlop.cpp
# End Source File
# Begin Source File

SOURCE=.\PHoldemHand.cpp
# End Source File
# Begin Source File

SOURCE=.\PlayerList.cpp
# End Source File
# Begin Source File

SOURCE=.\PPlayerAction.cpp
# End Source File
# Begin Source File

SOURCE=.\PPokerHand.cpp
# End Source File
# Begin Source File

SOURCE=.\PPokerObject.cpp
# End Source File
# Begin Source File

SOURCE=.\PPokerSite.cpp
# End Source File
# Begin Source File

SOURCE=.\PRank.cpp
# End Source File
# Begin Source File

SOURCE=.\PSuit.cpp
# End Source File
# Begin Source File

SOURCE=.\RS_DBQueue.cpp
# End Source File
# Begin Source File

SOURCE=.\RSCurrentPlayers.cpp
# End Source File
# Begin Source File

SOURCE=.\RSCurrentTables.cpp
# End Source File
# Begin Source File

SOURCE=.\RSLogDBLcoks.cpp
# End Source File
# Begin Source File

SOURCE=.\RSSelectAllCurrentTables.cpp
# End Source File
# Begin Source File

SOURCE=.\SharedMemory.cpp
# End Source File
# Begin Source File

SOURCE=.\SPDataKey.cpp
# End Source File
# Begin Source File

SOURCE=.\SPRSCountHands.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\TableGridRowData.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\ComboCompletion.h
# End Source File
# Begin Source File

SOURCE="..\History Parser\HistoryParser_DLL\ParseState.inl"
# End Source File
# Begin Source File

SOURCE=.\PCard.h
# End Source File
# Begin Source File

SOURCE=.\PCardList.h
# End Source File
# Begin Source File

SOURCE=.\PHoldemFlop.h
# End Source File
# Begin Source File

SOURCE=.\PHoldemHand.h
# End Source File
# Begin Source File

SOURCE=.\PlayerList.h
# End Source File
# Begin Source File

SOURCE=.\PPlayerAction.h
# End Source File
# Begin Source File

SOURCE=.\PPokerHand.h
# End Source File
# Begin Source File

SOURCE=.\PPokerObject.h
# End Source File
# Begin Source File

SOURCE=.\PPokerSite.h
# End Source File
# Begin Source File

SOURCE=.\PRank.h
# End Source File
# Begin Source File

SOURCE=.\PSuit.h
# End Source File
# Begin Source File

SOURCE=.\RS_DBQueue.h
# End Source File
# Begin Source File

SOURCE=.\RSCurrentPlayers.h
# End Source File
# Begin Source File

SOURCE=.\RSCurrentTables.h
# End Source File
# Begin Source File

SOURCE=.\RSLogDBLcoks.h
# End Source File
# Begin Source File

SOURCE=.\RSSelectAllCurrentTables.h
# End Source File
# Begin Source File

SOURCE=.\SharedMemory.h
# End Source File
# Begin Source File

SOURCE=.\SPDataKey.h
# End Source File
# Begin Source File

SOURCE=.\SPRSCountHands.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\TableGridRowData.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\Readme.txt
# End Source File
# End Target
# End Project
