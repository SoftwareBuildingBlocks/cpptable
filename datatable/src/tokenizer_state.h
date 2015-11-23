#pragma once
#include <vector>
#include "tokenizer_state_transition.h"

class tokenizer_state
{
public:
	tokenizer_state();
	~tokenizer_state();
	
	std::vector<tokenizer_state_transition> transitions;
	std::string accepted_token;
	bool is_accept_state;
};

