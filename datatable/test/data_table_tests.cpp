#include <gtest/gtest.h>
#include <data_table/data_table.h>
#include <random>


/////////////////////////////////////////////////////////////////////
// TEST HELPERS

static void populate_table(dt::data_table &table, std::uint32_t count)
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


static void populate_table_in_reverse(dt::data_table &table, std::uint32_t count)
{
	for (std::uint32_t i = count; i > 0; i--) {
		dt::data_table_row row = table.new_row();

		std::uint32_t id = i - 1;
		row.set("id", id);

		std::uint64_t value = (i - 1) * 100;
		row.set("value", value);

		std::uint64_t timestamp = count - i + 1;
		row.set("timestamp", timestamp);
	}
}


static void populate_table_random(dt::data_table &table, std::uint32_t count)
{
	for (std::uint32_t i = 0; i < count; i++) {
		dt::data_table_row row = table.new_row();

		std::uint32_t v = static_cast<std::uint32_t>(std::rand());
		std::uint32_t id = v;
		row.set("id", id);

		std::uint64_t value = (v + 1) * 100;
		row.set("value", value);

		std::uint64_t timestamp = i;
		row.set("timestamp", timestamp);
	}
}


static void dump_rows(dt::data_table &table)
{
	std::cout << "Start => Dump Rows***********************" << std::endl;
	for (auto r : table) {
		std::cout << r.row_num() << ", " << r.get<std::uint32_t>("id") << ", " << r.get<std::uint64_t>("value") << ", " << r.get<std::uint64_t>("timestamp") << std::endl;
	}
	std::cout << "End   => Dump Rows***********************" << std::endl;
}


template<typename T>
void verify_sort_ascending(dt::data_table &table, const std::string &col)
{
	T last = std::numeric_limits<T>::min();
	for (auto &r : table) {
		T v = r.get<T>(col);
		ASSERT_GE(v, last);
		last = v;
	}
}


/////////////////////////////////////////////////////////////////////
// TESTS

TEST(data_table_tests, add_2000_rows)
{
	dt::data_table_columns columns {
		dt::data_table_column<std::uint32_t>("id"),
		dt::data_table_column<std::uint64_t>("value"),
		dt::data_table_column<std::uint64_t>("timestamp")
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

		ASSERT_EQ(row.get<std::uint32_t>(0), id);
		ASSERT_EQ(row.get<std::uint64_t>(1), value);
		ASSERT_EQ(row.get<std::uint64_t>(2), timestamp);

		ASSERT_EQ(row.get<std::uint32_t>("id"), id);
		ASSERT_EQ(row.get<std::uint64_t>("value"), value);
		ASSERT_EQ(row.get<std::uint64_t>("timestamp"), timestamp);
	}

	auto rows = table.rows();
	ASSERT_EQ(rows.size(), max_rows);

	for (std::uint32_t i = 0; i < max_rows; i++) {
		std::uint32_t id = i + 1;
		std::uint64_t value = (i + 1) * 100;
		std::uint64_t timestamp = i;

		auto row = rows.row(i);

		ASSERT_EQ(row.get<std::uint32_t>(0), id);
		ASSERT_EQ(row.get<std::uint64_t>(1), value);
		ASSERT_EQ(row.get<std::uint64_t>(2), timestamp);

		ASSERT_EQ(row.get<std::uint32_t>("id"), id);
		ASSERT_EQ(row.get<std::uint64_t>("value"), value);
		ASSERT_EQ(row.get<std::uint64_t>("timestamp"), timestamp);
	}
}


TEST(data_table_tests, swap_test)
{
	dt::data_table table {
		dt::data_table_columns {
			dt::data_table_column<std::uint32_t>("id"),
			dt::data_table_column<std::uint64_t>("value"),
			dt::data_table_column<std::uint64_t>("timestamp")
		}
	};

	populate_table(table, 10);
	table.swap(0, 9);

	ASSERT_EQ(table.row(0).get<std::uint32_t>(0), 10);
	ASSERT_EQ(table.row(0).get<std::uint64_t>(1), 1000);
	ASSERT_EQ(table.row(0).get<std::uint64_t>(2), 9);

	ASSERT_EQ(table.row(9).get<std::uint32_t>(0), 1);
	ASSERT_EQ(table.row(9).get<std::uint64_t>(1), 100);
	ASSERT_EQ(table.row(9).get<std::uint64_t>(2), 0);
}


TEST(data_table_tests, sort_10_random_test)
{
	dt::data_table table {
		dt::data_table_columns {
			dt::data_table_column<std::uint32_t>("id"),
			dt::data_table_column<std::uint64_t>("value"),
			dt::data_table_column<std::uint64_t>("timestamp")
		}
	};

	populate_table_random(table, 10);

	dt::sort(table, [](dt::data_table::iterator::value_type &l, dt::data_table::iterator::value_type &r) {
		return(l.get<std::uint32_t>("id") < r.get<std::uint32_t>("id"));
	});

	verify_sort_ascending<std::uint32_t>(table, "id");
}


TEST(data_table_tests, sort_30_random_test)
{
	dt::data_table table {
		dt::data_table_columns {
			dt::data_table_column<std::uint32_t>("id"),
			dt::data_table_column<std::uint64_t>("value"),
			dt::data_table_column<std::uint64_t>("timestamp")
		}
	};

	populate_table_random(table, 30);

	dt::sort(table, [](dt::data_table::iterator::value_type &l, dt::data_table::iterator::value_type &r) {
		return(l.get<std::uint32_t>("id") < r.get<std::uint32_t>("id"));
	});

	verify_sort_ascending<std::uint32_t>(table, "id");
}


TEST(data_table_tests, sort_30_descending_input_test)
{
	dt::data_table table {
		dt::data_table_columns {
			dt::data_table_column<std::uint32_t>("id"),
			dt::data_table_column<std::uint64_t>("value"),
			dt::data_table_column<std::uint64_t>("timestamp")
		}
	};

	populate_table_in_reverse(table, 30);

	dt::sort(table, [](dt::data_table::iterator::value_type &l, dt::data_table::iterator::value_type &r) {
		return(l.get<std::uint32_t>("id") < r.get<std::uint32_t>("id"));
	});

	verify_sort_ascending<std::uint32_t>(table, "id");
}


TEST(data_table_tests, sort_3000_random_input_test)
{
	dt::data_table table {
		dt::data_table_columns {
			dt::data_table_column<std::uint32_t>("id"),
			dt::data_table_column<std::uint64_t>("value"),
			dt::data_table_column<std::uint64_t>("timestamp")
		}
	};

	populate_table_random(table, 3000);

	dt::sort(table, [](dt::data_table::iterator::value_type &l, dt::data_table::iterator::value_type &r) {
		return(l.get<std::uint32_t>("id") < r.get<std::uint32_t>("id"));
	});

	verify_sort_ascending<std::uint32_t>(table, "id");
}


TEST(data_table_tests, sort_30_acending_input_test)
{
	dt::data_table table {
		dt::data_table_columns {
			dt::data_table_column<std::uint32_t>("id"),
			dt::data_table_column<std::uint64_t>("value"),
			dt::data_table_column<std::uint64_t>("timestamp")
		}
	};

	populate_table(table, 30);

	dt::sort(table, [](dt::data_table::iterator::value_type &l, dt::data_table::iterator::value_type &r) {
		return(l.get<std::uint32_t>("id") < r.get<std::uint32_t>("id"));
	});

	verify_sort_ascending<std::uint32_t>(table, "id");
}


TEST(data_table_tests, binary_search_after_sort_3000_random_input_test)
{
	dt::data_table table {
		dt::data_table_columns {
			dt::data_table_column<std::uint32_t>("id"),
			dt::data_table_column<std::uint64_t>("value"),
			dt::data_table_column<std::uint64_t>("timestamp")
		}
	};

	populate_table_random(table, 3000);

	dt::sort(table, [](dt::data_table::iterator::value_type &l, dt::data_table::iterator::value_type &r) {
		return(l.get<std::uint32_t>("id") < r.get<std::uint32_t>("id"));
	});

	for (auto &r : table) {
		bool found = std::binary_search(table.begin(), table.end(), r, [](const dt::data_table::iterator::value_type &l, const dt::data_table::iterator::value_type &r) {
			return(l.get<std::uint32_t>("id") < r.get<std::uint32_t>("id"));
		});

		ASSERT_TRUE(found) << "unable to find " << r.get<std::uint32_t>("id");
	}
}
