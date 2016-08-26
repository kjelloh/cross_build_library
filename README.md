# cross_build_library

This project is about discovering, understanding and sharing knowledge about cross platform library builds.

## default_vs project

This project stems from a default Visual Studio Win32 DLLproject. It is not cross-platform but servers as a base to experiment and understand how DLL:s are built in Visual Studio.

    * The project was created using the visual studio wizard C++ Win32 Project - selecting <Application type:> "DLL" and <Application options:> "Export symbols"
    * Then a def-file has been added using <Project>/<Add New Item> selecting <Code> and "Mdoule-Definition File (.def)".
    * This updates project property <Linker>/<Input> "Module Definition File" to refer to the added def-file.

```
C:\Users\kjell-olovhogdahl\Documents\GitHub\cross_build_library\build>tree /F
Folder PATH listing
Volume serial number is D49B-BB89
C:.
└───default_vs
    │   default_vs.cpp
    │   default_vs.def
    │   default_vs.h
    │   default_vs.sln
    │   default_vs.VC.db
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

C:\Users\kjell-olovhogdahl\Documents\GitHub\cross_build_library\build>
```

* The dll built with this project reveals to be exporting C++ name mangled symbols AND the unmangled names defined by the .def file.

```
C:\Users\kjell-olovhogdahl\Documents\GitHub\cross_build_library\build\default_vs\Debug>dumpbin /EXPORTS default_vs.dll
Microsoft (R) COFF/PE Dumper Version 14.00.24210.0
Copyright (C) Microsoft Corporation.  All rights reserved.


Dump of file default_vs.dll

File Type: DLL

  Section contains the following exports for default_vs.dll

    00000000 characteristics
    57C01056 time date stamp Fri Aug 26 11:48:06 2016
        0.00 version
           1 ordinal base
           5 number of functions
           5 number of names

    ordinal hint RVA      name

          1    0 0001118B ??0Cdefault_vs@@QAE@XZ = @ILT+390(??0Cdefault_vs@@QAE@XZ)
          2    1 0001114F ??4Cdefault_vs@@QAEAAV0@$$QAV0@@Z = @ILT+330(??4Cdefault_vs@@QAEAAV0@$$QAV0@@Z)
          3    2 0001102D ??4Cdefault_vs@@QAEAAV0@ABV0@@Z = @ILT+40(??4Cdefault_vs@@QAEAAV0@ABV0@@Z)
          5    3 00018138 ?ndefault_vs@@3HA = ?ndefault_vs@@3HA (int ndefault_vs)
          4    4 000111A9 fndefault_vs = @ILT+420(?fndefault_vs@@YAHXZ)

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
* The entry "4    4 000111A9 fndefault_vs = @ILT+420(?fndefault_vs@@YAHXZ)" shows the unmangled symbol name defined in the def-file.
* Name mangling seems to be quite well explaing by wikipedia entry (https://en.wikipedia.org/wiki/Name_mangling)
* And the Microsoft dumpbin tool information seems to live here (https://msdn.microsoft.com/en-us/library/c1h23y6c.aspx)

