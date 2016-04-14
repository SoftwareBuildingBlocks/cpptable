#pragma once
#include <algorithm>
#include <iterator>
#include "data_table_column.h"
#include "data_table_row.h"
#include "data_table_where_iterator.h"

namespace dt 
{
	///
	/// @brief      data_table_rows iterator
	///
	template<typename _RTy>
	class data_table_iterator :
		public std::iterator<std::random_access_iterator_tag, typename _RTy::row_type>
	{
		public:
			///
			/// @brief 		Short name for the iterator of rows
			///
			using iter_t = data_table_iterator<_RTy>;

		public:
			///
			/// @brief      Constructor starting from row d
			///
			/// @param      r     The data table rows to iterate
			/// @param[in]  d     The row number to start from
			///
			data_table_iterator(_RTy &r, difference_type d) :
				m_rows { r },
				m_row { r.row(d) }
			{
			}

			///
			/// @brief      Copy constructor
			///
			/// @param[in]  r     Iterator to copy
			///
			data_table_iterator(const iter_t &r) :
				m_rows { r.m_rows },
				m_row { r.m_row }
			{
			}


			~data_table_iterator()
			{
			}


			///
			/// @brief      Assignment operator
			///
			/// @param[in]  r     The iterator to copy
			///
			/// @return     A reference to this iterator
			///
			iter_t& operator=(const iter_t &r)
			{
				m_row =  r.m_row;
				m_rows = r.m_rows;
				return(*this);
			}

			///
			/// @brief      Prefix increment the iterator
			///
			/// @return     The next row.
			///
			iter_t& operator++()
			{	
				m_row = m_rows.row(m_row.row_num() + 1);
				return(*this);
			}

			///
			/// @brief      Postfix increment the iterator
			///
			/// @return     The next row
			///
			iter_t operator++(int)
			{
				iter_t itr = *this;
				++*this;
				return(itr);
			}

			
			///
			/// @brief      Prefix decrement
			///
			/// @return     The previous row
			///
			iter_t& operator--()
			{
				m_row = m_rows.row(m_row.row_num() - 1);
				return(*this);
			}

			///
			/// @brief      Postfix decrement
			///
			/// @return     The previous row
			///
			iter_t operator--(int)
			{
				iter_t itr = *this;
				--*this;
				return(itr);
			}


			///
			/// @brief      Dereference a row
			///
			/// @return     A refrence to a row
			///
			reference operator*()
			{
				return(m_row);
			}


			///
			/// @brief      Pointer operator
			///
			/// @return     A pointer to a row
			///
			pointer operator->()
			{
				return(&m_row);
			}


			///
			/// @brief      Equal operator
			///
			/// @param[in]  r     The row to compare
			///
			/// @return     true if the row numbers are the same
			///
			bool operator==(const iter_t &r) const
			{
				return(m_row.row_num() == r.m_row.row_num());
			}


			///
			/// @brief      Not equal operator
			///
			/// @param[in]  r     The row to compare
			///
			/// @return     true if the rows are not the same row number
			///
			bool operator!=(const iter_t &r) const
			{
				return(m_row.row_num() != r.m_row.row_num());
			}


			///
			/// @brief      Less than operator
			///
			/// @param[in]  r     the row to compare to
			///
			/// @return     true if the row number less than r's
			///
			bool operator<(const iter_t &r) const
			{
				return(m_row.row_num() < r.m_row.row_num());
			}


			///
			/// @brief      Less equals operator
			///
			/// @param[in]  r     the row to compare to
			///
			/// @return     true if the row number less than or equal to r's
			///
			bool operator<=(const iter_t &r) const
			{
				return(m_row.row_num() <= r.m_row.row_num());
			}


			///
			/// @brief      Less than operator
			///
			/// @param[in]  r     the row to compare to
			///
			/// @return     true if the row number less than r's
			///
			bool operator>(const iter_t &r) const
			{
				return(m_row.row_num() > r.m_row.row_num());
			}


			///
			/// @brief      Greater equals operator
			///
			/// @param[in]  r     the row to compare to
			///
			/// @return     true if the row number greater than or equal to r's
			///
			bool operator>=(const iter_t &r) const
			{
				return(m_row.row_num() >= r.m_row.row_num());
			}


			///
			/// @brief      Add assignment operator
			///
			/// @param[in]  offset  Move to the offset relative to the current
			///                     position
			///
			/// @return     The iterator at the new row position
			///
			iter_t& operator+=(difference_type offset)
			{
				m_row = m_rows.row(m_row.row_num() + offset);
				return(*this);
			}


			///
			/// @brief      Addition operator
			///
			/// @param[in]  offset  The offset from the current position
			///
			/// @return     A new iterator at the new position
			///
			iter_t operator+(difference_type offset) const
			{
				iter_t itr = *this;
				return(itr += offset);
			}


			///
			/// @brief      Subtract assignment operator
			///
			/// @param[in]  offset  The offset from the current position to
			///                     subtract
			///
			/// @return     A reference to the iterator at the new position
			///
			iter_t& operator-=(difference_type offset)
			{
				m_row = m_rows.row(m_row.row_num() - offset);
				return(*this);
			}


			///
			/// @brief      Iterator subtraction operator
			///
			/// @param[in]  offset  The offset to subtract
			///
			/// @return     A new iterator at the new position
			///
			iter_t operator-(difference_type offset) const
			{
				iter_t itr = *this;
				return(itr -= offset);
			}


			///
			/// @brief      Iterator difference operator
			///
			/// @param[in]  r     The iterator to subtract from
			///
			/// @return     The distance between the two iterators
			///
			difference_type operator-(const iter_t &r) const
			{
				return(this->m_row.row_num() - r.m_row.row_num());
			}


		private:
			_RTy &m_rows;
			typename _RTy::row_type m_row;
	};


	///
	/// @brief      data_table with dynamic columns and basic dynamic query
	///             capability.
	///
	class data_table
	{
		public:
			using row_type = data_table_rows::row_type;
			using iterator = data_table_iterator<data_table_rows>;
			using where_iterator = data_table_where_iterator<data_table_rows>;

		public:
			///
			/// @brief      data_table contructor taking column definitions
			///
			/// @param[in]  columns  the column definition for the table
			///
			explicit data_table(const data_table_columns &columns) :
				m_rows { columns },
				m_columns { columns }
			{
			}

			///
			/// @brief      data_table copy constructor performs a deep copy
			///
			/// @param[in]  t     the table to copy
			///
			data_table(const data_table &t) :
				m_rows { t.m_rows },
				m_columns { t.m_columns }
			{
			}

			///
			/// @brief      Columns accessor
			///
			/// @return     The column definition for the table
			///
			inline data_table_columns& columns() { return(m_columns); }

			///
			/// @brief      Creates a new row in the table.  The row is created
			///             with null values
			///
			/// @return     The newly created row
			///
			inline data_table_row new_row() { return(m_rows.add()); }

			///
			/// @brief      Rows accessor
			///
			/// @return     the rows in the table
			///
			inline data_table_rows& rows() { return(m_rows); }

			///
			/// @brief      Row accessor
			///
			/// @param[in]  r     the row number
			///
			/// @return     The row for the now number specified
			///
			inline data_table_row row(std::uint64_t r) { return(m_rows.row(r)); }

			///
			/// @brief      Swap two rows given the row numbers
			///
			/// @param[in]  l     the first row to swap
			/// @param[in]  r     the second row to swap
			///
			inline void swap(std::uint64_t l, std::uint64_t r) { m_rows.swap(l, r); }

			///
			/// @brief      Iterator for the first row in the data_table rows
			///
			/// @return     An iterator representing the first row in the
			///             data_table
			///
			inline iterator begin() { return(iterator(m_rows, 0UL)); }

			///
			/// @brief      Iterator for past the end of the data_table rows
			///
			/// @return     Past the end iterator of the data_table rows
			///
			inline iterator end() { return(iterator(m_rows, m_rows.size())); }

			///
			/// @brief      An filtered iterator using a SQL-like where
			///             expression

			/// <pre>
			///		Examples:
			///				name = 'Euler'						// equal_to
			///				name > 'Andrew' AND name < ''		// AND
			///				age > 30							// greater_than
			///				age <= 43							// greater_equal
			///				age IN (22,22,43)					// IN
			///				zip != 10039						// not_equal
			///				zip <> 10039						// not_equal
			///				zip = 10039 AND age >= 43			// compound variables
			///				NOT zip = 10039						// NOT
			///				TRUE								// boolean
			///				(name IS NULL)						// parenthesis, NULL
			///				city LIKE '%dale'					// LIKE %
			///				city LIKE 'sc[ab]rsdal_'			// LIKE []
			///				city LIKE 'sc[^b]rsdale'			// LIKE [] with not expression
			///				aloha is null OR aloha = 1  		// conditional evaluation
			///				aloha is not null  					// Not Null
			///				city LIKE 'sca%' AND age in (20,30,43) 
			///
			///		Operators: 
			///				=, >, <, !=, <>, AND, OR, IN, NOT, IS, +, -, /, ()
			/// </pre>
			/// @param[in]  where_clause  A SQL-like where expression used to
			///                           filter the results of the iterator
			///
			/// @return     A where_iterator that filters rows using an
			///             expression
			///
			where_iterator where(const std::string& where_clause);

		private:
			data_table_columns m_columns;
			data_table_rows m_rows;
	};


	///
	/// @brief      A data_table_rows dual pivot quick sort
	///
	///             dual_pivot_qsort is from Vladimir Yaroslavskiy's Dual-Pivot
	///             Quicksort algorithm. This is basically a copy from the
	///             original paper.
	///
	/// @param[in]  left   The lower bound iterator
	/// @param[in]  right  The upper bound iterator
	/// @param[in]  div    The division point (should be set to 3)
	/// @param[in]  pred   The comparision predicate (use a lambda comparing row
	///                    details).  The expression should follow the standard
	///                    predicate rules of std::less or std::greater.
	///
	/// @tparam     Pred   the predicate type
	///
	template<typename Pred>
	void dual_pivot_qsort(data_table::iterator left, data_table::iterator right, data_table::iterator::difference_type div, Pred pred)
	{
		auto len = right - left + 1;
		if (len == 0)
			return;

		if (len < 27) {
			for (auto i = left + 1; i <= right; i++) {
				for (auto j = i; (j > left) && pred(*j, *(j - 1)); j--) {
					j->swap(*(j - 1));
				}
			}
			return;
		}

		auto third = len / div;

		// medians
		auto m1 = left + third;
		if (m1 <= left)
			m1 = left + 1;

		auto m2 = right - third;
		if (m2 >= right)
			m2 = right - 1;

		if (pred(*m1, *m2)) {
			m1->swap(*left);
			m2->swap(*right);
		}
		else {
			m1->swap(*right);
			m2->swap(*left);
		}

		// pivots
		auto pivot1 = left;
		auto pivot2 = right;

		// pointers
		auto less = left + 1;
		auto great = right - 1;

		// sorting
		for (auto k = less; k <= great; k++) {
			if (pred(*k, *pivot1)) {
				k->swap(*less);
				less++;
			}
			else if (pred(*pivot2, *k)) {
				while (k < great && pred(*pivot2, *great)) {
					great--;
				}
				k->swap(*great);
				great--;

				if (pred(*k, *pivot1)) {
					k->swap(*less);
					less++;
				}
			}
		}

		// swaps
		auto dist = great - less;

		left->swap(*(less - 1));
		right->swap(*(great + 1));

		dual_pivot_qsort(left, less - 2, div, pred);
		dual_pivot_qsort(great + 2, right, div, pred);

		// equal elements
		if (dist > len - 13 && pivot1 != pivot2) {
			for (auto k = less; k <= great; k++) {
				if (!pred(*k, *pivot1) && !pred(*pivot1, *k)) {
					k->swap(*less);
					less++;
				}
				else if (!pred(*k, *pivot2) && !pred(*pivot2, *k)) {
					k->swap(*great);
					great--;

					if (pred(*k, *pivot1)) {
						k->swap(*less);
						less++;
					}
				}
			}
		}

		if (pivot1 < pivot2) {
			dual_pivot_qsort(less, great, div, pred);
		}
	}


	///
	/// @brief      Sort the data_table within the begin/end range
	///
	///             Sort uses the dual_pivot_qsort function using the supplied
	///             predicate.
	///
	/// @param[in]  begin  The lower bound iterator
	/// @param[in]  end    The upper bound iterator
	/// @param[in]  pred   The comparision predicate (use a lambda comparing row
	///                    details).  The expression should follow the standard
	///                    predicate rules of std::less or std::greater.
	///
	/// @tparam     Pred   the predicate type
	///
	template<typename Pred>
	void sort(data_table::iterator begin, data_table::iterator end, Pred pred)
	{
		if (begin > end)
			throw(std::invalid_argument("begin > end"));

		dual_pivot_qsort(begin, end, 3, pred);
	}


	///
	/// @brief      Sorts the entire data_table.
	///
	/// @param      table  The data_table to sort.
	/// @param[in]  pred   The predicate used to control the sort.
	///
	/// @tparam     Pred   the predicate type
	///
	template<typename Pred>
	void sort(data_table &table, Pred pred)
	{
		sort(table.begin(), table.end() - 1, pred);
	}
}
