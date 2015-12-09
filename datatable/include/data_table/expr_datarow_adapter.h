#include "data_row.h"
#include "result.h"

class expr_datarow_adapter : public idata_row
{
public:
	expr_datarow_adapter(dt::data_table_row& dtrow, dt::data_table_columns& cols);
	~expr_datarow_adapter(){}
	val operator[](const std::string& name) override;
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

inline val expr_datarow_adapter::operator[](const std::string& name)
{
	switch (_map_colname_type[name])
	{
		case dt::tid_int8:
		{
			auto v = _dtrow.get<std::int8_t>(name);
			return val().set<std::int64_t>(v);
		}

		case dt::tid_uint8 :
		{
			auto v = _dtrow.get<std::uint8_t>(name);
			return val().set<std::int64_t>(v);
		}

		case dt::tid_int16 :
		{
			auto v = _dtrow.get<std::int16_t>(name);
			return val().set<std::int64_t>(v);
		}

		case dt::tid_uint16 :
		{
			auto v = _dtrow.get<std::uint16_t>(name);
			return val().set<std::int64_t>(v);
		}

		case dt::tid_int32 :
		{
			auto v = _dtrow.get<std::int32_t>(name);
			return val().set<std::int64_t>(v);
		}

		case dt::tid_uint32 :
		{
			auto v = _dtrow.get<std::uint32_t>(name);
			return val().set<std::int64_t>(v);
		}

		case dt::tid_int64 :
		{
			auto v = _dtrow.get<std::int64_t>(name);
			return val().set<std::int64_t>(v);
		}

		case dt::tid_uint64 :
		{
			auto v = _dtrow.get<std::uint64_t>(name);
			return val().set<std::int64_t>(v);
		}

		default:
			return val();
	}
}
