cmake_minimum_required(VERSION 3.5)

project(data_reader)

set(CMAKE_BINARY_DIR ${BUILD_BIN_DIR})
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

include_directories("${PROJECT_SOURCE_DIR}" "${PROJECT_SOURCE_DIR}/../../../include")

add_library(
	nanodbc_reader
	${PROJECT_SOURCE_DIR}/nanodbc_reader.cpp
)
