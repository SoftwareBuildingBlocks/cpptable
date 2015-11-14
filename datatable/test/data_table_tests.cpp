#include <gtest/gtest.h>
#include <data_table/data_table.h>


TEST(data_table_tests, add_2000_rows)
{
	dt::data_table_columns columns {
		dt::data_table_column<std::int32_t>("id"),
		dt::data_table_column<std::int64_t>("value"),
		dt::data_table_column<std::int64_t>("timestamp")
	};

	dt::data_table table { columns };

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