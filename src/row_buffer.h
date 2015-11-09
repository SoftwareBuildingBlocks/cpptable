#pragma once
#include <unordered_map>
#include <cstdint>
#include "data_table_column.h"


namespace dt
{
	class column_extent
	{
		public:
			column_extent() :
				m_rows { 0 },
				m_type { 0 },
				m_type_size { 0 },
				m_column { 0 },
				m_extent_size { 0 }
			{
			}


			void initialize(size_t col, std::uint32_t type, std::uint64_t typesize, std::uint64_t rows)
			{
				m_rows = rows;
				m_type = type;
				m_type_size = typesize;
				m_column = col;
				m_extent_size = rows * typesize;
			}


			template<typename T> void set(std::uint64_t row, const T &v)
			{
				T* pdata = reinterpret_cast<T*>(get_data_p(row));
				*pdata = v;	
			}   


			template<typename T> T& get(std::uint64_t row)
			{
				T* pdata = reinterpret_cast<T*>(get_data_p(row));
				return(*pdata);
			}


		private:
			inline char* get_data_p(std::uint64_t row)
			{
				std::uint64_t location = row * m_type_size;
				std::uint64_t offset = location % m_extent_size;
				std::uint64_t extentNo = location / m_extent_size;
				char *pdata = get_extent(extentNo) + offset;
				return(pdata);
			}


			inline char* get_extent(std::uint64_t extentNo)
			{
				// TODO: maybe use a linked list type structure for extents
				//		 so the extents and rows can be sparse
				if ((extentNo + 1) > m_extents.size())
					add_extents(extentNo - m_extents.size() + 1);
				return(m_extents[extentNo]);
			}


			inline void add_extents(std::uint64_t n)
			{
				// TODO: consider whether to clear the memory allocated
				// TODO: add an allocator
				for (std::uint64_t i = 0; i < n; i++)
					m_extents.push_back(new char[m_extent_size]);
			}
		

		private:
			std::vector<char*> m_extents;
			std::uint64_t m_extent_size;
			std::uint64_t m_rows;
			size_t m_column;
			std::uint32_t m_type;
			std::uint64_t m_type_size;
	};


	class row_buffer
	{
		public:
			explicit row_buffer(const data_table_columns &columns);

			
			std::uint64_t add();


			template<typename T> void set(std::uint64_t row, const std::string &col, const T& value)
			{
				return(set<T>(row, column_index(col), value));
			}


			template<typename T> void set(std::uint64_t row, size_t col, const T& value)
			{
				column_extent &extent = m_column_extents[col];
				extent.set<T>(row, value);
			}


			template<typename T> T get(std::uint64_t row, const std::string &col)
			{
				column_extent &extent = m_column_extents[column_index(col)];
				return(extent.get<T>(row));
			}


			template<typename T> T get(std::uint64_t row, size_t col)
			{
				column_extent &extent = m_column_extents[col];
				return(extent.get<T>(row));
			}


			inline size_t column_index(const std::string &col) const
			{
				auto itr = m_name_to_ordinal.find(col);
				if (itr == m_name_to_ordinal.end())
					throw(std::out_of_range("column " + col + " does not exist"));
				return(itr->second);
			}


			inline std::uint64_t row_count() const { return(m_row_count); }


		private:
			std::vector<column_extent> m_column_extents;
			std::unordered_map<std::string, size_t> m_name_to_ordinal;
			std::uint64_t m_rows_per_extent;
			std::uint64_t m_row_count;
	};
}
