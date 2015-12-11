#pragma once
#include <map>
#include <data_table/result.h>
#include <data_table/data_row.h>

class simple_data_row : public idata_row
{
public:
	simple_data_row();
	~simple_data_row();
	val operator[](const std::string& name) override;
private:
	std::map<std::string,val> _dict;
};

