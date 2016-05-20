///////////////////////////////////////////////////////////////////////////////
// tickstore
//
// load market bid/offer prices from a tab delimited file generated by the
// accompanying python script tickgen.py.
//
// see tickgen.py for notes are generating ticks.
//
// tickstore requires one command line parameter; the tick file as follows.
//
// > tickstore eurusd.ticks
//
#include <iostream>
#include <fstream>
#include <cstdint>
#include <sstream>
#include <chrono>
#include <iomanip>

#include <data_table\data_table.h>

const std::string g_timeFormat = "%Y-%m-%d %H:%M:%S";

using time_point_us = std::chrono::time_point<std::chrono::system_clock, std::chrono::microseconds>;


/// @brief	Converts a string in the form YYYY-MM-DD HH:mm:ss.ffffff to a time_point
/// @param	time	the time represented as a string described above
/// @return	time_point_us	a timepoint in microseconds
static time_point_us to_time_point_us(const std::string &time)
{
	std::stringstream ss(time);
	std::uint64_t usec;
	std::tm t;
	ss >> std::get_time(&t, g_timeFormat.c_str());
	char dot;
	ss.get(dot);
	ss >> usec;
	std::time_t converted_time = std::mktime(&t);
	auto timestamp = std::chrono::system_clock::from_time_t(converted_time);
	std::chrono::microseconds us { usec };
	timestamp += us;
	return(std::chrono::time_point_cast<std::chrono::microseconds>(timestamp));
}

/// @brief	Convert a time_point in microseconds to a string
/// @param	a time_point in microseconds
/// @return	a string with the following format YYYY-MM-DD HH:mm:ss.ffffff
static std::string to_string(time_point_us time)
{
	time_t tm = std::chrono::system_clock::to_time_t(time);
	std::tm *t = std::localtime(&tm);

	auto tm_seconds = std::chrono::time_point_cast<std::chrono::seconds>(time);
	auto tm_usec = std::chrono::time_point_cast<std::chrono::microseconds>(time);
	auto us = tm_usec - tm_seconds;

	std::stringstream ss;
	ss << std::put_time(t, g_timeFormat.c_str()) << "." << std::setw(6) << std::setfill('0') << us.count();
	return(ss.str());
}


/// @brief	load ticks from a file
/// The file format is a tab separated file with the following format
/// 
/// timestamp<tab>source<tab>bid<tab>offer<tab>size
/// 
/// timesatamp - a date time with the following format YYYY-MM-DD HH:mm:ss.ffffff
/// source - a string with no spaces containing the source of the price
/// bid - bid price
/// offer - offer price
/// size - the amount at the price to buy or sell 
static void load_ticks(const std::string &storeFile, dt::data_table &ticks)
{
	std::ifstream storeStream;

	storeStream.open(storeFile, std::ios::in);
	if (!storeStream)
		throw(std::runtime_error("failed to open file"));

	std::string timestamp_str;
	std::string date_str;
	std::string source;
	double bid { 0.0 };
	double offer { 0.0 };
	double size { 0.0 };

	std::cout << "loading ticks..." << std::endl;
	while (storeStream >> date_str >> timestamp_str >> source >> bid >> offer >> size) {
		dt::data_table_row row = ticks.new_row();
		row.set(0, to_time_point_us(date_str + " "+ timestamp_str).time_since_epoch().count());
		row.set(1, source);
		row.set(2, bid);
		row.set(3, offer);
		row.set(4, size);
	}

	storeStream.close();
	std::cout << "loaded " << ticks.rows().size() << " rows" << std::endl;
}

/// @brief	Run the filter string a send the result to stdio
static int execute_filter(dt::data_table &ticks, const std::string &filter)
{
	std::cout << "running filter: " << filter << std::endl;
	int c = 0;
	for (auto itr : ticks.where(filter)) {
		c++;
		std::chrono::microseconds us { itr.get<std::uint64_t>(0) };
		auto timestamp = time_point_us::time_point(us);

		std::cout << to_string(timestamp) << ", "
					  << itr.get<dt::dt_char_ptr>(1) << ", "
					  << itr.get<double>(2) << ", "
					  << itr.get<double>(3) << ", "
					  << itr.get<double>(4)
					  << std::endl;
	}
	return(c);
}

/// @brief	Display help text after each command is executed
static void display_help(dt::data_table table)
{
	std::cout << std::endl << std::endl << "table columns: ";
	for (auto i : table.columns())
		std::cout << i.name() << ", ";
	std::cout << std::endl << "e.g. filter>> column > 1000" << std::endl;
	std::cout << "e.g. filter>> column = 'value'" << std::endl << std::endl;
	std::cout << "or exit to quit" << std::endl << std::endl;
}

int main(int argc, char **argv)
{
	try {
		if (argc == 1)
			throw(std::runtime_error("a tickstore file was not specified"));

		dt::data_table ticks {
			dt::data_table_columns {
				dt::data_table_column<std::uint64_t>("timestamp"),
				dt::data_table_column<std::string>("source"),
				dt::data_table_column<double>("bid"),
				dt::data_table_column<double>("offer"),
				dt::data_table_column<double>("size")
			}
		};

		load_ticks(argv[1], ticks);
		display_help(ticks);

		std::string filter;
		while (true) {
			std::cout << "filter>> ";
			std::getline(std::cin, filter);
			if (filter == "exit")
				break;

			try {
				int found = execute_filter(ticks, filter);
				std::cout << "found " << found << " rows" << std::endl;
			}
			catch (std::exception &e) {
				std::cout << e.what() << std::endl;
			}
			display_help(ticks);
		}
	}
	catch (std::exception &e) {
		std::cout << e.what();
	}

	return(0);
}
