#pragma once
#include <stdarg.h>
#include <memory>
#include <string>

std::wstring s2ws(const std::string& str);
std::string ws2s(const std::wstring& wstr);
std::string& ltrim(std::string& s, const char* t = " \t\n\r\f\v");
std::string& rtrim(std::string& s, const char* t = " \t\n\r\f\v");
void str_replace(std::string& str,const std::string& search, const std::string& replace);

template <int buffsz>
std::string format(const char* fmt, ...) {
	auto buffer = std::make_unique<char[]>(buffsz);

	if (buffer == nullptr)
		throw std::runtime_error("Cannot allocate memory in format");

	va_list vl;
	va_start(vl, fmt);
	vsnprintf(buffer.get(), buffsz, fmt, vl);

	// if there is not enough room null termination is not added.
	// Always add null termination
	buffer[buffsz - 1] = 0;
	std::string ret(buffer.get());

	va_end(vl);
	return ret;
}
