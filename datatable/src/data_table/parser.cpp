#include "parser.h"
#include "string_util.h"
#include "parser_symbol.h"
#include "lalr_state_data.h"
#include "parse_stack.h"

parser::parser() : _parser_start_state_idx(0)
{
}


parser::~parser()
{
}

void parser::init()
{
	this->_rules = lalr_state_data::get_rules();
	this->_parser_states = lalr_state_data::get_states();
}

parser_action& parser::get_action(token& tok, int parser_state_idx)
{
	auto& curr_state = _parser_states[parser_state_idx];
	return curr_state.actions[tok.node_name];
}

parse_tree_node parser::parse(std::vector<token>& tokens)
{
	auto parser_state_idx = _parser_start_state_idx;
	parse_stack tree_node_stack;
//	std::stack<parse_tree_node> tree_node_stack;

	parse_tree_node init;
	init.parser_state_idx = 0;
	init.token.node_name = "START";
	tree_node_stack.push(init);

	for (auto i = 0; i < tokens.size(); i++)
	{
		auto& tok = tokens[i];
		auto& action = get_action(tok, parser_state_idx);
		switch (action.action)
		{
			case parser_action::SHIFT_REDUCE::SHIFT:
				parser_state_idx = shift(tree_node_stack, tok, action);
				break;
			case parser_action::SHIFT_REDUCE::REDUCE:
				--i;// don't consume this token during a reduction
				parser_state_idx = reduce(tree_node_stack, action);
				break;
			case parser_action::SHIFT_REDUCE::ACCEPT:
				return tree_node_stack.top();
			default:
				throw std::runtime_error(format<128>("Unknown parser action: %d", action.action));
		}
	}
	throw std::runtime_error("Missing input parsing, incomplete");
}

int parser::goto_state(parser_action& action)
{
	return action.action_idx;
}

int parser::shift(parse_stack& stack, token& tok, parser_action& action)
{
	parse_tree_node sym;
	sym.parser_state_idx = action.action_idx;
	sym.token = tok;
	stack.push(sym);
	return action.action_idx;
}

int parser::reduce(parse_stack& stack, parser_action& action)
{
	// production rule used for reduction
	auto& rule = _rules[action.action_idx];
	parse_tree_node reduction;
	reduction.token.node_name = rule.lhs;

	// add children to the rule from the parser stack
	reduction.insert_children(stack.vector(), rule.rhs.size());
	stack.pop(rule.rhs.size());

	// which state to go to from here
	auto& next_action = get_action(reduction.token, stack.top().parser_state_idx);
	if (next_action.action != parser_action::SHIFT_REDUCE::GOTO_STATE)
		throw std::runtime_error(format<128>("Expected to goto next state at the end of Reduce. Unexpected Action: %d", 
											 next_action.action));
	
	reduction.parser_state_idx = next_action.action_idx;
	
	// add production to stack and goto next state
	stack.push(reduction);
	return goto_state(next_action);
}