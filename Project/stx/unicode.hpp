//
// unicode.hpp
//

#pragma once
#include <string>
#include <fstream>
#include <boost/format.hpp>

#ifdef _WIN32

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#include <tchar.h>
#include <Windows.h>

#else

#define _T(t) (t)
#define TEXT(t) (t)

typedef char TCHAR;

#endif

typedef std::basic_string<TCHAR, std::char_traits<TCHAR>, std::allocator<TCHAR> > tstring;

typedef boost::basic_format<TCHAR> tformat;


namespace unicode {

#ifdef __linux__
  std::string ToString(const tstring& str);
#endif

#ifdef _WIN32

tstring sjis2utf8(const tstring&);
tstring utf82sjis(const tstring&);

std::string ToString(const std::wstring& s);
std::wstring ToWString(const std::string& s);

inline std::string ToString(const std::string& s)
{
    return s;
}


inline std::wstring ToWString(const std::wstring& s)
{
    return s;
}

inline tstring ToTString(const std::wstring& s)
{
#ifdef UNICODE
    return s;
#else
    return ToString(s);
#endif
}

#endif

inline tstring ToTString(const std::string& s)
{
#ifdef UNICODE
	return ToWString(s);
#else
	return s;
#endif
}

} // unicode
