cmake_minimum_required(VERSION 3.5)
set (This_Project "cross_build_library")
project(${This_Project})

# Library target definition
set (This_Api ${This_Project}_api)
include (GenerateExportHeader)
set(API_SOURCE_FILES 
    src/default_vs.cpp
    src/default_vs.def
    src/default_vs.h
    src/dllmain.cpp
    src/stdafx.cpp
    src/stdafx.h
    src/targetver.h
	)
add_library(${This_Api} SHARED ${API_SOURCE_FILES})
GENERATE_EXPORT_HEADER( ${This_Api}
             BASE_NAME ${This_Api}
             EXPORT_MACRO_NAME ${This_Api}_EXPORT
             EXPORT_FILE_NAME ${This_Api}_Export.h
             STATIC_DEFINE ${This_Api}_BUILT_AS_STATIC)
include_directories(src)
