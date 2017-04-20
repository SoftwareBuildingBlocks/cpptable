#include <ios>
#include <iomanip>
#include <data_table/tokenizer.h>
#include <data_table/tokenizer_state.h>
#include <data_table/string_util.h>
#include <data_table/dfa_state_data.h>

using namespace std;

tokenizer::tokenizer() : _case_sensitive(false), _start_state_idx(0)
{
	// TODO Next:  Fill out the _states vector
}


tokenizer::~tokenizer()
{
}

int tokenizer::next_state(int state_idx, char c)
{
	auto& curr_state = _states[state_idx];
	for(auto& transition: curr_state.transitions)
	{
		if (string::npos != transition.inputs.find_first_of(c))
		{
			return transition.to_state_idx;
		}
	}

	// no transitions out of this state take the current input as valid input
	return -1;
}

bool tokenizer::is_terminal(tokenizer_state& curr_state)
{
	return (_terminal_tokens.find(curr_state.accepted_token) != _terminal_tokens.end());
}

bool tokenizer::is_ws(tokenizer_state& curr_state)
{
	return (curr_state.accepted_token == "Whitespace");
}

char tokenizer::convert_case(char in)
{
	return (_case_sensitive ? in : tolower(in));
}

vector<token> tokenizer::tokenize(istream& input)
{
	input >> std::noskipws;
	auto current_state_idx = _start_state_idx;
	vector<token> tokens;
	vector<char> tmp_token;

	auto advance = true;
	char c;
	auto continue_to_tokenize = true;
	auto is_eof = false;

	while(continue_to_tokenize)
	{
		if (advance)  // advance in this iteration
			is_eof = (input >> c ? false : true);
		else // reset advance so we read input in the next iteration
			advance = true;

		auto next_state_idx = -1;
		if (!is_eof)  // end of file so we need to be at an accept state without consuming input
		{
			next_state_idx = next_state(current_state_idx, convert_case(c));
		}
		else
			continue_to_tokenize = false;  // end the tokenize loop

		if(next_state_idx >= 0) // we continue to consume input and move to next state in the state machine
		{
			tmp_token.push_back(c);
			current_state_idx = next_state_idx;
		}
		else // no transiation to any state using the current input
		{
			advance = false; // don't read any more inputs till we consume this input
			auto& curr_state = _states[current_state_idx];

			if (curr_state.is_accept_state)
			{
				if(is_terminal(curr_state))
				{
					token t;

					t.node_name = curr_state.accepted_token;
					t.value = string(tmp_token.begin(), tmp_token.end());
					tokens.push_back(t);
				}
				else if(!is_ws(curr_state))
				{
					throw runtime_error(format<128>("Expected this (%d,%s) to be a terminal or whitespace state",
													current_state_idx, curr_state.accepted_token.c_str()));
				}

				current_state_idx = _start_state_idx;
				tmp_token.clear();
			}
			else
			{
				// there is  no state transition into a new valid state from the 
				// current state using the current input.  So we are stuck and cannot 
				// consume any more characters from the stream
				throw runtime_error(format<128>("Current state (%d,%s) is not an accept state",
												current_state_idx, curr_state.accepted_token.c_str()));
			}
		}
	}

	token eof;
	eof.node_name = "EOF";
	eof.value = "EOF";
	tokens.push_back(eof);

	return tokens;
}

void tokenizer::init()
{
	_states = dfa_state_data::get_states();
	_terminal_tokens = dfa_state_data::get_terminal_tokens();
}
