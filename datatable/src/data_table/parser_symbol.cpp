#include "parser_symbol.h"

parse_tree_node::parse_tree_node() : parser_state_idx(0), _p_rhs(nullptr)
{
}

parse_tree_node::parse_tree_node(const parse_tree_node& other)
{
	if (other._p_rhs)
		_p_rhs = std::make_unique<std::vector<parse_tree_node>>(*(other._p_rhs.get()));
	else
		_p_rhs = nullptr;

	this->parser_state_idx = other.parser_state_idx;
	this->token = other.token;
}

parse_tree_node& parse_tree_node::operator=(const parse_tree_node& other)
{
	if (other._p_rhs)
		_p_rhs = std::make_unique<std::vector<parse_tree_node>>(*(other._p_rhs.get()));
	else
		_p_rhs = nullptr;

	this->parser_state_idx = other.parser_state_idx;
	this->token = other.token;

	return *this;
}

const std::unique_ptr<std::vector<parse_tree_node>>& parse_tree_node::rhs()
{
	return _p_rhs;
}

void parse_tree_node::insert_children(const std::vector<parse_tree_node>& vect, size_t size)
{
	if (!_p_rhs)
	{
		_p_rhs = std::make_unique<std::vector<parse_tree_node>>();
		_p_rhs->reserve(4);  // max children (99% of derivations of this grammar
	}

	auto start = vect.begin() + (vect.size() - size);
	_p_rhs->insert(_p_rhs->end(), start, vect.end());
}
