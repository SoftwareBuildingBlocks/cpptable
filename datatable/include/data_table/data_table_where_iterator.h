#pragma once
#include <vector>
#include <iterator>


namespace dt
{
	template<typename _TableTy>
	class data_table_where_iterator :
		public std::iterator<std::random_access_iterator_tag, typename _TableTy::row_type>
	{
	public:
		using difference_type = typename std::iterator_traits<data_table_where_iterator>::difference_type;
		using reference = typename std::iterator_traits<data_table_where_iterator>::reference;
		using pointer = typename std::iterator_traits<data_table_where_iterator>::pointer;
		using iter_t = data_table_where_iterator<_TableTy>;

	public:
		data_table_where_iterator(_TableTy &t, difference_type d, const std::vector<difference_type>& rows) :
			m_raw_table{ t },
			m_selected_row_ids(rows),
			m_row_idx_idx { d }
		{
			if(d < m_selected_row_ids.size())
				m_row = t.row(m_selected_row_ids[d]);
		}


		data_table_where_iterator(const iter_t &r) :
			m_raw_table{ r.m_raw_table },
			m_selected_row_ids(r.m_selected_row_ids),
			m_row_idx_idx{ r.m_row_idx_idx },
			m_row(r.m_row)
		{
		}


		~data_table_where_iterator()
		{
		}


		iter_t& operator=(const iter_t &r)
		{
			m_row_idx_idx = r.m_row_idx_idx;
			m_raw_table = r.m_raw_table;
			m_selected_row_ids = r.m_selected_row_ids;
			m_row = r.m_row;
			return(*this);
		}


		iter_t& operator++()
		{
			m_row_idx_idx++;
			if (m_row_idx_idx >= m_selected_row_ids.size())
			{
				m_row_idx_idx = m_selected_row_ids.size();
				return(*this);
			}

			auto rowidx = m_selected_row_ids[m_row_idx_idx];
			m_row = m_raw_table.row(rowidx);
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
			m_row_idx_idx = m_row_idx_idx - 1;
			auto rowidx = m_selected_row_ids[m_row_idx_idx];
			m_row = m_raw_table.row(rowidx);
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
			return m_row;
		}


		pointer operator->()
		{
			return &m_row;
		}


		bool operator==(const iter_t &r) const
		{
			return ((m_row_idx_idx == r.m_row_idx_idx) && (m_selected_row_ids == r.m_selected_row_ids));
		}


		bool operator!=(const iter_t &r) const
		{
			return(!operator==(r));
		}


		bool operator<(const iter_t &r) const
		{
			return(m_selected_row_ids[m_row_idx_idx]  < r.m_selected_row_ids[r.m_row_idx_idx]);
		}


		bool operator<=(const iter_t &r) const
		{
			return(m_selected_row_ids[m_row_idx_idx] <= r.m_selected_row_ids[r.m_row_idx_idx]);
		}


		bool operator>(const iter_t &r) const
		{
			return(m_selected_row_ids[m_row_idx_idx] > r.m_selected_row_ids[r.m_row_idx_idx]);
		}


		bool operator>=(const iter_t &r) const
		{
			return(m_selected_row_ids[m_row_idx_idx] >= r.m_selected_row_ids[r.m_row_idx_idx]);
		}


		iter_t& operator+=(difference_type offset)
		{
			m_row_idx_idx += offset;
			auto rowidx = m_selected_row_ids[m_row_idx_idx];
			m_row = m_raw_table.row(rowidx);
			return(*this);
		}


		iter_t operator+(difference_type offset) const
		{
			iter_t itr = *this;
			return(itr += offset);
		}


		iter_t& operator-=(difference_type offset)
		{
			m_row_idx_idx -= offset;
			auto rowidx = m_selected_row_ids[m_row_idx_idx];
			m_row = m_raw_table.row(rowidx);
			return(*this);
		}


		iter_t operator-(difference_type offset) const
		{
			iter_t itr = *this;
			return(itr -= offset);
		}


		difference_type operator-(const iter_t &r) const
		{
			return(this->m_row_idx_idx - r.m_row_idx_idx);
		}

		data_table_where_iterator<_TableTy> begin();
		data_table_where_iterator<_TableTy> end();

	private:
		_TableTy &m_raw_table;
		std::vector<difference_type> m_selected_row_ids;
		difference_type m_row_idx_idx;
		typename _TableTy::row_type m_row;
	};

	template <typename _TableTy>
	data_table_where_iterator<_TableTy> data_table_where_iterator<_TableTy>::begin()
	{
		data_table_where_iterator<_TableTy> dtwi(m_raw_table, 0, m_selected_row_ids);
		return dtwi;
	}

	template <typename _TableTy>
	data_table_where_iterator<_TableTy> data_table_where_iterator<_TableTy>::end()
	{
		return data_table_where_iterator<_TableTy>(m_raw_table, m_selected_row_ids.size(), m_selected_row_ids);
	}
}
