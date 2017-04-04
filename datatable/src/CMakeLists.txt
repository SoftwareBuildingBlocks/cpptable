cmake_minimum_required(VERSION 3.5)

project(data_table)

set(CMAKE_BINARY_DIR ${BUILD_BIN_DIR})
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

include_directories("${PROJECT_SOURCE_DIR}" "${PROJECT_SOURCE_DIR}/../include")

option(EXPR_USE_LOGDEBUG "build with expression library console tracing" OFF)
if (EXPR_USE_LOGDEBUG)
	message(STATUS "Console expression tracing: Enabled")
	add_definitions(-D_DEBUGEXPR -D_DEBUG)
else (EXPR_USE_LOGDEBUG)
	message(STATUS "Console expression tracing: Disabled")
endif (EXPR_USE_LOGDEBUG)

add_library(
	data_table 
	${PROJECT_SOURCE_DIR}/data_table_where.cpp
	${PROJECT_SOURCE_DIR}/row_buffer.cpp
)

add_library(
	expr_compiler
	${PROJECT_SOURCE_DIR}/dfa_state_data.cpp
	${PROJECT_SOURCE_DIR}/expr.cpp
	${PROJECT_SOURCE_DIR}/expr_compiler.cpp
	${PROJECT_SOURCE_DIR}/lalr_state_data.cpp
	${PROJECT_SOURCE_DIR}/parser_state.cpp
	${PROJECT_SOURCE_DIR}/parse_stack.cpp
	${PROJECT_SOURCE_DIR}/parser.cpp
	${PROJECT_SOURCE_DIR}/parser_action.cpp
	${PROJECT_SOURCE_DIR}/parser_symbol.cpp
	${PROJECT_SOURCE_DIR}/query_interpreter.cpp
	${PROJECT_SOURCE_DIR}/string_util.cpp
	${PROJECT_SOURCE_DIR}/token.cpp
	${PROJECT_SOURCE_DIR}/tokenizer.cpp
	${PROJECT_SOURCE_DIR}/tokenizer_state.cpp
	${PROJECT_SOURCE_DIR}/tokenizer_state_transition.cpp
)

