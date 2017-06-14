// zipquery.cpp : Defines the entry point for the console application.
//


#include <iostream>
#include <sstream>

#include <data_table/data_table.h>
#include "csv.h"

#ifdef _WIN32
#include <direct.h>
#else
#include <unistd.h>
#endif // _WIN32

void print_columns(dt::data_table& table);
dt::data_table create_datatable();
void load_from_csv(const std::string& fileName, dt::data_table& table);
void print_examples();

void print_curr_dir();

int main(int argc, char **argv)
{
	std::string storeFile = argc > 1 ? argv[1] : "zip.csv";

	print_curr_dir();

	try
	{
		dt::data_table zip_table = create_datatable();
		load_from_csv(storeFile, zip_table);

		print_examples();

		print_columns(zip_table);

		while (true)
		{
			std::cout << "ZIP> ";

			std::string filter;
			getline(std::cin, filter);

			std::cout << std::endl;

			auto row_count = 0;
			try
			{
				for (auto itr : zip_table.where(filter))
				{
					std::cout << ++row_count << ", " << itr.get<std::uint32_t>(0) << ", "
						<< itr.get<std::string>(1) << ", "
						<< itr.get<std::string>(2) << ", "
						<< itr.get<std::string>(3) << ", "
						<< itr.get<std::string>(4) << ", "
						<< itr.get<double>(5) << ", "
						<< itr.get<double>(6)
						<< std::endl;
				}
			}
			catch (const std::runtime_error& err)
			{
				std::cout << "Error: " << err.what() << std::endl;
			}			
			
			std::cout << "Found " << row_count << " rows." << std::endl << std::endl;
			print_columns(zip_table);
		}
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
	dt::data_table zip_table{
		dt::data_table_columns{
		dt::data_table_column<std::uint32_t>("zip"),
		dt::data_table_column<std::string>("city"),
		dt::data_table_column<std::string>("state"),
		dt::data_table_column<std::string>("state_code"),
		dt::data_table_column<std::string>("county"),
		dt::data_table_column<double>("latitude"),
		dt::data_table_column<double>("longitude")
	}
	};

	return zip_table;
}

void load_from_csv(const std::string& fileName, dt::data_table& table)
{
	io::CSVReader<7> in_csv(fileName);

	// load header
	in_csv.read_header(io::ignore_extra_column,
					   "Postal Code", "Place Name", "State", "State Abbreviation", "County", "Latitude", "Longitude");

	std::uint32_t zip{ 0 };
	std::string city;
	std::string state;
	std::string state_code;
	std::string county;
	auto latitude{ 0.0 };
	auto longitude{ 0.0 };

	std::cout << std::endl << "Loading zip codes..." << std::endl;

	while (in_csv.read_row(zip, city, state, state_code, county, latitude, longitude))
	{
		dt::data_table_row row = table.new_row();
		row.set(0, zip);
		row.set(1, city);
		row.set(2, state);
		row.set(3, state_code);
		row.set(4, county);
		row.set(5, latitude);
		row.set(6, longitude);
	}

	std::cout << table.rows().size() << " rows loaded." << std::endl << std::endl;
}

void print_examples()
{
	std::cout << "Example:" << std::endl;
	std::cout << "\tzip = 10583" << std::endl;
	std::cout << "\tstate = 'New York' and county = 'Westchester'" << std::endl << std::endl;
}

void print_curr_dir()
{
	char dir[1024];
	getcwd(dir, 1024);
	std::cout << "Searching " << dir << std::endl;
}
