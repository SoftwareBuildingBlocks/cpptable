#include <gtest/gtest.h>
#include <data_table/data_table.h>

// reduce verbosity
using namespace dt;
using namespace std;

data_table populate_test_data();

///
/// @brief      Simple expression test
///				age = 43 and (income > 0 and income <= 1000000)
///
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

///
/// @brief      Expression test with string variables
///				"name = 'bose'"
///
TEST(data_table_expr_tests, string_test)
{
	auto table = populate_test_data();

	// expression to search for
	string expr = "name = 'bose'";

	auto num_rows_found = 0;
	// get rows that match expression
	for (auto r : table.where(expr))
	{
		num_rows_found++;

		string name = r.get<dt_char_ptr>("name");
		ASSERT_EQ(name, "bose");
	}

	ASSERT_EQ(num_rows_found, 1);
}

///
/// @brief      Populate a datatable for the tests
///
dt::data_table populate_test_data()
{
	// reduce verbosity
	using columns = data_table_columns;
	using int_col = data_table_column<int32_t>;
	using long_col = data_table_column<int64_t>;
	using string_col = data_table_column<string>;
	using char_col = data_table_column<char>;

	// define columns for data table
	columns cols{
		int_col("age"),
		long_col("income"),
		long_col("soc"),
		string_col("name"),
		char_col("initial")
	};

	// define table
	data_table table{ cols };

	// fill in the rows
	{
		auto row = table.new_row();
		row.set("age", 43);
		row.set("income", 1000000LL);
		row.set("soc", 123456789LL);
		row.set<string>("name", "charlie");
		row.set<char>("initial", 'A');
	}
	{
		auto row = table.new_row();
		row.set("age", 44);
		row.set("income", 2000000LL);
		row.set("soc", 321456789LL);
		row.set<string>("name", "judy");
		row.set<char>("initial", 'B');
	}
	{
		auto row = table.new_row();
		row.set("age", 45);
		row.set("income", 3000000LL);
		row.set("soc", 432156789LL);
		row.set<string>("name", "bose");
		row.set<char>("initial", 'C');
	}

	return table;
}
