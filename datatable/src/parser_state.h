#pragma once
#include <map>
#include "parser_action.h"
#include <string>

class parser_state
{
public:
	parser_state();
	~parser_state();
	std::map<std::string,parser_action> actions;
};

