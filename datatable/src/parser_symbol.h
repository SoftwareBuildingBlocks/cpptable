#pragma once
#include <vector>
#include "token.h"
#include <memory>

class parse_tree_node
{
public:
	parse_tree_node();
	parse_tree_node(const parse_tree_node& other);
	parse_tree_node& operator=(const parse_tree_node& other);

	const std::unique_ptr<std::vector<parse_tree_node>>& rhs();
	void insert_children(const std::vector<parse_tree_node>& vector, size_t size);
	int parser_state_idx;
	token token;

private:
	std::unique_ptr<std::vector<parse_tree_node>> _p_rhs;
};

