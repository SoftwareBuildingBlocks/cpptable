```cpp
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
```