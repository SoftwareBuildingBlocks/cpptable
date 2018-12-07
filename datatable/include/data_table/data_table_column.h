#pragma once
#include <memory>
#include <string>
#include <vector>
#include <typeinfo>


namespace dt
{
	struct data_column_type_desc
	{
		virtual ~data_column_type_desc() { }
		virtual void clean(char *data) = 0;
		virtual void copy(char *from, char *to) = 0;
		virtual std::size_t type() const = 0;
		virtual std::size_t size() const = 0 ;
	};


	template<typename T>
	struct data_column_type_desc_impl : public data_column_type_desc
	{
		virtual void clean(char *data) override
		{
            // note: change the following line to the below to work
            //       around a compiler warning issue that may be a compiler warning bug
            //reinterpret_cast<T*>(data)->~T();
            auto obj { reinterpret_cast<T*>(data) };
            obj->~T();
            obj = nullptr;
		}

		virtual void copy(char *from, char *to) override
		{
			new (to) T(*reinterpret_cast<const T*>(from));
		}

		virtual std::size_t type() const override { return(typeid(T).hash_code()); }

		virtual std::size_t size() const override { return(sizeof(T)); }
	};

	// Struct to capture data column type in the constructor of basic_data_column
	template <typename U> struct identity { typedef U type; };

	class basic_data_column
	{
		public:
			basic_data_column() { }

			template<typename U>
			basic_data_column(const std::string &name, identity<U>) :
				m_name { name },
				m_destroyer { std::make_shared<data_column_type_desc_impl<U>>() }
			{
			}


			basic_data_column(const basic_data_column& c) :
				m_name { c.m_name },
				m_destroyer { c.m_destroyer }
			{
			}


			basic_data_column(basic_data_column&& c) :
				m_name { c.m_name },
				m_destroyer { c.m_destroyer }
			{
				c.m_destroyer = nullptr;
			}


			basic_data_column& operator=(const basic_data_column& c)
			{
				m_name = c.m_name;
				m_destroyer = c.m_destroyer;
				return(*this);
			}


			basic_data_column& operator=(basic_data_column&& c)
			{
				if (this == &c)
					return(*this);

				m_name = c.m_name;
				m_destroyer = c.m_destroyer;
				c.m_destroyer = nullptr;
				
				return(*this);
			}

			inline const std::string& name() const { return(m_name); }
			
			inline std::size_t type() const
			{
				if (m_destroyer)
					return(m_destroyer->type());
				return(0);
			}
		
			inline std::size_t size() const
			{
				if (m_destroyer)
					return(m_destroyer->size());
				return(0);
			}

			inline void clean(char *data)
			{
				if (m_destroyer)
					m_destroyer->clean(data);
			}

			inline void copy(char *from, char *to)
			{
				if (m_destroyer)
					m_destroyer->copy(from, to);
			}

		private:
			std::string m_name;
			std::shared_ptr<data_column_type_desc> m_destroyer;
	};


	template<typename T>
	class data_table_column : public basic_data_column
	{
		public:
			using value_type = T;

		public:
			data_table_column(const std::string &name) :
				basic_data_column { name, identity<T>() }
			{
			}

			data_table_column(const data_table_column& c) :
				basic_data_column { c }
			{
			}


			data_table_column(data_table_column&& c) :
				basic_data_column { c }
			{
			}


			data_table_column& operator=(const data_table_column &c)
			{
				return(basic_data_column::operator=(c));
			}

			
			data_table_column& operator=(data_table_column &&c)
			{
				return(basic_data_column::operator=(c));
			}
	};

	
	using data_table_columns = std::vector<basic_data_column>;
}
