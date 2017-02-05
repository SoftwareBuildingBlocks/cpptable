cmake_minimum_required(VERSION 3.5)

project(data_table-distribution)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
	set(BUILD_CONFIGURATION "debug")
else(CMAKE_BUILD_TYPE STREQUAL "Debug")
	set(BUILD_CONFIGURATION "release")
endif(CMAKE_BUILD_TYPE STREQUAL "Debug")

set(BUILD_BIN_DIR "${CMAKE_SOURCE_DIR}/bin/${CMAKE_SYSTEM_NAME}/x64/${BUILD_CONFIGURATION}" CACHE INTERNAL "")

message("bin files will be located in: " ${BUILD_BIN_DIR})

add_subdirectory(src)

include(FindGTest)
if (GTEST_FOUND)
	message("GTEST found... gtests will be built")
	add_subdirectory(test)
else (GTEST_FOUND)
	message("GTEST NOT FOUND... gtests will NOT be built")
endif (GTEST_FOUND)

add_subdirectory(examples/zipdb)
add_subdirectory(examples/tickstore)
add_subdirectory(examples/servicesettings)

include(FindDoxygen)
if (DOXYGEN_FOUND)
	message("DOXYGEN found... doc files will be generated")
	add_custom_target(doc ALL ${DOXYGEN_EXECUTABLE})
else (DOXYGEN_FOUND)
	message("DOXYGEN NOT FOUND... doc files will NOT be generated")
endif (DOXYGEN_FOUND)
