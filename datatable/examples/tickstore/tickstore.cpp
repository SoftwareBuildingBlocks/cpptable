#include <iostream>
#include <fstream>
#include <cstdint>
#include <sstream>

#include <data_table\data_table.h>


int main(int argc, char **argv)
{
	std::string storeFile = argv[1];

	try {
		std::ifstream storeStream;

		storeStream.open(storeFile, std::ios::in);
		if (!storeStream)
			throw(std::runtime_error("failed to open file"));

		std::uint32_t seconds { 0 };
		std::uint32_t usecs { 0 };
		std::string source;
		std::string side;
		double price { 0.0 };
		double size { 0.0 };

		dt::data_table ticks {
			dt::data_table_columns {
				dt::data_table_column<std::uint32_t>("seconds"),
				dt::data_table_column<std::uint32_t>("usecs"),
				dt::data_table_column<std::string>("source"),
				dt::data_table_column<std::string>("side"),
				dt::data_table_column<double>("price"),
				dt::data_table_column<double>("size")
			}
		};

		std::cout << "loading ticks..." << std::endl;
		while (storeStream >> seconds >> usecs >> source >> side >> price >> size) {
			dt::data_table_row row = ticks.new_row();
			row.set(0, seconds);
			row.set(1, usecs);
			row.set(2, source);
			row.set(3, side);
			row.set(4, price);
			row.set(5, size);
		}
		std::cout << "loading ticks complete" << std::endl;

		std::string filter = argv[2];
		std::cout << "running filter: " << filter << std::endl;
		for (auto itr : ticks.where(filter)) {
			std::cout << itr.get<std::uint32_t>(0) << ", "
					  << itr.get<std::uint32_t>(1) << ", "
					  << itr.get<dt::dt_char_ptr>(2) << ", "
					  << itr.get<dt::dt_char_ptr>(3) << ", "
					  << itr.get<double>(4) << ", "
					  << itr.get<double>(5)
					  << std::endl;
		}
		std::cout << "filtering complete" << std::endl;

		storeStream.close();
	}
	catch (std::exception &e) {
		std::cout << e.what();
	}

	return(0);
}