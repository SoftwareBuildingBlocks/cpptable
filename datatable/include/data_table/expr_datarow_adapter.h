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
	std::map<std::string, std::uint32_t> _map_colname_type;
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
	switch (_map_colname_type[name])
	{
		case dt::tid_int8:
		{
			auto v = _dtrow.get<std::int8_t>(name);
			DBG(std::cout << " " << v << " ");
			return val().set<std::int64_t>(v);
		}

		case dt::tid_uint8 :
		{
			auto v = _dtrow.get<std::uint8_t>(name);
			DBG(std::cout << " " << v << " ");
			return val().set<std::int64_t>(v);
		}

		case dt::tid_int16 :
		{
			std::int64_t v = _dtrow.get<std::int16_t>(name);
			DBG(std::cout << " " << v << " ");
			return val().set<std::int64_t>(v);
		}

		case dt::tid_uint16 :
		{
			std::int64_t v = _dtrow.get<std::uint16_t>(name);
			DBG(std::cout << " " << v << " ");
			return val().set<std::int64_t>(v);
		}

		case dt::tid_int32 :
		{
			std::int64_t v = _dtrow.get<std::int32_t>(name);
			DBG(std::cout << " " << v << " ");
			return val().set<std::int64_t>(v);
		}

		case dt::tid_uint32 :
		{
			std::int64_t v = _dtrow.get<std::uint32_t>(name);
			DBG(std::cout << " " << v << " ");
			return val().set<std::int64_t>(v);
		}

		case dt::tid_int64 :
		{
			std::int64_t v = _dtrow.get<std::int64_t>(name);
			DBG(std::cout << " " << v << " ");
			return val().set<std::int64_t>(v);
		}

		case dt::tid_uint64 :
		{
			std::int64_t v = _dtrow.get<std::uint64_t>(name);
			DBG(std::cout << " " << v << " ");
			return val().set<std::int64_t>(v);
		}

		case dt::tid_char_ptr:
		{
			auto v = _dtrow.get<dt::dt_char_ptr>(name);
			DBG(std::cout << " " << v << " ");
			return val().set<std::string>(std::string(v));
		}

		case dt::tid_double:
		{
			std::double_t v = _dtrow.get<std::double_t>(name);
			DBG(std::cout << " " << v << " ");
			return val().set<std::double_t>(v);
		}

		default:
			return val();
	}
}

inline void expr_datarow_adapter::set(const std::string& name, val& v)
{
	switch (_map_colname_type[name])
	{
		case dt::tid_int8:
		{
			auto x = v.get<std::int64_t>();
			_dtrow.set(name, std::int8_t(v.get<std::int64_t>()));
		}

		case dt::tid_uint8:
		{
			_dtrow.set(name, std::uint8_t(v.get<std::int64_t>()));
		}

		case dt::tid_int16:
		{
			_dtrow.set(name, std::int16_t(v.get<std::int64_t>()));
		}

		case dt::tid_uint16:
		{
			_dtrow.set(name, std::uint16_t(v.get<std::int64_t>()));
		}

		case dt::tid_int32:
		{
			_dtrow.set(name, std::int32_t(v.get<std::int64_t>()));
		}

		case dt::tid_uint32:
		{
			_dtrow.set(name, std::uint32_t(v.get<std::int64_t>()));
		}

		case dt::tid_int64:
		{
			_dtrow.set(name, std::int64_t(v.get<std::int64_t>()));
		}

		case dt::tid_uint64:
		{
			_dtrow.set(name, std::uint64_t(v.get<std::int64_t>()));
		}
	}
}
