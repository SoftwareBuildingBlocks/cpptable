#pragma once
#include <string>
#include <vector>

struct production_rule
{
	std::string lhs;
	std::vector<std::string> rhs;
};

