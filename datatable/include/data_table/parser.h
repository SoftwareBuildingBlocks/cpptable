#pragma once
#include <vector>
#include "token.h"
#include <map>
#include "parser_state.h"
#include "parser_symbol.h"
#include "production_rule.h"

class parse_stack;

class parser
{
public:
	parser();
	~parser();
	void init();
	parse_tree_node parse(std::vector<token>& tokens);
private:
	int goto_state(parser_action& action);
	int shift(parse_stack& stack, token& tok, parser_action& action);
	int reduce(parse_stack& stack, parser_action& action);
	parser_action& get_action(token& tok, int parser_state);
	int _parser_start_state_idx;
	std::map<int,parser_state> _parser_states;
	std::map<int,production_rule> _rules;
};
