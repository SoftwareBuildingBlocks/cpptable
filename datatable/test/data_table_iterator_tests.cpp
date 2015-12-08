#include <gtest/gtest.h>
#include "../src/data_table.h"
#include <algorithm>


static void PopulateTable(dt::data_table &table, std::uint32_t count)
{
	for (std::uint32_t i = 0; i < count; i++) {
		dt::data_table_row row = table.new_row();

		std::uint32_t id = i + 1;
		row.set("id", id);

		std::uint64_t value = (i + 1) * 100;
		row.set("value", value);

		std::uint64_t timestamp = i;
		row.set("timestamp", timestamp);
	}
}


TEST(data_table_iterator_tests, iterate_10_rows)
{
	dt::data_table_columns columns {
		dt::data_table_column<std::int32_t>("id"),
		dt::data_table_column<std::int64_t>("value"),
		dt::data_table_column<std::int64_t>("timestamp")
	};

	dt::data_table table {columns};

	std::uint32_t target_rows = 10;
	PopulateTable(table, target_rows);

	std::uint32_t i = 1;
	for (auto r : table) {
		std::uint32_t id = r.get<std::uint32_t>("id");
		ASSERT_EQ(id, i++);
	}
	ASSERT_EQ(target_rows, i - 1);
}


TEST(data_table_iterator_tests, iterate_find_if_value_equals_500)
{
	dt::data_table_columns columns {
		dt::data_table_column<std::int32_t>("id"),
		dt::data_table_column<std::int64_t>("value"),
		dt::data_table_column<std::int64_t>("timestamp")
	};

	dt::data_table table {columns};

	PopulateTable(table, 10);

	auto itr = std::find_if(table.begin(), table.end(), [](const dt::data_table::row_type &r) {
		return(r.get<std::uint32_t>("value") == 500);
	});

	ASSERT_EQ(itr->get<std::uint32_t>("value"), 500);
}
