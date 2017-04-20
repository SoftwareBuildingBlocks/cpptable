#include <data_table/expr.h>
#include <data_table/query_interpreter.h>
#include <data_table/expr_debug.h>

expr::expr(parse_tree_node& root) : _root(root)
{
}

bool expr::eval(idata_row& dr)
{
	query_interpreter qi;
	auto retval = qi.interpret(_root, dr);
	if (!retval.is<bool>())
		throw std::runtime_error("Expression must return a boolean value");

	DBG(std::cout << std::endl);

	return retval.get<bool>();
}