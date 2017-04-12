cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_COMPILER "/usr/bin/clang++")
set(CMAKE_C_COMPILER "/usr/bin/clang")

project(data_table-distribution)

option(BUILD_ALL "build all projects (GTests, Docs, and Examples)" OFF)
option(BUILD_GTESTS "build gtests" OFF)
option(BUILD_DOCS "build documentation" OFF)
option(BUILD_EXAMPLES "build example projects" OFF)

###################################
## check for compiler support
###################################
MESSAGE("Compiler Id = " ${CMAKE_CXX_COMPILER_ID})

if (CMAKE_CXX_COMPILER_ID MATCHES ".*Clang.*" OR CMAKE_COMPILER_IS_GNUCXX)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror")
	include(CheckCXXCompilerFlag)
	CHECK_CXX_COMPILER_FLAG("-std=c++1y" COMPILER_SUPPORTS_CXX1y)
	if(COMPILER_SUPPORTS_CXX1y)
		message(STATUS "C++ Standard: C++1y")
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y")
	else()
		message(WARNING "Compiler ${CMAKE_CXX_COMPILER} has no C++ 1y support.")
	endif()
elseif (MSVC)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4 /WX")
	if(NOT (MSVC_VERSION LESS 1700))
		message(STATUS "C++ Standard: C++0x")
		set(COMPILER_SUPPORTS_CXX0X TRUE)
	elseif(NOT (MSVC_VERSION LESS 1900))
		message(STATUS "C++ Standard: C++11")
		set(COMPILER_SUPPORTS_CXX11 TRUE)
	endif()
endif()

###################################
## Main
###################################
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
	set(BUILD_CONFIGURATION "debug")
else(CMAKE_BUILD_TYPE STREQUAL "Debug")
	set(BUILD_CONFIGURATION "release")
endif(CMAKE_BUILD_TYPE STREQUAL "Debug")

if (WIN32)
	set(BUILD_BIN_DIR "${CMAKE_SOURCE_DIR}/bin/${CMAKE_SYSTEM_NAME}/x64" CACHE INTERNAL "")
else (WIN32)
	set(BUILD_BIN_DIR "${CMAKE_SOURCE_DIR}/bin/${CMAKE_SYSTEM_NAME}/x64/${BUILD_CONFIGURATION}" CACHE INTERNAL "")
endif (WIN32)
message("bin files will be located in: " ${BUILD_BIN_DIR})


add_subdirectory(src)

###################################
## BUILD_ALL
###################################
if (BUILD_ALL)
	set(BUILD_GTESTS ON)
	set(BUILD_DOCS ON)
	set(BUILD_EXAMPLES ON)
endif (BUILD_ALL)

###################################
## GTEST
###################################
if (BUILD_GTESTS)
	message(STATUS "GTests: Enabled")
	include(FindGTest)
	if (GTEST_FOUND)
		message("GTEST found... gtests will be built")
		add_subdirectory(test)
	else (GTEST_FOUND)
		message("GTEST NOT FOUND... gtests will NOT be built")
	endif (GTEST_FOUND)
else (BUILD_GTESTS)
	message(STATUS "GTests: Disabled")
endif (BUILD_GTESTS)

###################################
## DOCUMENTATION
###################################
if (BUILD_DOCS)
	message(STATUS "Docs: Enabled")
	include(FindDoxygen)
	if (DOXYGEN_FOUND)
		message("DOXYGEN found... doc files will be generated")
		add_custom_target(doc ALL ${DOXYGEN_EXECUTABLE})
	else (DOXYGEN_FOUND)
		message("DOXYGEN NOT FOUND... doc files will NOT be generated")
	endif (DOXYGEN_FOUND)
else (BUILD_DOCS)
	message(STATUS "Docs: Disabled")
endif (BUILD_DOCS)

###################################
## EXAMPLES
###################################
if (BUILD_EXAMPLES)
	message(STATUS "Examples: Enabled")
	add_subdirectory(examples/zipdb)
	add_subdirectory(examples/tickstore)
	add_subdirectory(examples/servicesettings)
else (BUILD_EXAMPLES)
	message(STATUS "Examples: Disabled")
endif (BUILD_EXAMPLES)
