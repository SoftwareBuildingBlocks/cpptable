#pragma once
#include <algorithm>
#include <iterator>
#include "data_table_column.h"
#include "data_table_row.h"

namespace dt 
{
	template<typename _RTy>
	class data_table_iterator :
		public std::iterator<std::random_access_iterator_tag, typename _RTy::row_type>
	{
		public:
			using iter_t = data_table_iterator<_RTy>;

		public:
			data_table_iterator(_RTy &r, difference_type d) :
				m_rows { r },
				m_row { r.row(d) }
			{
			}


			data_table_iterator(const _RTy &r) :
				m_rows { r },
				m_row { r.row(d) }
			{
			}


			iter_t& operator=(const _RTy &r)
			{
				m_row = m_rows.row(r.row_num());
				return(*this);
			}


			iter_t& operator++()
			{	
				m_row = m_rows.row(m_row.row_num() + 1);
				return(*this);
			}

			iter_t operator++(int)
			{
				iter_t itr = *this;
				++*this;
				return(itr);
			}

			
			iter_t& operator--()
			{
				m_row = m_rows.row(m_row.row_num() - 1);
				return(*this);
			}

			iter_t operator--(int)
			{
				iter_t itr = *this;
				--*this;
				return(itr);
			}


			reference operator*()
			{
				return(m_row);
			}


			pointer operator->()
			{
				return(&m_row);
			}


			bool operator==(const iter_t &r) const
			{
				return(m_row.row_num() == r.m_row.row_num());
			}


			bool operator!=(const iter_t &r) const
			{
				return(m_row.row_num() != r.m_row.row_num());
			}


			bool operator<(const iter_t &r) const
			{
				return(m_row.row_num() < r.m_row.row_num());
			}


			bool operator<=(const iter_t &r) const
			{
				return(m_row.row_num() <= r.m_row.row_num());
			}


			bool operator>(const iter_t &r) const
			{
				return(m_row.row_num() > r.m_row.row_num());
			}


			bool operator>=(const iter_t &r) const
			{
				return(m_row.row_num() >= r.m_row.row_num());
			}


			iter_t& operator+=(difference_type offset)
			{
				m_rows.row(m_row.row_num() + offset);
				return(*this);
			}


			iter_t operator+(difference_type offset) const
			{
				iter_t itr = *this;
				return(itr += offset);
			}


			iter_t& operator-=(difference_type offset)
			{
				m_rows.row(m_row.row_num() - offset);
				return(*this);
			}


			iter_t operator-(difference_type offset) const
			{
				iter_t itr = *this;
				return(itr -= offset);
			}


		private:
			_RTy &m_rows;
			typename _RTy::row_type m_row;
	};


	class data_table
	{
		public:
			using row_type = data_table_rows::row_type;
			using iterator = data_table_iterator<data_table_rows>;

		public:
			explicit data_table(const data_table_columns &columns) :
				m_rows { columns },
				m_columns { }
			{
				std::copy(columns.cbegin(), columns.cend(), std::back_inserter(m_columns));
			}

			inline data_table_columns& columns() { return(m_columns); }
			inline data_table_row new_row() { return(m_rows.add()); }
			inline data_table_rows& rows() { return(m_rows); }
			inline data_table_row row(std::uint64_t r) { return(m_rows.row(r)); }

			inline iterator begin()
			{
				return(iterator(m_rows, 0UL));
			}

			//inline const_iterator cbegin() const
			//{
			//	return(const_iterator(m_rows, 0UL));
			//}

			inline iterator end()
			{
				return(iterator(m_rows, m_rows.size() - 1));
			}

			//inline const_iterator end() const
			//{
			//	return(const_iterator(m_rows, m_rows.size() - 1));
			//}


		private:
			data_table_columns m_columns;
			data_table_rows m_rows;
	};
}
