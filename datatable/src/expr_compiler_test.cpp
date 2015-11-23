// ExprCompilerTest.cpp : Defines the entry point for the console application.
//

#include <iomanip>
#include <iostream>
#include "gtest/gtest.h"
#include "result.h"
#include "simple_data_row.h"
#include "test_data.h"
#include "string_util.h"
#include "expr_compiler.h"

using namespace std;

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	std::cout.imbue(std::locale(""));
	std::cout << std::fixed << std::setprecision(0);
	return RUN_ALL_TESTS();
}

void print_result(std::string& query, bool retval)
{
	std::cout << (retval ? "True " : "False") << " -> " << " `" << query << "'" << std::endl;
}

vector<simple_data_row> get_test_data_rows()
{
	shared_ptr<vector<Data>> pdataColl;
	try
	{
		pdataColl = ComplierTest::TestData();
	}
	catch(const exception& e)
	{
		cout << e.what() << endl;
	}

	auto& dataColl = *(pdataColl.get());

	vector<simple_data_row> rows;
	for(auto data : dataColl)
	{
		simple_data_row row;

		row["Zip"]		= val().set(get<0>(data));
		row["Place"]	= val().set(get<1>(data));
		row["State"]	= val().set(get<2>(data));
		row["Stateabb"] = val().set(get<3>(data));
		row["County"]	= val().set(get<4>(data));
		row["Latitude"]	= val().set(get<5>(data));
		row["Longitde"] = val().set(get<6>(data));
		rows.push_back(row);
	}

	return rows;
}

void print_zip_header()
{
	cout << endl;
	cout << "------------------------------------------------------------------------------" << endl;
	cout << format<128>("%6s, %20.20s, %10.10s, %3.3s, %10.10s, %6.6s, %6.6s",
						"Zip","Place","State","Stateabb","County","Latitude","Longitude") << endl;
	cout << "------------------------------------------------------------------------------" << endl;
}

void print_zip_row(simple_data_row& ziprow)
{
	cout << format<128>("%6d, %20.20s, %10.10s, %3.3s, %10.10s, %0.3f, %0.3f", 
		ziprow["Zip"].get<int>(),
		ziprow["Place"].get<string>().c_str(),
		ziprow["State"].get<string>().c_str(),
		ziprow["Stateabb"].get<string>().c_str(),
		ziprow["County"].get<string>().c_str(),
		ziprow["Latitude"].get<double>(),
		ziprow["Longitde"].get<double>()) << endl;
}

TEST(ZipCodeSearch, pre_compiled_expression)
{
	auto zip_table = get_test_data_rows();
	expr_compiler expr_compiler;

	ASSERT_TRUE(expr_compiler.init());
	auto expr = expr_compiler.compile("Zip > 1 AND Zip <= 3000");
//	print_zip_header();

	for (auto zip_row: zip_table)
	{
		if (expr.eval(zip_row))
		{
//			print_zip_row(zip_row);
		}
	}

	cout << endl;
}

TEST(ZipCodeSearch, non_pre_compiled_expression)
{
	auto ziprows = get_test_data_rows();

	expr_compiler ec;
	ASSERT_TRUE(ec.init());

//	print_zip_header();

	for(auto ziprow : ziprows)
	{
		if(ec.eval("Zip > 2000 AND Zip <= 3000 OR State like 'Ma%' or Latitude > 42.0",ziprow))
		{
//			print_zip_row(ziprow);
		}
	}
	cout << endl;
}

TEST(ExprCompiler, SimpleUsage)
{
	simple_data_row dr;

	dr["age"]	= val().set(43);
	dr["zip"]	= val().set(10583);
	dr["city"]	= val().set<string>("scarsdale");

	expr_compiler ec;
	ASSERT_TRUE(ec.init());
	ASSERT_TRUE(ec.eval("age > 30", dr));
	ASSERT_TRUE(ec.eval("(age > 30 + 12) AND (city = 'scarsdale') OR (zip = 10583)", dr));
}

TEST(ExprCompiler, AllUsage)
{
	simple_data_row dr;
	
	dr["age"]	= val().set(43);
	dr["zip"]	= val().set(10039);
	dr["name"]	= val();  // NULL
	dr["city"]	= val().set<string>("scarsdale");

	expr_compiler ec;
	ASSERT_TRUE(ec.init());

	std::string query = "age > 30";
	EXPECT_TRUE(ec.eval(query, dr));

	query = "age > 43";
	EXPECT_FALSE(ec.eval(query, dr));

	query = "age >= 43";
	EXPECT_TRUE(ec.eval(query, dr));

	query = "age <= 43";
	EXPECT_TRUE(ec.eval(query, dr));

	query = "age <= 42";
	EXPECT_FALSE(ec.eval(query, dr));

	query = "zip = 10039";
	EXPECT_TRUE(ec.eval(query, dr));

	query = "zip != 10039";
	EXPECT_FALSE(ec.eval(query, dr));

	query = "zip <> 10039";
	EXPECT_FALSE(ec.eval(query, dr));

	query = "zip = 10039 AND age >= 43";
	EXPECT_TRUE(ec.eval(query, dr));

	query = "zip = 10039 AND age > 43";
	EXPECT_FALSE(ec.eval(query, dr));

	query = "zip = 10039 OR age > 43";
	EXPECT_TRUE(ec.eval(query, dr));

	query = "NOT zip = 10039";
	EXPECT_FALSE(ec.eval(query, dr));

	query = "NOT zip = 10000";
	EXPECT_TRUE(ec.eval(query, dr));

	query = "NOT zip <> 10039";
	EXPECT_TRUE(ec.eval(query, dr));

	query = "name IS NULL";
	EXPECT_TRUE(ec.eval(query, dr));

	query = "name IS NOT NULL";
	EXPECT_FALSE(ec.eval(query, dr));

	//query = "5";
	//print_result(query, ec.eval(query, dr));

	//query = "Zip = 10039";
	//print_result(query, ec.eval(query, dr));

	query = "true";
	EXPECT_TRUE(ec.eval(query, dr));

	query = "TRUE";
	EXPECT_TRUE(ec.eval(query, dr));

	query = "false";
	EXPECT_FALSE(ec.eval(query, dr));

	query = "FALSE";
	EXPECT_FALSE(ec.eval(query, dr));

	query = "(name IS NULL)";
	EXPECT_TRUE(ec.eval(query, dr));

	query = "false AND true or false";
	EXPECT_FALSE(ec.eval(query, dr));

	query = "age = 20+23";
	EXPECT_TRUE(ec.eval(query, dr));

	query = "age = 63-20";
	EXPECT_TRUE(ec.eval(query, dr));

	query = "age = (64 - 20 - 1)";
	EXPECT_TRUE(ec.eval(query, dr));

	query = "age = 64-20-2";
	EXPECT_FALSE(ec.eval(query, dr));

	query = "age = 20*2+3";
	EXPECT_TRUE(ec.eval(query, dr));

	query = "age = 20*2+2";
	EXPECT_FALSE(ec.eval(query, dr));

	query = "age = 80/2+3";
	EXPECT_TRUE(ec.eval(query, dr));

	query = "age = 80/2+2";
	EXPECT_FALSE(ec.eval(query, dr));

	query = "age IN (22,22,43)";
	EXPECT_TRUE(ec.eval(query, dr));

	query = "age IN (22,22,42)";
	EXPECT_FALSE(ec.eval(query, dr));

	query = "city = 'scarsdale'";
	EXPECT_TRUE(ec.eval(query, dr));

	query = "city = \"scarsdale\"";
	EXPECT_TRUE(ec.eval(query, dr));

	query = "city = 'hartsdale'";
	EXPECT_FALSE(ec.eval(query, dr));

	query = "city LIKE '%dale'";
	EXPECT_TRUE(ec.eval(query, dr));

	query = "city LIKE 'scar%'";
	EXPECT_TRUE(ec.eval(query, dr));

	query = "city LIKE 'scarsdal_'";
	EXPECT_TRUE(ec.eval(query, dr));

	query = "city LIKE 'sc[ab]rsdal_'";
	EXPECT_TRUE(ec.eval(query, dr));

	query = "city LIKE 'sc[^b]rsdale'";
	EXPECT_TRUE(ec.eval(query, dr));

	query = "city LIKE '%ar_da%'";
	EXPECT_TRUE(ec.eval(query, dr));

	query = "city LIKE '%foo'";
	EXPECT_FALSE(ec.eval(query, dr));

	query = "aloha is null";  
	EXPECT_TRUE(ec.eval(query, dr));

	query = "aloha is null OR aloha = 1";  // conditional evaluation
	EXPECT_TRUE(ec.eval(query, dr));

	query = "aloha is not null";  
	EXPECT_FALSE(ec.eval(query, dr));

	query = "aloha is not null and aloha = 1";  // conditional evaluation
	EXPECT_FALSE(ec.eval(query, dr));

	query =	R"(	
				city LIKE 'sca%'
				AND age in (20,30,43) 
			)";
	EXPECT_TRUE(ec.eval(query, dr));

}

