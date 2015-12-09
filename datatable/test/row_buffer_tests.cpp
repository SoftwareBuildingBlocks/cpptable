#include <gtest/gtest.h>
#include <data_table/row_buffer.h>


TEST(row_buffer_tests, enure_the_columns_can_be_found_by_name)
{
	dt::data_table_columns columns {
		dt::data_table_column<std::int32_t>("column_0"),
		dt::data_table_column<std::int32_t>("column_1"),
		dt::data_table_column<std::int32_t>("column_2"),
		dt::data_table_column<std::int32_t>("column_3"),
		dt::data_table_column<std::int32_t>("column_4"),
		dt::data_table_column<std::int32_t>("column_5"),
		dt::data_table_column<std::int32_t>("column_6"),
		dt::data_table_column<std::int32_t>("column_7"),
		dt::data_table_column<std::int32_t>("column_8"),
		dt::data_table_column<std::int32_t>("column_9")
	};

	dt::row_buffer buffer { columns };
	for (std::size_t i = 0; i < columns.size(); i++) {
		ASSERT_EQ(buffer.column_index(columns[i].name()), i);
	}
}


TEST(row_buffer_tests, get_out_of_range)
{
	dt::data_table_columns columns{
		dt::data_table_column<std::int32_t>("column_0"),
		dt::data_table_column<std::int32_t>("column_1")
	};

	dt::row_buffer buffer { columns };

	ASSERT_THROW(buffer.get<std::int32_t>(10, "column_0"), std::out_of_range);
}