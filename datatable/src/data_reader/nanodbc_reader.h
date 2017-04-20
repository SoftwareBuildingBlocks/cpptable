namespace dt { class data_table; }
namespace nanodbc { class result; }


namespace dt
{
	///
	/// @brief      fill a data_table with a nanodbc result set
	///
	///             the data_table passed in will be reset.  the schema
	///             will be reset from the nanodbc result.  the data type
	///             are mapped as follows:
	///
	///				SQL_C_LONG		=> std::int32_t
	///				SQL_C_SBIGINT	=> std::int64_t
	///				SQL_C_DOUBLE	=> double
	///				SQL_C_DATE		=> nanodbc::date
	///				SQL_C_TIMESTAMP	=> nanodbc::timestamp
	///				SQL_C_CHAR		=> std::string
	///
	///				Type not mentioned will throw std::runtime_error
	///
	/// @param[in]  from   a nanodbc result set
	/// @param[in]  to     the data_table to fill
	void fill(nanodbc::result &from, data_table &to);
}