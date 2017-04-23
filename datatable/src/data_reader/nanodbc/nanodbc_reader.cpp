#include <vector>
#include <functional>
#include <tuple>
#include <data_table/data_table.h>
#include <nanodbc.h>

#ifdef _WIN32
	#define NOMINMAX
	#include <windows.h>
#endif
#include <sql.h>
#include <sqlext.h>


namespace dt
{
	using mapper_type = std::tuple<dt::basic_data_column, std::function<void (short, nanodbc::result&, dt::data_table_row&)>>;
	using mapper = std::vector<mapper_type>;

	template<typename T>
	static void copy_from(short col, nanodbc::result &from, data_table_row &to)
	{
		to.set(col, from.get<T>(col));
	}


	template<typename T, typename U = T>
	static mapper_type map_to(const std::string &name)
	{
		return(mapper_type { dt::data_table_column<T>(name), copy_from<U> });
	}


	static mapper_type create_mapper_entry(const std::string &name, short c_type)
	{
		switch (c_type) {
			case SQL_C_LONG:
				return(map_to<std::int32_t>(name));
			case SQL_C_SBIGINT:
				return(map_to<std::int64_t>(name));
			case SQL_C_DOUBLE:
				return(map_to<double>(name));
			case SQL_C_DATE:
				return(map_to<nanodbc::date>(name));
			case SQL_C_TIMESTAMP:
				return(map_to<nanodbc::timestamp>(name));
			case SQL_C_CHAR:
				return(map_to<std::string>(name));
			//case SQL_C_WCHAR: 
			//	return(map_to<std::wstring>(name));
			default:
				throw std::runtime_error("cannot map type " + std::to_string(c_type) + " for column " + name);
		}
	}

	static mapper build_columns(nanodbc::result &from, dt::data_table &to)
	{
		dt::data_table_columns columns;
		mapper m;
		for (int i = 0; i < from.columns(); i++) {
			mapper_type mt = create_mapper_entry(from.column_name(i), from.column_c_datatype(i));
			m.emplace_back(mt);
			columns.emplace_back(std::get<0>(mt));
		}
		to = dt::data_table{ columns };
		return(m);
	}

	void fill(nanodbc::result &from, dt::data_table &to)
	{
		auto mapper = build_columns(from, to);
		while (from.next()) {
			auto tr = to.new_row();
			for (short c = 0; c < from.columns(); c++) {
				std::get<1>(mapper[c])(c, from, tr);
			}
		}
	}
}