#pragma once
#include "result.h"


class idata_row
{
public:
	virtual ~idata_row() {}
	virtual val get(const std::string& name) = 0;
	virtual void set(const std::string& name,val& v) = 0;
}; 
