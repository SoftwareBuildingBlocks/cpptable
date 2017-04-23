#include "parse_stack.h"
#include "parser_symbol.h"

parse_stack::parse_stack() 
{
	_stack.reserve(100);
}

parse_stack::~parse_stack()
{
}

void parse_stack::push(parse_tree_node& node)
{
	_stack.push_back(node);
}

parse_tree_node& parse_stack::top()
{
	return _stack.back();
}

void parse_stack::pop(std::size_t num)
{
	auto start = _stack.begin() + (_stack.size() - num);
	_stack.erase(start, _stack.end());
}

const std::vector<parse_tree_node>& parse_stack::vector()
{
	return _stack;
}
