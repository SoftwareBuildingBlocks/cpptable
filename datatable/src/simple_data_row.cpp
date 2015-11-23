#include "simple_data_row.h"

simple_data_row::simple_data_row()
{
}


simple_data_row::~simple_data_row()
{
}

val& simple_data_row::operator[](const std::string& name) 
{
	return _dict[name];
}