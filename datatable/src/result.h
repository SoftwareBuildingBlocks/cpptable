#pragma once
#include "variant.h"
#include <list>

typedef variant<int, double, bool, std::list<void*>, std::string> val;