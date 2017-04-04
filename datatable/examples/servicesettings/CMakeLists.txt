cmake_minimum_required(VERSION 3.5)

project(servicesettings)

set(CMAKE_BINARY_DIR ${BUILD_BIN_DIR})
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

include_directories("${PROJECT_SOURCE_DIR}" "${PROJECT_SOURCE_DIR}/../../include")

add_executable(
	servicesettings
	${PROJECT_SOURCE_DIR}/servicesettings.cpp
)

link_directories(
	${LIBRARY_OUTPUT_PATH}
)

if (WIN32)
	target_link_libraries(servicesettings data_table expr_compiler)
else (WIN32)
	target_link_libraries(servicesettings pthread data_table expr_compiler)
endif (WIN32)
