#pragma once
#include <data_table/row_buffer.h>


namespace dt
{
	class data_table_row
	{
		public:
			data_table_row() :
				m_buffer { nullptr },
				m_row { 0 }
			{
			}


			data_table_row(std::uint64_t row, row_buffer *buffers) :
				m_buffer { buffers },
				m_row { row }
			{
			}


			data_table_row(const data_table_row &r) :
				m_buffer { r.m_buffer },
				m_row { r.m_row }
			{
			}


			data_table_row& operator=(const data_table_row &r)
			{
				m_row = r.m_row;
				m_buffer = r.m_buffer;
				return(*this);
			}


			inline std::uint64_t row_num() const { return(m_row); }


			template<typename T> void set(const std::string &col, const T& value)
			{
				m_buffer->set<T>(m_row, col, value);
			}

			template<typename T> void set(size_t col, const T& value)
			{
				m_buffer->set<T>(m_row, col, value);
			}
			

			template<typename T> const T& get(const std::string &col) const
			{
				return(m_buffer->get<T>(m_row, col));
			}


			template<typename T> const T& get(size_t col) const
			{
				return(m_buffer->get<T>(m_row, col));
			}


			inline bool is_null(std::size_t col) const
			{
				return(m_buffer->is_null(m_row, col));
			}


			inline bool is_null(const std::string &col)
			{
				return(m_buffer->is_null(m_row, col));
			}

			
			template<typename T> void clear(const std::string &col)
			{
				m_buffer->clear<T>(m_row, col);
			}


			template<typename T> void clear(size_t col)
			{
				m_buffer->clear<T>(m_row, col);
			}

			inline void swap(data_table_row &r)
			{
				if (m_row == r.m_row)
					return;
				m_buffer->swap(m_row, r.m_row);
			}

		private:
			row_buffer *m_buffer;
			std::uint64_t m_row;
	};


	class data_table_rows
	{
		public:
			using row_type = data_table_row;

		public:
			explicit data_table_rows(const data_table_columns &columns) :
				m_buffer { columns }
			{
			}

			data_table_rows(const data_table_rows &c) :
				m_buffer { c.m_buffer }
			{
			}

			inline std::uint64_t size() const { return(m_buffer.row_count()); }

			inline row_type add() { return(row_type(m_buffer.add(), &m_buffer)); }
			inline row_type row(std::uint64_t r) { return(row_type(r, &m_buffer)); }
			inline void swap(std::uint64_t l, std::uint64_t r) 
			{
				row_type lr = row(l);
				row_type rr = row(r);
				swap(lr, rr);
			}
			// todo: enforce that l and r are from the same table
			inline void swap(row_type &l, row_type &r) { l.swap(r); }

		public:
			row_buffer m_buffer;
	};
}
