#!/bin/sh

# compile source files
clang++ -g -O0 -std=c++1y -D GTEST_HAS_TR1_TUPLE=0 -c -I ../include ../src/*.cpp 

# compile expr test source files
clang++ -g -O0 -std=c++1y -D GTEST_HAS_TR1_TUPLE=0 -c -I ../include ../test/*.cpp

## link expr test source files
clang++ -g -O0 -o expr_test dfa_state_data.o expr.o expr_compiler.o expr_compiler_test.o lalr_state_data.o parser.o parser_action.o parser_state.o parser_symbol.o parse_stack.o query_interpreter.o row_buffer.o simple_data_row.o string_util.o test_data.o token.o tokenizer.o tokenizer_state.o tokenizer_state_transition.o -lgtest -lpthread  

## link data_table test source files
clang++ -g -O0 -o data_table_tests data_table_tests.o test_main.o dfa_state_data.o expr.o expr_compiler.o lalr_state_data.o parser.o parser_action.o parser_state.o parser_symbol.o parse_stack.o query_interpreter.o row_buffer.o simple_data_row.o string_util.o test_data.o token.o tokenizer.o tokenizer_state.o tokenizer_state_transition.o -lgtest -lpthread  


