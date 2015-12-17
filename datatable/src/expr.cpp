#include <data_table/expr.h>
#include <data_table/query_interpreter.h>

expr::expr(parse_tree_node& root) : _root(root)
{
}

bool expr::eval(idata_row& dr)
{
	query_interpreter qi;
	auto retval = qi.interpret(_root, dr);
	if (!retval.is<bool>())
		throw std::runtime_error("Expression must return a boolean value");

	return retval.get<bool>();
}