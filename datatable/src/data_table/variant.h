#pragma once
// Adapted from code authored by Tibor Djurica Potpara
// https://gist.github.com/tibordp/6909880

#include <utility>
#include <typeinfo>
#include <type_traits>
#include <stdexcept>
#include <iostream>

template <std::size_t arg1, std::size_t ... others>
struct static_max;

template <std::size_t arg>
struct static_max<arg>
{
	static const std::size_t value = arg;
};

template <std::size_t arg1, std::size_t arg2, std::size_t ... others>
struct static_max<arg1, arg2, others...>
{
	static const std::size_t value = arg1 >= arg2 ? static_max<arg1, others...>::value :
		static_max<arg2, others...>::value;
};

const std::size_t void_typeid = typeid(void).hash_code();

template<typename... Ts>
struct variant_helper;

template<typename F, typename... Ts>
struct variant_helper<F, Ts...> {
	inline static void destroy(std::size_t id, void * data)
	{
		if (id == void_typeid)
			return;
		if (id == typeid(F).hash_code()) 
			reinterpret_cast<F*>(data)->~F();
		else
			variant_helper<Ts...>::destroy(id, data);
	}

	inline static void move(std::size_t old_t, void * old_v, void * new_v)
	{
		if (old_t == void_typeid)
			return;
		if (old_t == typeid(F).hash_code())
			new (new_v) F(std::move(*reinterpret_cast<F*>(old_v)));
		else
			variant_helper<Ts...>::move(old_t, old_v, new_v);
	}

	inline static void copy(std::size_t old_t, const void * old_v, void * new_v)
	{
		if (old_t == void_typeid)
			return;
		if (old_t == typeid(F).hash_code())
			new (new_v) F(*reinterpret_cast<const F*>(old_v));
		else
			variant_helper<Ts...>::copy(old_t, old_v, new_v);
	}
};

template<> struct variant_helper<std::string> {
	inline static void destroy(std::size_t id, void *data)
	{
		using str = std::string;
		reinterpret_cast<str*>(data)->~str();
	}
	
	inline static void move(std::size_t old_t, void *old_v, void *new_v)
	{ 
		new (new_v) typename std::string(std::move(*reinterpret_cast<std::string*>(old_v)));
	}

	inline static void copy(std::size_t old_t, const void *old_v, void *new_v)
	{
		new (new_v) typename std::string(*reinterpret_cast<const std::string*>(old_v));
	}
};

template<> struct variant_helper<> {
	inline static void destroy(std::size_t id, void * data) { throw std::runtime_error("variant does not have this type"); }
	inline static void move(std::size_t old_t, void * old_v, void * new_v) { throw std::runtime_error("variant does not have this type"); }
	inline static void copy(std::size_t old_t, const void * old_v, void * new_v) { throw std::runtime_error("variant does not have this type"); }
};

template<typename... Ts>
struct variant {
private:
	static const std::size_t data_size = static_max<sizeof(Ts)...>::value;
	static const std::size_t data_align = static_max<alignof(Ts)...>::value;

	using data_t = typename std::aligned_storage<data_size, data_align>::type;

	using helper_t = variant_helper<Ts...>;

	static inline std::size_t invalid_type() {
		return typeid(void).hash_code();
	}

	std::size_t type_id;
	data_t data;
public:
	variant() : type_id(invalid_type()) { }

	variant(const variant<Ts...>& old) : type_id(old.type_id)
	{
		helper_t::copy(old.type_id, &old.data, &data);
	}

	variant(variant<Ts...>&& old) : type_id(old.type_id)
	{
		helper_t::move(old.type_id, &old.data, &data);
	}

	variant<Ts...>& operator=(variant<Ts...>&& old)
	{
		if (this == &old)
			return *this;
		helper_t::move(old.type_id, &old.data, &data);
		type_id = old.type_id;
		old.type_id = void_typeid;
		return *this;
	}

	variant<Ts...>& operator=(const variant<Ts...>& old)
	{
		helper_t::copy(old.type_id, &old.data, &data);
		type_id = old.type_id;
		return *this;
	}

	template<typename T>
	bool is() {
		return (type_id == typeid(T).hash_code());
	}

	bool valid() {
		return (type_id != invalid_type());
	}

	template<typename T>
	variant<Ts...>& set(const T& arg)
	{
		// First we destroy the current contents    
		helper_t::destroy(type_id, &data);
		new (&data) T(arg);
		type_id = typeid(T).hash_code();
		return *this;
	}

	template<typename T>
	T& get()
	{
		// It is a dynamic_cast-like behaviour
		if (type_id == typeid(T).hash_code())
			return *reinterpret_cast<T*>(&data);
		else
			throw std::bad_cast();
	}

	~variant() {
		helper_t::destroy(type_id, &data);
		type_id = void_typeid;
	}
};
