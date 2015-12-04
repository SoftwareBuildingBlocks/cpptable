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


			data_table_iterator(const iter_t &r) :
				m_rows { r.m_rows },
				m_row { r.m_row }
			{
			}


			~data_table_iterator()
			{
			}


			iter_t& operator=(const iter_t &r)
			{
				m_row =  r.m_row;
				m_rows = r.m_rows;
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
				m_row = m_rows.row(m_row.row_num() + offset);
				return(*this);
			}


			iter_t operator+(difference_type offset) const
			{
				iter_t itr = *this;
				return(itr += offset);
			}


			iter_t& operator-=(difference_type offset)
			{
				m_row = m_rows.row(m_row.row_num() - offset);
				return(*this);
			}


			iter_t operator-(difference_type offset) const
			{
				iter_t itr = *this;
				return(itr -= offset);
			}


			difference_type operator-(const iter_t &r) const
			{
				return(this->m_row.row_num() - r.m_row.row_num());
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
				m_columns { columns }
			{
			}

			inline data_table_columns& columns() { return(m_columns); }
			inline data_table_row new_row() { return(m_rows.add()); }
			inline data_table_rows& rows() { return(m_rows); }
			inline data_table_row row(std::uint64_t r) { return(m_rows.row(r)); }
			inline void swap(std::uint64_t l, std::uint64_t r) { m_rows.swap(l, r); }

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
				return(iterator(m_rows, m_rows.size()));
			}

			//inline const_iterator end() const
			//{
			//	return(const_iterator(m_rows, m_rows.size()));
			//}


		private:
			data_table_columns m_columns;
			data_table_rows m_rows;
	};


	// dual_pivot_qsort is from Vladimir Yaroslavskiy's Dual-Pivot Quicksort algorithm.
	// This is basically a copy from the original paper.
	// TODO: make improvements: at least attempt to remove the double predicate logic
	//       in the equals processing near the end
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
				// todo: this logic calls for k == pivot
				//       figure out how to make this work with pred without
				//       calling it twice (pred is less or greater)
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


	template<typename Pred>
	void sort(data_table::iterator begin, data_table::iterator end, Pred pred)
	{
		if (begin > end)
			throw(std::invalid_argument("begin > end"));

		dual_pivot_qsort(begin, end, 3, pred);
	}


	template<typename Pred>
	void sort(data_table &table, Pred pred)
	{
		sort(table.begin(), table.end() - 1, pred);
	}
}
