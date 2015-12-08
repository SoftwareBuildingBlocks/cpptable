#pragma once
#include <vector>
#include <tuple>
#include <memory>

using Data = std::tuple<int, std::string, std::string, std::string, std::string, double, double>;

class ComplierTest
{
public:
	static std::shared_ptr<std::vector<Data>> TestData();
};
