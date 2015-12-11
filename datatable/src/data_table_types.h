#pragma once
#include <cstdint>


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
	const std::uint32_t tid_char = 9;
	const std::uint32_t tid_char_ptr = 10;
	const std::uint32_t tid_wchar = 11;
	const std::uint32_t tid_wchar_ptr = 12;


	using dt_char_ptr = const char *const;
	using dt_wchar_ptr = const wchar_t *const;
}