```cpp
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
```