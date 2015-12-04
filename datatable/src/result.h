#pragma once
#include "variant.h"
#include <list>
#include <string>

typedef variant<int, double, bool, std::list<void*>, std::string> val;