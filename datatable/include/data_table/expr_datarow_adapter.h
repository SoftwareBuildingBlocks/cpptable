#pragma once
#include "data_row.h"
#include "result.h"
#include <data_table/expr_debug.h>

class expr_datarow_adapter : public idata_row
{
public:
	expr_datarow_adapter(dt::data_table_row& dtrow, dt::data_table_columns& cols);
	~expr_datarow_adapter(){}
	val get(const std::string& name) override;
	void set(const std::string& name,val& v) override;
private:
	dt::data_table_row& _dtrow;
	std::map<std::string, std::size_t> _map_colname_type;
};

inline expr_datarow_adapter::expr_datarow_adapter(dt::data_table_row& dtrow, dt::data_table_columns& cols)
	: _dtrow(dtrow)
{
	for(auto& c : cols)
	{
		_map_colname_type[c.name()] = c.type();
	}
}

inline val expr_datarow_adapter::get(const std::string& name)
{
	std::size_t id =_map_colname_type[name]; 
	if (id == typeid(std::int8_t).hash_code()) {
		auto v = _dtrow.get<std::int8_t>(name);
		DBG(std::cout << " " << v << " ");
		return val().set<std::int64_t>(v);
	}
	else if (id == typeid(std::uint8_t).hash_code()) {
		auto v = _dtrow.get<std::uint8_t>(name);
		DBG(std::cout << " " << v << " ");
		return val().set<std::int64_t>(v);
	}
	else if (id == typeid(std::int16_t).hash_code()) {
		std::int64_t v = _dtrow.get<std::int16_t>(name);
		DBG(std::cout << " " << v << " ");
		return val().set<std::int64_t>(v);
	}
	else if (id == typeid(std::uint16_t).hash_code()) {
		std::int64_t v = _dtrow.get<std::uint16_t>(name);
		DBG(std::cout << " " << v << " ");
		return val().set<std::int64_t>(v);
	}
	else if (id == typeid(std::int32_t).hash_code()) {
		std::int64_t v = _dtrow.get<std::int32_t>(name);
		DBG(std::cout << " " << v << " ");
		return val().set<std::int64_t>(v);
	}
	else if (id == typeid(std::uint32_t).hash_code()) {
		std::int64_t v = _dtrow.get<std::uint32_t>(name);
		DBG(std::cout << " " << v << " ");
		return val().set<std::int64_t>(v);
	}
	else if (id == typeid(std::int64_t).hash_code()) {
		std::int64_t v = _dtrow.get<std::int64_t>(name);
		DBG(std::cout << " " << v << " ");
		return val().set<std::int64_t>(v);
	}
	else if (id == typeid(std::uint64_t).hash_code()) {
		std::int64_t v = _dtrow.get<std::uint64_t>(name);
		DBG(std::cout << " " << v << " ");
		return val().set<std::int64_t>(v);
	}
	else if (id == typeid(std::string).hash_code()) {
		auto v = _dtrow.get<std::string>(name);
		DBG(std::cout << " " << v << " ");
		return val().set<std::string>(std::string(v));
	}
	else if (id == typeid(std::wstring).hash_code()) {
		auto v = _dtrow.get<std::wstring>(name);
		DBG(std::wcout << " " << v << " ");
		return val().set<std::wstring>(std::wstring(v));
	}
	else if (id == typeid(double).hash_code()) {
		std::double_t v = _dtrow.get<std::double_t>(name);
		DBG(std::cout << " " << v << " ");
		return val().set<std::double_t>(v);
	}

	return val();
}

inline void expr_datarow_adapter::set(const std::string& name, val& v)
{
	std::size_t id = _map_colname_type[name];
	if (id == typeid(std::int8_t).hash_code()) {
		_dtrow.set(name, std::int8_t(v.get<std::int64_t>()));
	}
	else if (id == typeid(std::uint8_t).hash_code()) {
		_dtrow.set(name, std::uint8_t(v.get<std::int64_t>()));
	}
	else if (id == typeid(std::int16_t).hash_code()) {
		_dtrow.set(name, std::int16_t(v.get<std::int64_t>()));
	}
	else if (id == typeid(std::uint16_t).hash_code()) {
		_dtrow.set(name, std::uint16_t(v.get<std::int64_t>()));
	}
	else if (id == typeid(std::int32_t).hash_code()) {
		_dtrow.set(name, std::int32_t(v.get<std::int64_t>()));
	}
	else if (id == typeid(std::uint32_t).hash_code()) {
		_dtrow.set(name, std::uint32_t(v.get<std::int64_t>()));
	}
	else if (id == typeid(std::int64_t).hash_code()) {
		_dtrow.set(name, std::int64_t(v.get<std::int64_t>()));
	}
	else if (id == typeid(std::uint64_t).hash_code()) {
		_dtrow.set(name, std::uint64_t(v.get<std::int64_t>()));
	}
}
