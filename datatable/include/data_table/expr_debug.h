#pragma once

#if (defined _DEBUG && defined _DEBUGEXPR)
#include <iostream>
	#define DBG(x) x
#else
	#define DBG(x)
#endif
