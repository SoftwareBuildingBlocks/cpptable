#!/bin/sh

# compile source files
clang++ -std=c++1y -D GTEST_HAS_TR1_TUPLE=0 -c ../src/*.cpp 

# compile expr test source files
clang++ -std=c++1y -D GTEST_HAS_TR1_TUPLE=0 -c -I ../include ../test/expr_compiler_test.cpp ../test/simple_data_row.cpp ../test/test_data.cpp

# link expr test source files
clang++ -o expr_test dfa_state_data.o expr.o expr_compiler.o expr_compiler_test.o lalr_state_data.o parser.o parser_action.o parser_state.o parser_symbol.o parse_stack.o query_interpreter.o row_buffer.o simple_data_row.o string_util.o test_data.o token.o tokenizer.o tokenizer_state.o tokenizer_state_transition.o -lgtest -lpthread

# g++ -std=c++1y -D GTEST_HAS_TR1_TUPLE=0 ../src/*.cpp
