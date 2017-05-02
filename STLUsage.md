```cpp
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
```