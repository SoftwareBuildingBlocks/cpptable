#include "simple_data_row.h"

simple_data_row::simple_data_row()
{
}


simple_data_row::~simple_data_row()
{
}

val simple_data_row::get(const std::string& name)
{
	return _dict[name];
}

void simple_data_row::set(const std::string& name,val& v)
{
	_dict[name] = v;
}
