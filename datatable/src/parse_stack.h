#pragma once
#include <vector>

class parse_tree_node;

class parse_stack
{
public:
	parse_stack();
	~parse_stack();
	void push(parse_tree_node& node);
	parse_tree_node& top();
	void pop(int sz);
	const std::vector<parse_tree_node>& vector();
private:
	//std::stack<parse_tree_node> _stack;
	std::vector<parse_tree_node> _stack;
};

