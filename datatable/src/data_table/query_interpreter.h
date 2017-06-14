#pragma once
#include "result.h"

class idata_row;
class parse_tree_node;

class query_interpreter
{
public:
	query_interpreter();
	~query_interpreter();
	val interpret(parse_tree_node& root, idata_row& dr);

private:
	val OR(val& left, val& right, idata_row& dr);
	val AND(val& left, val& right, idata_row& dr);
	val NOT(val& right, idata_row& dr);
	val greater_than(val& left, val& right, idata_row& dr);
	val less_than(val& left, val& right, idata_row& dr);
	val equal_to(val& left, val& right, idata_row& dr);
	val not_equal_to(val& left, val& right, idata_row& dr);
	val less_eq(val& right, val& left, idata_row &dr);
	val greater_eq(val& right, val& left, idata_row& dr);
	val ISNULL(val& left, idata_row& dr);
	val ISNOTNULL(val& left, idata_row& dr);
	val add(val& left, val& right, idata_row& dr);
	val subtract(val& left, val& right, idata_row& dr);
	val multiply(val& right, val& left, idata_row& dr);
	val divide(val& right, val& left, idata_row& dr);
	val negate(val& right, idata_row& dr);
	val IN(val& right, val& left, idata_row& dr);
	val LIKE(val& left, val& right, idata_row& dr);

	val process_expression(parse_tree_node&  symbol, idata_row& dr);
	val process_and(parse_tree_node&  symbol, idata_row& dr);
	val process_not(parse_tree_node&  symbol, idata_row& dr);

	val process_pred(parse_tree_node&  symbol, idata_row& dr);
	val process_add(parse_tree_node&  symbol, idata_row& dr);
	val process_mult(parse_tree_node&  symbol, idata_row& dr);
	val process_negate(parse_tree_node&  symbol, idata_row& dr);

	val process_value(parse_tree_node&  symbol, idata_row& dr);
	val process_tuple(parse_tree_node&  symbol, idata_row& dr);
	val process_expr_list(parse_tree_node&  symbol, idata_row& dr);
	val process_id(parse_tree_node& symbol, idata_row& dr);
	val process_integer(parse_tree_node& symbol, idata_row& dr);
	val process_double(parse_tree_node& symbol, idata_row& dr);
	val process_string(parse_tree_node& terminal, idata_row& dr);
	val process_bool(parse_tree_node& terminal, idata_row& dr);
	val process_null(parse_tree_node& terminal, idata_row& dr);

	val act_on_node(parse_tree_node&  symbol, idata_row& dr);
};

