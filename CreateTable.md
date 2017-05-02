```cpp
    TEST(data_table_tests, create_table)
    {
        dt::data_table_columns columns {
            dt::data_table_column<std::int32_t>("id"),
            dt::data_table_column<std::int64_t>("value"),
            dt::data_table_column<std::int64_t>("timestamp")
        };
    
        dt::data_table table {columns};
        ASSERT_EQ(table.columns().size(), columns.size());
    }
```