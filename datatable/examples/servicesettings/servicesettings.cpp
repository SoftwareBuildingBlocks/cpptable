// servicesettings.cpp : Defines the entry point for the console application.
//
// zipquery.cpp : Defines the entry point for the console application.
//


#include <iostream>
#include <cstdint>
#include <sstream>

#include "data_table/data_table.h"
#include "csv.h"

#ifdef _WIN32
#include <direct.h>
#else
#include <unistd.h>
#endif // _WIN32

void print_columns(dt::data_table& table);
dt::data_table create_datatable();
void load_from_csv(const std::string& fileName, dt::data_table& table);

int main(int argc, char **argv)
{
	std::string storeFile = argc > 1 ? argv[1] : "config.csv";

	char dir[1024];
	getcwd(dir, 1024);
	std::cout << dir << std::endl;

	try
	{
		auto cfg_table = create_datatable();
		load_from_csv(storeFile, cfg_table);

		print_columns(cfg_table);

		// Mark
		std::string filter = "true";

		std::cout << std::endl;

		for (auto itr : cfg_table.where(filter))
		{
			size_t col = 0;
			bool val = itr.is_null(col);
		}
		print_columns(cfg_table);

	}
	catch (std::exception &e)
	{
		std::cout << e.what();
	}

	return(0);
}

void print_columns(dt::data_table& table)
{
	std::cout << "Query Columns:  ";
	std::for_each(table.columns().begin(), table.columns().end(),
				  [](dt::basic_data_column& col) { std::cout << col.name() << " "; });
	std::cout << std::endl << std::endl;
}

dt::data_table create_datatable()
{
	dt::data_table cfg_table{
		dt::data_table_columns{
		dt::data_table_column<std::string>("service"),
		dt::data_table_column<std::string>("instance"),
		dt::data_table_column<std::string>("partition"),
		dt::data_table_column<std::string>("name"),
		dt::data_table_column<std::string>("value")
	}
	};

	return cfg_table;
}

void load_from_csv(const std::string& fileName, dt::data_table& table)
{
	io::CSVReader<5> in_csv(fileName);

	// load header
	in_csv.read_header(io::ignore_extra_column,
					   "Service","Instance","Partition","Name","Value");

	std::string service;
	std::string instance;
	std::string partition;
	std::string name;
	std::string value;

	std::cout << std::endl << "Loading configuration..." << std::endl;

	while (in_csv.read_row(service,instance,partition,name,value))
	{
		auto row = table.new_row();
		if (!service.empty()) row.set(0, service);
		if (!instance.empty()) row.set(1, instance);
		if (!partition.empty()) row.set(2, partition);
		if (!name.empty()) row.set(3, name);
		if (!value.empty()) row.set(4, value);
	}

	std::cout << table.rows().size() << " rows loaded." << std::endl << std::endl;
}


