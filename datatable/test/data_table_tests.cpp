#include <gtest/gtest.h>
#include "../src/data_table.h"


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


static void DumpRows(dt::data_table &table)
{
	std::cout << "Start => Dump Rows***********************" << std::endl;
	for (auto r : table) {
		std::cout << r.row_num() << ", " << r.get<std::uint32_t>("id") << ", " << r.get<std::uint64_t>("value") << ", " << r.get<std::uint64_t>("timestamp") << std::endl;
	}
	std::cout << "End   => Dump Rows***********************" << std::endl;
}


TEST(data_table_tests, add_2000_rows)
{
	dt::data_table_columns columns {
		dt::data_table_column<std::int32_t>("id"),
		dt::data_table_column<std::int64_t>("value"),
		dt::data_table_column<std::int64_t>("timestamp")
	};

	dt::data_table table {columns};

	ASSERT_EQ(table.columns().size(), columns.size());

	const std::uint32_t max_rows = 2000;
	for (std::uint32_t i = 0; i < max_rows; i++) {
		dt::data_table_row row = table.new_row();

		std::uint32_t id = i + 1;
		row.set("id", id);

		std::uint64_t value = (i + 1) * 100;
		row.set("value", value);

		std::uint64_t timestamp = i;
		row.set("timestamp", timestamp);

		ASSERT_EQ(row.get<std::int32_t>(0), id);
		ASSERT_EQ(row.get<std::int64_t>(1), value);
		ASSERT_EQ(row.get<std::int64_t>(2), timestamp);

		ASSERT_EQ(row.get<std::int32_t>("id"), id);
		ASSERT_EQ(row.get<std::int64_t>("value"), value);
		ASSERT_EQ(row.get<std::int64_t>("timestamp"), timestamp);
	}

	auto rows = table.rows();
	ASSERT_EQ(rows.size(), max_rows);

	for (std::uint32_t i = 0; i < max_rows; i++) {
		std::uint32_t id = i + 1;
		std::uint64_t value = (i + 1) * 100;
		std::uint64_t timestamp = i;

		auto row = rows.row(i);

		ASSERT_EQ(row.get<std::int32_t>(0), id);
		ASSERT_EQ(row.get<std::int64_t>(1), value);
		ASSERT_EQ(row.get<std::int64_t>(2), timestamp);

		ASSERT_EQ(row.get<std::int32_t>("id"), id);
		ASSERT_EQ(row.get<std::int64_t>("value"), value);
		ASSERT_EQ(row.get<std::int64_t>("timestamp"), timestamp);
	}
}


TEST(data_table_tests, swap_test)
{
	dt::data_table table {
		dt::data_table_columns {
			dt::data_table_column<std::int32_t>("id"),
			dt::data_table_column<std::int64_t>("value"),
			dt::data_table_column<std::int64_t>("timestamp")
		}
	};

	PopulateTable(table, 10);
	table.swap(0, 9);

	ASSERT_EQ(table.row(0).get<std::uint32_t>(0), 10);
	ASSERT_EQ(table.row(0).get<std::uint64_t>(1), 1000);
	ASSERT_EQ(table.row(0).get<std::uint64_t>(2), 9);

	ASSERT_EQ(table.row(9).get<std::uint32_t>(0), 1);
	ASSERT_EQ(table.row(9).get<std::uint64_t>(1), 100);
	ASSERT_EQ(table.row(9).get<std::uint64_t>(2), 0);
}
