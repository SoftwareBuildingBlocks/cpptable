#include <gtest/gtest.h>
#include "../src/row_buffer.h"

/////////////////////////////////////////////////////////////////////
// TESTS

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


TEST(row_buffer_tests, get_add_string_values)
{
	dt::data_table_columns columns {
		dt::data_table_column<std::int32_t>("column_0"),
		dt::data_table_column<std::string>("column_1")
	};

	dt::row_buffer buffer { columns };

	buffer.set<std::string>(0, 1, "get_add_string_values: test string 1");
	std::string s1 = buffer.get<dt::dt_char_ptr>(0, 1);
	ASSERT_EQ(s1, "get_add_string_values: test string 1");

	buffer.set<std::string>(1, "column_1", "get_add_string_values: test string 2");
	std::string s2 = buffer.get<dt::dt_char_ptr>(1, 1);
	ASSERT_EQ(s2, "get_add_string_values: test string 2");
}
