#pragma once
#include "production_rule.h"
#include <map>
#include "parser_state.h"

class LALR_state_data
{
public:
	static std::map<int, production_rule> get_rules();
	static std::map<int, parser_state> get_states();
};

