#include "tokenizer_state_transition.h"

tokenizer_state_transition::tokenizer_state_transition(int to_st, const std::string& in)
	: inputs(in), to_state_idx (to_st)
{
}

tokenizer_state_transition::~tokenizer_state_transition()
{
}
