#pragma once
#include "variant.h"
#include <list>
#include <string>

using val = variant<std::int64_t, std::double_t, bool, std::list<void*>, std::string>;