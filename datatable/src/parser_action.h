#pragma once
class parser_action
{
public:
	parser_action();
	~parser_action();

	enum class SHIFT_REDUCE
	{
		SHIFT = 1,
		REDUCE = 2,
		GOTO_STATE = 3,
		ACCEPT = 4
	};

	SHIFT_REDUCE action;
	int action_idx;
};

