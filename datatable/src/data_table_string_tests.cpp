#include <gtest/gtest.h>
#include <data_table/data_table.h>


/////////////////////////////////////////////////////////////////////
// TESTS

TEST(data_table_tests, add_string_rows)
{
	dt::data_table_columns columns {
		dt::data_table_column<std::uint32_t>("id"),
		dt::data_table_column<std::string>("value"),
		dt::data_table_column<std::uint64_t>("timestamp")
	};

	dt::data_table table { columns };

	ASSERT_EQ(table.columns().size(), columns.size());

	dt::data_table_row row1 = table.rows().add();

	row1.set<std::string>("value", "add_string_rows: value 1");
	dt::dt_char_ptr p1 = row1.get<dt::dt_char_ptr>("value");
	// TODO: user strcmp to verify p1 is "add_string_rows: value 1"
	std::string s1 = row1.get<dt::dt_char_ptr>("value");
	ASSERT_EQ(s1, "add_string_rows: value 1");
	ASSERT_NE(s1.c_str(), p1);
}
