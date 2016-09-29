# Microsoft Developer Studio Project File - Name="FlopOdds" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=FlopOdds - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "FlopOdds.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "FlopOdds.mak" CFG="FlopOdds - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "FlopOdds - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "FlopOdds - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""$/FlopOdds", PCAAAAAA"
# PROP Scc_LocalPath "."
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "FlopOdds - Win32 Release"

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
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /Zi /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 ../../Output/Release/PokerObjects.lib ../../Output/Release/GridCtrl_src.lib /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "FlopOdds - Win32 Debug"

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
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 ../../Output/Debug/PokerObjectsd.lib ../../Output/Debug/GridCtrl_srcd.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "FlopOdds - Win32 Release"
# Name "FlopOdds - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\DAPokerStatistics.cpp
# End Source File
# Begin Source File

SOURCE=.\DBHandListNames.cpp
# End Source File
# Begin Source File

SOURCE=.\FlopOdds.cpp
# End Source File
# Begin Source File

SOURCE=.\FlopOdds.rc
# End Source File
# Begin Source File

SOURCE=.\FlopOddsDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\HandEVDialog.cpp
# End Source File
# Begin Source File

SOURCE=.\HandsMap.cpp
# End Source File
# Begin Source File

SOURCE=.\HoldemHandList.cpp
# End Source File
# Begin Source File

SOURCE=.\PCalculateStartEVs.cpp
# End Source File
# Begin Source File

SOURCE=.\PDBSpradList.cpp
# End Source File
# Begin Source File

SOURCE=.\PDeck.cpp
# End Source File
# Begin Source File

SOURCE=.\PDisplayRowData.cpp
# End Source File
# Begin Source File

SOURCE=.\PDlgHandsSelection.cpp
# End Source File
# Begin Source File

SOURCE=.\PFlopOddsGrid.cpp
# End Source File
# Begin Source File

SOURCE=.\PFlopPercentages.cpp
# End Source File
# Begin Source File

SOURCE=.\PFPOneSuited.cpp
# End Source File
# Begin Source File

SOURCE=.\PFPRainbowPaired.cpp
# End Source File
# Begin Source File

SOURCE=.\PFPRainbowUnpaired.cpp
# End Source File
# Begin Source File

SOURCE=.\PFPTrips.cpp
# End Source File
# Begin Source File

SOURCE=.\PFPTwoSuitedPaired.cpp
# End Source File
# Begin Source File

SOURCE=.\PFPTwoSuitedUnpaired.cpp
# End Source File
# Begin Source File

SOURCE=.\PGameBoard.cpp
# End Source File
# Begin Source File

SOURCE=.\PHandsListArray.cpp
# End Source File
# Begin Source File

SOURCE=.\PHandsListList.cpp
# End Source File
# Begin Source File

SOURCE=.\PHoldemHandData.cpp
# End Source File
# Begin Source File

SOURCE=.\PSpreadListGridCell.cpp
# End Source File
# Begin Source File

SOURCE=.\RankCombo.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\SuitCombo.cpp
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\FlopOdds.ico
# End Source File
# Begin Source File

SOURCE=.\res\FlopOdds.rc2
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter ".h"
# Begin Source File

SOURCE=.\DAPokerStatistics.h
# End Source File
# Begin Source File

SOURCE=.\DBHandListNames.h
# End Source File
# Begin Source File

SOURCE=.\FlopOdds.h
# End Source File
# Begin Source File

SOURCE=.\FlopOddsDlg.h
# End Source File
# Begin Source File

SOURCE=.\HandsMap.h
# End Source File
# Begin Source File

SOURCE=.\PDBSpradList.h
# End Source File
# Begin Source File

SOURCE=.\PDisplayRowData.h
# End Source File
# Begin Source File

SOURCE=.\PDlgHandsSelection.h
# End Source File
# Begin Source File

SOURCE=.\PFlopOddsGrid.h
# End Source File
# Begin Source File

SOURCE=.\PFlopPercentages.h
# End Source File
# Begin Source File

SOURCE=.\PFPOneSuited.h
# End Source File
# Begin Source File

SOURCE=.\PFPRainbowPaired.h
# End Source File
# Begin Source File

SOURCE=.\PFPRainbowUnpaired.h
# End Source File
# Begin Source File

SOURCE=.\PFPTrips.h
# End Source File
# Begin Source File

SOURCE=.\PFPTwoSuitedPaired.h
# End Source File
# Begin Source File

SOURCE=.\PFPTwoSuitedUnpaired.h
# End Source File
# Begin Source File

SOURCE=.\PHandsListArray.h
# End Source File
# Begin Source File

SOURCE=.\PHandsListList.h
# End Source File
# Begin Source File

SOURCE=.\PSpreadListGridCell.h
# End Source File
# Begin Source File

SOURCE=.\RankCombo.h
# End Source File
# Begin Source File

SOURCE=.\resource.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\SuitCombo.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\HandEVDialog.h
# End Source File
# Begin Source File

SOURCE=.\HoldemHandList.h
# End Source File
# Begin Source File

SOURCE=.\PCalculateStartEVs.h
# End Source File
# Begin Source File

SOURCE=.\PDeck.h
# End Source File
# Begin Source File

SOURCE=.\PGameBoard.h
# End Source File
# Begin Source File

SOURCE=.\PHoldemHandData.h
# End Source File
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
