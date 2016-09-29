# Microsoft Developer Studio Project File - Name="HistoryAnalyserDLL" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=HistoryAnalyserDLL - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "HistoryAnalyserDLL.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "HistoryAnalyserDLL.mak" CFG="HistoryAnalyserDLL - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "HistoryAnalyserDLL - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "HistoryAnalyserDLL - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""$/HistoryAnalyserDLL", GGBAAAAA"
# PROP Scc_LocalPath "."
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "HistoryAnalyserDLL - Win32 Release"

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
# ADD LINK32 ../../Output/Release/PokerObjects.lib ..\..\Output\Release\GridCtrl_src.lib /nologo /subsystem:windows /dll /machine:I386 /out:"../../Output/Release/HistoryAnalyserDLL.dll"

!ELSEIF  "$(CFG)" == "HistoryAnalyserDLL - Win32 Debug"

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
# ADD LINK32 ../../Output/Debug/PokerObjectsd.lib ..\..\Output\Debug\GridCtrl_srcd.lib /nologo /subsystem:windows /dll /debug /machine:I386 /out:"../../Output/Debug/HistoryAnalyserDLLd.dll" /pdbtype:sept

!ENDIF 

# Begin Target

# Name "HistoryAnalyserDLL - Win32 Release"
# Name "HistoryAnalyserDLL - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\ActiveTablesCombo.cpp
# End Source File
# Begin Source File

SOURCE=.\ColumnData.cpp
# End Source File
# Begin Source File

SOURCE=.\ellData.cpp
# End Source File
# Begin Source File

SOURCE=".\History AnalyserDlg.cpp"
# End Source File
# Begin Source File

SOURCE=.\HistoryAnalyserDLL.cpp
# End Source File
# Begin Source File

SOURCE=.\HistoryAnalyserDLL.def
# End Source File
# Begin Source File

SOURCE=.\HistoryAnalyserDLL.rc
# End Source File
# Begin Source File

SOURCE=.\HystoryAnalyserExports.cpp
# End Source File
# Begin Source File

SOURCE=.\NickGridCell.cpp
# End Source File
# Begin Source File

SOURCE=.\NickGridComboCell.cpp
# End Source File
# Begin Source File

SOURCE=.\RSColumData.cpp
# End Source File
# Begin Source File

SOURCE=.\RSPlayers.cpp
# End Source File
# Begin Source File

SOURCE=.\StatsGrid1.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\StoredProcGridCell.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\ActiveTablesCombo.h
# End Source File
# Begin Source File

SOURCE=.\ColumnData.h
# End Source File
# Begin Source File

SOURCE=.\ellData.h
# End Source File
# Begin Source File

SOURCE=".\History AnalyserDlg.h"
# End Source File
# Begin Source File

SOURCE=.\HistoryAnalyserDLL.h
# End Source File
# Begin Source File

SOURCE=.\HystoryAnalyserExports.h
# End Source File
# Begin Source File

SOURCE=.\NickGridCell.h
# End Source File
# Begin Source File

SOURCE=.\NickGridComboCell.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\RSColumData.h
# End Source File
# Begin Source File

SOURCE=.\RSPlayers.h
# End Source File
# Begin Source File

SOURCE=.\StatsGrid1.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\StoredProcGridCell.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\HistoryAnalyserDLL.rc2
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
