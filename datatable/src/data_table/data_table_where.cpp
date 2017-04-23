#include <string>
#include <data_table/data_table.h>
#include "expr.h"
#include "expr_compiler.h"
#include "expr_datarow_adapter.h"


namespace dt
{
	data_table::where_iterator data_table::where(const std::string& where_clause)
	{
		expr_compiler ec;
		ec.init();
		auto e = ec.compile(where_clause);
		std::vector<where_iterator::difference_type> sel_rows;

		for (auto i = 0; i < m_rows.size(); i++)
		{
			auto row = m_rows.row(i);
			expr_datarow_adapter arow(row,m_columns);
			if (e.eval(arow))
				sel_rows.push_back(i);
		}

		return data_table::where_iterator(m_rows, 0, sel_rows);
	}
}
