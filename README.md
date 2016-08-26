# cross_build_library

This project is about discovering, understanding and sharing knowledge about cross platform library builds.

## default_vs project

This project stems from a default Visual Studio Win32 DLLproject. It is not cross-platform but servers as a base to experiment and understand how DLL:s are built in Visual Studio.

```
C:\Users\kjell-olovhogdahl\Documents\GitHub\cross_build_library\build>tree /F
Folder PATH listing
Volume serial number is D49B-BB89
C:.
└───default_vs
    │   default_vs.cpp
    │   default_vs.h
    │   default_vs.sln
    │   default_vs.vcxproj
    │   default_vs.vcxproj.filters
    │   dllmain.cpp
    │   ReadMe.txt
    │   stdafx.cpp
    │   stdafx.h
    │   targetver.h
    │
    └───Debug
        │   default_vs.dll
```
The dll build with this project revelas to be exprting the following symbols.
```
C:\Program Files (x86)\Microsoft Visual Studio 14.0>cd \Users\kjell-olovhogdahl\Documents\GitHub\cross_build_library\build\default_vs\Debug

C:\Users\kjell-olovhogdahl\Documents\GitHub\cross_build_library\build\default_vs\Debug>dumpbin /EXPORTS default_vs.dll
Microsoft (R) COFF/PE Dumper Version 14.00.24210.0
Copyright (C) Microsoft Corporation.  All rights reserved.


Dump of file default_vs.dll

File Type: DLL

  Section contains the following exports for default_vs.dll

    00000000 characteristics
    57C00531 time date stamp Fri Aug 26 11:00:33 2016
        0.00 version
           1 ordinal base
           5 number of functions
           5 number of names

    ordinal hint RVA      name

          1    0 0001118B ??0Cdefault_vs@@QAE@XZ = @ILT+390(??0Cdefault_vs@@QAE@XZ)
          2    1 0001114F ??4Cdefault_vs@@QAEAAV0@$$QAV0@@Z = @ILT+330(??4Cdefault_vs@@QAEAAV0@$$QAV0@@Z)
          3    2 0001102D ??4Cdefault_vs@@QAEAAV0@ABV0@@Z = @ILT+40(??4Cdefault_vs@@QAEAAV0@ABV0@@Z)
          4    3 000111A9 ?fndefault_vs@@YAHXZ = @ILT+420(?fndefault_vs@@YAHXZ)
          5    4 00018138 ?ndefault_vs@@3HA = ?ndefault_vs@@3HA (int ndefault_vs)

  Summary

        1000 .00cfg
        1000 .data
        1000 .gfids
        1000 .idata
        2000 .rdata
        1000 .reloc
        1000 .rsrc
        5000 .text
       10000 .textbss

C:\Users\kjell-olovhogdahl\Documents\GitHub\cross_build_library\build\default_vs\Debug>
```
* The exported names are C++ name mangled using the Microsoft Visual Stuido name mangling.

