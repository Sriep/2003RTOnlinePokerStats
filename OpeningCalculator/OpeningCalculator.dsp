# Microsoft Developer Studio Project File - Name="OpeningCalculator" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=OpeningCalculator - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "OpeningCalculator.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "OpeningCalculator.mak" CFG="OpeningCalculator - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "OpeningCalculator - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "OpeningCalculator - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""$/OpeningCalculator", JSAAAAAA"
# PROP Scc_LocalPath "."
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "OpeningCalculator - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "OpeningCalculator - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
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
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "OpeningCalculator - Win32 Release"
# Name "OpeningCalculator - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\DlgProxy.cpp
# End Source File
# Begin Source File

SOURCE=.\HoldemStartHand.cpp
# End Source File
# Begin Source File

SOURCE=.\OpeningCalculator.cpp
# End Source File
# Begin Source File

SOURCE=.\OpeningCalculator.odl
# End Source File
# Begin Source File

SOURCE=.\OpeningCalculator.rc
# End Source File
# Begin Source File

SOURCE=.\OpeningCalculator1.cpp
# End Source File
# Begin Source File

SOURCE=.\OpeningCalculatorDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\PHandSpread.cpp
# End Source File
# Begin Source File

SOURCE=.\PHoldemHandActions.cpp
# End Source File
# Begin Source File

SOURCE=.\PPlayerAction.cpp
# End Source File
# Begin Source File

SOURCE=.\PPokerObject.cpp
# End Source File
# Begin Source File

SOURCE=.\PRank.cpp
# End Source File
# Begin Source File

SOURCE=.\PSuit.cpp
# End Source File
# Begin Source File

SOURCE=.\RSCardsCalled.cpp
# End Source File
# Begin Source File

SOURCE=.\RSCardsRaised.cpp
# End Source File
# Begin Source File

SOURCE=.\SPRSCountHands.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\DlgProxy.h
# End Source File
# Begin Source File

SOURCE=.\HoldemStartHand.h
# End Source File
# Begin Source File

SOURCE=.\OpeningCalculator.h
# End Source File
# Begin Source File

SOURCE=.\OpeningCalculator1.h
# End Source File
# Begin Source File

SOURCE=.\OpeningCalculatorDlg.h
# End Source File
# Begin Source File

SOURCE=.\PHandSpread.h
# End Source File
# Begin Source File

SOURCE=.\PHoldemHandActions.h
# End Source File
# Begin Source File

SOURCE=.\PPlayerAction.h
# End Source File
# Begin Source File

SOURCE=.\PPokerObject.h
# End Source File
# Begin Source File

SOURCE=.\PRank.h
# End Source File
# Begin Source File

SOURCE=.\PSuit.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\RSCardsCalled.h
# End Source File
# Begin Source File

SOURCE=.\RSCardsRaised.h
# End Source File
# Begin Source File

SOURCE=.\SPRSCountHands.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\OpeningCalculator.ico
# End Source File
# Begin Source File

SOURCE=.\res\OpeningCalculator.rc2
# End Source File
# End Group
# Begin Source File

SOURCE=.\OpeningCalculator.reg
# End Source File
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
