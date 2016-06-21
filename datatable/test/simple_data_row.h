#pragma once
#include <map>
#include <data_table/result.h>
#include <data_table/data_row.h>

class simple_data_row : public idata_row
{
public:
	simple_data_row();
	~simple_data_row();
	val get(const std::string& name) override;
	void set(const std::string& name,val& v) override;

	
	simple_data_row(const simple_data_row &r)
	{
		_dict = r._dict;
	}

	simple_data_row& operator=(const simple_data_row &r)
	{
		_dict = r._dict;
		return(*this);
	}


	simple_data_row(simple_data_row &&r)
	{
		_dict = std::move(r._dict);
	}

	simple_data_row& operator=(simple_data_row &&r)
	{
		if (this == &r)
			return(*this);
		_dict = std::move(r._dict);
		return(*this);
	}

private:
	std::map<std::string,val> _dict;
};

