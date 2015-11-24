#pragma once
#include <string>
#include <vector>

class production_rule
{
public:
	production_rule();
	~production_rule();
	std::string lhs;
	std::vector<std::string> rhs;
};

