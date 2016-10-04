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

	std::string s1 = "add_string_rows: value 1";
	row1.set<std::string>("value", s1);
	const std::string &s2 = row1.get<std::string>("value");
	ASSERT_EQ(s2, "add_string_rows: value 1");
	ASSERT_EQ(s1, s2);
}
