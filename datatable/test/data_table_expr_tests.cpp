#include <gtest/gtest.h>
#include "../src/data_table.h"

// reduce verbosity
using namespace dt;
using namespace std;

data_table populate_test_data();

TEST(data_table_expr_tests, simple)
{
	auto table = populate_test_data();

	// expression to search for
	string expr = "age = 43 and (income > 0 and income <= 1000000)";

	auto num_rows_found = 0;
	// get rows that match expression
	for (auto r : table.where(expr))
	{
		num_rows_found++;

		int32_t age = r.get<int32_t>("age");
		ASSERT_EQ(age, 43);

		int64_t income = r.get<int64_t>("income");
		ASSERT_TRUE(income > 0);
		ASSERT_TRUE(income <= 1000000);
	}

	ASSERT_EQ(num_rows_found, 1);
}

dt::data_table populate_test_data()
{
	// reduce verbosity
	using columns = data_table_columns;
	using int_col = data_table_column<int32_t>;
	using long_col = data_table_column<int64_t>;

	// define columns for data table
	columns cols{
		int_col("age"),
		long_col("income"),
		long_col("soc")
	};

	// define table
	data_table table{ cols };

	// fill in the rows
	{
		auto row = table.new_row();
		row.set("age", 43);
		row.set("income", 1000000LL);
		row.set("soc", 123456789LL);
	}
	{
		auto row = table.new_row();
		row.set("age", 44);
		row.set("income", 2000000LL);
		row.set("soc", 321456789LL);
	}
	{
		auto row = table.new_row();
		row.set("age", 45);
		row.set("income", 3000000LL);
		row.set("soc", 432156789LL);
	}

	return table;
}
