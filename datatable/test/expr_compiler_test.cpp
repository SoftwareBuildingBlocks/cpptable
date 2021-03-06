// ExprCompilerTest.cpp : Defines the entry point for the console application.
//

#include <ios>
#include <iomanip>
#include <iostream>
#include <gtest/gtest.h>
#include <data_table/result.h>
#include <data_table/string_util.h>
#include <data_table/expr_compiler.h>
#include "simple_data_row.h"
#include "test_data.h"

using namespace std;

vector<simple_data_row> get_test_data_rows();
static vector<simple_data_row> test_data = get_test_data_rows();


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

		row.set("Zip",val().set(get<0>(data)));
		row.set("Place",val().set(get<1>(data)));
		row.set("State",val().set(get<2>(data)));
		row.set("Stateabb",val().set(get<3>(data)));
		row.set("County",val().set(get<4>(data)));
		row.set("Latitude",val().set(get<5>(data)));
		row.set("Longitde",val().set(get<6>(data)));
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
		ziprow.get("Zip").get<std::int64_t>(),
		ziprow.get("Place").get<string>().c_str(),
		ziprow.get("State").get<string>().c_str(),
		ziprow.get("Stateabb").get<string>().c_str(),
		ziprow.get("County").get<string>().c_str(),
		ziprow.get("Latitude").get<double>(),
		ziprow.get("Longitde").get<double>()) << endl;
}

TEST(ExprCompiler, LikeTest)
{
	simple_data_row dr;
	dr.set("city",val().set<string>("scarsdale"));
	expr_compiler ec;
	ASSERT_TRUE(ec.init());
	ASSERT_TRUE(ec.eval("city LIKE 'scar%'", dr));
}

TEST(BasicCppTest, noskipws_test)
{
	string somestr("and so it goes");
	const string& str_expr = somestr;
	stringstream in(str_expr);
	istream& input = in;
	input >> std::noskipws;
	char c;
	auto is_eof = false;
	is_eof = (input >> c ? false : true);
}

TEST(ZipCodeSearch, pre_compiled_expression)
{
	auto& zip_table = test_data;
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
	auto& ziprows = test_data;

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

	dr.set("age",val().set(43));
	dr.set("zip",val().set(10583));
	dr.set("city",val().set<string>("scarsdale"));

	expr_compiler ec;
	ASSERT_TRUE(ec.init());
	ASSERT_TRUE(ec.eval("age > 30", dr));
	ASSERT_TRUE(ec.eval("(age > 30 + 12) AND (city = 'scarsdale') OR (zip = 10583)", dr));
}

TEST(ExprCompiler, AllUsage)
{
	simple_data_row dr;
	val null_val;
	
	dr.set("age",val().set(43));
	dr.set("zip",val().set(10039));
	dr.set("name",null_val);  // NULL
	dr.set("city",val().set<string>("scarsdale"));

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

