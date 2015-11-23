#include "expr.h"
#include "query_interpreter.h"

expr::expr(parse_tree_node& root) : _root(root)
{
}

bool expr::eval(idata_row& dr)
{
	query_interpreter qi;
	auto retval = qi.interpret(_root, dr);
	if (!retval.is<bool>())
		throw std::exception("Expression must return a boolean value");

	return retval.get<bool>();
}