#pragma once
#include <string>
#include <vector>
#include <typeinfo>
#include "data_table_types.h"


namespace dt
{
	class basic_data_column
	{
		public:
			basic_data_column() { }

			basic_data_column(const std::string &name, std::size_t type, std::size_t size) :
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


			inline std::size_t size() const { return(m_size); }
			inline const std::string& name() const { return(m_name); }
			inline std::size_t type() const { return(m_type); }

		private:
			std::size_t m_type;
			std::size_t m_size;
			std::string m_name;
	};



	template<typename T>
	class data_table_column : public basic_data_column
	{
		public:
			using value_type = T;

		public:
			data_table_column(const std::string &name) :
				basic_data_column { name, typeid(T).hash_code(), sizeof(T) }
			{
			}
	};

	
	using data_table_columns = std::vector<basic_data_column>;
}
