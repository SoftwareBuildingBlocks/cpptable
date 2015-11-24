#pragma once
#include <array>
#include "token.h"
#include <vector>
#include "tokenizer_state.h"
#include <set>

class tokenizer
{
public:
	tokenizer();
	~tokenizer();

	std::vector<token> tokenize(std::istream& str_expr);
	void init();
private:
	int next_state(int state_idx, char c);
	bool is_terminal(tokenizer_state& curr_state);
	bool is_ws(tokenizer_state& curr_state);
	char convert_case(char in);
	bool _case_sensitive;
	int _start_state_idx;
	std::vector<tokenizer_state> _states;
	std::set<std::string> _terminal_tokens;
};

