```cpp
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
```