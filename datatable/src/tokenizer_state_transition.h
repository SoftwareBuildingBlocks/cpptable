#pragma once
#include <string>

class tokenizer_state_transition
{
public:
	tokenizer_state_transition(int to_st, const std::string& in);
	~tokenizer_state_transition();
	std::string inputs;
	int to_state_idx;
};

