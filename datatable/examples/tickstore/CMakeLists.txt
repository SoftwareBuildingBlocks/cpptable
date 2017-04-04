cmake_minimum_required(VERSION 3.5)

project(tickstore)

set(CMAKE_BINARY_DIR ${BUILD_BIN_DIR})
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

include_directories("${PROJECT_SOURCE_DIR}" "${PROJECT_SOURCE_DIR}/../../include")

add_executable(
	tickstore
	${PROJECT_SOURCE_DIR}/tickstore.cpp
)

link_directories(
	${LIBRARY_OUTPUT_PATH}
)

target_link_libraries(tickstore	data_table expr_compiler)
