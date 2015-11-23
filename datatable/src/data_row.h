#pragma once
#include "result.h"

class idata_row
{
public:
	virtual ~idata_row()	{}
	virtual val& operator[](const std::string& name) = 0;
}; 
