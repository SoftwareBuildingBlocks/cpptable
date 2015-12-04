#pragma once
#include <vector>
#include <tuple>
#include <memory>

typedef std::tuple<int, std::string, std::string, std::string, std::string, double, double> Data;

class ComplierTest
{
public:
	static std::shared_ptr<std::vector<Data>> TestData();
};
