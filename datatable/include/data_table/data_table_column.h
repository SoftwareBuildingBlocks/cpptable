#pragma once
#include <string>
#include <vector>
#include "data_table_types.h"


namespace dt
{
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


	template<>
	class data_table_column<char> : public basic_data_column
	{
		public:
		explicit data_table_column(const std::string &name) :
			basic_data_column { name, tid_char, sizeof(char) }
		{
		}
	};


	template<>
	class data_table_column<std::string> : public basic_data_column
	{
		public:
		explicit data_table_column(const std::string &name) :
			basic_data_column { name, tid_char_ptr, sizeof(char*) }
		{
		}
	};


	template<>
	class data_table_column<wchar_t> : public basic_data_column
	{
		public:
		explicit data_table_column(const std::string &name) :
			basic_data_column { name, tid_wchar, sizeof(wchar_t) }
		{
		}
	};


	template<>
	class data_table_column<std::wstring> : public basic_data_column
	{
		public:
		explicit data_table_column(const std::string &name) :
			basic_data_column { name, tid_char_ptr, sizeof(wchar_t*) }
		{
		}
	};


	using data_table_columns = std::vector<basic_data_column>;
}
