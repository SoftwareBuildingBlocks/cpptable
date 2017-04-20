cmake_minimum_required(VERSION 3.5)

project(data_table_tests)

include(FindGTest)
if (NOT GTEST_FOUND)
	message("GTEST NOT FOUND... gtests will NOT be built")
	return()
endif (NOT GTEST_FOUND)

set(CMAKE_BINARY_DIR ${BUILD_BIN_DIR})
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

include_directories("${PROJECT_SOURCE_DIR}" "${PROJECT_SOURCE_DIR}/../include" "${PROJECT_SOURCE_DIR}/../src")

add_executable(
	data_table_test 
	${PROJECT_SOURCE_DIR}/data_table_expr_tests.cpp
	${PROJECT_SOURCE_DIR}/data_table_iterator_tests.cpp
	${PROJECT_SOURCE_DIR}/data_table_string_tests.cpp
	${PROJECT_SOURCE_DIR}/data_table_tests.cpp
	${PROJECT_SOURCE_DIR}/row_buffer_tests.cpp
	${PROJECT_SOURCE_DIR}/test_main.cpp
)

link_directories(
	${LIBRARY_OUTPUT_PATH}
)

target_compile_definitions(
	data_table_test 
	PRIVATE
	GTEST_LANG_CXX11
) 

if (WIN32)
	target_link_libraries(data_table_test gtest data_table expr_compiler)
else (WIN32)
	target_link_libraries(data_table_test gtest pthread data_table expr_compiler)
endif (WIN32)

add_executable(
	expr_compiler_test
	${PROJECT_SOURCE_DIR}/expr_compiler_test.cpp
	${PROJECT_SOURCE_DIR}/simple_data_row.cpp
	${PROJECT_SOURCE_DIR}/test_data.cpp
)

target_compile_definitions(
	expr_compiler_test
	PRIVATE
	GTEST_LANG_CXX11
)

if (WIN32)
	target_link_libraries(expr_compiler_test gtest data_table expr_compiler)
else (WIN32)
	target_link_libraries(expr_compiler_test gtest pthread data_table expr_compiler )
endif (WIN32)
