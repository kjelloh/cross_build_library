#cross_build_library

This project is about discovering, understanding and sharing knowledge about cross platform library builds.

##CMake generated DLL project

    * The DOS Shell cript vs_me.cmd calls Cmake to generate a Visual Stuio solution build/build_vs/cross_build_library.sln

```
C:\Users\kjell-olovhogdahl\Documents\GitHub\cross_build_library\build>vs_me.cmd

C:\Users\kjell-olovhogdahl\Documents\GitHub\cross_build_library\build>REM Use Cmake to generate Visual Studio (VS) build environment

C:\Users\kjell-olovhogdahl\Documents\GitHub\cross_build_library\build>SET BUILD_DIR=build_vs

C:\Users\kjell-olovhogdahl\Documents\GitHub\cross_build_library\build>if exist build_vs (rmdir /s/q build_vs )

C:\Users\kjell-olovhogdahl\Documents\GitHub\cross_build_library\build>mkdir build_vs

C:\Users\kjell-olovhogdahl\Documents\GitHub\cross_build_library\build>cd build_vs

C:\Users\kjell-olovhogdahl\Documents\GitHub\cross_build_library\build\build_vs>REM use Cmake to generate default build environment (on windows it is Visual Studio)

C:\Users\kjell-olovhogdahl\Documents\GitHub\cross_build_library\build\build_vs>cmake ..
-- Building for: Visual Studio 14 2015
-- The C compiler identification is MSVC 19.0.24210.0
-- The CXX compiler identification is MSVC 19.0.24210.0
-- Check for working C compiler using: Visual Studio 14 2015
-- Check for working C compiler using: Visual Studio 14 2015 -- works
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working CXX compiler using: Visual Studio 14 2015
-- Check for working CXX compiler using: Visual Studio 14 2015 -- works
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Performing Test COMPILER_HAS_DEPRECATED_ATTR
-- Performing Test COMPILER_HAS_DEPRECATED_ATTR - Failed
-- Performing Test COMPILER_HAS_DEPRECATED
-- Performing Test COMPILER_HAS_DEPRECATED - Success
-- Configuring done
-- Generating done
-- Build files have been written to: C:/Users/kjell-olovhogdahl/Documents/GitHub/cross_build_library/build/build_vs

C:\Users\kjell-olovhogdahl\Documents\GitHub\cross_build_library\build\build_vs>cd ..

C:\Users\kjell-olovhogdahl\Documents\GitHub\cross_build_library\build>
```
* This Project builds an cross_build_library_api.dll

```
1>------ Rebuild All started: Project: ZERO_CHECK, Configuration: Debug Win32 ------
1>  Checking Build System
1>  CMake does not need to re-run because C:/Users/kjell-olovhogdahl/Documents/GitHub/cross_build_library/build/build_vs/CMakeFiles/generate.stamp is up-to-date.
2>------ Rebuild All started: Project: cross_build_library_api, Configuration: Debug Win32 ------
2>  Building Custom Rule C:/Users/kjell-olovhogdahl/Documents/GitHub/cross_build_library/build/CMakeLists.txt
2>  CMake does not need to re-run because C:\Users\kjell-olovhogdahl\Documents\GitHub\cross_build_library\build\build_vs\CMakeFiles\generate.stamp is up-to-date.
2>  default_vs.cpp
2>  dllmain.cpp
2>  stdafx.cpp
2>  Generating Code...
2>     Creating library C:/Users/kjell-olovhogdahl/Documents/GitHub/cross_build_library/build/build_vs/Debug/cross_build_library_api.lib and object C:/Users/kjell-olovhogdahl/Documents/GitHub/cross_build_library/build/build_vs/Debug/cross_build_library_api.exp
2>  cross_build_library_api.vcxproj -> C:\Users\kjell-olovhogdahl\Documents\GitHub\cross_build_library\build\build_vs\Debug\cross_build_library_api.dll
========== Rebuild All: 2 succeeded, 0 failed, 0 skipped ==========

```

* And the generated dll exposes the __declspec(dllexport) symbols and the unmangled symbol names (e.g., "fndefault_vs") in the de-file.

```
C:\Users\kjell-olovhogdahl\Documents\GitHub\cross_build_library\build\build_vs\Debug>dumpbin /EXPORTS cross_build_library_api.dll
Microsoft (R) COFF/PE Dumper Version 14.00.24210.0
Copyright (C) Microsoft Corporation.  All rights reserved.


Dump of file cross_build_library_api.dll

File Type: DLL

  Section contains the following exports for default_vs.dll

    00000000 characteristics
    57C01863 time date stamp Fri Aug 26 12:22:27 2016
        0.00 version
           1 ordinal base
           5 number of functions
           5 number of names

    ordinal hint RVA      name

          1    0 00001109 ??0Cdefault_vs@@QAE@XZ = @ILT+260(??0Cdefault_vs@@QAE@XZ)
          2    1 000010E1 ??4Cdefault_vs@@QAEAAV0@$$QAV0@@Z = @ILT+220(??4Cdefault_vs@@QAEAAV0@$$QAV0@@Z)
          3    2 00001023 ??4Cdefault_vs@@QAEAAV0@ABV0@@Z = @ILT+30(??4Cdefault_vs@@QAEAAV0@ABV0@@Z)
          5    3 00009138 ?ndefault_vs@@3HA = ?ndefault_vs@@3HA (int ndefault_vs)
          4    4 0000111D fndefault_vs = @ILT+280(?fndefault_vs@@YAHXZ)

  Summary

        1000 .00cfg
        1000 .data
        1000 .gfids
        1000 .idata
        3000 .rdata
        1000 .reloc
        1000 .rsrc
        5000 .text

C:\Users\kjell-olovhogdahl\Documents\GitHub\cross_build_library\build\build_vs\Debug>
```


##default_vs project

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

