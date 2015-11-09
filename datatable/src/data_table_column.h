#pragma once
#include <string>
#include <cstdint>
#include <vector>


namespace dt
{
	const std::uint32_t tid_int8 = 1;
	const std::uint32_t tid_uint8 = 2;
	const std::uint32_t tid_int16 = 3;
	const std::uint32_t tid_uint16 = 4;
	const std::uint32_t tid_int32 = 5;
	const std::uint32_t tid_uint32 = 6;
	const std::uint32_t tid_int64 = 7;
	const std::uint32_t tid_uint64 = 8;


	class basic_data_column
	{
		public:
			basic_data_column() { }

			basic_data_column(const std::string &name, std::uint32_t type, std::uint32_t size) :
				m_name { name },
				m_type { type },
				m_size { size }
			{
			}


			basic_data_column(const basic_data_column& c) :
				m_name { c.m_name },
				m_type { c.m_type },
				m_size { c.m_size }
			{
			}


			basic_data_column(const basic_data_column&& c) :
				m_name { c.m_name },
				m_type { c.m_type },
				m_size { c.m_size }
			{
			}


			basic_data_column& operator=(const basic_data_column& c)
			{
				m_size = c.m_size;
				m_type = c.m_type;
				m_name = c.m_name;
				return(*this);
			}


			inline std::uint32_t size() const { return(m_size); }
			inline const std::string& name() const { return(m_name); }
			inline const std::uint32_t type() const { return(m_type); }

		private:
			std::uint32_t m_type;
			std::uint32_t m_size;
			std::string m_name;
	};



	template<typename T>
	class data_table_column : public basic_data_column
	{
		public:
			using value_type = T;

		public:
			data_table_column(const std::string &name, std::uint32_t type, std::uint32_t size) :
				basic_data_column { name, type, size }
			{
			}
	};


	template<>
	class data_table_column<std::int8_t> : public basic_data_column
	{
		public:
		explicit data_table_column(const std::string &name) :
			basic_data_column {name, tid_int8, sizeof(std::int8_t)}
		{
		}
	};


	template<>
	class data_table_column<std::uint8_t> : public basic_data_column
	{
		public:
		explicit data_table_column(const std::string &name) :
			basic_data_column {name, tid_uint8, sizeof(std::uint8_t)}
		{
		}
	};


	template<>
	class data_table_column<std::int16_t> : public basic_data_column
	{
		public:
		explicit data_table_column(const std::string &name) :
			basic_data_column {name, tid_int16, sizeof(std::int16_t)}
		{
		}
	};


	template<>
	class data_table_column<std::uint16_t> : public basic_data_column
	{
		public:
		explicit data_table_column(const std::string &name) :
			basic_data_column {name, tid_uint16, sizeof(std::uint16_t)}
		{
		}
	};


	template<>
	class data_table_column<std::int32_t> : public basic_data_column
	{
		public:
			explicit data_table_column(const std::string &name) :
				basic_data_column { name, tid_int32, sizeof(std::int32_t) }
			{
			}
	};


	template<>
	class data_table_column<std::uint32_t> : public basic_data_column
	{
		public:
		explicit data_table_column(const std::string &name) :
			basic_data_column {name, tid_uint32, sizeof(std::uint32_t)}
		{
		}
	};


	template<>
	class data_table_column<std::int64_t> : public basic_data_column
	{
		public:
			explicit data_table_column(const std::string &name) :
				basic_data_column { name, tid_int64, sizeof(std::int64_t) }
			{
			}
	};


	template<>
	class data_table_column<std::uint64_t> : public basic_data_column
	{
		public:
		explicit data_table_column(const std::string &name) :
			basic_data_column { name, tid_uint64, sizeof(std::uint64_t) }
		{
		}
	};

	using data_table_columns = std::vector<basic_data_column>;
}
