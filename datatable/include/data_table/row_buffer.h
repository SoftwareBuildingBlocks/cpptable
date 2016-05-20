#pragma once
#include <memory>
#include <unordered_map>
#include <cstdint>
#include "data_table_column.h"
#include <cstring>

namespace dt
{
	template<typename T>
	class store_data_t
	{
		public:
			inline void store(char *p, const T &v)
			{
				T *pdata = reinterpret_cast<T*>(p);
				*pdata = v;
			}

			inline T get(char *p) const { return(*reinterpret_cast<T*>(p)); }

			inline void clear(char *p) { }
	};

	
	template<>
	class store_data_t<std::string>
	{
		public:
			inline void store(char *p, const std::string &v)
			{
				char **pdata = reinterpret_cast<char**>(p);
				*pdata = store_string(v);
			}

			inline dt::dt_char_ptr get(char *p) const { return(*reinterpret_cast<char**>(p)); }

			inline void clear(char *p)
			{
				char **pdata = reinterpret_cast<char**>(p);
				delete [](*pdata);
				*pdata = nullptr;
			}

		private:
			inline char* store_string(const std::string &v)
			{
				char *s = new char[v.size() + 1];
				std::memcpy(s, v.c_str(), v.size() + 1);
				return(s);
			}
	};


	template<>
	class store_data_t<std::wstring>
	{
		public:
			inline void store(char *p, const std::wstring &v)
			{
				wchar_t **pdata = reinterpret_cast<wchar_t**>(p);
				*pdata = store_string(v);
			}

			inline dt::dt_wchar_ptr get(char *p) const { return(*reinterpret_cast<wchar_t**>(p)); }

			inline void clear(char *p)
			{
				wchar_t **pdata = reinterpret_cast<wchar_t**>(p);
				delete [](*pdata);
				*pdata = nullptr;
			}

		private:
			inline wchar_t* store_string(const std::wstring &v)
			{
				wchar_t *s = new wchar_t[v.size() + 1];
				std::memcpy(s, v.c_str(), (v.size() + 1) * sizeof(wchar_t));
				return(s);
			}
	};


	class column_extent
	{
		public:
			column_extent() :
				m_rows { 0 },
				m_type { 0 },
				m_type_size { 0 },
				m_column { 0 },
				m_extent_size { 0 },
				m_data_size { 0 },
				m_null_map_size { 0 }
			{
			}


			column_extent(std::size_t col, std::uint32_t type, std::uint64_t typesize, std::uint64_t rows)
			{
				initialize(col, type, typesize, rows);
			}


			~column_extent()
			{
				delete_strings();
			}

			
			column_extent(const column_extent &c)
			{
				*this = c;
			}

			
			column_extent(column_extent &&c)
			{
				if (this == &c)
					return;
				m_extents.swap(c.m_extents);
				m_rows = c.m_rows;
				m_type = c.m_type;
				m_type_size = c.m_type_size;
				m_column = c.m_column;
				m_data_size = c.m_data_size;
				m_extent_size = c.m_extent_size;
				m_null_map_size = c.m_null_map_size;
				c.m_extents.clear();
				m_temp_data = std::move(c.m_temp_data);
			}


			column_extent& operator=(const column_extent &c)
			{
				m_rows = c.m_rows;
				m_type = c.m_type;
				m_type_size = c.m_type_size;
				m_column = c.m_column;
				m_data_size = c.m_data_size;
				m_extent_size = c.m_extent_size;
				m_null_map_size = c.m_null_map_size;
				copy_buffer(c);
				return(*this);
			}


			column_extent& operator=(column_extent &&c)
			{
				if (this == &c)
					return(*this);
				m_extents.swap(c.m_extents);
				m_rows = c.m_rows;
				m_type = c.m_type;
				m_type_size = c.m_type_size;
				m_column = c.m_column;
				m_data_size = c.m_data_size;
				m_extent_size = c.m_extent_size;
				m_null_map_size = c.m_null_map_size;
				return(*this);
			}


			void initialize(std::size_t col, std::uint32_t type, std::uint64_t typesize, std::uint64_t rows)
			{
				m_rows = rows;
				m_type = type;
				m_type_size = typesize;
				m_column = col;
				std::size_t null_words = (rows / c_nullset_word_bits) + (rows % c_nullset_word_bits ? 1 : 0);
				m_null_map_size = static_cast<std::uint32_t>(null_words * sizeof(null_word_t));
				m_data_size = (rows * typesize);
				m_extent_size = m_data_size + m_null_map_size;
			}

			template<typename T> void set(std::uint64_t row, const T &v)
			{
				store_data_t<T> st;
				st.store(get_data_p(row), v);
				set_null_flag(row, false);
			}   


			template<typename T> void clear(std::uint64_t row)
			{
				store_data_t<T> st;
				st.clear(get_data_p(row));
				set_null_flag(row, true);
			}


			template<typename T> T get(std::uint64_t row) const
			{
				store_data_t<T> st;
				T pdata = st.get(get_data_p(row));
				return(pdata);
			}

			
			inline bool is_null(std::uint64_t row) const
			{
				null_word_t *pnullset = reinterpret_cast<null_word_t*>(get_null_set(row).get());
				std::uint64_t row_in_extent = row % m_rows;
				std::uint64_t null_word = row_in_extent / c_nullset_word_bits;
				std::uint64_t bit_in_word = row_in_extent % c_nullset_word_bits;
				std::uint64_t bit_mask = 1ull << bit_in_word;
				return((pnullset[null_word] & bit_mask) ? true : false);
			}

							
			inline void swap(std::uint64_t l, std::uint64_t r)
			{
				std::memcpy(get_temp(), get_data_p(l), m_type_size);
				std::memcpy(get_data_p(l), get_data_p(r), m_type_size);
				std::memcpy(get_data_p(r), get_temp(), m_type_size);
			}

		private:
			inline char* get_data_p(std::uint64_t row) const
			{
				std::uint64_t location = row * m_type_size;
				std::uint64_t offset = m_null_map_size + (location % m_data_size);
				std::uint64_t extentNo = location / m_data_size;
				char *pdata = get_extent(extentNo).get() + offset;
				return(pdata);
			}


			inline const std::unique_ptr<char>& get_extent(std::uint64_t extentNo) const
			{
				// TODO: maybe use a linked list type structure for extents
				//		 so the extents and rows can be sparse
				if ((extentNo + 1) > m_extents.size())
					add_extents(extentNo - m_extents.size() + 1);
				return(m_extents[extentNo]);
			}


			inline void add_extents(std::uint64_t n) const
			{
				// TODO: add an allocator
				for (std::uint64_t i = 0; i < n; i++) {
					std::unique_ptr<char> pdata { new char[m_extent_size] };
					std::memset(pdata.get(), 0xff, m_null_map_size);
					m_extents.emplace_back(std::move(pdata));
				}
			}


			inline const std::unique_ptr<char>& get_null_set(std::uint64_t row) const
			{
				std::uint64_t location = row * m_type_size;
				std::uint64_t extentNo = location / m_data_size;
				return(get_extent(extentNo));
			}


			inline void set_null_flag(std::uint64_t row, bool setnull)
			{
				null_word_t *pnullset = reinterpret_cast<null_word_t*>(get_null_set(row).get());
				std::uint64_t row_in_extent = row % m_rows;
				std::uint64_t null_word = row_in_extent / c_nullset_word_bits;
				std::uint64_t bit_in_word = row_in_extent % c_nullset_word_bits;
				std::uint64_t bit_mask = 1ull << bit_in_word;
				pnullset[null_word] = setnull ? (pnullset[null_word] | bit_mask) : (pnullset[null_word] & ~bit_mask);
			}


			inline char* get_temp()
			{
				if (m_temp_data == nullptr)
					m_temp_data = std::unique_ptr<char>(new char[m_type_size]);
				return(m_temp_data.get());
			}

			
			inline void copy_buffer(const column_extent &c)
			{
				for (auto &buffer : c.m_extents) {
					std::unique_ptr<char> bufCpy { new char[m_extent_size] };
					std::memcpy(bufCpy.get(), buffer.get(), m_extent_size);
					m_extents.emplace_back(std::move(bufCpy));
				}
				if (m_type == tid_char_ptr) {
					for (int r = 0; r < c.m_rows; r++) {
						if (!c.is_null(r))
							set<std::string>(r, c.get<dt_char_ptr>(r));
					}
				}
				else if (m_type == tid_wchar_ptr) {
					for (int r = 0; r < m_rows; r++) {
						if (!is_null(r))
							set<std::wstring>(r, get<dt_wchar_ptr>(r));
					}
				}
			}


			inline void delete_strings()
			{
				if (m_type == tid_char_ptr) {
					for (int r = 0; r < m_rows; r++) {
						if (!is_null(r))
							delete get<dt_char_ptr>(r);
					}
				}
				else if (m_type == tid_wchar_ptr) {
					for (int r = 0; r < m_rows; r++) {
						if (!is_null(r))
							delete get<dt_wchar_ptr>(r);
					}
				}
			}

		private:
			mutable std::vector<std::unique_ptr<char>> m_extents;
			std::unique_ptr<char> m_temp_data;
			std::uint64_t m_data_size;
			std::uint64_t m_extent_size;
			std::uint64_t m_rows;
			std::size_t m_column;
			std::uint32_t m_type;
			std::uint64_t m_type_size;
			std::uint32_t m_null_map_size;

			using null_word_t = std::uint64_t;
			static const std::size_t c_nullset_word_bits = sizeof(null_word_t) * 8;
	};
	

	class row_buffer
	{
		public:
			explicit row_buffer(const data_table_columns &columns);


			row_buffer(const row_buffer &c)
			{
				*this = c;
			}


			row_buffer& operator=(const row_buffer &c)
			{
				m_column_extents = c.m_column_extents;
				m_name_to_ordinal = c.m_name_to_ordinal;
				m_rows_per_extent = c.m_rows_per_extent;
				m_row_count = c.m_row_count;
				return(*this);
			}

			
			std::uint64_t add();


			template<typename T> void set(std::uint64_t row, const std::string &col, const T& value)
			{
				return(set<T>(row, column_index(col), value));
			}


			template<typename T> void set(std::uint64_t row, std::size_t col, const T& value)
			{
				column_extent &extent = m_column_extents[col];
				extent.set<T>(row, value);
			}

			template<typename T> void clear(std::uint64_t row, const std::string &col)
			{
				return(clear<T>(row, column_index(col)));
			}


			template<typename T> void clear(std::uint64_t row, std::size_t col)
			{
				column_extent &extent = m_column_extents[col];
				extent.clear<T>(row);
			}


			template<typename T> T get(std::uint64_t row, const std::string &col)
			{
				column_extent &extent = m_column_extents[column_index(col)];
				return(extent.get<T>(row));
			}


			template<typename T> T get(std::uint64_t row, std::size_t col)
			{
				column_extent &extent = m_column_extents[col];
				return(extent.get<T>(row));
			}


			inline bool is_null(std::uint64_t row, std::size_t col)
			{
				column_extent &extent = m_column_extents[col];
				return(extent.is_null(row));
			}

			
			inline bool is_null(std::uint64_t row, const std::string &col)
			{
				column_extent &extent = m_column_extents[column_index(col)];
				return(extent.is_null(row));
			}


			inline std::size_t column_index(const std::string &col) const
			{
				auto itr = m_name_to_ordinal.find(col);
				if (itr == m_name_to_ordinal.end())
					throw(std::out_of_range("column " + col + " does not exist"));
				return(itr->second);
			}


			inline std::uint64_t row_count() const { return(m_row_count); }


			inline void swap(std::uint64_t src_row, std::uint64_t dest_row)
			{
				for (auto &e : m_column_extents) { e.swap(src_row, dest_row); }
			}


		private:
			std::vector<column_extent> m_column_extents;
			std::unordered_map<std::string, std::size_t> m_name_to_ordinal;
			std::uint64_t m_rows_per_extent;
			std::uint64_t m_row_count;
	};
}
