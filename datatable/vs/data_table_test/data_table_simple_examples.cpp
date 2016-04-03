#include <gtest/gtest.h>
#include <data_table/data_table.h>

extern dt::data_table populate_test_data();

// reduce verbosity
using namespace dt;
using namespace std;

data_table populate_test_data();

TEST(data_table_examples, one)
{
	// reduce verbosity
	using columns = data_table_columns;
	using int_col = data_table_column<int32_t>;
	using long_col = data_table_column<int64_t>;
	using string_col = data_table_column<string>;

	// Define columns 
	columns cols{
		int_col("age"),
		long_col("income"),
		long_col("soc"),
		string_col("name")
	};

	// Define table
	data_table table{ cols };

	// Fill in the data 
	auto row = table.new_row();
	row.set("age", 25);
	row.set("income", 1000000LL);
	row.set("soc", 123456789LL);
	row.set<string>("name", "john");

	// Read data
	for (auto r : table)
	{
		cout << r.row_num() << ", " << r.get<uint32_t>("age") << ", ";
		cout << r.get<uint64_t>("income") << ", " << r.get<dt_char_ptr>("name") << std::endl;
	}

}

TEST(data_table_examples, two)
{
	// Helper method to define table and polulate it
	auto table = populate_test_data();

	// Runtime query against the table
	auto result = table.where("income > 100000");
	
	// Iterate through results
	for (auto it = result.begin(); it != result.end(); ++it)
	{
		cout << it->get<dt_char_ptr>("name") << "," << it->get<int32_t>("income") << endl;
	}
}
