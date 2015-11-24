#pragma once
#include "parser_symbol.h"

class idata_row;

class expr
{
public:
	expr(parse_tree_node& root);
	bool eval(idata_row& ziprow);

private:
	parse_tree_node _root;
};

