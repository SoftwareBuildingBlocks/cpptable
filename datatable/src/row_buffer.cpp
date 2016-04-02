#include <algorithm>
#include <data_table/row_buffer.h>


namespace dt
{
	row_buffer::row_buffer(const data_table_columns &columns) :
		m_rows_per_extent { 100 },
		m_row_count { 0 }
	{
		for (size_t i = 0; i < columns.size(); i++) {
			// TODO: need to include alignment
			// TODO: create a new memory block for each column
			const data_table_columns::value_type& desc = columns[i];
			m_column_extents.emplace_back(i, desc.type(), desc.size(), m_rows_per_extent);
			m_name_to_ordinal.emplace(desc.name(), i);
		}
	}


	std::uint64_t row_buffer::add()
	{
		std::uint64_t row = m_row_count;
		m_row_count++;
		return(row);
	}
}
