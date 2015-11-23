#pragma once
#include "tokenizer_state.h"
#include <set>

class DFA_state_data
{
public:
	static std::set<std::string> get_terminal_tokens();
	static std::vector<tokenizer_state> get_states();
};

