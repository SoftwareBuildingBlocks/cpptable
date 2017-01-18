cmake_minimum_required(VERSION 3.6)
project(datatable)

set(CMAKE_CXX_STANDARD 14)

include_directories( include )

set(DATATABLE_LIB_FILES
    src/data_table_where.cpp
    src/dfa_state_data.cpp
    src/expr.cpp
    src/expr_compiler.cpp
    src/lalr_state_data.cpp
    src/parse_stack.cpp
    src/parser.cpp
    src/parser_action.cpp
    src/parser_state.cpp
    src/parser_symbol.cpp
    src/query_interpreter.cpp
    src/row_buffer.cpp
    src/string_util.cpp
    src/token.cpp
    src/tokenizer.cpp
    src/tokenizer_state.cpp
    src/tokenizer_state_transition.cpp
    )
add_library(datatable ${DATATABLE_LIB_FILES})

set(DATATABLE_TEST_FILES
    test/data_table_expr_tests.cpp
    test/data_table_iterator_tests.cpp
    test/data_table_tests.cpp
    test/expr_compiler_test.cpp
    test/row_buffer_tests.cpp
    test/simple_data_row.cpp
    test/test_data.cpp
    test/test_main.cpp
    test/data_table_string_tests.cpp
    )

add_executable(datatable_test ${DATATABLE_TEST_FILES})

target_link_libraries( datatable_test libgtest libgmock datatable )

# Build gtest
# Download and install GoogleTest
# We need thread support
find_package(Threads REQUIRED)

# Enable ExternalProject CMake module
include(ExternalProject)

ExternalProject_Add(
        gtest
        URL https://github.com/google/googletest/archive/master.zip
        URL_HASH MD5=3b93096d1145b3434d00d72b31f7fe27
        PREFIX ${CMAKE_CURRENT_BINARY_DIR}/gtest
        # Disable install step
        INSTALL_COMMAND ""
)

# Get GTest source and binary directories from CMake project
ExternalProject_Get_Property(gtest source_dir binary_dir)

# Create a libgtest target to be used as a dependency by test programs
add_library(libgtest IMPORTED STATIC GLOBAL)
add_dependencies(libgtest gtest)

# Set libgtest properties
set_target_properties(libgtest PROPERTIES
        "IMPORTED_LOCATION" "${binary_dir}/googlemock/gtest/libgtest.a"
        "IMPORTED_LINK_INTERFACE_LIBRARIES" "${CMAKE_THREAD_LIBS_INIT}"
        )

# Create a libgmock target to be used as a dependency by test programs
add_library(libgmock IMPORTED STATIC GLOBAL ../libbanker/BankerFactory.cpp ../libbanker/BankerFactory.h)
add_dependencies(libgmock gtest)

# Set libgmock properties
set_target_properties(libgmock PROPERTIES
        "IMPORTED_LOCATION" "${binary_dir}/googlemock/libgmock.a"
        "IMPORTED_LINK_INTERFACE_LIBRARIES" "${CMAKE_THREAD_LIBS_INIT}"
        )

# I couldn't make it work with INTERFACE_INCLUDE_DIRECTORIES
include_directories("${source_dir}/googletest/include"
        "${source_dir}/googlemock/include")