#pragma once
#include "variant.h"
#include <list>
#include <string>
#include <stdint.h>
#include <math.h>

// std::double_t not defined in linux
// using val = variant<std::int64_t, std::double_t, bool, std::list<void*>, std::string>;
using val = variant<std::int64_t, std::int32_t, double, bool, std::list<void*>, std::string>;