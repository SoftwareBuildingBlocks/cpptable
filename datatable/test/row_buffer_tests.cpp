#include <gtest/gtest.h>
#include <data_table/row_buffer.h>

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


TEST(row_buffer_tests, is_null)
{
	dt::data_table_columns columns {
		dt::data_table_column<std::int32_t>("column_0"),
		dt::data_table_column<std::int32_t>("column_1"),
		dt::data_table_column<std::int32_t>("column_2"),
		dt::data_table_column<std::string>("column_3")
	};

	dt::row_buffer buffer { columns };

	buffer.set<std::int32_t>(0, 0, 33);
	std::int32_t v1 = buffer.get<std::int32_t>(0, 0);
	ASSERT_EQ(v1, 33);

	buffer.set<std::int32_t>(0, 1, 44);
	std::int32_t v2 = buffer.get<std::int32_t>(0, 1);
	ASSERT_EQ(v2, 44);

	ASSERT_FALSE(buffer.is_null(0, 0));
	ASSERT_FALSE(buffer.is_null(0, 1));
	ASSERT_TRUE(buffer.is_null(0, 2));

	buffer.set<std::string>(0, 3, "int_is_null: row 0, column 3");
	std::string s1 = buffer.get<dt::dt_char_ptr>(0, 3);
	ASSERT_FALSE(buffer.is_null(0, 3));
	ASSERT_EQ(s1, "int_is_null: row 0, column 3");
}


TEST(row_buffer_tests, clear_null)
{
	dt::data_table_columns columns {
		dt::data_table_column<std::int32_t>("column_0"),
		dt::data_table_column<std::int32_t>("column_1"),
		dt::data_table_column<std::int32_t>("column_2"),
		dt::data_table_column<std::string>("column_3")
	};

	dt::row_buffer buffer {columns};

	buffer.set<std::int32_t>(0, 0, 33);
	std::int32_t v1 = buffer.get<std::int32_t>(0, 0);
	ASSERT_EQ(v1, 33);

	buffer.set<std::int32_t>(0, 1, 44);
	std::int32_t v2 = buffer.get<std::int32_t>(0, 1);
	ASSERT_EQ(v2, 44);

	ASSERT_FALSE(buffer.is_null(0, 0));
	buffer.clear<std::int32_t>(0, 0);
	ASSERT_TRUE(buffer.is_null(0, 0));

	ASSERT_FALSE(buffer.is_null(0, 1));
	buffer.clear<std::int32_t>(0, 1);
	ASSERT_TRUE(buffer.is_null(0, 1));

	ASSERT_TRUE(buffer.is_null(0, 2));

	buffer.set<std::string>(0, 3, "int_is_null: row 0, column 3");
	std::string s1 = buffer.get<dt::dt_char_ptr>(0, 3);
	ASSERT_FALSE(buffer.is_null(0, 3));
	ASSERT_EQ(s1, "int_is_null: row 0, column 3");
	buffer.clear<dt::dt_char_ptr>(0, 3);
	ASSERT_TRUE(buffer.is_null(0, 3));
}
